#ifndef MOVEMENTTYPEMOVELEFT_H
#define MOVEMENTTYPEMOVELEFT_H

#include <vector>

#include "MovementType.h"

class MovementTypeMoveLeft : public MovementType
{
    public:
        MovementTypeMoveLeft(MatrixUnit units[4]);
        virtual ~MovementTypeMoveLeft();

        // inherited from interface MovementType
        bool can_move();
        void move();
};

#endif // MOVEMENTTYPEMOVELEFT_H
