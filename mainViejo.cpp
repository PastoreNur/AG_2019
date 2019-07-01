//movimiento en tierra

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdlib.h>
#include <math.h>
#include "include/Edificios/Edificios.h"
#include "include/Fisicas/Fisicas.h"
#include <SDL2/SDL.h>


// variables que representan direccion de la camara
float lx=1.0f,lz=0.0f;
// XZ posicion de la camara
float x=-100.0f,z=0.0f;

// angulo de rotación
float angulo = 90.0f;


//para LSD
//audio a reproducir dentro de la carpeta del Cmake-build-debug
#define RUTA_AUDIO ""

// variables para audio
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play

void my_audio_callback(void *userdata, Uint8 *stream, int len) {

    if (audio_len == 0)
        return;

    len = (len > audio_len ? audio_len : len);

    SDL_memcpy(stream, audio_pos, len); // Simplemente copie desde un buffer en el otro
    //SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME / 2); // Mezclar de un buffer a otro

    audio_pos += len;
    audio_len -= len;
}


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
    SDL_PauseAudio(false);
    e_suelo();
    e_callep();
    e_parqueo1();
    e_calleparqueo1();
    e_acera1();
    e_acera2();
    e_suelop();
    e_acerapp();
    e_calleparqueo2();
    e_parqueo2();
    e_suelos();

    edificio1();
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
    float fraccion = 0.5f;

    switch (key) {
        case GLUT_KEY_LEFT :
            angulo -= 0.1f;
            lx = sin(angulo);
            lz = -cos(angulo);
            break;
        case GLUT_KEY_RIGHT :
            angulo += 0.1f;
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

    // sonido
    // Inicializar SDL.
    if (SDL_Init(SDL_INIT_AUDIO) < 0){

    }


    // Variables locales
    static Uint32 wav_length; // Longitud de nuestra muestra
    static Uint8 *wav_buffer; // Buffer que contiene nuestro archivo de audio
    static SDL_AudioSpec wav_spec; // Las especificaciones de nuestra pieza de música

    /* Cargar el WAV */
    // Las especificaciones, la longitud y el búfer de nuestro wav se llenan
    if( SDL_LoadWAV(RUTA_AUDIO, &wav_spec, &wav_buffer, &wav_length) == NULL )
    {

    }
    // Establecer la función de devolución de llamada
    wav_spec.callback = my_audio_callback;
    wav_spec.userdata = NULL;

    // Establecer nuestras variables estáticas globales
    audio_pos = wav_buffer; // Copia el buffer de sonido
    audio_len = wav_length; // Copia la longitud del archivo

    /*Abrir el dispositivo de audio */
    if ( SDL_OpenAudio(&wav_spec, NULL) < 0 )
    {
        fprintf(stderr, "No se pudo abrir el audio: %s\n", SDL_GetError());
        exit(-1);
    }



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
 
