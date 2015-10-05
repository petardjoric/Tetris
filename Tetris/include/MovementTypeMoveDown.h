#ifndef MOVEMENTTYPEMOVEDOWN_H
#define MOVEMENTTYPEMOVEDOWN_H

#include <vector>

#include "MovementType.h"

class MovementTypeMoveDown : public MovementType
{
    public:
        MovementTypeMoveDown(MatrixUnit units[4]);
        virtual ~MovementTypeMoveDown();

        // inherited from interface MovementType
        bool can_move();
        void move();
};

#endif // MOVEMENTTYPEMOVEDOWN_H
