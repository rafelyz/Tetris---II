#include <raylib.h>
#include"game.h"  //userdefined header are placed inside "headerfile.h"
#include"color.h"
#include <iostream>  //standard header files are placed inside "headerfiles.h" eg: iostream,stdio.h


double lastUpdateTime = 0;

bool EvenTriggered(double interval)    
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime= currentTime;
        return true;

    }
    return false;
}

int main ()
{
    
    InitWindow(510, 630, "Tetris");     //creates a windowsbox 
    SetTargetFPS(60);                      //60frames pers second 

    Font font = LoadFontEx("doto.ttf", 64, 0, 0);      


    Game game = Game();
    

    
    while (WindowShouldClose()== false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if(EvenTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        
        BeginDrawing();
        ClearBackground(darkBlue);  //background of windows of tetris 
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);    
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
             DrawTextEx(font, "GAME OVER", {320, 420}, 38, 2, WHITE);
        }
       
        DrawRectangleRounded({320,55,170,60},0.3,6,lightBlue);

        char scoreText[10];
        sprintf(scoreText,"%d",game.score);
        Vector2 textSize= MeasureTextEx(font , scoreText,38,2);
        

        DrawTextEx(font, scoreText, {320 + (170-textSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320,235,170,180},0.3,6,lightBlue);

        game.Draw();
        EndDrawing();
    }

    CloseWindow();   //closes the windows

    return 0;
}
