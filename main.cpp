#include <iostream>
#include <stdlib.h>
using namespace std;

void drawMap(int heroPosX, int heroPosY, char gameMap[5][5])
{
    system("cls");
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

int main()
{
    int  heroPosX=2;
    int  heroPosY=2;
    bool isGameOver=false;
    char input=' ';
    char gameMap[5][5]={{'1','1','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','1','1','1','1'},
                        {'1','1','1','1','1'}};

    while(isGameOver == false)
    {
        drawMap(heroPosX,heroPosY,gameMap);

        cin>>input;

        switch(input){
        case'a': heroPosX--; break;
        case'd': heroPosX++; break;
        case'w': heroPosY--; break;
        case's': heroPosY++; break;
        case'p': isGameOver=true; break;
        }
    }

    return 0;
}


