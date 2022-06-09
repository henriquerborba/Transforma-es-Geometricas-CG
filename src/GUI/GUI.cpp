#include <iostream>
#include "GUI.h"
#include "../Canvas/gl_canvas2d.h"
#include "../polygon/polygon.h"
#include "../stickman/stickmanPart/stickmanPart.h"

using namespace std;

/* Inicia os atributos necessarios
 */
GUI::GUI()
{
    screenWidth = 1366;
    screenHeight = 768;
    stickmanPart = new StickmanPart(200, 1, Vector2(0, 100), 30, 4);
    stickmanPart2 = new StickmanPart(200, 1, Vector2(200, 100), 30, 4);
}

/* Renderiza/desenha tudo que sera necessario na tela
 */
void GUI::Render()
{
    CV::translate(GUI::getScreenWidth() / 2, GUI::getScreenHeight() / 2);
    CV::color(0, 0, 0);
    CV::line(0, -GUI::screenHeight / 2, 0, GUI::screenHeight / 2);
    CV::line(-GUI::screenWidth / 2, 0, GUI::screenWidth / 2, 0);
    stickmanPart->draw();
    stickmanPart2->draw();
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
    case 201:
        stickmanPart->rotation += 1;
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
