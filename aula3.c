#include "raylib.h"

// tipos pré definidos na biblioteca

// vector2 V
// V.x = x;
// V.y = y;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Rectangle start = (Rectangle) {x: (screenWidth-MeasureText("Start", 30))/2,
                                   y: (screenHeight-30)/2,
                                   width: MeasureText("Start", 30),
                                   height: 30};

    Vector2 mouse;
    Color cor_palavra = RED, cor_fundo = BLACK, cor_mudando =  (Color) {r: 127, g:50, b: 255, a:255};

    SetTargetFPS(60);

    while (!WindowShouldClose()){

        mouse = (Vector2) {GetMouseX(), GetMouseY()}; // tem que ser dentro do while para atualizar o valor

        cor_mudando.r+=5;

        BeginDrawing();

        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
            cor_fundo = WHITE;
        } else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            cor_fundo = BLACK;
        }

        ClearBackground(cor_fundo);

        if(CheckCollisionPointRec(mouse, start)){
            cor_palavra = GREEN;
        } else {
            cor_palavra = RED;
        }

        // DrawRectangleRec(start, WHITE);

        DrawText("Start", start.x, start.y, start.height, cor_palavra);

        EndDrawing();

    }


    CloseWindow();

    return 0;
}
