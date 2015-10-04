#include "TranslateMatrixToVisual.h"

TranslateMatrixToVisual::TranslateMatrixToVisual(UnitVisual & unit, int i, int j)
{
    _unit = &unit;

    float y = (  MATRIX_SIZE/2 - i ) * .1;
    float x = ( -MATRIX_SIZE/2 + j - 2) * .1;

    _unit->setCoordinates(x,y);
}

TranslateMatrixToVisual::~TranslateMatrixToVisual()
{
    //dtor
}
