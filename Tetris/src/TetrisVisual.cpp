#include "TetrisVisual.h"

TetrisVisual::TetrisVisual()
{
    //ctor
}

void TetrisVisual::addUnit(UnitVisual& unit)
{
    units.push_back(unit);
}

void TetrisVisual::draw()
{
    for( auto &unit : units )
        unit.drawUnit();
}

TetrisVisual::~TetrisVisual()
{
    //dtor
}
