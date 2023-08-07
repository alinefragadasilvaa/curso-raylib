#include "raylib.h"
#define FPS 60

typedef enum {left = -1, right = 1} Lado;

void SetupWindow()
{
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Aula Texturas");
    SetTargetFPS(FPS);
    HideCursor();
    InitAudioDevice();
}

typedef struct
{
    Texture2D texturesR[3]; // estrutura pré-definida da biblioteca
    Texture2D texturesL[3];
    Rectangle rec;
    int scale;
    Lado side;
    Texture2D *texture;
    double start_walking;
    Vector2 vel;
    Sound bark;
} dog;

void SetupDog(dog *Dog)
{
    char nome_end[40];
    for(int i = 0; i < 3; i++)
    {
        sprintf(nome_end, "./Texturas/Dog%dR.png", i + 1);
        Dog->texturesR[i] = LoadTexture(nome_end); // carrega um arquivo LoadTexture("./pasta/imagem.png")
        sprintf(nome_end, "./Texturas/Dog%dL.png", i + 1);
        Dog->texturesL[i] = LoadTexture(nome_end);
    }
    Dog->texture = &Dog->texturesR[0];
    Dog->scale = 5;
    Dog->side = right;
    Dog->rec = (Rectangle)
    {
        x: 100,
        y: 100,
        width:
            Dog->texture->width * Dog->scale, // escala do desenho
        height:
            Dog->texture->height * Dog->scale
    };
    Dog->vel = (Vector2)
    {
        x:
            (float) 150 / FPS,
        y:
            (float) 100 / FPS
    };
    Dog->bark = LoadSound("./Sons/Dog_bark.mp3");
}

Vector2 Dog_pos(dog Dog)
{
    return (Vector2)
    {
        Dog.rec.x, Dog.rec.y
    };
}

void Restaurar(dog *Dog)
{
    for(int i = 0; i < 3; i++)
    {
        UnloadTexture(Dog->texturesR[i]);
        UnloadTexture(Dog->texturesL[i]);
    }
    CloseAudioDevice();
}

void Draw(dog Dog, Rectangle Obstaculo)
{
    BeginDrawing();
    ClearBackground(WHITE);
    DrawRectangleRec(Dog.rec, BLUE);
    DrawTextureEx(*Dog.texture, Dog_pos(Dog), 0, Dog.scale, WHITE);
    DrawRectangleRec(Obstaculo, RED);
    EndDrawing();
}

void Anim_dog(dog *Dog)
{

    int i;
    i = (int)((GetTime() - Dog->start_walking)*4)%4; // retorna segundos, double
    switch (i)
    {
    case 0:
        i = 0;
        break;
    case 1:
        i = 1;
        break;
    case 2:
        i = 0;
        break;
    case 3:
        i = 2;
        break;
    default:
        break;
    }
    if(Dog->side == right) Dog->texture = &Dog->texturesR[i];
    if(Dog->side == left) Dog->texture = &Dog->texturesL[i];
}

void MovingDog(dog *Dog,Rectangle Obstaculo)
{
    if(IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN) && IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT))
    {
        if(Dog->side == left) Dog->texture = &Dog->texturesL[0];
        if(Dog->side == right) Dog->texture = &Dog->texturesR[0];
        Dog->start_walking = GetTime();
    }
    else
    {
        Anim_dog(Dog);
        if(IsKeyDown(KEY_UP))
        {
            Dog->rec.y -= Dog->vel.y;
        }
        while(CheckCollisionRecs(Dog->rec, Obstaculo))
        {
            Dog->rec.y++;
            Dog->rec.y = floor(Dog->rec.y); // funções de arredondamento
        }
        if(IsKeyDown(KEY_DOWN))
        {
            Dog->rec.y += Dog->vel.y;
        }
        while(CheckCollisionRecs(Dog->rec, Obstaculo))
        {
            Dog->rec.y--;
            Dog->rec.y = ceil(Dog->rec.y);
        }
        if(IsKeyDown(KEY_LEFT))
        {
            Dog->rec.x -= Dog->vel.x;
            Dog->side = left;
        }
        while(CheckCollisionRecs(Dog->rec, Obstaculo))
        {
            Dog->rec.x++;
            Dog->rec.x = floor(Dog->rec.x);
        }
        if(IsKeyDown(KEY_RIGHT))
        {
            Dog->rec.x += Dog->vel.x;
            Dog->side = right;
        }
        while(CheckCollisionRecs(Dog->rec, Obstaculo))
        {
            Dog->rec.x--;
            Dog->rec.x = ceil(Dog->rec.x);
        }
    }
}

void BarkSound(dog Dog)
{
    if(IsKeyPressed(KEY_A))
    {
        if(IsSoundPlaying(Dog.bark)) // funções para sons
        {
            StopSound(Dog.bark);
        }
        PlaySound(Dog.bark);
    }
}

void AmbientSound(Sound Ambiente)
{
    if(!IsSoundPlaying(Ambiente))
    {
        PlaySound(Ambiente);
    }
}

void Prog(dog *Dog, Rectangle Obstaculo, Sound Ambiente)
{
    MovingDog(Dog, Obstaculo);
    BarkSound(*Dog);
    AmbientSound(Ambiente);
}

main()
{
    SetupWindow();
    dog Dog;
    SetupDog(&Dog);
    // Texture2D teste = LoadTexture("./Texturas/dog1R.png"); // teste.height ou teste.whidth são campos da estrutura, podem ser usados para criar um retangulo para detectar colisão
    Texture2D testes[3] = {LoadTexture("./Texturas/dog1R.png"), LoadTexture("./Texturas/dog2R.png"), LoadTexture("./Texturas/dog3R.png")};
    int i=0;
    double tempo=GetTime();
    Vector2 posicao_teste = {500, 50};
    Rectangle Obstaculo  = (Rectangle)
    {
        400, 400, 200, 200
    };
    Sound Ambiente = LoadSound("./Sons/Farm.mp3");
    while(!WindowShouldClose())
    {

        //Prog
        Prog(&Dog, Obstaculo, Ambiente);
        if(IsKeyDown(KEY_SPACE)){
            i=(int) ((GetTime()-tempo)*3)%3;
        } else {
            i=0;
        }
        //Draw
        //DrawTexture(teste, 100, 50, WHITE);
        DrawTextureEx(testes[i], posicao_teste, 0, 5, WHITE);
        Draw(Dog, Obstaculo);
    }
    Restaurar(&Dog);
    CloseWindow();
    return 0;

}
