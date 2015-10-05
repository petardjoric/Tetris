#ifndef MOVING_H
#define MOVING_H


class Moving
{
    public:
        Moving();
        virtual ~Moving();
    protected:
        virtual bool move_right()   = 0;
        virtual bool move_left ()   = 0;
        virtual bool move_down ()   = 0;
};

#endif // MOVING_H
