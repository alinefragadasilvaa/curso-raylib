#include "raylib.h"
#define FPS 60

typedef struct {
    float x;
    float y;
    float width;
    float height;
    float rot;
    float vel;
    Texture2D text;
} Tree;

main()
{
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Aula 6");
    Camera2D camera;
    Tree arvore;
    arvore.x = 350;
    arvore.y = 350;
    arvore.width = 200;
    arvore.height = 200;
    arvore.rot = 0;
    arvore.vel = 10;
    arvore.text = LoadTexture("Arvore.png");
    camera.target.x = arvore.x;
    camera.target.y = arvore.y;
    camera.offset.x = 100;
    camera.offset.y = 100;
    camera.rotation = 0;
    camera.zoom = 1;
    SetTargetFPS(FPS);
    while(!WindowShouldClose())
    {
        if(IsKeyDown(KEY_RIGHT))
        {
            arvore.rot+=2;
        }
        if(IsKeyDown(KEY_LEFT))
        {
            arvore.rot-=2;
        }
        if(IsKeyDown(KEY_UP))
        {
            arvore.y-=cos(arvore.rot*3.14/180)*arvore.vel;
            arvore.x+=sin(arvore.rot*3.14/180)*arvore.vel;
        }
        camera.target.x = arvore.x;
        camera.target.y = arvore.y;
        camera.rotation = -arvore.rot;
        camera.offset.x = GetScreenWidth()/2;
        camera.offset.y = GetScreenHeight()/2;

        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(WHITE);

        //FUNDO
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                DrawRectangle(i*100, j*100, 50, 50, RED);
            }
        }
        DrawRectanglePro((Rectangle){arvore.x, arvore.y, arvore.width, arvore.height}, (Vector2){arvore.width/2, arvore.height/2}, arvore.rot,  LIME);
        DrawTexturePro(arvore.text, (Rectangle){0, 0, arvore.text.width, arvore.text.height}, (Rectangle){arvore.x, arvore.y, arvore.width, arvore.height}, (Vector2){arvore.width/2, arvore.height/2}, arvore.rot, WHITE);
        //DrawRectangle(100, 100, 500, 500, BLUE);
        EndDrawing();
        EndMode2D();
    }
    CloseWindow();

}
