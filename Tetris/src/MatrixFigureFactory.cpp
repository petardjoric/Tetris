#include "MatrixFigureFactory.h"

#include <iostream>

MatrixFigureFactory::MatrixFigureFactory(TetrisMatrix& matrix, TetrisVisual& tetris, MatrixFigure*& figure)
{
    _matrix = &matrix;
    _tetris = &tetris;
    _figure = &figure;

    srand(time(NULL));

    std::cout << "proso konstrukotr factory" << std::endl;
}

void MatrixFigureFactory::generate()
{
    int key = rand() % 2;

    std::cout << "key : " << key << std::endl;

    switch(key)
    {
    case FIGURE_T :     *_figure = new MatrixFigureT(*_matrix, *_tetris);    break;
    case FIGURE_CUBE :  *_figure = new MatrixFigureCube(*_matrix, *_tetris); break;
    default :   std::cout << "nista" << std::endl;
    }

    std::cout << "proso generate " << std::endl;
}

void MatrixFigureFactory::delete_figure()
{
    delete *_figure;
}

MatrixFigureFactory::~MatrixFigureFactory()
{
    //dtor
}
