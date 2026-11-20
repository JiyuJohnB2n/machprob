#include "raylib.h"
#include "menu.h"

Color CYAN = (Color){0, 255, 255, 255};

int main(void)
{
    InitWindow(800, 600, "game");
    SetTargetFPS(60);

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
                DrawText("GAMEPLAY SCREEN", 250, 250, 30, WHITE);
                DrawText("Press ESC to return", 280, 300, 20, LIGHTGRAY);
                break;

        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
