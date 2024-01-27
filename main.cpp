#include<iostream>
#include<fstream>
#include<cstring>
#include"raylib.h"
using namespace std;
int main()
{
	InitWindow(1300, 950, "The Legacy");

	//Textures
	
	Texture2D meteor2 = LoadTexture("Assets\\Meteor2.png");
	Texture2D meteor2r1 = LoadTexture("Assets\\meteor2r1.png");
	Texture2D meteor2r2 = LoadTexture("Assets\\meteor2r2.png");
	Texture2D meteor2r3 = LoadTexture("Assets\\meteor2r3.png");
	Texture2D meteor2r4 = LoadTexture("Assets\\meteor2r4.png");



	//Variables for stages
	int screen = 0;
	//pre game
	char intro1[] = { "A huge meteor had fallen on Earth in an uninhabitated valley. It was out of inhabited lands, so no one paid attention\nto it. Little did they know, it emitted very slight radiations." };
	char intro2[] = { "\n\nHowever these radiations did not pose a threat, instead they bestowed very few chosen ones with unimaginable\nabillities, which were later named \"Anomalies\". At first, their appearances were non-existent, later they grew in enough\nnumbers to be visible to the curious. To avoid chaos, anomalies were kept a secret by governments worldwide." };
	int intro1_counter = 1,intro1_text_delay=0, intro2_counter = 1, intro2text_delay = 0;


	SetTargetFPS(30);

	while (!WindowShouldClose())
	{

		/*--------------------------Update Phase--------------------------*/
		//Pre game
		if (screen == 0)
		{
			if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
			{
				screen = 1;
			}
		}
		else if (screen == 1)
		{

			cout << "AAAAAAAAAAAAAAAAA" << endl << endl << endl;
		}











		/*--------------------------Draw Phase--------------------------*/
		BeginDrawing();
		ClearBackground(BLACK);

		if (screen == 0)
		{
			ClearBackground(BLACK);
			DrawTexture(meteor2, 0, 0, WHITE);
			DrawText(TextSubtext(intro1, 0, intro1_counter), 50, 710, 20, WHITE);
			if (intro1_counter < strlen(intro1))
			{
				intro1_text_delay++;
				if (intro1_text_delay == 2)
				{
					intro1_counter++;
					intro1_text_delay = 0;
				}
			}

			if (intro1_counter >= strlen(intro1))
			{
				DrawTexture(meteor2r1, 0, 0, WHITE);
				DrawText(TextSubtext(intro2, 0, intro2_counter), 50, 710, 20, WHITE);
				intro2text_delay++;
				if (intro2text_delay == 2)
				{
					intro2_counter++;
					if (intro2_counter >= strlen(intro2) / 3 && intro2_counter < (strlen(intro2) / 3) + 1 / 3)
					{
						DrawTexture(meteor2r2, 0, 0, WHITE);
					}
					else if (intro2_counter >= (strlen(intro2) / 3) + 1 / 3 && intro2_counter < (strlen(intro2) / 3) + 2 / 3)
					{
						DrawTexture(meteor2r3, 0, 0, WHITE);
					}
					else if (intro2_counter >= (strlen(intro2) / 3) + 2 / 3)
					{
						DrawTexture(meteor2r4, 0, 0, WHITE);
					}
					intro2text_delay=0;
				}
			}
		}
		else if (screen == 1)
		{

		}



		EndDrawing();
	}

	//Unloading
	UnloadTexture(meteor2);
	UnloadTexture(meteor2r1);
	UnloadTexture(meteor2r2);
	UnloadTexture(meteor2r3);
	UnloadTexture(meteor2r4);




	CloseWindow();
}