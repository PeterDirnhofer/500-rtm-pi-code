#include <stdlib.h>
#include "globalVariables.h"


double kI = 0.0;                                
double kP = 0.0;
double destinationTunnelCurrentnA = 0.0;
double remainingTunnelCurrentDifferencenA = 0.0;
uint16_t startX = 0;
uint16_t startY = 0;
bool direction = false;
uint16_t maxX = 0;
uint16_t maxY = 0;
std::string filenameExport = "newScan.csv";  

uint16_t configSend = 0; 

bool nextTransmitionConfig = false;
bool lastTransmitionBad = false;

bool ignoreConfigReady = false;