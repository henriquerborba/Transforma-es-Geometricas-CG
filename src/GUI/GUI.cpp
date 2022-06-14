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
    Sleep(1 / fps * 600);
    circle->draw();
    CV::clear(255, 255, 255);
    // Direciona o eixo para o centro da viewport
    CV::translate(GUI::getScreenWidth() / 2, GUI::getScreenHeight() / 2);
    CV::color(0, 0, 0);

    // Desenha o eixo cartesiano para referencia
    // CV::line(0, -GUI::screenHeight / 2, 0, GUI::screenHeight / 2);
    // CV::line(-GUI::screenWidth / 2, 0, GUI::screenWidth / 2, 0);

    // Desenha o stickman
    if (i == 0)
    {
        i = circle->transformedVertices.size();
    }
    i--;
    Vector2 leg1Angles = getAngle(stickman->leg1[0]->pivot, circle->transformedVertices[i], stickman->leg1[0]->width);
    Vector2 leg2Angles = getAngle(stickman->leg1[0]->pivot, circle->transformedVertices[(i + 50 < circle->transformedVertices.size()) ? i + 50 : i - 50], stickman->leg1[0]->width);
    stickman->draw();
    stickman->leg1[0]->rotation = leg1Angles.x;
    stickman->leg1[1]->rotation = -180 + leg1Angles.y;
    stickman->leg2[0]->rotation = leg2Angles.x;
    stickman->leg2[1]->rotation = -180 + leg2Angles.y;

    Vector2 diff = Vector2(0, -60) - stickman->leg1[1]->polygon->transformedVertices[0];
    printf("%f, %f\n", diff.x, diff.y);
    float angle = diff.getAngle();

    // Desenha a bicicleta
    bicicle->draw();
    bicicle->parts[1]->rotation = angle;
    bicicle->parts[2]->rotation = angle + 180;
    bicicle->radiusWheel1[0]->rotation = angle;
    bicicle->radiusWheel2[0]->rotation = angle;
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

    float ang1 = 180 - ang2 - 90;

    ang1 = diff.getAngle() + ang1;

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
