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
    {
        _matrix->matrix[_x][_y] = false;
    }
}

void MatrixUnit::set(int x, int y)
{
    _x = (short)x;
    _y = (short)y;

    TranslateMatrixToVisual translate(*visualRepresentation, _x, _y);
}

bool MatrixUnit::can_move_manual(int x, int y)
{
    bool canMove = true;

    canMove &= x >= 0 && x < MATRIX_SIZE;
    canMove &= y >= 0 && y < MATRIX_SIZE;
    canMove &= !_matrix->matrix[_x+x][_y+y];

    return canMove;
}

void MatrixUnit::move_manual(int x, int y)
{
    _x += x;
    _y += y;
    TranslateMatrixToVisual translate(*visualRepresentation, _x, _y);
}

bool MatrixUnit::move_down ()
{
    _x += 1;
    TranslateMatrixToVisual translate(*visualRepresentation, _x, _y);
}

bool MatrixUnit::move_left ()
{
    _y -= 1;
    TranslateMatrixToVisual translate(*visualRepresentation, _x, _y);
}

bool MatrixUnit::move_right()
{
    _y += 1;
    TranslateMatrixToVisual translate(*visualRepresentation, _x, _y);
}

bool  MatrixUnit::can_move_down()
{
    if( !_matrix->matrix[_x+1][_y] && _x+1 < MATRIX_SIZE )
        return true;
    return false;
}

bool  MatrixUnit::can_move_left()
{
    if( !_matrix->matrix[_x][_y-1] && _y-1 >= 0 )
        return true;
    return false;
}

bool  MatrixUnit::can_move_right()
{
    if( !_matrix->matrix[_x][_y+1] && _y+1 < MATRIX_SIZE)
        return true;
    return false;
}

MatrixUnit::~MatrixUnit()
{
    //dtor
}
