#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include "../polygon/polygon.h"
#include "../stickman/stickman.h"
#include "../ObjectPart/ObjectPart.h"

class GUI
{
private:
    int mx, my; // variaveis do mouse para poder exibir dentro da render().
    int screenWidth, screenHeight;
    GUI();
    GUI(const GUI &) = delete;
    static GUI instance;

    Stickman *stickman;

public:
    static GUI &getInstance() { return instance; }
    static int getScreenWidth() { return instance.screenWidth; }
    static int getScreenHeight() { return instance.screenHeight; }

    Polygon2d *circle;
    ObjectPart *circle2;

    int i;
    Vector2 getAngle(Vector2 p1, Vector2 p2, float size);

    void InitCanvas();
    void Render();
    void Keyboard(int key);
    void Mouse(int x, int y, int state);
};

#endif // GUI_H_INCLUDED
