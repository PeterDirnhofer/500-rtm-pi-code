#include <pigpio.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "globalVariables.h"
#include "spi.h"
#include "communication.h"

//installation of bcm2835 library
//http://www.airspayce.com/mikem/bcm2835/index.html
void handshakeInterrupt(int gpio, int level, uint32_t tick) {
    
    if(level == 0){ //falling edge 
        printf("handshakeInterrupt\n");
        
        if(nextTransmitionConfig){
            nextTransmitionConfig = false;
            spiSendConfig(kI,kP,destinationTunnelCurrentnA,remainingTunnelCurrentDifferencenA, startX, startY, direction, maxX, maxY);
        }else{
            uint8_t transmitBuffer[10];
            if(lastTransmitionBad){
                lastTransmitionBad = false;
                std::fill_n(transmitBuffer, 10, (1<< POSITION_PI_RCV_BAD));
            }else{
                std::fill_n(transmitBuffer, 10, 0xFF);
            }
            uint8_t receiveBuffer[10] = {};
            spiReceiveCommand(10,transmitBuffer, receiveBuffer);
        }
    }
    
}

int main (int argc, char *argv[]) {
    for (int argCounter = 1; argCounter < argc; argCounter++)
    {
        printf("Argument %d: %s\n", argCounter, argv[argCounter]);
        fflush(stdout);
    }
    if((argc -1) == 9){
        printf("Correct count of parameters\n");
        fflush(stdout);
        kI = atof(argv[1]);                                
        kP = atof(argv[2]);
        destinationTunnelCurrentnA = atof(argv[3]); 
        remainingTunnelCurrentDifferencenA = atof(argv[4]); 
        startX = (uint16_t) atoi(argv[5]);
        startY = (uint16_t) atoi(argv[6]);
        direction = (bool) atoi(argv[7]);
        maxX = (uint16_t) atoi(argv[8]);
        maxY = (uint16_t) atoi(argv[9]);
    }

    //setup
    if (gpioInitialise() < 0){
        printf("Error pigpio setup");
        fflush(stdout);
        return 1;
    }
    gpioSetMode(GPIO_HANDSHAKE, PI_INPUT); //input
    gpioSetPullUpDown(GPIO_HANDSHAKE, PI_PUD_UP); //pullup

    //interrupt
    //if ( wiringPiISR (GPIO_HANDSHAKE, INT_EDGE_RISING, &handshakeInterrupt) < 0 ){
    gpioSetAlertFunc(GPIO_HANDSHAKE, handshakeInterrupt);

    //bcm2835 init spi
    if(initSPI()){
        printf ("Unable to setup SPI\n");
        fflush(stdout);
    }else{
        printf ("SPI setup succesfull\n");
        fflush(stdout);
    }
    volatile int temp = 0;
    
    while(true){
        temp = 1;
    }
    return 0;    
}
