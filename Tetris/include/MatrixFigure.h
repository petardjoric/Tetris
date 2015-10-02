#ifndef MATRIXFIGURE_H
#define MATRIXFIGURE_H

#include "MatrixUnit.h"
#include "Moving.h"
#include "TetrisMatrix.h"

class MatrixFigure : public Moving
{
    public:
        explicit MatrixFigure(TetrisMatrix& matrix);
        virtual ~MatrixFigure();

        enum DIRECTION { UP, DOWN, RIGHT, LEFT };

        void move(DIRECTION dir);
    protected:
        TetrisMatrix* _matrix;
        MatrixUnit units[4];

        // every concrete figure has its own implementation
        virtual void rotate_figure() = 0;
        virtual void init_units()    = 0;

        // inherited methods from abstract class Moving
        void move_down ();
        void move_left ();
        void move_right();
};

#endif // MATRIXFIGURE_H
