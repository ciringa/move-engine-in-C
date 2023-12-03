#include <stdio.h>
#include <conio.h>
#include "useful.h"


#define X_LENGTH 65
#define Y_LENGTH 15
#define PLAYER_START_Y 7
#define PLAYER_START_X 32
#define INI_AMOUNT 2


struct  player
{
    int x;
    int y;
    int spd;
};
struct preset_ini{
    int x;
    int y;
    int spd;
    int can_move;
};

int game_start = 0;
int map[Y_LENGTH][X_LENGTH];



struct player prtf;
struct  preset_ini ini[INI_AMOUNT];


int create(),step();



//player control
int controls(){
    int dir = getch();
    int check;
    switch (dir)
    {
    //A = left
    case 97:
        check = prtf.x-prtf.spd;
        if(map[prtf.y][check] == 0){
        prtf.x -=prtf.spd;
        }
        break;
    //S = down
    case 115:
        check = prtf.y+prtf.spd;
        if(map[check][prtf.x] == 0){
        prtf.y +=prtf.spd;
        }
        break;
    //W = up
    case 119:
        check = prtf.y-prtf.spd;
        if(map[check][prtf.x] == 0){
        prtf.y -=prtf.spd;
        }
        break;
    // D = rigth
    case 100:
        check = prtf.x+prtf.spd;
        if(map[prtf.y][check] == 0){
        prtf.x +=prtf.spd;
        }
        break;
    case 27:
        printf("\n thank u \n");
        game_start = -1;
        break;    
    default:
        controls();
        break;
    }

    //main();
}

//separated objects actions (used for objects who uses diferent codes, all of them is linked by step event)
int ini_action(int id){
    if(ini[id].can_move == 1){
        if(prtf.x > ini[id].x && map[ini[id].y][ini[id].x+1] == 0 ){
            ini[id].x ++;
        }else if(prtf.x<ini[id].x && map[ini[id].y][ini[id].x-1] == 0){
            ini[id].x --;
        }
        if(prtf.y<ini[id].y && map[ini[id].y-1][ini[id].x] == 0){
            ini[id].y --;
        }else if(prtf.y>ini[id].y && map[ini[id].y+1][ini[id].x] == 0){
            ini[id].y ++;
        }
    ini[id].can_move = 0;
    }else{
        ini[id].can_move = 1;
    }
}

//map 
int draw_map(){
    for (int i = 0; i < Y_LENGTH; i++)
    {
        for (int j = 0; j < X_LENGTH; j++)
        {
            if (map[i][j] == 0)
            {
                printf(" ");
            }
            if (map[i][j] == 1)
            {   setColor(2);
                printf("@");
                setColor(0);
            }
            if (map[i][j] == 2)
            {   SetBackgroundColor(24);
                printf("#");
                SetBackgroundColor(0);
            }
            if(map[i][j] == 3){
                setColor(4);
                printf("$");
                setColor(0);
            }
            
            //printf("%d",map[i][j]);
        }
        printf("\n");

    }
    printf("X:%d Y:%d\nBOMBS:\nInimigos:%d\n",prtf.x,prtf.y,INI_AMOUNT);
    for(int i = 0;i<INI_AMOUNT;i++){
        printf("%d X:%d Y:%d\n",i,ini[i].x,ini[i].y);
    }
}
int set_map(){
    //config map

    for (int i = 0; i < Y_LENGTH; i++)
    {   
        for (int j = 0; j < X_LENGTH; j++)
        {   
            if (i == prtf.y && j == prtf.x)
            {
                map[i][j] = 1;
            }else if (i == 0 || i == Y_LENGTH-1 || j == 0 || j == X_LENGTH-1){
                map[i][j] = 2;
            }else{
                map[i][j] = 0;
                for(int k = 0;k < INI_AMOUNT;k++){
                    if (ini[k].x == j && ini[k].y == i)
                    {
                        map[i][j] = 3;
                    }
                }
            }
        }
    }

    
    map[5][15] = 2;
    map[6][15] = 2;
    map[7][15] = 2;
    map[8][15] = 2;
    map[5][43] = 2;
    map[6][43] = 2;
    map[7][43] = 2;
    map[8][43] = 2;
}


//bro it's main function
int main(){
    hidecursor();
    system("cls");
    if (game_start ==0)
    {   
        create();
    }else if(game_start == 1){
        step();
    }else{
        printf("---------------------------------\n\tGame Over\n-----------------------------------");
        return 0;
    }
}




//round events (the most important ones)
int create(){
    //happens when the game start (used to set some configs)
    prtf.x = PLAYER_START_X;
    prtf.y = PLAYER_START_Y;
    prtf.spd = 1;

    ini[0].x = 5;
    ini[0].y = 6;
    ini[0].spd = 1;
    ini[0].can_move = 1;

    ini[1].x = 35;
    ini[1].y = 8;
    ini[1].spd = 1;
    ini[1].can_move = 1;

    game_start = 1;
    main();
}
int step(){
    if(prtf.x == ini[0].x && prtf.y == ini[0].y){
        game_start = -1;
    }
    //happens everytime
    set_map();
    draw_map();
    controls();    

    for(int i =0;i<INI_AMOUNT;i++){
        ini_action(i);
    }
    main();
}

