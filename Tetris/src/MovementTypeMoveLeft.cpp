#include "MovementTypeMoveLeft.h"

#include <iostream>

MovementTypeMoveLeft::MovementTypeMoveLeft(MatrixUnit units[4])
    : MovementType(units)
{

}

bool MovementTypeMoveLeft::can_move()
{
    bool canMove = true;
    for(auto &unit : _units)
        canMove &= unit->can_move_left();

    return canMove;
}

void MovementTypeMoveLeft::move()
{
    for(auto &unit : _units)
        unit->move_left();
}

MovementTypeMoveLeft::~MovementTypeMoveLeft()
{

}
