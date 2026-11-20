#include "raylib.h"
#include "menu.h"

typedef struct {
    char name[20];
    int score;
} Player;

Player topScores[5] = {
 { "Player 1", 0 },
 { "Player 2", 0 },
 { "Player 3", 0 },
 { "Player 4", 0 },
 { "Player 5", 0 },
};
Rectangle startButton = {300, 250, 200, 60};
Rectangle scoreButton = {300, 350, 200, 60};


void UpdateMenu(GameScreen *currentScreen)
{
    Vector2 mouse = GetMousePosition();

    if (CheckCollisionPointRec(mouse, startButton) &&
        IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        *currentScreen = GAMEPLAY;
    }
    else if (CheckCollisionPointRec(mouse, scoreButton) &&
        IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        *currentScreen = SCORESCREEN;
    }
}

void DrawMenu(void)
{
    DrawRectangle(10, 10, 780, 580, GRAY);
    DrawText("TITLE", 300, 140, 40, WHITE);

    DrawRectangleRec(startButton, DARKGRAY);
    DrawText("START", 350, 265, 25, WHITE);

    DrawRectangleRec(scoreButton, DARKGRAY);
    DrawText("SCORES", scoreButton.x + 55, 365, 25, WHITE);
}

void ShowScores(void)
{
    DrawRectangle(10, 10, 780, 580, GRAY);
    DrawText("TOP SCORES", 350, 100, 20, WHITE);
    DrawText("Rank", 100, 150, 20, WHITE);
    DrawText("Score", 650, 150, 20, WHITE);
    for (int i = 0; i < 5; i++) {
            switch (i) {
            case 0:
                DrawText(topScores[i].name, 100, 200 + (i*50) , 25, GOLD);
                DrawText(TextFormat("%d", topScores[i].score), 650, 200 + (i*50), 25, GOLD);
                break;
            case 1:
                DrawText(topScores[i].name, 100, 200 + (i*50) , 25, LIGHTGRAY);
                DrawText(TextFormat("%d", topScores[i].score), 650, 200 + (i*50), 25, LIGHTGRAY);
                break;
            case 2:
                DrawText(topScores[i].name, 100, 200 + (i*50) , 25, BROWN);
                DrawText(TextFormat("%d", topScores[i].score), 650, 200 + (i*50), 25, BROWN);
                break;
            default:
                DrawText(topScores[i].name, 100, 200 + (i*50) , 25, WHITE);
                DrawText(TextFormat("%d", topScores[i].score), 650, 200 + (i*50), 25, WHITE);
            };

    }

}

