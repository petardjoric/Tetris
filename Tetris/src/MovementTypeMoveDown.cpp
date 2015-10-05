#include "MovementTypeMoveDown.h"

MovementTypeMoveDown::MovementTypeMoveDown(MatrixUnit units[4])
    : MovementType(units)
{

}

bool MovementTypeMoveDown::can_move()
{
    bool canMove = true;
    for(auto &unit : _units)
        canMove &= unit->can_move_down();

    return canMove;
}

void MovementTypeMoveDown::move()
{
    for(auto &unit : _units)
        unit->move_down();
}

MovementTypeMoveDown::~MovementTypeMoveDown()
{
    //dtor
}
