#include "MatrixFigureFactory.h"

MatrixFigureFactory::MatrixFigureFactory(TetrisMatrix& matrix, TetrisVisual& tetris, MatrixFigure* figure)
{
    _figure = figure;
    _matrix = &matrix;
    _tetris = &tetris;

    srand(time(NULL));
}

void MatrixFigureFactory::generate()
{
    int key = rand() % 2;

    switch(key)
    {
    case FIGURE_T : _figure = new MatrixFigureT(_matrix, _tetris);
    case FIGURE_CUBE : figure = new MatrixFigureCube(_matrix, _tetris);
    }
}

void MatrixFigureFactory::delete_figure()
{
    delete _figure;
}

MatrixFigureFactory::~MatrixFigureFactory()
{
    //dtor
}
