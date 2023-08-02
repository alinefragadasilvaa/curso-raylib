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
    int x=0, y=0;

    Rectangle rec_preto, rec_vermelho;

    // inicialização da janela
    InitWindow(screenWidth, screenHeight, "TEMPLATE");

    // quantidade de frames por segundo
    SetTargetFPS(60);

    while (!WindowShouldClose()) // finaliza com o fechamento da janela ou ESC
    {
        // ÁREA DE PROGRAMAÇÃO

        rec_preto = (Rectangle){x:x, y:y, width:50, height:50};
        rec_vermelho = (Rectangle){x:100, y:100, width:50, height:50};

        if(IsKeyDown(KEY_UP)){
                y-=2;
                if(CheckCollisionRecs(rec_preto,rec_vermelho))
                    y+=2;
        }

        if(IsKeyDown(KEY_DOWN)){
            y+=2;
        } if(IsKeyDown(KEY_LEFT)){
            x-=2;
        } if(IsKeyDown(KEY_RIGHT)){
            x+=2;
        }
        if(CheckCollisionRecs(rec_preto,rec_vermelho)){
           /* if(IsKeyDown(KEY_UP)){
                y+=2;
            }*/ if(IsKeyDown(KEY_DOWN)){
                y-=2;
            } else if(IsKeyDown(KEY_LEFT)){
                x+=2;
            } else if(IsKeyDown(KEY_RIGHT)){
                x-=2;
            }

        }




        // ÁREA DE DESENHO

        BeginDrawing();

        ClearBackground(WHITE); // cor de fundo da janela

        DrawRectangleRec(rec_preto, BLACK);
        DrawRectangleRec(rec_vermelho, RED);


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
