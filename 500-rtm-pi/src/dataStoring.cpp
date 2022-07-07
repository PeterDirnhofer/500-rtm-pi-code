#include <fstream>
#include <iostream>
#include "dataStoring.h"
#include "communication.h"
#include "globalVariables.h"


//constructor of dataElement for queue
dataElement::dataElement(uint16_t x, uint16_t y, uint16_t z)
: x(x), y(y), z(z)
{}

void dataElement::exportToCSV(){
    std::ofstream file;

    file.open(filenameExport, std::ios_base::out | std::ios_base::app); //append
    //format X;Y;Z
    printf("%d %d %d \n",this->getDataX(), this->getDataY(), this->getDataZ() );
    fflush(stdout);
    file << this->getDataX() << ";" << this->getDataY() << ";" << this->getDataZ() << "\n" ;
    file.close();
}
