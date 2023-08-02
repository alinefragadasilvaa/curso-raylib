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
        // ÁREA DE PROGRAMAÇÃO

        // uso de funções que detectam entradas pelo mouse e constantes que representam os botões
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
           tabela[GetMouseX()/sb][GetMouseY()/sb] =1; // GetMouseX e GetMouseY retornam as cordenadas x e y do mouse
        } else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
           tabela[GetMouseX()/sb][GetMouseY()/sb] =2; // as cordenadas divididas pelo tamanho do quadro retornam um valor inteiro que corresponde a posição na matriz do mapa
        } else if(IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)){
           for(i=0;i<10;i++){
                for(j=0;j<10;j++){
                    tabela[i][j]=0; // os valores na posição da matriz são usados para desenhar quadros deiferentes
                }
            }
        }

        // ÁREA DE DESENHO
     
        BeginDrawing();

        ClearBackground(BLACK); // cor de fundo da janela

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
     
            // desenhando matriz do mapa
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
                    DrawRectangleLines(i*sb,j*sb,sb,sb,WHITE); // função que desenha apenas as linhas do quadrado
                }
            }

            //DrawRectangle(0,0,GetMouseX(),GetMouseY(),BLUE);
            //(GetMouseX(),GetMouseY(),sb,sb,GREEN);

        EndDrawing();
    }
 
    CloseWindow();       

    return 0;
}
