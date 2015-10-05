#include "MovementType.h"

#include <iostream>

MovementType::MovementType(MatrixUnit units[4])
{
    for(int i=0; i<4; i++)
        _units.push_back(&units[i]);
}

MovementType::~MovementType()
{
    //dtor
}
