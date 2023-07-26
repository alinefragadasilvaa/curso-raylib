 /*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 500;
    const int screenHeight = 500;

    // minhas variáveis
    int i, j;
    int sb=50;
    int tabela[10][10]={0};


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

        // a ideia é fazer a string "DVD" percorrer pela janela sem ultrapassar os limites da mesma

        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
           tabela[GetMouseX()/sb][GetMouseY()/sb] =1;
        } else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
           tabela[GetMouseX()/sb][GetMouseY()/sb] =2;
        } else if(IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)){
           for(i=0;i<10;i++){
                for(j=0;j<10;j++){
                    tabela[i][j]=0;
                }
            }
        }

        BeginDrawing();

            /*inicio+=dx; // string percorrendo a janela linearmente incrementando a coordenada i
            j+=vx;


            if(inicio>screenWidth-MeasureText(C,100) || inicio<0){
               dx*=-1;
            } else if(j>screenHeight-100 || j<0){
                vx*=-1;
            } else {
                DrawText(C, inicio, j, 100, GREEN);
            }*/

            ClearBackground(BLACK);

            /*for(i=0;i<10;i++){
                for(j=0;j<10;j++){
                    if(i==GetMouseX()/sb && j==GetMouseY()/sb){
                        DrawRectangle(i*sb,j*sb,sb,sb,RED); //DrawRectangle(i*sb,j*sb+50,sb,sb,WHITE);
                    }else{
                        DrawRectangle(i*sb,j*sb,sb,sb,WHITE); //DrawRectangle(i*sb,j*sb+50,sb,sb,WHITE);
                        DrawRectangleLines(i*sb,j*sb,sb,sb,RED); // DrawRectangleLines(i*sb,j*sb+50,sb,sb,RED);
                    }
                }
            }*/

            for(i=0;i<10;i++){
                for(j=0;j<10;j++){

                    switch(tabela[i][j]){
                        case 1:
                            DrawRectangle(i*sb,j*sb,sb,sb,BLUE);
                        break;
                        case 2:
                            DrawRectangle(i*sb,j*sb,sb,sb,RED);
                        break;
                        default:
                            DrawRectangle(i*sb,j*sb,sb,sb,BLACK);
                        break;
                    }
                     DrawRectangleLines(i*sb,j*sb,sb,sb,WHITE);
                }
            }

            //DrawRectangle(0,0,GetMouseX(),GetMouseY(),BLUE);
            //(GetMouseX(),GetMouseY(),sb,sb,GREEN);

        EndDrawing();

        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
