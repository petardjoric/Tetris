#ifndef MATRIXFIGURECUBE_H
#define MATRIXFIGURECUBE_H

#include "MatrixFigure.h"

class MatrixFigureCube : public MatrixFigure
{
    public:
        MatrixFigureCube(TetrisMatrix& matrix, TetrisVisual& tetris);
        virtual ~MatrixFigureCube();
    protected:
        // inherited from abstract class MatrixFigure
         void init_units();
};

#endif // MATRIXFIGURECUBE_H
