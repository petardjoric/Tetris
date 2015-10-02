#ifndef MATRIXFIGURET_H
#define MATRIXFIGURET_H

#include "MatrixFigure.h"

class MatrixFigureT : public MatrixFigure
{

    public:
        MatrixFigureT(TetrisMatrix& matrix);
        virtual ~MatrixFigureT();
    protected:
        // inherited from abstract class MatrixFigure
         void rotate_figure();
         void init_units();
};

#endif // MATRIXFIGURET_H
