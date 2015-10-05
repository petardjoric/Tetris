#include "MovementTypeMoveRight.h"

#include <iostream>

MovementTypeMoveRight::MovementTypeMoveRight(MatrixUnit units[4])
    : MovementType(units)
{

}

bool MovementTypeMoveRight::can_move()
{
    bool canMove = true;
    for(auto &unit : _units)
        canMove &= unit->can_move_right();

    return canMove;
}

void MovementTypeMoveRight::move()
{
    for(auto &unit : _units)
        unit->move_right();
}

MovementTypeMoveRight::~MovementTypeMoveRight()
{

}
