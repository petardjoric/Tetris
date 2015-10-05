#include "MatrixFigure.h"

MatrixFigure::MatrixFigure(TetrisMatrix& matrix, TetrisVisual& tetris, float color[3])
    : unitsVisual{UnitVisual(color), UnitVisual(color), UnitVisual(color), UnitVisual(color)},
        unitsMatrix{MatrixUnit(matrix, unitsVisual[0]), MatrixUnit(matrix, unitsVisual[1]), MatrixUnit(matrix, unitsVisual[2]), MatrixUnit(matrix, unitsVisual[3])}
{
    _matrix = &matrix;
    _tetris = &tetris;
}

bool MatrixFigure::move_down()
{
   for(auto &unit : unitsMatrix)
        unit.clearMatrix();

    bool canMove = true;
    for(int i=0; i<4; i++)
        canMove &= unitsMatrix[i].can_move_down();

    if( canMove )
        for(auto &unit : unitsMatrix)
            unit.move_down();

    for(auto &unit : unitsMatrix)
        unit.imprintInMatrix();

    _matrix->printMatrix();

    return canMove;
}

void MatrixFigure::move_right()
{
    for(auto &unit : unitsMatrix)
        unit.clearMatrix();

    bool canMove = true;
    for(auto &unit : unitsMatrix)
        canMove &= unit.can_move_right();

    if( canMove )
        for(auto &unit : unitsMatrix)
            unit.move_right();

    for(auto &unit : unitsMatrix)
        unit.imprintInMatrix();

    _matrix->printMatrix();
}

void MatrixFigure::move_left()
{
    for(auto &unit : unitsMatrix)
        unit.clearMatrix();

    bool canMove = true;
    for(int i=0; i<4; i++)
        canMove &= unitsMatrix[i].can_move_left();

    if( canMove )
        for(auto &unit : unitsMatrix)
            unit.move_left();

    for(auto &unit : unitsMatrix)
        unit.imprintInMatrix();

    _matrix->printMatrix();
}
/*
bool MatrixFigure::move(DIRECTION dir)
{
    bool canMove;

    switch(dir)
    {
        case UP     : canMove = rotate_figure(); break;
        case DOWN   : canMove = move_down    (); break;
        case LEFT   : canMove = move_left    (); break;
        case RIGHT  : canMove = move_right   (); break;
    }

    if( !canMove )
    {
        if ( dir == DOWN )
        {
            for(int i=0; i<4; i++)
                unitsMatrix[i].imprintInMatrix();

            _matrix->printMatrix();
        }
        return false;
    }

    for(int i=0; i<4; i++)
        unitsMatrix[i].imprintInMatrix();

    _matrix->printMatrix();

    return true;
}
*/
MatrixFigure::~MatrixFigure()
{
    for(auto &unit : unitsVisual)
        _tetris->addUnit(unit);
}
