#pragma warning( push , 0)
#include "raylib_cpp.h"
#include "SpriteObject.h"
#include "Colour.h"
#include "Matrix3.h"
#include "Vector3.h"
#include "TankPlayer.h"
#include "Turret.h"

#pragma warning(pop)

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1920;
    int screenHeight = 1080;

    raylib::InitWindow(screenWidth, screenHeight, "ULTIMATE AWESOME TANK SIMLATOR(VERY COOL !)!");

    raylib::SetTargetFPS(60);

    raylib::Texture2D tankSprite= raylib::LoadTexture("res/tank_green.png");
    raylib::Texture2D turretSprite = raylib::LoadTexture("res/tankGreen_barrel1.png");

    TankPlayer Player;
    Turret Child;
    Player.Sprite = &tankSprite;
    Child.SetParent(&Player);
    Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);
    Child.Sprite = &turretSprite;
    Child.SetLocalPosition(50,100);

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!raylib::WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        float deltaTime = raylib::GetFrameTime();

        Player.Update(deltaTime);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        raylib::BeginDrawing();

        raylib::ClearBackground(raylib::BLACK);

        Player.Draw();
       
        raylib::EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    raylib::CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}