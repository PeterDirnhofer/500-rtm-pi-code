#ifndef GLOBALVARIABLES
#define GLOBALVARIABLES

#include <stdint.h>
#include <string>

#define GPIO_HANDSHAKE 17

extern double kI;                                
extern double kP;
extern double destinationTunnelCurrentnA;
extern double remainingTunnelCurrentDifferencenA;
extern uint16_t startX;
extern uint16_t startY;
extern bool direction;
extern uint16_t maxX;
extern uint16_t maxY;

extern std::string filenameExport;


extern uint16_t configSend;

extern bool nextTransmitionConfig;
extern bool lastTransmitionBad;

extern bool ignoreConfigReady;
#endif