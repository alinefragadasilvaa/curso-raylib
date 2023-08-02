#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    // é preciso inicializar a janela antes de usar as funções GetMouse
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    // variáveis de tipos pré-definidos
    Rectangle start = (Rectangle) {x: (screenWidth-MeasureText("Start", 30))/2, // tipo retângulo
                                   y: (screenHeight-30)/2,
                                   width: MeasureText("Start", 30),
                                   height: 30}; // os valores desse retângulo serão usados para detectar colisão do mouse em uma string de mesmos valores
    
    Vector2 mouse; // tipo vetor tipo 2
    
    Color cor_palavra = RED, cor_fundo = BLACK; // tipo cor
    Color cor_mudando =  (Color) {r: 127, g:50, b: 255, a:255}; // as cores podem ser criadas mudando a intensidade das cores primárias

    SetTargetFPS(60);

    while (!WindowShouldClose()){

        // ÁREA DE PROGRAMAÇÃO

        mouse = (Vector2) {GetMouseX(), GetMouseY()}; // atualizando o vetor da posição do mouse a cada iteração

        // cor_mudando.r+=5; para mudar a intensidade da cor a cada iteração

        // ÁREA DE DESENHO

        BeginDrawing();

        // mudando a cor do fundo usando entrada do mouse
        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
            cor_fundo = WHITE;
        } else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            cor_fundo = BLACK;
        }

        ClearBackground(cor_fundo); // cor do fundo variável

        // colisão do mouse com a posição da matriz
        if(CheckCollisionPointRec(mouse, start)){
            cor_palavra = GREEN; // cor com mouse
        } else {
            cor_palavra = RED; // cor sem mouse
        }

        // DrawRectangleRec(start, WHITE); para testar a existÊncia do retângulo abaixo da string

        DrawText("Start", start.x, start.y, start.height, cor_palavra); // string com os mesmos valores do retângulo

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
