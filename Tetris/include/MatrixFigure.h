#ifndef MATRIXFIGURE_H
#define MATRIXFIGURE_H

#include "MatrixUnit.h"
#include "TetrisMatrix.h"
#include "UnitVisual.h"
#include "FigureColors.h"
#include "TetrisVisual.h"
#include "MovementType.h"
#include "MovementTypeMoveDown.h"
#include "MovementTypeMoveLeft.h"
#include "MatrixFigureMoveFacade.h"
#include "MovementTypeMoveRight.h"

class MatrixFigure //: public Moving
{
    public:
        MatrixFigure() {};
        explicit MatrixFigure(TetrisMatrix& matrix, TetrisVisual& tetris, float color[3]);
        virtual ~MatrixFigure();

        enum DIRECTION { UP, DOWN, RIGHT, LEFT };

        // za brisanje
        void draw() {
            for(auto &unit : unitsVisual)
                unit.drawUnit();
        }

        bool move_down ();
        void move_left ();
        void move_right();

        virtual bool rotate_figure() = 0;

        //bool move(DIRECTION dir);
    protected:
        TetrisMatrix* _matrix;
        TetrisVisual* _tetris;
        UnitVisual unitsVisual[4];
        MatrixUnit unitsMatrix[4];
        FigureColors colors;

        // every concrete figure has its own implementation

        virtual void init_units()    = 0;

        // inherited methods from abstract class Moving

};

#endif // MATRIXFIGURE_H
