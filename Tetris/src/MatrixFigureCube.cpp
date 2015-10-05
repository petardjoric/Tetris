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
}

bool MatrixFigureCube::rotate_figure()
{

}

MatrixFigureCube::~MatrixFigureCube()
{

}
