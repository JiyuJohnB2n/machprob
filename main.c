#include "raylib.h"
#include "menu.h"
#include "lane.h"


int main(void)
{
    InitWindow(700, 700, "game");
    SetTargetFPS(60);

    lane lanes[LANE_COUNT];

    GameScreen currentScreen = MENU;

    while (!WindowShouldClose())
    {
        if (currentScreen == MENU)
        {
            UpdateMenu(&currentScreen);
        }
        else if(currentScreen == SCORESCREEN)
        {
             if (IsKeyPressed(KEY_ESCAPE))
            {
                currentScreen = MENU;
            }
        }
        else if (currentScreen == GAMEPLAY)
        {
            if (IsKeyPressed(KEY_ESCAPE))
            {
                currentScreen = MENU;
            }
        }


        BeginDrawing();

        ClearBackground(BLACK);

        switch (currentScreen)
        {
            case MENU:
                DrawMenu();
                break;

            case SCORESCREEN:
                ShowScores();
                break;

            case GAMEPLAY:
                ClearBackground(WHITE);
                InitLane(lanes);
                DrawLane(lanes);
                break;

        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
