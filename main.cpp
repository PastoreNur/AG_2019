#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h> // freeglut instead of glut because glut is DEPRECATED
#include <SOIL/SOIL.h>
#include <SDL2/SDL.h>

#include <math.h>
#include "include/Edificios/Edificios.h"
#include "include/Fisicas/Fisicas.h"

using namespace std;

GLfloat ortho = 200;
GLfloat step = ortho/100;
GLfloat defaultRotX = -45.0f, defaultRotZ = -135.0f;


GLfloat X = 0.0f; // Translate screen to x direction (left or right)
GLfloat Y = 0.0f; // Translate screen to y direction (up or down)
GLfloat Z = 0.0f; // Translate screen to z direction (zoom in or out)
GLfloat rotX = defaultRotX; // Rotate screen on x axis
GLfloat rotY = 0.0f; // Rotate screen on y axis
GLfloat rotZ = defaultRotZ; // Rotate screen on z axis

// window title
#define WINDOW_TITLE_PREFIX "TERRENO"

// default window's size, but these settings are override later
int
        CurrentWidth = 800,
        CurrentHeight = 600,
        WindowHandle = 0;

// frame-counter var
unsigned FrameCount = 0;

// function prototypes
void Initialize(int, char *[]);

void InitWindow(int, char *[]);

void ResizeFunction(int, int);

void RenderFunction();

void TimerFunction(int);

void IdleFunction();

void display();

void xyz();

void keyboard(unsigned char, int, int);

void specialKey(int, int, int);

void translateRotate();

//metodos para dibujar
void paredes();


//para SOIL
GLuint paredT[0];

//para LSD

#define RUTA_AUDIO "Fuse Box.wav" //nombre del archivo de audio

// variables para audio
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play

void my_audio_callback(void *userdata, Uint8 *stream, int len)
{

    if (audio_len ==0)
        return;

    len = ( len > audio_len ? audio_len : len );

    SDL_memcpy (stream, audio_pos, len); // Simplemente copie desde un buffer en el otro
    //SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME / 2); // Mezclar de un buffer a otro

    audio_pos += len;
    audio_len -= len;
}


// entry point
int main(int argc, char *argv[]) {

    Initialize(argc, argv);

    glutMainLoop();

    exit(EXIT_SUCCESS);
}

