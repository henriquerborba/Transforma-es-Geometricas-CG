#ifndef UfloatILS_H_INCLUDED
#define UfloatILS_H_INCLUDED

#include "../canvas/gl_canvas2d.h"
class Utils
{
public:
    /*
        Desenha uma curva dados 3 pontos.
    */
    static void bezierCurve(Vector2 p1, Vector2 p2, Vector2 p3)
    {
        for (float t = 0; t < 1; t += 0.001)
        {
            float xt = p1.x * (1 - t) * (1 - t) + p2.x * (2 * t * (1 - t)) + p3.x * t * t;
            float yt = p1.y * (1 - t) * (1 - t) + p2.y * (2 * t * (1 - t)) + p3.y * t * t;
            CV::point(xt, yt);
        }
    }

    /*
        * Função que dado dois pontos liga os dois pontos com dois segmentos de tamanho "size" e retorna os angulos de referencia entre os segmentos
        @param p1: primeiro ponto
        @param p2: segundo ponto
        @param size: tamanho do segmento
        @return: angulo entre o primeiro segmento e o a abicissa e angulo entre o primeiro e segundo segmento
    */
    static Vector2 getAngle(Vector2 p1, Vector2 p2, float size)
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
};

#endif
