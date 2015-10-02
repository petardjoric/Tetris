#include "MatrixFigure.h"

MatrixFigure::MatrixFigure(TetrisMatrix& matrix)
{
    for(int i=0; i<4; i++)
        units[i].setMatrix(matrix);

    _matrix = &matrix;
}

void MatrixFigure::move_down()
{
    for(int i=0; i<4; i++)
        units[i].move_down();
}

void MatrixFigure::move_right()
{
    for(int i=0; i<4; i++)
        units[i].move_right();
}

void MatrixFigure::move_left()
{
    for(int i=0; i<4; i++)
        units[i].move_left();
}

void MatrixFigure::move(DIRECTION dir)
{
    for(int i=0; i<4; i++)
        units[i].clearMatrix();

    switch(dir)
    {
        case UP     : rotate_figure(); break;
        case DOWN   : move_down    (); break;
        case LEFT   : move_left    (); break;
        case RIGHT  : move_right   (); break;
    }

    for(int i=0; i<4; i++)
        units[i].imprintInMatrix();

    _matrix->printMatrix();
}

MatrixFigure::~MatrixFigure()
{

}
