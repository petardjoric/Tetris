#include "MatrixUnit.h"

MatrixUnit::MatrixUnit(TetrisMatrix& matrix, UnitVisual & unitVisual)
{
    visualRepresentation = &unitVisual;
    _matrix = &matrix;
}

void MatrixUnit::imprintInMatrix()
{
    if( _matrix == NULL )
        std::cout << "unit is not connected to matrix" << std::endl;
    else
        _matrix->matrix[_x][_y] = true;

}

void MatrixUnit::clearMatrix()
{
    if( _matrix == NULL )
        std::cout << "unit is not connected to matrix" << std::endl; // ovu proveru refaktorisi, zajedno sa istom u imprintInMatrix
    else
        _matrix->matrix[_x][_y] = false;
}

void MatrixUnit::set(int x, int y)
{
    _x = (short)x;
    _y = (short)y;

    TranslateMatrixToVisual translate(*visualRepresentation, _x, _y);
}

MatrixUnit::~MatrixUnit()
{
    //dtor
}
