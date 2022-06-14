#include "stickman.h"
#include "../utils/Utils.h"

Stickman::Stickman()
{
    // Modelagem da cabeça e dos braços
    ObjectPart *head = new ObjectPart(8, 8, Vector2(10, 120), 0, 20);
    ObjectPart *body = new ObjectPart(100, 1, Vector2(-10, 0), 80, 4);

    parts = {head, body};

    // Modelagem dos pernas
    ObjectPart *femur1 = new ObjectPart(50, 1, Vector2(-10, 0), 0, 4);
    ObjectPart *tibia1 = new ObjectPart(50, 1, Vector2(25, 0), 0, 4);

    leg1 = {femur1, tibia1};

    ObjectPart *femur2 = new ObjectPart(50, 1, Vector2(-10, 0), 0, 4);
    ObjectPart *tibia2 = new ObjectPart(50, 1, Vector2(25, 0), 0, 4);

    leg2 = {femur2, tibia2};
}

void Stickman::drawJoint(vector<ObjectPart *> parts)
{
    vector<Matrix> tmpStack;

    for (auto part : parts)
    {
        if (!tmpStack.empty())
        {
            part->wtransform(tmpStack.back());
        }
        part->draw();
        tmpStack.push_back(part->localTransformation);
    }
}

void Stickman::draw()
{
    // Desnhando o braço como uma curva de bezier
    Utils::bezierCurve(Vector2(4, 70), Vector2(10, 30), Vector2(40, 35));
    Utils::bezierCurve(Vector2(4, 80), Vector2(15, 40), Vector2(50, 40));
    drawJoint(leg1);
    drawJoint(leg2);
    for (auto part : parts)
    {
        part->draw();
    }
}