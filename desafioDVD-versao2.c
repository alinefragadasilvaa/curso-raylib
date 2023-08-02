#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    int x=0, y=0; // cordenadas da string
    int dx=2, dy=2; // direções da string nas cordenadas
    char S[4] = {"DVD"}; // string

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);             
 
    while (!WindowShouldClose())
    {
      
        // ÁREA DE PROGRAMAÇÃO

        // icrementando as cordenadas com as direções
        x+=dx; 
        y+=dy;

        // ÁREA DE DESENHO

        BeginDrawing();

        ClearBackground(BLACK);

        if(x>screenWidth-MeasureText(S,100) || x<0){
           dx*=-1;
        } else if(y>screenHeight-100 || y<0){
           dy*=-1;
        } else{
            DrawText(S, x, y, 100, GREEN);
        }

        EndDrawing();

    }

    CloseWindow(); 

    return 0;
}
