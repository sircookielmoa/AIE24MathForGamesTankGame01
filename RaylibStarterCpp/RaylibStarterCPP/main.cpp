#pragma warning( push , 0)
#include "raylib_cpp.h"
#include "SpriteObject.h"
#include "Colour.h"
#include "Matrix3.h"
#include "Vector3.h"
#include "TankPlayer.h"
#include "Turret.h"
#include "Bullet.h"
#include "Utility.h"

#pragma warning(pop)

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1280;
    int screenHeight = 720;

    raylib::InitWindow(screenWidth, screenHeight, "ULTIMATE AWESOME TANK SIMLATOR(VERY COOL !)!");

    raylib::SetTargetFPS(60000);

    raylib::Texture2D tankSprite= raylib::LoadTexture("res/tankBody_blue_outline.png");
    raylib::Texture2D turretSprite = raylib::LoadTexture("res/homersMouth.png");
    raylib::Texture2D bulletSprite = raylib::LoadTexture("res/homersSpit.png");

    TankPlayer Player;
    Turret Child;
    GameObject BulletSpawn;
    Player.Sprite = &tankSprite;
    Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);
    Child.SetParent(&Player);
    Child.Sprite = &turretSprite;
    Child.SetLocalPosition(50,100);
    BulletSpawn.SetParent(&Child);
    BulletSpawn.SetLocalPosition(60, -40);

    std::vector <Bullet> bulletpool{};

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!raylib::WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        float deltaTime = raylib::GetFrameTime();

        Player.Update(deltaTime);

        if (raylib::IsKeyPressed(raylib::KeyboardKey::KEY_SPACE))
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

        Plane(0, 1280, 0);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        raylib::BeginDrawing();

        raylib::ClearBackground(raylib::RAYWHITE);

        Player.Draw();
        for (size_t i = 0; i < bulletpool.size(); i++)
        {
            bulletpool[i].Draw();
        }
        raylib::DrawFPS(10, 10);
        raylib::EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    raylib::CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}