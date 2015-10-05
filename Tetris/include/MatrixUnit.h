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
        MatrixUnit() {} ;
        MatrixUnit(TetrisMatrix& matrix, UnitVisual & unitVisual);
        virtual ~MatrixUnit();

        void set(int x, int y);
    private:
        TetrisMatrix* _matrix;
        UnitVisual* visualRepresentation;
        short _x, _y;

        // inherited from abstract class Moving
        bool move_down ();
        bool move_left ();
        bool move_right();

        bool can_move_down();
        bool can_move_left();
        bool can_move_right();

        void imprintInMatrix();
        void clearMatrix();

    friend class MatrixFigure;
    friend class MatrixFigureMoveFacade;
    friend class MovementTypeMoveDown;
    friend class MovementTypeMoveLeft;
    friend class MovementTypeMoveRight;
};

#endif // MATRIXUNIT_H