//funcion para imprimir numero en pantalla
int numero = 0;
void number(double a){
    char text[255];
    //sprintf(text, "X:%.0f Y:%.0f", xrot, yrot);
    sprintf(text, "SCORE = %.0f", a);
    glColor3f(1, 1, 1);
    glRasterPos3f(120 , 140, 100);
    for(int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

// all drawings here
void display() {
    translateRotate(); // put this function before each drawing you make.
    xyz();
    //number(numero);
    SDL_PauseAudio(false); //reproducir el audio
    translateRotate(); // put this function before each drawing you make.

    //dibujos aqui

    glColor3f(1,1,1);
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

    paredes();

}


//EJEMPLO BASICO DE COMO FUNCIONA EL ORTHO AQUI
// X ejemplo de donde esta ese eje en la pared atras
// Y ejemplo de donde esta ese eje en la pared adelante
// Z ejemplo de donde este ese eje en la pared arriba basicamen es la altura

void paredes(){
    paredT[0] = SOIL_load_OGL_texture // cargamos la imagen
            (
                    "../wood.bmp",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, paredT[0]);
    //parametros
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //pared
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glNormal3f( 1.0f, 1.0f,1.0f);
    //pared atras
    glTexCoord2f(10,0); glVertex3f(70.0, -50.0, 0.0);
    glTexCoord2f(10,10); glVertex3f(70.0, -50.0, 100.0);
    glTexCoord2f(0,10); glVertex3f(70.0, 50.0, 100.0);
    glTexCoord2f(0,0); glVertex3f(70.0, 50.0, 00.0);
    //pared adelante
    glTexCoord2f(10,0); glVertex3f(-50.0, -80.0, 0.0);
    glTexCoord2f(10,10); glVertex3f(-50.0, -80.0, 100.0);
    glTexCoord2f(0,10); glVertex3f(-50.0, 80.0, 100.0);
    glTexCoord2f(0,0); glVertex3f(-50.0, 80.0, 00.0);
    //pared izquierda
    glTexCoord2f(10,10); glVertex3f(50.0, -50.0, 100.0);
    glTexCoord2f(0,10); glVertex3f(-50.0, -50.0, 100.0);
    glTexCoord2f(0,0); glVertex3f(-50.0, -50.0, 0.0);
    glTexCoord2f(10,0); glVertex3f(50.0, -50.0, 0.0);
    //pared derecha
    glTexCoord2f(10,10); glVertex3f(50.0, 50.0, 100.0);
    glTexCoord2f(0,10); glVertex3f(-50.0, 50.0, 100.0);
    glTexCoord2f(0,0); glVertex3f(-50.0, 50.0, 0.0);
    glTexCoord2f(10,0); glVertex3f(50.0, 50.0, 0.0);
    //abajo
    glTexCoord2f(10,0); glVertex3f(50.0, -50.0, 0.0);
    glTexCoord2f(10,10); glVertex3f(-50.0, -50.0, 0.0);
    glTexCoord2f(0,10); glVertex3f(-50.0, 50.0, 0.0);
    glTexCoord2f(0,0); glVertex3f(50.0, 50.0, 0.0);
    //arriba
    glTexCoord2f(10,0); glVertex3f(50.0, -50.0, 150.0);
    glTexCoord2f(10,10); glVertex3f(-50.0, -50.0, 150.0);
    glTexCoord2f(0,10); glVertex3f(-50.0, 50.0, 150.0);
    glTexCoord2f(0,0); glVertex3f(50.0, 50.0, 150.0);
    glEnd();
}

void xyz() {

    // glRotatef and glTranslatef

    //cout << "rot(" << rotX << ", " << rotY << ", " << rotZ << ")" << endl;
    //cout << "trans(" << X << ", " << Y << ", " << Z << ")" << endl;

    // up or down or zoom in zoom out
    // Draw the positive side of the lines x,y,z
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0); // Green for x axis
    glVertex3f(0, 0, 0);
    glVertex3f(10 * ortho, 0, 0);
    glColor3f(1.0, 0.0, 0.0); // Red for y axis
    glVertex3f(0, 0, 0);
    glVertex3f(0, 10 * ortho, 0);
    glColor3f(0.0, 0.0, 1.0); // Blue for z axis
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 10 * ortho);

    glEnd();

    // Dotted lines for the negative sides of x,y,z
    glEnable(GL_LINE_STIPPLE);    // Enable line stipple to use a
    // dotted pattern for the lines
    glLineStipple(1, 0x0101);    // Dotted stipple pattern for the lines
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);    // Green for x axis
    glVertex3f(-10 * ortho, 0, 0);
    glVertex3f(0, 0, 0);
    glColor3f(1.0, 0.0, 0.0);    // Red for y axis
    glVertex3f(0, 0, 0);
    glVertex3f(0, -10 * ortho, 0);
    glColor3f(0.0, 0.0, 1.0);    // Blue for z axis
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, -10 * ortho);

    glEnd();

    glDisable(GL_LINE_STIPPLE);    // Disable the line stipple
    glPopMatrix();        // Don't forget to pop the Matrix
}

void Initialize(int argc, char *argv[]) {

    GLenum GlewInitResult;

    InitWindow(argc, argv);

    GlewInitResult = glewInit();

    if (GLEW_OK != GlewInitResult) {
        fprintf(
                stderr,
                "ERROR: %s\n",
                glewGetErrorString(GlewInitResult)
        );
        exit(EXIT_FAILURE);
    }

    // print system's capability
    fprintf(
            stdout,
            "INFO: OpenGL Version: %s\n",
            glGetString(GL_VERSION)
    );

    // OpenGL clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void InitWindow(int argc, char *argv[]) {
    glutInit(&argc, argv);

    // set OpenGL's major and minor versions
    glutInitContextVersion(1, 0);

    // Only not deprecated methods allowed
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    // set behavior on window close by user
    glutSetOption(
            GLUT_ACTION_ON_WINDOW_CLOSE,
            GLUT_ACTION_GLUTMAINLOOP_RETURNS
    );

    // settings initial values for the window, this override deafult values on top
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));

    // way to render frames
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    // Setup display mode to
    glShadeModel(GL_FLAT); // Set the shading model to GL_FLAT
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); // Set Line Antialiasing

    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(0.5f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // if windowHandle is greater than 0, then no errors on creating the window
    WindowHandle = glutCreateWindow(WINDOW_TITLE_PREFIX);

    if (WindowHandle < 1) {
        fprintf(
                stderr,
                "ERROR: Could not create a new rendering window.\n"
        );
        exit(EXIT_FAILURE);
    }

    // reset draws to the new size
    glutReshapeFunc(ResizeFunction);
    glutDisplayFunc(RenderFunction);

    // behavior to run at idle
    glutIdleFunc(IdleFunction);
    glutTimerFunc(0, TimerFunction, 0);

    // sonido
    // Inicializar SDL.


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

    // other function calls
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
}

