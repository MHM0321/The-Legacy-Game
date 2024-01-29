#include<iostream>
#include<fstream>
#include<cstring>
#include"raylib.h"
using namespace std;
int main()
{
	InitWindow(1300, 950, "The Legacy");
	InitAudioDevice();
	//Textures
	
	Texture2D meteor2 = LoadTexture("Assets\\Meteor2.png");
	Texture2D meteor2r1 = LoadTexture("Assets\\meteor2r1.png");
	Texture2D meteor2r2 = LoadTexture("Assets\\meteor2r2.png");
	Texture2D meteor2r3 = LoadTexture("Assets\\meteor2r3.png");
	Texture2D meteor2r4 = LoadTexture("Assets\\meteor2r4.png");
	Texture2D Intro2 = LoadTexture("Assets\\Intro2.png");
	Texture2D menu = LoadTexture("Assets\\menu.png");


	Sound pregame = LoadSound("Assets\\Pregame.mp3");
	Sound shoish = LoadSound("Assets\\shoish.mp3");
	Sound taun = LoadSound("Assets\\Taun_Taun.mp3");


	//Variables for stages
	int screen = 0;
	//pre game
	char intro1[] = { "A huge meteor had fallen on Earth in an uninhabitated valley. It was out of inhabited lands, so no one paid attention\nto it. Little did they know, it emitted very slight radiations." };
	char intro2[] = { "\n\nHowever these radiations did not pose a threat, instead they bestowed very few chosen ones with unimaginable\nabillities, which were later named \"Anomalies\". At first, their appearances were non-existent, later they grew in enough\nnumbers to be visible to the curious eye. To avoid chaos, anomalies were kept a secret by governments worldwide.\n\n                  \"PRESS SPACE TO CONTINUE\"                   " };
	char intro3[] = { "The anomalies were inconsistent. Some caused gigantism, while some resulted in telekinesis. It happened irrespective\nof the person's will. Some cherished their gifts, some regretted their unfortunate lives, while some abused them.\nThe anomalous people, after absorbing the radiations due to their rare genetic molecular structure, released very\nweak but similar radiations of their own, which helped differentiate between normal and anomalous people. Consider it\nfate or coincidence, but people who released such radiations always seemed to attract each other. Aside the\nanomalies, the anomalous people were no different than the rest. Thus, they had their own paths, whether to live a\nquiet life, or make changes to the world.\n                  \"PRESS SPACE TO CONTINUE\"                   "};
	int intro1_counter = 1,intro1_text_delay=0, intro2_counter = 1, intro2text_delay = 0,pregamesoundtime=0, intro3_counter = 1,intro3text_delay=0;

	//Main Menu
	enum Menu
	{
		MAIN_MENU,
		NEW_GAME,
		LOAD_GAME
	};
	Menu current = MAIN_MENU;
	int option = 0, character = 0, slot = 0, taun_timer=0;
	char asif_intro[] = {"Anomaly : Electricity. He has exceptional\nneurons that can produce large\namount of electricity. He also\nhas amazing reflexes, agility and\nspeed"};
	char atif_intro[] = {"Anomaly : Fire Resistance. He is resistant\nto fire. While utilizing this,\nhe can also manipulate the element\nof fire. He can cover both short\nand far range combat"};


	SetTargetFPS(30);

	while (!WindowShouldClose())
	{

		/*--------------------------Update Phase--------------------------*/
		//Pre game
		if (screen == 0)
		{
			if (pregamesoundtime == 0)
			{
				PlaySound(pregame);
				pregamesoundtime++;
			}

			if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
			{
				screen = 1;
			}
		}
		else if (screen == 1)
		{
			if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
			{
				screen = 2;
			}
		}
		else if (screen == 2)
		{
			StopSound(pregame);
			if (taun_timer == 0)
			{
				PlaySound(taun);
				taun_timer++;
			}
			switch (current)
			{
			case MAIN_MENU:
				if (IsKeyPressed(KEY_UP))
				{
					PlaySound(shoish);
					option = (option - 1 + 2) % 2;
				}
				else if (IsKeyPressed(KEY_DOWN))
				{
					PlaySound(shoish);
					option = (option + 1) % 2;
				}

				if (IsKeyPressed(KEY_ENTER))
				{
					PlaySound(shoish);
					if (option == 0)
					{
						current = NEW_GAME;
					}
					else if (option == 1)
					{
						current = LOAD_GAME;
					}
					
				}
				break;
			case NEW_GAME:
				if (IsKeyPressed(KEY_UP))
				{
					PlaySound(shoish);
					character = (character - 1 + 2) % 2;
				}
				else if (IsKeyPressed(KEY_DOWN))
				{
					PlaySound(shoish);
					character = (character + 1) % 2;
				}

				if (IsKeyPressed(KEY_ENTER))
				{
					PlaySound(shoish);
					if (character == 0)
					{
						screen = 3;
					}
					else if (character == 1)
					{
						screen = 50;
					}
				}
				else if (IsKeyPressed(KEY_BACKSPACE))
				{
					current = MAIN_MENU;
				}
				break;
			case LOAD_GAME:
				if (IsKeyPressed(KEY_UP))
				{
					PlaySound(shoish);
					slot = (slot - 1 + 3) % 3;
				}
				else if (IsKeyPressed(KEY_DOWN))
				{
					PlaySound(shoish);
					slot = (slot + 1) % 3;
				}

				if (IsKeyPressed(KEY_ENTER))
				{
					PlaySound(shoish);
					if (slot == 0)
					{
						cout<<1<<"\n\n\n"<<1;
					}
					else if (slot == 1)
					{
						cout << 2 << "\n\n\n"<<2;
					}
					else if (slot == 2)
					{
						cout << 3 << "\n\n\n" << 3;
					}
				}
				else if (IsKeyPressed(KEY_BACKSPACE))
				{
					current = MAIN_MENU;
				}
				break;
			default:
				break;
			}
		}
		else if (screen == 3)
		{
			cout << 3333333 << endl << endl << endl;
		}
		else if (screen == 50)
		{
			cout << 505050505050 << endl << endl << endl;
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
			DrawTexture(Intro2, 0, 0, WHITE);
			DrawText(TextSubtext(intro3, 0, intro3_counter), 50, 710, 20, WHITE);
			intro3text_delay++;
			if (intro3text_delay == 2)
			{
				intro3_counter++;
				intro3text_delay=0;
			}
		}

		else if (screen == 2)
		{
			DrawTexture(menu, 800, 370, WHITE);
			switch (current)
			{
			case MAIN_MENU:
				DrawText("Main Menu", 275, 10, 150, YELLOW);
				DrawText(TextFormat("   New Game"), 275, 400, 50, option == 0 ? RED : DARKGRAY);
				DrawText(TextFormat("   Load Game"), 275, 500, 50, option == 1 ? RED : DARKGRAY);
				break;

			case NEW_GAME:
				DrawText("Character Select :", 200, 100, 100, RED);
				DrawText(TextFormat("   Asif"), 275, 300, 50, character == 0 ? YELLOW : DARKGRAY);
				if (character == 0)
				{
					DrawText(TextSubtext(asif_intro, 0 ,strlen(asif_intro)), 200, 660, 30, BLUE);
				}
				DrawText(TextFormat("   Atif"), 275, 600, 50, character == 1 ? ORANGE : DARKGRAY);
				if (character == 1)
				{
					DrawText(TextSubtext(atif_intro, 0, strlen(atif_intro)), 200, 660, 30, VIOLET);
				}
				break;

			case LOAD_GAME:
				DrawText("Load Game", 200, 150, 150, ORANGE);
				DrawText(TextFormat("   Slot 1"), 275, 400, 50, slot == 0 ? PINK : DARKGRAY);
				DrawText(TextFormat("   Slot 2"), 275, 500, 50, slot == 1 ? PINK : DARKGRAY);
				DrawText(TextFormat("   Slot 3"), 275, 600, 50, slot == 2 ? PINK : DARKGRAY);
				break;

			default:
				break;
			}
		}
		else if (screen == 3)
		{

		}
		else if (screen == 50)
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
	UnloadTexture(Intro2);
	UnloadTexture(menu);

	UnloadSound(pregame);
	UnloadSound(shoish);
	UnloadSound(taun);


	CloseWindow();
	CloseAudioDevice();
}