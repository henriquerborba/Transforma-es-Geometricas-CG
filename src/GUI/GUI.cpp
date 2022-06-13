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
}

/* Renderiza/desenha tudo que sera necessario na tela
 */
void GUI::Render()
{
    CV::translate(GUI::getScreenWidth() / 2, GUI::getScreenHeight() / 2);
    CV::color(0, 0, 0);
    CV::line(0, -GUI::screenHeight / 2, 0, GUI::screenHeight / 2);
    CV::line(-GUI::screenWidth / 2, 0, GUI::screenWidth / 2, 0);
    stickman->draw();
    // stickman->parts[1]->wtransform(Matrix::scale(100, 1));
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
