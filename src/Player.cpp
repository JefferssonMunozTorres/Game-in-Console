#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{

}

void Player::callInput()
{
    char userInput =' ';

    cin>> userInput;

    lastY=y;
    lastX=x;

    switch(userInput){
        case'a':  y--; break;
        case'd':  y++; break;
        case'w':  x--; break;
        case's':  x++; break;
        //default: isGameOver=true; break;
        }
}

void Player::resetPositionPlayer()
{
    x=lastX;
    y=lastY;
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}

int Player::getLastX()
{
    return lastX;
}

int Player::getLastY()
{
    return lastY;
}

