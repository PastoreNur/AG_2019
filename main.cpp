//movimiento en tierra

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdlib.h>
#include <math.h>
#include "include/Edificios/Edificios.h"
#include "include/Fisicas/Fisicas.h"


// variables que representan direccion de la camara
float lx=1.0f,lz=0.0f;
// XZ posicion de la camara
float x=-100.0f,z=0.0f;

// angulo de rotación
float angulo = 90.0f;


void camara(int w, int h)
{

// Evitar una división por cero, cuando la ventana es demasiado pequeña
// (No permitir una ventana de alto 0).
    if (h == 0)
        h = 1;
    float proporcion = w * 1.0 / h*2;

// Usando Matrix proyección
    glMatrixMode(GL_PROJECTION);

// Reseteando la Matrix
    glLoadIdentity();

// configurar el viewport para una ventana completa
    glViewport(0, 0, w, h);

// Configurando las perspectivas.
    gluPerspective(45.0f, proporcion, 0.1f, 100.0f);

// Regresar la vista a Modelview
    glMatrixMode(GL_MODELVIEW);
}

void escena(void)
{
    // Borrar Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Reseteando transformaciones
    glLoadIdentity();
    // Configurando camara
    gluLookAt(	x, 1.0f, z,
                  x+lx, 1.0f, z+lz,
                  0.0f, 1.0f, 0.0f);


//######################################################
//######################################################
//######################################################
//######################################################
//######################################################
//INPLEMENTACIOS DE EDIFICIOS
    e_suelo();
    e_callep();
    e_parqueo1();
    e_calleparqueo1();
    e_acera1();
//######################################################
//######################################################
//######################################################
//######################################################
//######################################################
//INPLEMENTACIOS DE FISICAS



    glutSwapBuffers();
}

void salir(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

void keyboard(int key, int xx, int yy)
{
    float fraccion = 0.1f;

    switch (key) {
        case GLUT_KEY_LEFT :
            angulo -= 0.01f;
            lx = sin(angulo);
            lz = -cos(angulo);
            break;
        case GLUT_KEY_RIGHT :
            angulo += 0.01f;
            lx = sin(angulo);
            lz = -cos(angulo);
            break;
        case GLUT_KEY_UP :
            x += lx * fraccion;
            z += lz * fraccion;
            break;
        case GLUT_KEY_DOWN :
            x -= lx * fraccion;
            z -= lz * fraccion;
            break;
    }
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("el terreno");

    // register callbacks
    glutDisplayFunc(escena);
    glutReshapeFunc(camara);
    glutIdleFunc(escena);
    glutKeyboardFunc(salir);
    glutSpecialFunc(keyboard);

    // OpenGL init
    glEnable(GL_DEPTH_TEST);
    //Para texturas
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutMainLoop();
    return 1;
}
