#ifndef MOVING_H
#define MOVING_H


class Moving
{
    public:
        Moving();
        virtual ~Moving();
    protected:
        virtual void move_right()   = 0;
        virtual void move_left ()   = 0;
        virtual void move_down ()   = 0;
};

#endif // MOVING_H
