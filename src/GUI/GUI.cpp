#include <iostream>
#include "GUI.h"
#include "../Canvas/gl_canvas2d.h"
#include "../polygon/polygon.h"

using namespace std;

/* Inicia os atributos necessarios
 */
GUI::GUI()
{
    screenWidth = 1368;
    screenHeight = 768;

    background = new Bmp("Trabalho3_Henrique_Borba/background.bmp", 0, 0);
    background->convertBGRtoRGB();
    background2 = new Bmp("Trabalho3_Henrique_Borba/background.bmp", 1367, 0);
    background2->convertBGRtoRGB();
    stickman = new Stickman();
    bicicle = new Bicicle();

    // Circulo que direciona a rotação dos pedais
    circle = new Polygon2d(100);
    circle->translate(0, -60);
    circle->scale(30, 30);
}

/* Renderiza/desenha tudo que sera necessario na tela
 */
void GUI::Render()
{
    fps = frames->getFrames();
    char fps_char[10];
    sprintf(fps_char, "FPS: %.0f", fps);
    CV::color(0, 0, 0);
    CV::text(screenWidth - 100, screenHeight - 30, fps_char);
    circle->draw();
    CV::clear(255, 255, 255);

    background->render(0, 0, 0);
    background2->render(0, 0, 0);
    background->x -= 1;
    background2->x -= 1;
    if (background->x < -1367)
        background->x = 1366;
    if (background2->x < -1367)
        background2->x = 1367;

    // Direciona o eixo para o centro da viewport
    CV::translate(GUI::getScreenWidth() / 2, (GUI::getScreenHeight() / 2) - 100);
    CV::color(0, 0, 0);

    // Desenha o stickman
    if (i == 0)
    {
        i = circle->transformedVertices.size();
    }
    i--;
    Vector2 leg1Angles = Utils::getAngle(stickman->leg1[0]->pivot, circle->transformedVertices[i], stickman->leg1[0]->width);
    Vector2 leg2Angles = Utils::getAngle(stickman->leg1[0]->pivot, circle->transformedVertices[(i + 50 < circle->transformedVertices.size()) ? i + 50 : i - 50], stickman->leg1[0]->width);
    stickman->draw();
    stickman->leg1[0]->rotation = leg1Angles.x;
    stickman->leg1[1]->rotation = -180 + leg1Angles.y;
    stickman->leg2[0]->rotation = leg2Angles.x;
    stickman->leg2[1]->rotation = -180 + leg2Angles.y;

    Vector2 diff = Vector2(0, -60) - stickman->leg1[1]->polygon->transformedVertices[0];
    float angle = diff.getAngle();

    // Desenha a bicicleta
    bicicle->draw();
    bicicle->parts[1]->rotation = angle;
    bicicle->parts[2]->rotation = angle + 180;
    bicicle->radiusWheel1[0]->rotation = angle;
    bicicle->radiusWheel2[0]->rotation = angle;
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
