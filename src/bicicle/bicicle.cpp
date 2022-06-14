#include "bicicle.h"

Bicicle::Bicicle()
{
    // Modelando os pedais da bicicleta
    auto pedalCircle = new ObjectPart(3, 3, Vector2(-1.5, -60), 0, 40);
    auto pedal1 = new ObjectPart(30, 1, Vector2(0, -60), 0, 4);
    auto pedal2 = new ObjectPart(30, 1, Vector2(0, -60), 0, 4);

    // Modelando o quadro da bicicleta
    auto bar = new ObjectPart(80, 2, Vector2(-20, -60), 180, 4);
    auto bar2 = new ObjectPart(105, 2, Vector2(40, 0), 180 + 30, 4);
    auto bar3 = new ObjectPart(60, 2, Vector2(35, -50), 70, 4);
    auto bar4 = new ObjectPart(90, 2, Vector2(25, 0), -90, 4);
    auto bar5 = new ObjectPart(100, 2, Vector2(-45, -50), 30, 4);
    auto bar6 = new ObjectPart(80, 2, Vector2(50, 0), -105, 4);
    auto bar7 = new ObjectPart(40, 2, Vector2(-40, 0), 180, 4);
    auto bar8 = new ObjectPart(30, 2, Vector2(20, 0), 90, 4);

    // Rodas
    circleWheel1 = new Polygon2d(40);
    circleWheel1->translate(110, -60);
    circleWheel1->scale(60, 60);

    circleWheel2 = new Polygon2d(40);
    circleWheel2->translate(-100, -60);
    circleWheel2->scale(60, 60);

    radiusWheel1.push_back(new ObjectPart(60, 1, Vector2(-100, -60), 0, 4));
    radiusWheel2.push_back(new ObjectPart(60, 1, Vector2(110, -60), 0, 4));

    for (int i = 0; i < 7; i++)
    {
        radiusWheel1.push_back(new ObjectPart(60, 1, Vector2(-30, 0), (i + 1) * 45, 4));
        radiusWheel2.push_back(new ObjectPart(60, 1, Vector2(-30, 0), (i + 1) * 45, 4));
    }

    parts = {pedalCircle, pedal1, pedal2};
    frame = {bar, bar2, bar3, bar4, bar5, bar6, bar7, bar8};
}

void Bicicle::drawJoint(vector<ObjectPart *> parts)
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

void Bicicle::draw()
{
    circleWheel2->draw();
    circleWheel1->draw();
    drawJoint(radiusWheel1);
    drawJoint(radiusWheel2);
    drawJoint(frame);
    for (auto part : parts)
    {
        part->draw();
    }
}