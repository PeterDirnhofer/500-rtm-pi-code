#include <stdio.h>
#include <memory>
#include <cstring>
#include "globalVariables.h"
#include "communication.h"
#include "spi.h"
#include "dataStoring.h"


protocolElement::protocolElement(uint16_t x, uint16_t y, uint16_t z, uint8_t config)

{
    this->dataBytewise[0] = config;
    this->dataBytewise[1] = (x & 0xFF);
    this->dataBytewise[2] = (x & (0xFF<<8))>>8;
    this->dataBytewise[3] = (y & 0xFF);
    this->dataBytewise[4] = (y & (0xFF<<8))>>8;
    this->dataBytewise[5] = (z & 0xFF);
    this->dataBytewise[6] = (z & (0xFF<<8))>>8;  

}
protocolElement::protocolElement(uint8_t *dataBytewise)

{
    //received data and going to analyze it
    memcpy(&(this->x), &(dataBytewise[1]), 2);
    memcpy(&(this->y), &(dataBytewise[3]), 2);
    memcpy(&(this->z), &(dataBytewise[5]), 2);

    uint8_t configByte = dataBytewise[0];
    printf("0x%02x\n", configByte);
    switch(configByte){
        case(0x00):
            printf("empty transmition\n");
            fflush(stdout);
            break;
        case((1 << POSITION_ESP_READY_CONFIGFILE)):                         
            printf("ESP ready to receive config file \n");
            fflush(stdout);
                /*send config*/
                //if(!ignoreConfigReady){
                    //spiSendConfig(kI,kP,destinationTunnelCurrentnA,remainingTunnelCurrentDifferencenA, startX, startY, direction, maxX, maxY);
                //}
                nextTransmitionConfig = true;
                //ignoreConfigReady = !ignoreConfigReady;
            break;
        case((1 << POSITION_ESP_READY_DATA)):
            printf("ESP ready to send datasets \n");
                /*receive data*/ 
            break;
        case((1 << POSITION_ESP_SEND_DATA)):{
            printf("ESP sending data to pi \n");
            fflush(stdout);
                /*save to csv*/
                std::unique_ptr<dataElement> receivedDataset = std::make_unique<dataElement>(dataElement(this->x, this->y, this->z));
                receivedDataset->exportToCSV();
                
                //receive another dataset
                /* uint8_t transmitBuffer[10];
                std::fill_n(transmitBuffer, 10, 0xFF);
                uint8_t receiveBuffer[10] = {};
                spiReceiveCommand(10,transmitBuffer, receiveBuffer); */

            break;
        }    
        case((1 << POSITION_ESP_SEND_DATA) | (1 << POSITION_ESP_ENDTAG)):{
            printf("ESP sending data to pi, last dataset \n");
                /*save to csv*/
                std::unique_ptr<dataElement> receivedDatasetEnd = std::make_unique<dataElement>(dataElement(this->x, this->y, this->z));
                receivedDatasetEnd->exportToCSV();
            break;
        }
        default:
            printf("unknown protocol config byte: 0x%02x\n", configByte);
            fflush(stdout);
            lastTransmitionBad = true;
            break;
    }

}

uint8_t protocolElement::getDataBytewise(int byteNumber){
    return this->dataBytewise[byteNumber];
}

