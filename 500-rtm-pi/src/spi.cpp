#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <memory>

extern "C" {
    #include <bcm2835.h> 
} 
#include "globalVariables.h"
#include "communication.h"
#include "spi.h"

int initSPI(){
    //https://www.iot-programmer.com/index.php/books/22-raspberry-pi-and-the-iot-in-c/chapters-raspberry-pi-and-the-iot-in-c/32-getting-started-with-the-spi-bus?showall=1
    if (!bcm2835_init()) {
        return 1;
    }
    if (!bcm2835_spi_begin()) {
        return 1;
    }

    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_128); //6.25MHz
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0); //wiringpi Pin 10 physical 24
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);

    return 0;
}

void spiSendConfig(double kI, double kP, double destinationTunnelCurrentnA, double remainingTunnelCurrentDifferencenA, uint16_t startX, uint16_t startY, bool direction, uint16_t maxX, uint16_t maxY){
    
    double dataArray[] = {kI, kP, destinationTunnelCurrentnA, remainingTunnelCurrentDifferencenA, (double) startX, (double) startY, (double) direction, (double) maxX, (double) maxY};
    
    //for (int configSend = 0; configSend < sizeof(dataArray)/sizeof(dataArray[0]); configSend++){
    printf("configSend: %d\n", configSend);
    printf("%f\n", dataArray[configSend]);
    
        struct timespec time;
        time.tv_sec = 0;
        time.tv_nsec = 50000;
        nanosleep(&time,&time);

        char buf[10] = {0};
        buf[0] = (char)(1 << POSITION_PI_SEND_CONFIG);
        buf[1] = (char)(configSend);
        memcpy(&buf[2], &dataArray[configSend], 8);

        for(int i = 0; i <= 9; i++){
            printf("%x", buf[i]);
        }
        printf("\n");
        
        bcm2835_spi_writenb(buf, 10);

        if(configSend <sizeof(dataArray)/sizeof(dataArray[0]) -1){
            configSend++;
        }else{
            configSend = 0;
        }
        
    
}

void spiReceiveCommand(uint16_t sizeBytes, uint8_t* transmitBuffer, uint8_t* receiveBuffer){
    //expecting receiveBuffer with length of sizeBytes
        struct timespec time;
        time.tv_sec = 0;
        time.tv_nsec = 5000;
        nanosleep(&time,&time);
    bcm2835_spi_transfernb((char*) transmitBuffer, (char*) receiveBuffer, sizeBytes); //receive over spi, sending trash data 0xFF or bad transmition 0x40
    std::unique_ptr<protocolElement> receivedCommand = std::make_unique<protocolElement>((uint8_t*) receiveBuffer); //create protocolElement, constructor will proceed
} 