void ResizeFunction(int Width, int Height) {
    CurrentWidth = Width;
    CurrentHeight = Height;

    glViewport(0, 0, (GLsizei) CurrentWidth, (GLsizei) CurrentHeight); // Set the viewport
    glMatrixMode(GL_PROJECTION);    // Set the Matrix mode
    glLoadIdentity();
    //gluPerspective(75, (GLfloat) CurrentWidth / (GLfloat) CurrentHeight, 0, 300.0);
    glOrtho(-ortho, ortho, -ortho, ortho, -ortho, ortho);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void RenderFunction() {
    ++FrameCount; // increasing fps counter
    glClear(GL_COLOR_BUFFER_BIT);


    // DRAWINGS START
    display();
    // DRAWINGS END

    // send all draws
    glPopMatrix();
    glFlush();

    // OpenGL is the front when calling to glutSwapBuffers();
    glutSwapBuffers();
    //glutPostRedisplay();
}

void IdleFunction() {
    glutPostRedisplay();
}

void TimerFunction(int Value) {
    if (0 != Value) {
        char *TempString = (char *)
                malloc(512 + strlen(WINDOW_TITLE_PREFIX));

        sprintf(
                TempString,
                "%s: %d FPS @ %d x %d",
                WINDOW_TITLE_PREFIX,
                FrameCount * 4,
                CurrentWidth,
                CurrentHeight
        );

        glutSetWindowTitle(TempString);
        free(TempString);
    }

    FrameCount = 0;
    glutTimerFunc(250, TimerFunction, 1);
}

// This function is used for the navigation keys
void keyboard(unsigned char key, int x, int y) {
    switch (key) {   // x,X,y,Y,z,Z uses the glRotatef() function

        // I-J-K-L-U-O for 90 degrees rotation
        case 'j': // Rotates on x axis by -90 degree
        case 'J':
            break;
        case 'l': // Rotates on x axis by 90 degree
        case 'L':
            //rotX += 90.0f;
            break;

        case 'k': // Rotates on y axis by -90 degree
        case 'K':
            //rotY -= 90.0f;x
            break;
        case 'i': // Rotates on y axis by 90 degree
        case 'I':
            rotY += 90.0f;
            break;
        case 'u': // Rotates on z axis by -90 degree
        case 'U':
            rotZ -= 90.0f;
            break;
        case 'o': // Rotates on z axis by 90 degree
        case 'O':
            rotZ += 90.0f;
            break;

        case 'r': // Default, resets the translations vies from starting view
        case 'R':
            X = Y = 0.0f;
            Z = 0.0f;
            rotX = defaultRotX;
            rotY = 0.0f;
            rotZ = defaultRotZ;
            break;

            // W-A-S-D

        case 's': // Rotates screen on x axis
        case 'S':
            rotX -= step;
            break;
        case 'w': // Opposite way
        case 'W':
            rotX += step;
            break;

        case 'd': // Rotates screen on z axis
        case 'D':
            rotZ -= step;
            break;

        case 'a': // Opposite way
        case 'A':
            rotZ += step;
            break;
        default:
            break;
    }
    glutPostRedisplay(); // Redraw the scene
}

// called on special key pressed
void specialKey(int key, int x, int y) {

// The keys below are using the gluLookAt() function for navigation
// Check which key is pressed

    switch (key) {
        case GLUT_KEY_LEFT : // Rotate on x axis
            X -= step;
            break;
        case GLUT_KEY_RIGHT : // Rotate on x axis (opposite)
            X += step;
            break;
        case GLUT_KEY_UP : // Rotate on y axis
            Y += step;
            break;
        case GLUT_KEY_DOWN : // Rotate on y axis (opposite)
            Y -= step;
            break;
        case GLUT_KEY_PAGE_UP: // Rotate on z axis
            Z -= step;
            break;
        case GLUT_KEY_PAGE_DOWN:// Rotate on z axis (opposite)
            Z += step;
            break;
        default:
            break;
    }
    glutPostRedisplay(); // Redraw the scene
}

// this function is used to move objects along with XYZ
void translateRotate() {
    glPushMatrix();    // It is important to push the Matrix before calling
    glRotatef(rotX, 1.0, 0.0, 0.0); // Rotate on x
    glRotatef(rotY, 0.0, 1.0, 0.0); // Rotate on y
    glRotatef(rotZ, 0.0, 0.0, 1.0); // Rotate on z
    glTranslatef(X, Y, Z);    //
}