#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();

        void callInput();

        void resetPositionPlayer();

        int getX();

        int getY();

        int getLastX();

        int getLastY();

    protected:
        int x=1;
        int y=1;
        int lastX=1;
        int lastY=1;
    private:
};

#endif // PLAYER_H
