//#pragma warning( push , 0)
#include "Game.h"

#include <iostream>

Game::~Game()
{

    for (int i = 0; i < bulletsInWorld.size(); i++)
    {
        delete bulletsInWorld[i];
    }
    for (int i = 0; i < entities.size(); i++)
    {
        delete entities[i];
    }

    delete player;

}

//int main(int argc, char* argv[])
    // Initialization
    //--------------------------------------------------------------------------------------
void Game::Initialization()
{
    int screenWidth = 1280;
    int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "ULTIMATE AWESOME homer SIMULATOR(VERY COOL !)!");

    SetTargetFPS(600000);

    player = new TankPlayer;
    turret = new Turret;
    barrel = new CircleCollision;

    //load necessary textures
        //Texture2D tankSprite= LoadTexture("res/tankBody_blue_outline.png");
        //Texture2D turretSprite = LoadTexture("res/homersMouth.png");
        //Texture2D bulletSprite = LoadTexture("res/homersSpit.png");
    tankSprite = LoadTexture("res/tankBody_blue_outline.png");
    tankTurretSprite = LoadTexture("res/homersMouth.png");
    tankBullet = LoadTexture("res/homersSpit.png");


    //TankPlayer tank;
    //Turret turret;
    //GameObject BulletSpawn;
    //tank.Sprite = &Game::tankSprite;
    //tank.SetLocalPosition(screenWidth / 2, screenHeight / 2);
    //turret.SetParent(&tank);
    //turret.Sprite = &Game::tankTurretSprite;
    //turret.SetLocalPosition(50,100);
    //BulletSpawn.SetParent(&turret);
    //BulletSpawn.SetLocalPosition(60, -40);
    //The player initialization
    player->Sprite = &tankSprite;
    player->SetLocalPosition(screenWidth / 2, screenHeight / 2);

    //The tanks's turret initialization
    turret->SetParent(player);
    turret->Sprite = &tankTurretSprite;
    turret->Origin = MathClasses::Vector3(0.0f, 0.5f, 0.5f);

    //The barrel initialization
    barrel->SetLocalPosition(1000, 200);
    barrel->radius = 20.0f;
    barrel->center = barrel->GetLocalPosition();
    barrel->Sprite = &barrelSptite;


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

}
        // Update
        //----------------------------------------------------------------------------------
void Game::Update()
{
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float deltaTime = GetFrameTime();

        player.Update(deltaTime);

        //bullet shooting :)
        if (IsKeyPressed(KEY_SPACE))
        {
            //Bullet Bullet;
            //Bullet.Update(deltaTime);
            //Bullet.Sprite = &bulletSprite;

            //Bullet.SetLocalRotation(BulletSpawn.GetWorldRotation());
            //Bullet.SetLocalPosition(BulletSpawn.GetWorldPosition());

            //bulletpool.push_back(Bullet);

            Bullet* bullet = new Bullet;
            bullet->Sprite = &tankBullet;
            bullet->collisionObject = new CircleCollision;

            MathClasses::Vector3 offset = MathClasses::Vector3(turret->Sprite->width + 20, 0, 1);

            bullet->SetlocalRotation(turret->GetWorldRotation());

            bullet->SetLocalPosition(turret->GetWorldMatrix() * offset);

            bulletsInWorld.push_back(bullet);

            size_t amount = bulletsInWorld.size();
            std::cout << amount << std::endl;

        }

        for (size_t i = 0; i < bulletpool.size(); i++)
        {
            bulletpool[i].Update(deltaTime);
        }

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