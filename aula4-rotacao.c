/*RESUMO*/

// inclusão da biblioteca
#include "raylib.h"

//void preenche(int mapa[][10]){
   // mapa[0][]
//}

int main(void)
{
    // largura e altura da janela
    const int screenWidth = 500;
    const int screenHeight = 500;

    // variáveis usadas para resolver os desafios
    float r=0;
    Color cor = (Color) {r:0, g:0, b:0, a:255};

    // inicialização da janela
    InitWindow(screenWidth, screenHeight, "TEMPLATE");

    // quantidade de frames por segundo
    SetTargetFPS(60);

    while (!WindowShouldClose()) // finaliza com o fechamento da janela ou ESC
    {
        // ÁREA DE PROGRAMAÇÃO

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            cor = (Color) {r: GetRandomValue(0, 255), g: GetRandomValue(0, 255), b:GetRandomValue(0, 255), a: 255};
        }

        r++;

        // ÁREA DE DESENHO

        BeginDrawing();

        ClearBackground(WHITE); // cor de fundo da janela

        DrawRectanglePro((Rectangle){x:((screenWidth-100)/2)+50,y:((screenHeight-100)/2)+50,width:100,height:100}, (Vector2){x:50,y:50}, r, cor);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
