#include <iostream>
#include "GUI.h"
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
    polygon = new Polygon2d(4);
}

/* Renderiza/desenha tudo que sera necessario na tela
 */
void GUI::Render()
{
    CV::color(0, 0, 0);
    polygon->draw();
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
    case 43:
        polygon->width += 10;
        polygon->height += 10;
        break;
    case 45:
        polygon->width -= 10;
        polygon->height -= 10;
        break;
    case 61:
        polygon->angle += 10 * PI / 180;
        break;
    case 200:
        polygon->positionX -= 10;
        break;
    case 201:
        polygon->positionY += 10;
        break;
    case 202:
        polygon->positionX += 10;
        break;
    case 203:
        polygon->positionY -= 10;
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
