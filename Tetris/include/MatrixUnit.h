#ifndef MATRIXUNIT_H
#define MATRIXUNIT_H

#include <iostream>

#include "Moving.h"
#include "TetrisMatrix.h"
#include "UnitVisual.h"
#include "TranslateMatrixToVisual.h"

class MatrixUnit : public Moving
{
    public:
        MatrixUnit(TetrisMatrix& matrix, UnitVisual & unitVisual);
        virtual ~MatrixUnit();

        void set(int x, int y);
    private:
        TetrisMatrix* _matrix;
        UnitVisual* visualRepresentation;
        short _x, _y;

        // inherited from abstract class Moving
        void move_down () { _x += 1;  TranslateMatrixToVisual translate(*visualRepresentation, _x, _y); }
        void move_left () { _y -= 1;  TranslateMatrixToVisual translate(*visualRepresentation, _x, _y); }
        void move_right() { _y += 1;  TranslateMatrixToVisual translate(*visualRepresentation, _x, _y); }

        void imprintInMatrix();
        void clearMatrix();

    friend class MatrixFigure;
};

#endif // MATRIXUNIT_H
