#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include "../polygon/polygon.h"
#include "../stickman/stickmanPart/stickmanPart.h"

class GUI
{
private:
    int mx, my; // variaveis do mouse para poder exibir dentro da render().
    int screenWidth, screenHeight;
    GUI();
    GUI(const GUI &) = delete;
    static GUI instance;

public:
    static GUI &getInstance() { return instance; }
    static int getScreenWidth() { return instance.screenWidth; }
    static int getScreenHeight() { return instance.screenHeight; }
    StickmanPart *stickmanPart;
    StickmanPart *stickmanPart2;

    void InitCanvas();
    void Render();
    void Keyboard(int key);
    void Mouse(int x, int y, int state);
};

#endif // GUI_H_INCLUDED
