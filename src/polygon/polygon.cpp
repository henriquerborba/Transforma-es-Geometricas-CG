#include "polygon.h"
#include "../canvas/gl_canvas2d.h"
#include "../utils/utils.h"

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
                product[row] += mtransformation[row][col] * mpoints[col];
            }
        }

        aux[i].set(product[0], product[1]);
    }

    // reseta a matriz transformação
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            mtransformation[row][col] = 0;
            if (row == col)
                mtransformation[row][col] = 1;
        }
    }

    for (int i = 0; i < aux.size(); i++)
    {
        CV::color(0, 0, 0);
        CV::line(aux[i], aux[(i + 1) % aux.size()]);
    }
}

void Polygon2d::scale()
{
    float product[3][3];

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            product[row][col] = 0;
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 3; inner++)
            {
                product[row][col] += mtransformation[row][inner] * mscale[inner][col];
            }
        }
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            mtransformation[row][col] = product[row][col];
        }
    }
}

void Polygon2d::rotate()
{
    float product[3][3];

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            product[row][col] = 0;
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 3; inner++)
            {
                product[row][col] += mtransformation[row][inner] * mrotate[inner][col];
            }
        }
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            mtransformation[row][col] = product[row][col];
        }
    }
}

void Polygon2d::translate()
{
    Utils::multplyMatrix((float **)mtransformation, (float **)mtranslate, 3, 3, 3);
    // float product[3][3];

    // for (int row = 0; row < 3; row++)
    // {
    //     for (int col = 0; col < 3; col++)
    //     {
    //         product[row][col] = 0;
    //         // Multiply the row of A by the column of B to get the row, column of product.
    //         for (int inner = 0; inner < 3; inner++)
    //         {
    //             product[row][col] += mtransformation[row][inner] * mtranslate[inner][col];
    //         }
    //     }
    // }

    // for (int row = 0; row < 3; row++)
    // {
    //     for (int col = 0; col < 3; col++)
    //     {
    //         mtransformation[row][col] = product[row][col];
    //     }
    // }
}

void Polygon2d::transform()
{
    setTranslation(tx, ty);
    setRotation(degrees);
    setScale(sx, sy);
    translate();
    scale();
    rotate();
}

void Polygon2d::setRotation(float angle)
{
    this->degrees = angle;
    mrotate[0][0] = cos(angle);
    mrotate[0][1] = -sin(angle);
    mrotate[1][0] = sin(angle);
    mrotate[1][1] = cos(angle);
}

void Polygon2d::setScale(float x, float y)
{
    this->sx = x;
    this->sy = y;
    mscale[0][0] = x;
    mscale[1][1] = y;
}

void Polygon2d::setTranslation(float x, float y)
{
    this->tx = x;
    this->ty = y;
    mtranslate[0][2] = x;
    mtranslate[1][2] = y;
}
