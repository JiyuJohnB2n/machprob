#ifndef MENU_H
#define MENU_H

typedef enum GameScreen
{
    MENU,
    SCORESCREEN,
    GAMEPLAY
} GameScreen;

void UpdateMenu(GameScreen *currentScreen);
void DrawMenu(void);
void ShowScores(void);

#endif
