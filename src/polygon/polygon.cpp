#include "polygon.h"
#include "../canvas/gl_canvas2d.h"
#include "../utils/utils.h"
#include "../GUI/GUI.h"

Polygon2d::Polygon2d(int n)
{
    float start = n % 2 == 1 ? PI / 2 : PI / n;
    float offset = PI_2 / n;
    for (int i = 0; i < n; i++)
    {
        float angle = start + offset * i;
        float x = cos(angle);
        float y = sin(angle);
        this->vertices.push_back(Vector2(x, y));
    }
    rotate(90);
    translate(GUI::getScreenWidth() / 2, GUI::getScreenHeight() / 2);
    scale(100, 100);
}

Polygon2d::~Polygon2d()
{
    // dtor
}

void Polygon2d::draw()
{
    transform();
    vector<Vector2> aux = vertices;

    // aplica a transformação em cada um dos pontos e salva na variavel aux
    float product[3];
    for (int i = 0; i < aux.size(); i++)
    {
        aux[i] = mtransformation * aux[i];
    }

    mtransformation = Matrix::createIdentity(3);

    for (int i = 0; i < aux.size(); i++)
    {
        CV::color(0, 0, 0);
        CV::line(aux[i], aux[(i + 1) % aux.size()]);
        // printf("%f %f\n", aux[i].x, aux[i].y);
    }
}

void Polygon2d::scale(float width, float height)
{
    this->width = width;
    this->height = height;
    mscale = Matrix::scale(this->width, this->height);
    mtransformation *= mscale;
}

void Polygon2d::rotate(float angle)
{
    this->angle = angle;
    mrotate = Matrix::rotate(angle);
    mtransformation *= mrotate;
}

void Polygon2d::translate(float positionX, float positionY)
{
    this->positionX = positionX;
    this->positionY = positionY;
    mtranslate = Matrix::translate(positionX, positionY);
    mtransformation *= mtranslate;
}

void Polygon2d::addTransformation(Matrix m = Matrix::createIdentity(3))
{
    mtransformation *= m;
}

void Polygon2d::transform()
{
    translate(positionX, positionY);
    rotate(angle);
    scale(width, height);
    addTransformation();
}