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

        // desenha a matriz do mapa e muda a cor do quadrado que o mouse estiver em cima
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                if(i==GetMouseX()/sb && j==GetMouseY()/sb){ // GetMouseX() e GetMouseY() deivididas pelo tamanho do quadrado devolvem posição da matriz
                    DrawRectangle(i*sb,j*sb,sb,sb,RED); //DrawRectangle(i*sb,j*sb+50,sb,sb,WHITE);
                }else{
                    DrawRectangle(i*sb,j*sb,sb,sb,WHITE); //DrawRectangle(i*sb,j*sb+50,sb,sb,WHITE);
                    DrawRectangleLines(i*sb,j*sb,sb,sb,RED); // DrawRectangleLines(i*sb,j*sb+50,sb,sb,RED);
                }
            }
        }

        EndDrawing();
    }
 
    CloseWindow();       

    return 0;
}
