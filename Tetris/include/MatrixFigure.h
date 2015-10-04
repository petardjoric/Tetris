#ifndef MATRIXFIGURE_H
#define MATRIXFIGURE_H

#include "MatrixUnit.h"
#include "Moving.h"
#include "TetrisMatrix.h"
#include "UnitVisual.h"
#include "FigureColors.h"

class MatrixFigure : public Moving
{
    public:
        explicit MatrixFigure(TetrisMatrix& matrix, float color[3]);
        virtual ~MatrixFigure();

        enum DIRECTION { UP, DOWN, RIGHT, LEFT };

        // za brisanje
        void draw() {
            for(auto &unit : unitsVisual)
                unit.drawUnit();
        }

        void move(DIRECTION dir);
    protected:
        TetrisMatrix* _matrix;
        UnitVisual unitsVisual[4];
        MatrixUnit unitsMatrix[4];
        FigureColors colors;

        // every concrete figure has its own implementation
        virtual void rotate_figure() = 0;
        virtual void init_units()    = 0;

        // inherited methods from abstract class Moving
        void move_down ();
        void move_left ();
        void move_right();
};

#endif // MATRIXFIGURE_H
