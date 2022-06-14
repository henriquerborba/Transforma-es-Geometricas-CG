#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include "../polygon/polygon.h"
#include "../stickman/stickman.h"
#include "../ObjectPart/ObjectPart.h"
#include "../bicicle/bicicle.h"
#include "../Frames/Frames.h"
#include "../utils/Utils.h"
#include "../bmp/bmp.h"

class GUI
{
private:
    int mx, my; // variaveis do mouse para poder exibir dentro da render().
    int screenWidth, screenHeight;
    GUI();
    GUI(const GUI &) = delete;
    static GUI instance;
    Bicicle *bicicle;
    Stickman *stickman;
    Frames *frames = new Frames();
    float fps = 100;

public:
    static GUI &getInstance() { return instance; }
    static int getScreenWidth() { return instance.screenWidth; }
    static int getScreenHeight() { return instance.screenHeight; }

    Bmp *background;
    Bmp *background2;

    Polygon2d *circle;
    ObjectPart *circle2;

    int i;

    void InitCanvas();
    void Render();
    void Keyboard(int key);
    void Mouse(int x, int y, int state);
};

#endif // GUI_H_INCLUDED
