/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#pragma warning( push , 0)
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include <raygui.h>

#include "Game.h"

#pragma warning(pop)

int main(int argc, char* argv[])
{
	// Initialization
	//--------------------------------------------------------------------------------------


	
	//SetTargetFPS(60);

	Game* tankGame = new Game;

	tankGame->Initialization();

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here

		BeginDrawing();
		tankGame->Update();

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		ClearBackground(RAYWHITE);

		tankGame->Draw();
		DrawRectangle(5, 5, 120, 25, BLACK);
		DrawFPS(10, 10);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}
	// De-Initialization
	//--------------------------------------------------------------------------------------   
	delete tankGame;
	
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}