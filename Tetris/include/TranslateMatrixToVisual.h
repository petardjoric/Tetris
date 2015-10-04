#ifndef TRANSLATEMATRIXTOVISUAL_H
#define TRANSLATEMATRIXTOVISUAL_H

#include "TetrisMatrix.h"
#include "UnitVisual.h"

class TranslateMatrixToVisual
{
    public:
        TranslateMatrixToVisual(UnitVisual& unit, int i, int j);
        virtual ~TranslateMatrixToVisual();
    private:
        UnitVisual* _unit;
};

#endif // TRANSLATEMATRIXTOVISUAL_H
