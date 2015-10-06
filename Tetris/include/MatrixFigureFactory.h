#ifndef MATRIXFIGUREFACTORY_H
#define MATRIXFIGUREFACTORY_H

#include <ctime>
#include <cstdlib>

#include "MatrixFigure.h"
#include "TetrisMatrix.h"
#include "TetrisVisual.h"
#include "MatrixFigureT.h"
#include "MatrixFigureCube.h"

class MatrixFigureFactory
{
    public:
        MatrixFigureFactory(TetrisMatrix& matrix, TetrisVisual& tetris, MatrixFigure*& figure);
        virtual ~MatrixFigureFactory();

        enum figure_enum { FIGURE_T, FIGURE_CUBE };

        void generate();
        void delete_figure();
    private:
        MatrixFigure** _figure;
        TetrisMatrix* _matrix;
        TetrisVisual* _tetris;
};

#endif // MATRIXFIGUREFACTORY_H
