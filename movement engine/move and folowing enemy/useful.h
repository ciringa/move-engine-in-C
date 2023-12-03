#include <stdio.h>
#include <windows.h>

//change back colors
void SetBackgroundColor(int BackC)
{
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     WORD wColor = ((BackC & 0x0F) << 4) + (csbi.wAttributes & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;

     //credits codeincodeblock
}


//change font colors
void setColor(int ForgC){

    //We will need this handle to get the current background attribute
    WORD wColor; 
    
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    //we use csbi for the wAttributes word.
    CONSOLE_SCREEN_BUFFER_INFO csbi; 

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        //Mask out all but the background attribute
        //, and add in the foreground color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;

    //credits codeincodeblock
}


void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y});
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}