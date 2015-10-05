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
    MovementType* mTypeDown = new MovementTypeMoveDown(unitsMatrix);
    MatrixFigureMoveFacade moveFacade(unitsMatrix, *mTypeDown);

    delete mTypeDown;

    _matrix->printMatrix();

    return moveFacade.canMove();
}

void MatrixFigure::move_right()
{
    MovementType* mTypeRight = new MovementTypeMoveRight(unitsMatrix);
    MatrixFigureMoveFacade moveFacade(unitsMatrix, *mTypeRight);

    delete mTypeRight;

    _matrix->printMatrix();
}

void MatrixFigure::move_left()
{
    MovementType* mTypeLeft = new MovementTypeMoveLeft(unitsMatrix);
    MatrixFigureMoveFacade moveFacade(unitsMatrix, *mTypeLeft);

    delete mTypeLeft;

    _matrix->printMatrix();
}

MatrixFigure::~MatrixFigure()
{
    for(auto &unit : unitsVisual)
        _tetris->addUnit(unit);
}
