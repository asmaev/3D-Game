#ifndef _MAIN_C_
#define _MAIN_C_

#include "GL/gl.h"
#include "GL/glut.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/GameWindow.h"


extern int GAMESTATE;
extern float deltaTime;

extern int mouseX;
extern int mouseY;


void display(){
    glClearColor( 0, 0, 0, 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 60, w / h, 1, 1000 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    updateGame();

    glutSwapBuffers();
}

void idle(){
    glutPostRedisplay();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void mInit(){
    GAMESTATE = MAIN_MENU;
    mouseX = 0;
    mouseY = 0;
}


int main(int argc, char*argv[]) {

    mInit();

    //Initialisation
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(400, 150);
    glutCreateWindow("GTA 6");
    glutKeyboardFunc(onKeyDown);
    glutKeyboardUpFunc(onKeyUp);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMotionFunc(mouseMove);
    glutPassiveMotionFunc(mouseMove);
    glutMouseFunc(mouseClick);
    glutSetCursor(GLUT_CURSOR_NONE);
    initGame();
    
    glutMainLoop();


}


#endif
