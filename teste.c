/*
1 1 1 1 1 1 1 1 1 1
1 0 1 0 1 1 1 1 1 1
1 0 0 0 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
*/

// inclusão da biblioteca
#include "raylib.h"

void preenche(int mapa[][10]){
    mapa[0][]
}

int main(void)
{
    // largura e altura da janela
    const int screenWidth = 500;
    const int screenHeight = 500;

    // variáveis usadas para resolver os desafios
    int i, j;
    int mapa[10][10]={0};

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

        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                if(mapa[i][j]==0){
                    DrawRectangleLines(50*i, 50*j, 50, 50, WHITE);
                }
            }

        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
