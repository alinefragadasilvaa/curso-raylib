/*NESTA AULA, A JANELA FOI ESTRUTURADA COMO UMA MATRIZ, FORAM UTILIZADAS
FUNÇÕES DE ENTRADAS DO MOUSE E DE POSIÇÃO DO MOUSE PARA ALTERAR OS VALORES 
DAS POSIÇÕES DAS MATRIZ E, COM BASE NISSO, DESENHAR RETÂNGULOS DIFERENTES NA JANELA*/

// inclusão da biblioteca
#include "raylib.h" 

int main(void)
{
    // largura e altura da janela
    const int screenWidth = 500; 
    const int screenHeight = 500; 

    // variáveis usadas para resolver os desafios
    int i, j; // iterações
    int sb=50; // sizebox
    int tabela[10][10]={0}; // matriz do mapa

    // inicialização da janela
    InitWindow(screenWidth, screenHeight, "AULA 3");

    // quantidade de frames por segundo
    SetTargetFPS(60);            

    // Mloop da janela
    while (!WindowShouldClose()) // finaliza com o fechamento da janela ou ESC
    {
        // ÁREA DE DESENHO
     
        BeginDrawing();

        ClearBackground(BLACK); // cor de fundo da janela

        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                DrawRectangle(i*sb,j*sb,sb,sb,WHITE); //DrawRectangle(i*sb,j*sb+50,sb,sb,WHITE) caso queira deixar um cabeçalho
                DrawRectangleLines(i*sb,j*sb,sb,sb,RED); // DrawRectangleLines(i*sb,j*sb+50,sb,sb,RED) caso queira deixar um cabeçalho
            }
        }
 
        // tetando posições do mouse
        DrawRectangle(0,0,GetMouseX(),GetMouseY(),BLUE); // largura e altura alteram de acordo com a posição do mouse
        DrawRectangle(GetMouseX(),GetMouseY(),sb,sb,GREEN); // cordenadas alteram de acordo com a posição do mouse 

        EndDrawing();
    }
 
    CloseWindow();       

    return 0;
}
