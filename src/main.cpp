#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.
#include "GUI/GUI.h"
#include <iostream>

using namespace std;

GUI GUI::instance;

GUI &gui = GUI::getInstance();

// funcao chamada guiinuamente. Deve-se guirolar o que desenhar por meio de variaveis globais
// Todos os comandos para desenho na canvas devem ser chamados dentro da render().
// Deve-se manter essa fun��o com poucas linhas de codigo.
void render()
{
   gui.Render();
}

// funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   gui.Keyboard(key);
}

// funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   cout << "\nLiberou: " << key << endl;
}

// funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   gui.Mouse(x, y, state);
}

int main(int argc, char *argv[])
{
   gui.InitCanvas();
}
