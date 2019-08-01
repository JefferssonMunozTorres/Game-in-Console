#include <iostream>
//#include <stdlib.h>
#include <fstream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"

using namespace std;

/*void drawMap(int heroPosX, int heroPosY, char gameMap[5][5])
{
    //system("cls");
    for(int i = 0 ; i<5; i++)
    {
        for(int j=0; j<5;j++)
        {
            if(i!=heroPosY)
            {
                cout<<gameMap[i][j];
            }
            else
            {
                if(j!=heroPosX)
                {
                    cout<<gameMap[i][j];
                }
                else
                {
                    cout<<'H';
                }
            }
        }

        cout<<endl;
    }
}
*/

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
//**************************************
    bool gameOver=false;
    Player hero;
    GameMap map;

    map.drawIntro();
    cout<<"Inicia el juego"<<endl;
    map.draw(hero.getX(),hero.getY());

    while(gameOver==false)
    {
       hero.callInput();
       if(map.validationPlayerCell(hero.getX(),hero.getY()))
       {
         hero.resetPositionPlayer();
         map.draw(hero.getX(),hero.getY());
       }
       else
       {
         map.draw(hero.getX(),hero.getY());
       }
    }


//*****************************************

    /*int  heroPosX=1;
    int  heroPosY=0;
    bool isGameOver=false;
    char input=' ';
    char gameMap[5][5]={{'P','1','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','1','1','1','S'}};

    while(isGameOver == false)
    {
        drawMap(heroPosX,heroPosY,gameMap);

        cin>>input;

        switch(input){
        case'a': heroPosX--; break;
        case'd': heroPosX++; break;
        case'w': heroPosY--; break;
        case's': heroPosY++; break;
        default: isGameOver=true; break;
        }
    }

    cout<<"*******Termino el juego*******"<<endl;
    */

    return 0;
}

