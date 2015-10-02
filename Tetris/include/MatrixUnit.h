#ifndef MATRIXUNIT_H
#define MATRIXUNIT_H

#include <iostream>

#include "Moving.h"
#include "TetrisMatrix.h"

class MatrixUnit : public Moving
{
    public:
        MatrixUnit();
        virtual ~MatrixUnit();

        void set(int x, int y);
        void setMatrix(TetrisMatrix& matrix);
    private:
        TetrisMatrix* _matrix;
        short _x, _y;

        // inherited from abstract class Moving
        void move_down () { _x += 1;  }
        void move_left () { _y -= 1;  }
        void move_right() { _y += 1;  }

        void imprintInMatrix();
        void clearMatrix();

    friend class MatrixFigure;
};

#endif // MATRIXUNIT_H
