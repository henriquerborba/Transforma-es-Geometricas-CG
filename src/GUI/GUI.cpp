#include <iostream>
#include "GUI.h"
#include "../Canvas/gl_canvas2d.h"
#include "../polygon/polygon.h"

using namespace std;

/* Inicia os atributos necessarios
 */
GUI::GUI()
{
    screenWidth = 1366;
    screenHeight = 768;
    stickman = new Stickman();
    circle2 = new ObjectPart(12, 12, Vector2(-6, -200), 0, 40);
    circle = new Polygon2d(100);
    circle->translate(0, -100);
    circle->scale(40, 40);
}

/* Renderiza/desenha tudo que sera necessario na tela
 */
void GUI::Render()
{
    Sleep(10);
    CV::translate(GUI::getScreenWidth() / 2, GUI::getScreenHeight() / 2);
    CV::color(0, 0, 0);
    CV::line(0, -GUI::screenHeight / 2, 0, GUI::screenHeight / 2);
    CV::line(-GUI::screenWidth / 2, 0, GUI::screenWidth / 2, 0);
    circle->draw();
    if (i == 0)
    {
        i = circle->transformedVertices.size();
    }
    i--;
    Vector2 angles = getAngle(stickman->parts[0]->pivot, circle->transformedVertices[i], 100);
    stickman->draw();
    stickman->parts[0]->rotation = angles.x;
    stickman->parts[1]->rotation = -180 + angles.y;
}

/*
    @param p1: primeiro ponto do segmento
    @param p2: segundo ponto do segmento
    @param size: tamanho do segmento
    @return: angulo do segmento
*/
Vector2 GUI::getAngle(Vector2 p1, Vector2 p2, float size)
{
    Vector2 diff = p2 - p1;
    float b = diff.module();
    float hip = size;

    float ang2 = asin((b / 2) / hip);
    ang2 = ang2 * 180 / M_PI;
    // printf("%f\n", ang2);
    float ang1 = 180 - ang2 - 90;
    // printf("%f\n", diff.getAngle());
    // printf("%f\n", ang1);
    ang1 = diff.getAngle() + ang1;
    printf("%f\n", ang1);
    ang2 = 2 * ang2;

    return Vector2(ang1, ang2);
}

/* Controla as teclas apertadas durante a execucao
   @param key: inteiro equivalente a tecla apertada
*/
void GUI::Keyboard(int key)
{
    cout << "Tecla: " << key << endl;
    switch (key)
    {
    case 27:
        exit(0);
        break;
    // seta para cima
    case 201:
        break;
    // seta para o lado esquerdo
    case 200:
        break;
    // seta para baixo
    case 203:
        break;
    // seta para o lado direito
    case 202:
        break;
    }
}

/* Controla a posicao do mouse e se houve clique ou nao
   @param x: coordenada x do mouse
   @param y: coordenada y do mouse
   @param state: estado do mouse (clicado ou nao)
*/
void GUI::Mouse(int x, int y, int state)
{
    mx = x; // guarda as coordenadas do mouse para exibir dentro da render()
    my = y;
}

/* Inicia a canvas
 */
void GUI::InitCanvas()
{
    CV::init(&screenWidth, &screenHeight, "T3 - Henrique Rodrigues de Borba");
    CV::run();
}
