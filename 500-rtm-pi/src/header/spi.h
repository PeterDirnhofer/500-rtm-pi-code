#ifndef SPI
#define SPI

#include <stdint.h>

int initSPI();
void spiSendConfig(double kI, double kP, double destinationTunnelCurrentnA, double remainingTunnelCurrentDifferencenA, uint16_t startX, uint16_t startY, bool direction, uint16_t maxX, uint16_t maxY);
void spiReceiveCommand(uint16_t sizeBytes, uint8_t* transmitBuffer, uint8_t* receiveBuffer);

#endif