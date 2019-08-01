#include "GameMap.h"
#include <iostream>
#include <fstream>


using namespace std;

GameMap::GameMap()
{
    loadMapFromFile();
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
                 cout<<"3";
                }
            }
        }
        cout<<endl;
    }
}

bool GameMap::validationPlayerCell(int PlayerX, int PlayerY)
{
    //cout<<"Las coordenadas del jugador estan en "<<PlayerX<<" , "<<PlayerY;
    //cells[PlayerX][PlayerY].id=3;
    //cout<<cells[PlayerX][PlayerY].id;

    if(cells[PlayerX][PlayerY].id=='1')
    {
        return true;
    }
    else
    {
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
            //cout<<"***"<<contentLine<<"***";
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
}
