#include "MatrixFigureCube.h"

MatrixFigureCube::MatrixFigureCube(TetrisMatrix& matrix, TetrisVisual& tetris)
    : MatrixFigure(matrix, tetris, colors.FigureCubeColor)
{
    init_units();

    _matrix->printMatrix();
}

void MatrixFigureCube::init_units()
{
    unitsMatrix[0].set(0,0);
    unitsMatrix[1].set(0,1);
    unitsMatrix[2].set(1,0);
    unitsMatrix[3].set(1,1);

    initMatrixPosition[0][0] = 0; initMatrixPosition[0][1] = 0;
    initMatrixPosition[1][0] = 0; initMatrixPosition[1][1] = 0;
    initMatrixPosition[2][0] = 0; initMatrixPosition[2][1] = 0;
    initMatrixPosition[3][0] = 0; initMatrixPosition[3][1] = 0;
}

MatrixFigureCube::~MatrixFigureCube()
{

}
