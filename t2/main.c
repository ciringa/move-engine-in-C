#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "useful.h"
#include <conio.h>


#define X_LENGTH 60
#define Y_LENGTH 15
#define PLAYER_START_POSX 30
#define PLAYER_START_POSY 5
#define SPD 1


int player_posX,player_posY;
player_posX = PLAYER_START_POSX;
player_posY = PLAYER_START_POSY;

int x_map[X_LENGTH];
int y_map[Y_LENGTH];


//move and colision in X axis
int moveX(int dir,int pos){
    //pos = position before move, dir = move direction;
    int x,cos_calc;
    //calcs
    switch (dir)
    {
        case 97:
            cos_calc = pos-SPD;
            if (x_map[cos_calc]!=2)
            {
                x = pos-SPD;
            }else{
                x = pos;
            }
        

            break;
        case 100:
            cos_calc = pos+SPD;
            if (x_map[cos_calc]!=2)
            {
                x = pos+SPD;

            }else{
                x = pos;
            }
            break; 
    }

    return x;
}

int moveY(int dir,int pos){
    //pos = position before move, dir = move direction;
    int x,cos_calc;
    //calcs
    switch (dir)
    {
        case 119:
            cos_calc = pos-SPD;
            if (y_map[cos_calc]!=2)
            {
                x = pos-SPD;

            }else{
                x = pos;
            }
            break;
        case 115:
            cos_calc = pos+SPD;
            if (y_map[cos_calc]!=2)
            {
                x = pos+SPD;

            }else{
                x = pos;
            }
            break; 
    }

    return x;
}

//get keyboard inputs
void controles(){
    SetBackgroundColor(0);
    int menu;
    //control variable
    setColor(1);
    printf("press ESC to exit\n");
    printf("X:%d Y:%d\n",player_posX,player_posY);
    menu = getch();
    
    if (menu==119||menu==115){
        player_posY = moveY(menu,player_posY);
    }else if(menu==97||menu==100){
        player_posX = moveX(menu,player_posX);
    }else if (menu == 27)
    {
       return 0;
    }else{
        controles();
    }
    main();
}


int main(){
    system("cls");
    SetBackgroundColor(1);
    printf("move using WASD\n");
    SetBackgroundColor(0);
    //seting coordenates to X and y On the map
    for (int j = 0; j <= Y_LENGTH; j++)
        {
            if (j == player_posY)
            {
                y_map[j] = 1;
            }else if (j == 0||j == Y_LENGTH)
            {
                y_map[j]=2;
            }else{
                y_map[j] = 0;
            }
            for (int i = 0; i <= X_LENGTH; i++)
            {   
                if (i == player_posX){
                    x_map[i] = 1;
                }else if (i == 0||i == X_LENGTH)
                {
                    x_map[i]=2;
                }else{
                    x_map[i] = 0;
                }
            }
    }

    //drawing things in map
    for (int i = 0; i <= Y_LENGTH; i++)
    {   
        for (int j = 0; j <= X_LENGTH; j++)
        {   
            if (x_map[j] == 1 && y_map[i] == 1)
            {   setColor(28);
                printf("@");
            }else if(x_map[j]==2 || y_map[i]==2){
                setColor(17);
                printf("#");
            }
            else{
                setColor(0);
                printf(" ");
            }
            
        }
        printf("\n");
    }


    controles();
}