#include "MatrixFigureMoveFacade.h"

#include <iostream>

MatrixFigureMoveFacade::MatrixFigureMoveFacade(MatrixUnit units[4], MovementType & moveType)
{
    for(int i=0; i<4; i++)
        _units.push_back(&units[i]);
    movementType = &moveType;

    for(auto *unit : _units)
        unit->clearMatrix();

    bool canMove = moveType.can_move();

    if( canMove )
        moveType.move();

    for(auto *unit : _units)
        unit->imprintInMatrix();

    _canMove = canMove;
}

MatrixFigureMoveFacade::~MatrixFigureMoveFacade()
{
    //dtor
}
