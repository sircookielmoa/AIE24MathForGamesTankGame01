#pragma warning( push , 0)
#include "Raylib.h"
#include "SpriteObject.h"
#include "Colour.h"
#include "Matrix3.h"
#include "Vector3.h"
#include "TankPlayer.h"
#include "Turret.h"
#include "Bullet.h"
#include "PlaneCollision.h"


#pragma warning(pop)

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1280;
    int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "ULTIMATE AWESOME homer SIMLATOR(VERY COOL !)!");

    SetTargetFPS(600000);

    Texture2D tankSprite= LoadTexture("res/tankBody_blue_outline.png");
    Texture2D turretSprite = LoadTexture("res/homersMouth.png");
    Texture2D bulletSprite = LoadTexture("res/homersSpit.png");

    TankPlayer tank;
    Turret turret;
    GameObject BulletSpawn;
    tank.Sprite = &tankSprite;
    tank.SetLocalPosition(screenWidth / 2, screenHeight / 2);
    turret.SetParent(&tank);
    turret.Sprite = &turretSprite;
    turret.SetLocalPosition(50,100);
    BulletSpawn.SetParent(&turret);
    BulletSpawn.SetLocalPosition(60, -40);

    std::vector<PlaneCollision> borders{ 4 };
    //BORDER TIME :D
    //north
    borders[0] = PlaneCollision(0.0f, 1.0f, 0.0f, 0);

    //East boarder 
    borders[1] = PlaneCollision(-1.0f, 0.0f, 0.0f, screenWidth);

    //South boarder 
    borders[2] = PlaneCollision(0.0f, -1.0f, 0.0f, screenHeight);

    //West boarder 
    borders[3] = PlaneCollision(1.0f, 0.0f, 0.0f, 0);



    std::vector <Bullet> bulletpool{};

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();

        tank.Update(deltaTime);

        if (IsKeyPressed(KeyboardKey::KEY_SPACE))
        {
            Bullet Bullet;
            Bullet.Update(deltaTime);
            Bullet.Sprite = &bulletSprite;

            Bullet.SetLocalRotation(BulletSpawn.GetWorldRotation());
            Bullet.SetLocalPosition(BulletSpawn.GetWorldPosition());

            bulletpool.push_back(Bullet);
        }

        for (size_t i = 0; i < bulletpool.size(); i++)
        {
            bulletpool[i].Update(deltaTime);
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        tank.Draw();
        for (size_t i = 0; i < bulletpool.size(); i++)
        {
            bulletpool[i].Draw();
        }
        DrawFPS(10, 10);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}