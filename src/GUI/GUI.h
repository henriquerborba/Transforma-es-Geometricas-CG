#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include "../polygon/polygon.h"

class GUI
{
private:
    int mx, my;        // variaveis do mouse para poder exibir dentro da render().
    float aspectRatio; // aspect ratio da tela.

public:
    int screenWidth, screenHeight;
    Polygon2d *polygon;
    GUI();
    ~GUI();
    void InitCanvas();
    void Render();
    void Keyboard(int key);
    void Mouse(int x, int y, int state);
};

#endif // GUI_H_INCLUDED
