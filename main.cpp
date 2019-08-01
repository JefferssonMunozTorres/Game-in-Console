#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"

using namespace std;

string startGame()
{
    ifstream MyFileRead("GameData.txt");
    string contentLine;
    int numberLine = 0;
    string gameStatus="0";

    if(MyFileRead.is_open())
    {
        while (getline(MyFileRead,contentLine))
        {
            numberLine++;
            if (numberLine==2)
            {
                gameStatus= contentLine;
                break;
            }
        }
    }
    else
    {
        cout<<"No se encontro el archivo GameData.txt";
    }

    MyFileRead.close();
    return gameStatus;
}

void saveGame(string nameHero)
{
    ofstream MyFileWrite("GameData.txt");

        MyFileWrite<<"gameStart:"<<endl;
        MyFileWrite<<"1"<<endl;
        MyFileWrite<<"nameHero:"<<endl;
        MyFileWrite<<nameHero<<endl;

    MyFileWrite.close();
}

int main()
{
    string nameHero;
    string start=startGame();

    if (start=="0")
    {
        cout<<"Cual sera el nombre de tu heroe?";
        cin>>nameHero;
        saveGame(nameHero);
    }

    Player hero;
    GameMap map;

    map.drawIntro();
    system("cls");
    cout<<"Inicia el juego"<<endl;
    cout<<map.getGameOver();
    map.draw(hero.getX(),hero.getY());
    cout<<map.getGameOver();

    while(map.getGameOver()==0)
    {

       cout<<"Mueve a tu heroe hasta el tesoro con: 'w' 's' 'a' 'd' :"<<endl;
       hero.callInput();
       system("cls");
       if(map.validationPlayerCell(hero.getX(),hero.getY()))
       {
         hero.resetPositionPlayer();
         map.draw(hero.getX(),hero.getY());
       }
       else
       {
           if(map.getGameOver())
           {
              map.drawVictory();
           }
           else
           {
              map.draw(hero.getX(),hero.getY());
           }

       }
    }

    return 0;
}

