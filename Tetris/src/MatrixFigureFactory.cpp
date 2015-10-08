#include "MatrixFigureFactory.h"

#include <iostream>

MatrixFigureFactory::MatrixFigureFactory(TetrisMatrix& matrix, TetrisVisual& tetris, MatrixFigure*& figure)
{
    _matrix = &matrix;
    _tetris = &tetris;
    _figure = &figure;

    srand(time(NULL));
}

void MatrixFigureFactory::generate()
{
    int key = rand() % 2;
    //int key = 0;
    switch(key)
    {
    case TetrisMatrix::FIGURE_T :     *_figure = new MatrixFigureT(*_matrix, *_tetris);    break;
    case TetrisMatrix::FIGURE_CUBE :  *_figure = new MatrixFigureCube(*_matrix, *_tetris); break;
    }
}

void MatrixFigureFactory::delete_figure()
{
    delete *_figure;
}

MatrixFigureFactory::~MatrixFigureFactory()
{
    //dtor
}
