#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    int x=0, y=30; // cordenadas da string
    int dx=2; // direção x incrementa a cordenada x da string
    char S[4] = {"DVD"}; // string

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);            
 
    while (!WindowShouldClose())   
    {

        // ÁREA DE PROGRAMAÇÃO

        x+=dx; // icrementa cordenada x
     
        // ÁREA DE DESNEHO
        
        BeginDrawing();

        ClearBackground(BLACK);
            
        // muda direção x da string
        if(x>screenWidth-MeasureText(C,100) || x<0){ // quando a cordenada x for maior que largura da tela - a largura da string ou quando for menor que 0 (inicio da janela)
           dx*=-1;
        } else{ // senão segue desenhando a string com a cordenada x sendo icrementada
            DrawText(C, x, y, 100, GREEN); 
        }

        EndDrawing();
     
    }

    CloseWindow();  

    return 0;
}
