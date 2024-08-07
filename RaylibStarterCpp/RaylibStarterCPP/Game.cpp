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
    delete turret;
    delete barrel;
}

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
    tankSprite = LoadTexture("res/tankBody_blue_outline.png");
    tankTurretSprite = LoadTexture("res/homersMouth.png");
    tankBullet = LoadTexture("res/homersSpit.png");


    player->Sprite = &tankSprite;
    player->SetLocalPosition(screenWidth / 2, screenHeight / 2);

    //Homer's mouth initialization
    turret->SetParent(player);
    turret->Sprite = &tankTurretSprite;
    turret->Origin = MathClasses::Vector3(0.25f, 0.24f, 0.5f);

    //Homer's lips pivot point initialization
    barrel->SetLocalPosition(1000, 200);
    barrel->radius = 20.0f;
    barrel->center = barrel->GetLocalPosition();
    barrel->Sprite = &barrelSprite;

    //BORDER TIME :D
    //north
    awesomeBorder.push_back(PlaneCollision(0.0f, 1.0f, 0.0f, 0));

    //east
    awesomeBorder.push_back(PlaneCollision(-1.0f, 0.0f, 0.0f, screenWidth));

    //south 
    awesomeBorder.push_back(PlaneCollision(0.0f, -1.0f, 0.0f, screenHeight));

    //west
    awesomeBorder.push_back(PlaneCollision(1.0f, 0.0f, 0.0f, 0));

}
        // Update
        //----------------------------------------------------------------------------------
void Game::Update()
{
        float deltaTime = GetFrameTime();
        float maxTime = .06f;

        if (fired) { timer += (float)GetFrameTime(); }
        if (timer >= maxTime) { fired = false; }
        player->Update(deltaTime);

		//bullet shooting :)
        //implement a timeout where like, theres a cooldown per shot
		//i.e., increment a timer each frame Space is held and respan if it is ok
        if (IsKeyDown(KEY_SPACE) && !fired)
        {
            fired = true;
            timer = 0;
            Bullet* bullet = new Bullet;
            bullet->Sprite = &tankBullet;
            bullet->collisionObject = new CircleCollision;

            MathClasses::Vector3 offset = MathClasses::Vector3(turret->Sprite->width + -100, 50, 1);

            bullet->SetLocalRotation(turret->GetWorldRotation());

            bullet->SetLocalPosition(turret->GetWorldMatrix() * offset);

            bulletsInWorld.push_back(bullet);

            size_t amount = bulletsInWorld.size();
        	std::cout << "P'TOOIE!" << '\n';
        }
        //check for any collisions
        for (unsigned int i = 0; i < bulletsInWorld.size(); i++)
        {
            bulletsInWorld[i]->collisionObject->radius = 3;
            bulletsInWorld[i]->collisionObject->center = bulletsInWorld[i]->GetLocalPosition();

            //collision against awesomeBorders
            for (unsigned int p = 0; p < awesomeBorder.size(); p++)
            {
	            if (bulletsInWorld[i]-> collisionObject->Overlaps(&awesomeBorder[p]))
	            {
                    bulletsToRemove.push_back(bulletsInWorld[i]);
	            }
            }
        }

        //delete bullets that collide with awesomeBorders
        for (unsigned int i = 0; i < bulletsInWorld.size(); i++)
        {
            for (unsigned int j = 0; j < bulletsToRemove.size(); j++)
            {
                if (bulletsToRemove[j] == bulletsInWorld[i])
                {
                    bulletsInWorld.erase(bulletsInWorld.begin() + i);
                    delete bulletsToRemove[j];
                }
            }
        }
        bulletsToRemove.clear();

        for (size_t i = 0; i < bulletsInWorld.size(); i++)
        {
            bulletsInWorld[i]->Update(deltaTime);
        }

}
        // Draw
		//----------------------------------------------------------------------------------
void Game::Draw()
{

        player->Draw();
        for (size_t i = 0; i < bulletsInWorld.size(); i++)
        {
            bulletsInWorld[i]->Draw();
        }

}