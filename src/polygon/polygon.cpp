#include "polygon.h"
#include "../canvas/gl_canvas2d.h"
#include "../utils/utils.h"
#include "../GUI/GUI.h"

Polygon2d::Polygon2d(int n)
{
    rotate(PI_2);
    translate(GUI::getScreenWidth() / 2, GUI::getScreenHeight() / 2);
    scale(100, 100);
    float start = n % 2 == 1 ? PI / 2 : PI / n;
    float offset = PI_2 / n;
    for (int i = 0; i < n; i++)
    {
        float angle = start + offset * i;
        float x = cos(angle);
        float y = sin(angle);
        this->vertices.push_back(Vector2(x, y));
    }
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
        float mpoints[3] = {aux[i].x, aux[i].y, 1};
        for (int row = 0; row < 3; row++)
        {
            product[row] = 0;
            for (int col = 0; col < 3; col++)
            {
                product[row] += mtransformation(row, col) * mpoints[col];
            }
        }

        aux[i].set(product[0], product[1]);
    }

    mtransformation = Matrix::createIdentity(3);

    for (int i = 0; i < aux.size(); i++)
    {
        CV::color(0, 0, 0);
        CV::line(aux[i], aux[(i + 1) % aux.size()]);
    }
}

void Polygon2d::scale(float width, float height)
{
    this->width = width;
    this->height = height;
    mscale(0, 0) = width;
    mscale(1, 1) = height;
    mtransformation *= mscale;
}

void Polygon2d::rotate(float angle)
{
    this->angle = angle;
    mrotate(0, 0) = cos(angle);
    mrotate(0, 1) = -sin(angle);
    mrotate(1, 0) = sin(angle);
    mrotate(1, 1) = cos(angle);
    mtransformation *= mrotate;
}

void Polygon2d::translate(float positionX, float positionY)
{
    this->positionX = positionX;
    this->positionY = positionY;
    mtranslate(0, 2) = positionX;
    mtranslate(1, 2) = positionY;
    mtransformation *= mtranslate;
}

void Polygon2d::transform()
{
    translate(positionX, positionY);
    scale(width, height);
    rotate(angle);
}