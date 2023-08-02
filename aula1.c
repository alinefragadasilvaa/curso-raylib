/*NESTA AULA FORAM INTRODUZIDOS CONCEITOS DE FUNCIONAMENTO DA JANELA E DE CORDENADAS, USANDO FUNÇÃO
QUE DESENHA TEXTOS*/

#include "raylib.h" // incluindo a biblioteca

int main(void)
{
    // largura e altura da janela
    const int screenWidth = 800;
    const int screenHeight = 450;

    // variáveis usadas na janela
    int i; // contador das iterações
    char C[4][50] = {"oi", "tchau", "a", "gremio"}; // strings para desenhar na janela

    // inicialização da janela
    InitWindow(screenWidth, screenHeight, "Aula 1"); 

    SetTargetFPS(60);  // frames por segundo
    
    while (!WindowShouldClose())  // função indica o fechamento da janela ou ESC
    {
        // ÁREA DE DESENHO

        BeginDrawing();

        ClearBackground(BLACK); // cor do fundo da janela

        // desenhando cada string em uma coordenada diferente
        for(i=0;i<4;i++){
            DrawText(C[i], (screenWidth-MeasureText(C[i],30))/2,100+(30+50)*i, 30, RED); // MeasureText() devolve a largura da string
        }

        EndDrawing();
    }

    CloseWindow(); 
    
    return 0;
}
