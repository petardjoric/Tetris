#include "MatrixFigureT.h"

MatrixFigureT::MatrixFigureT(TetrisMatrix& matrix)
    : MatrixFigure(matrix)
{
    init_units();

    _matrix->printMatrix();
}

void MatrixFigureT::init_units()
{
    units[0].set(0,0);
    units[1].set(0,1);
    units[2].set(0,2);
    units[3].set(0,3);
}

void MatrixFigureT::rotate_figure()
{

}

MatrixFigureT::~MatrixFigureT()
{

}
