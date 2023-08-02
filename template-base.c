/*RESUMO*/

// inclusão da biblioteca
#include "raylib.h" 

int main(void)
{
    // largura e altura da janela
    const int screenWidth = 500; 
    const int screenHeight = 500; 

    // variáveis usadas para resolver os desafios
    

    // inicialização da janela
    InitWindow(screenWidth, screenHeight, "TEMPLATE");

    // quantidade de frames por segundo
    SetTargetFPS(60);            

    while (!WindowShouldClose()) // finaliza com o fechamento da janela ou ESC
    {
        // ÁREA DE PROGRAMAÇÃO

        // ÁREA DE DESENHO
     
        BeginDrawing();

        ClearBackground(BLACK); // cor de fundo da janela

        EndDrawing();
    }
 
    CloseWindow();       

    return 0;
}
