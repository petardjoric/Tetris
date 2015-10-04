#ifndef TETRISVISUAL_H
#define TETRISVISUAL_H

#include <vector>

#include "UnitVisual.h"

class TetrisVisual
{
    public:
        TetrisVisual();
        virtual ~TetrisVisual();

        void addUnit(UnitVisual& unit);
        void draw();
    private:
        std::vector<UnitVisual> units;
};

#endif // TETRISVISUAL_H
