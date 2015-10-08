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

    initMatrixPosition[0][0] = 1; initMatrixPosition[0][1] = 2;
    initMatrixPosition[1][0] = 0; initMatrixPosition[1][1] =  1;
    initMatrixPosition[2][0] = -1; initMatrixPosition[2][1] =  0;
    initMatrixPosition[3][0] = -2; initMatrixPosition[3][1] =  -1;
}


MatrixFigureT::~MatrixFigureT()
{

}
