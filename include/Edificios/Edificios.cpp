//
// Created by nur on 06-30-19.
//

#include "Edificios.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdlib.h>
#include <math.h>

GLuint texture[0];


void e_suelo(){
    texture[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "../cesped.bmp",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 300.0f, 0.0f, 100.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 300.0f, 0.0f, -100.0f);
    glEnd();

}

void e_callep(){
    texture[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "../wood.bmp",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-100.0f, 0.0001f, -5.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-100.0f, 0.0001f, 5.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 200.0f, 0.0001f, 5.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 200.0f, 0.0001f, -5.0f);
    glEnd();

}

void e_parqueo1(){
    texture[2] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "../pavimento.jpg",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(-80.0f, 0.0001f, -15.0f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(-80.0f, 0.0001f, -40.0f);
    glTexCoord2f(0.0f, 1.0f);glVertex3f( -30.0f, 0.0001f, -40.0f);
    glTexCoord2f(1.0f, 1.0f);glVertex3f( -30.0f, 0.0001f, -15.0f);
    glEnd();

}

void e_calleparqueo1(){
    texture[3] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "/..cemento2.jpg",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-80.0f, 0.0001f, -5.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-80.0f, 0.0001f, -15.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( -70.0f, 0.0001f, -15.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( -70.0f, 0.0001f, -5.0f);
    glEnd();

}

void e_acera1(){
    texture[4] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "/grama.jpg",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-100.0f, 0.0001f, -8.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-100.0f, 0.0001f, -12.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( -80.0f, 0.0001f, -12.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( -80.0f, 0.0001f, -8.0f);
    glEnd();

}

void e_acera2(){
    texture[5] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "../wood.bmp",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-70.0f, 0.0001f, -8.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-70.0f, 0.0001f, -12.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 100.0f, 0.0001f, -12.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 100.0f, 0.0001f, -8.0f);
    glEnd();

}

void e_suelop(){
    texture[6] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "../cemento.jpg",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 0.0001f, -15.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 0.0001f, -50.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 80.0f, 0.0001f, -50.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 80.0f, 0.0001f, -15.0f);
    glEnd();
}

void e_acerapp(){
    texture[7] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "/grama.jpg",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-30.0f, 0.0001f, -21.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-30.0f, 0.0001f, -18.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 0.0f, 0.0001f, -18.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 0.0f, 0.0001f, -21.0f);
    glEnd();

}

void e_calleparqueo2(){
    texture[8] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "/grama.jpg",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(100.0f, 0.0001f, -5.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(100.0f, 0.0001f, -15.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 110.0f, 0.0001f, -15.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 110.0f, 0.0001f, -5.0f);
    glEnd();

}

void e_parqueo2(){
    texture[9] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "/grama.jpg",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(100.0f, 0.0001f, -15.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(100.0f, 0.0001f, -40.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 140.0f, 0.0001f, -40.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 140.0f, 0.0001f, -15.0f);
    glEnd();

}

void e_suelos(){
    texture[10] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
            (
                    "/grama.jpg",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    //glColor3f(0.9f, 0.9f, 0.9f);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(150.0f, 0.001f, -15.0f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(150.0f, 0.001f, -50.0f);
    glTexCoord2f(0.0f, 1.0f);glVertex3f( 200.0f, 0.001f, -50.0f);
    glTexCoord2f(1.0f, 1.0f);glVertex3f( 200.0f, 0.001f, -15.0f);
    glEnd();
}

void edificio1(){
    /*paredT[0] = SOIL_load_OGL_texture // cargamos la imagen
            (
                    "pared.bmp",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            ); */
    glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, paredT[0]);
    //parametros
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //pared

    //glutSolidSphere(50,100,100);

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    //pared abajo
    glTexCoord2f(0.0f, 0.0f);glVertex3f(-10.0f, 0.0f, -10.0f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(-10.0f, 0.0f, 10.0f);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(-20.0f, 0.0f, 10.0f);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(-20.0f, 0.0f, -10.0f);

    //pared enfrente
    glTexCoord2f(1,0); glVertex3f(-20.0, -00.0, 0.0);
    glTexCoord2f(1,1); glVertex3f(-20.0, -00.0, 10.0);
    glTexCoord2f(0,1); glVertex3f(-20.0, 10.0, 10.0);
    glTexCoord2f(0,0); glVertex3f(-20.0, 10.0, 00.0);
    //pared izquierda
    /*glTexCoord2f(1,1); glVertex3f(200.0, -200.0, 100.0);
    glTexCoord2f(0,1); glVertex3f(-200.0, -200.0, 100.0);
    glTexCoord2f(0,0); glVertex3f(-200.0, -200.0, 0.0);
    glTexCoord2f(1,0); glVertex3f(200.0, -200.0, 0.0);
    //pared derecha
    glTexCoord2f(1,1); glVertex3f(200.0, 200.0, 100.0);
    glTexCoord2f(0,1); glVertex3f(-200.0, 200.0, 100.0);
    glTexCoord2f(0,0); glVertex3f(-200.0, 200.0, 0.0);
    glTexCoord2f(1,0); glVertex3f(200.0, 200.0, 0.0); */
    glEnd();
}