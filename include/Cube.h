#ifndef _CUBE_H_
#define _CUBE_H_

#include "Vec.h"
#include "GL/glut.h"

//representation d'un cube avec sa position et son echelle 
typedef struct Cube{
    Vec3 pos;
    Vec3 scale;
}Cube;

void quad(int a,int b,int c,int d);
void quad1Color(int a,int b,int c,int d, float r,float g,float blue );
void colorcube();
void color1Cube(float r,float g,float b);
Cube* newCube(Vec3 pos,Vec3 scale);
void drawCube(Cube* cube);
void draw1ColorCube(Cube* cube,float r,float g,float b);
int cubeCollidePlayer(Cube* cube,float x,float z);

#endif
