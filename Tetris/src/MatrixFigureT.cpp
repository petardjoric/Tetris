#include "MatrixFigureT.h"

MatrixFigureT::MatrixFigureT(TetrisMatrix& matrix, TetrisVisual& tetris)
    : MatrixFigure(matrix, tetris, colors.FigureTColor)
{
    init_units();

    _matrix->printMatrix();
}

void MatrixFigureT::init_units()
{
    unitsMatrix[0].set(0,0);
    unitsMatrix[1].set(0,1);
    unitsMatrix[2].set(0,2);
    unitsMatrix[3].set(0,3);
}

bool MatrixFigureT::rotate_figure()
{
    for(int i=0; i<4; i++)
        unitsMatrix[i].clearMatrix();

    // can move

    // move

    for(int i=0; i<4; i++)
        unitsMatrix[i].imprintInMatrix();

    _matrix->printMatrix();
}

MatrixFigureT::~MatrixFigureT()
{

}
