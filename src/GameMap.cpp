#include "GameMap.h"
#include <iostream>
#include <fstream>

using namespace std;

GameMap::GameMap()
{
    loadMapFromFile();
    setGameOver(false);
}

void GameMap::draw(int PlayerX, int PlayerY)
{
    for(int i=0;i<15;i++)
    {
        for(int j=0; j<10; j++)
        {
            if(PlayerX!=i){
            cout<<cells[i][j].id;
            }
            else
            {
                if(PlayerY!=j)
                {
                 cout<<cells[i][j].id;
                }
                else
                {
                 cout<<"H";
                }
            }
        }
        cout<<endl;
    }
}

bool GameMap::validationPlayerCell(int PlayerX, int PlayerY)
{
    if(cells[PlayerX][PlayerY].id=='1')
    {
        return true;
    }
    else
    {
        if(cells[PlayerX][PlayerY].id=='$')
        {
            setGameOver(true);
        }
        return false;
    }
}

void GameMap::loadMapFromFile()
{
    string contentLine;
    int row=0;
    ifstream MyMapFile("Map.txt");

    if(MyMapFile.is_open())
    {
        while(getline(MyMapFile,contentLine))
        {
            //cout<<"***"<<contentLine<<"***"; //Ver el contenido de la linea extraida
         for(int i=0;i<contentLine.length();i++)
         {
             if(contentLine[i]=='0')
             {
               cells[row][i].id=0;
             }
             else
             {
               cells[row][i].id=contentLine[i];
             }
         }
         row++;
        }
    }
    else
    {
        cout<<"FATAL ERROR: MAP FILE COULD NOT BE LOADED!"<<endl;
    }

    MyMapFile.close();
}

void GameMap::drawIntro()
{
    string contentLine;
    ifstream MyIntroFile("Intro.txt");

    if(MyIntroFile.is_open())
    {
        while(getline(MyIntroFile,contentLine))
        {
          cout<<contentLine<<endl;
        }

        cin>>contentLine;
    }
    else
    {
        cout<<"FATAL ERROR: INTRO COULD NOT BE LOADED!"<<endl;
    }

    MyIntroFile.close();
}

void GameMap::drawVictory()
{
    string contentLine;
    ifstream MyVictFile("Victory.txt");

    if(MyVictFile.is_open())
    {
        while(getline(MyVictFile,contentLine))
        {
          cout<<contentLine<<endl;
        }
    }
    else
    {
        cout<<"FATAL ERROR: VICTORY COULD NOT BE LOADED!"<<endl;
    }

    MyVictFile.close();
}

bool GameMap::getGameOver()
{
    return gameOver;
}

void GameMap::setGameOver(bool status)
{
    gameOver=status;
}
