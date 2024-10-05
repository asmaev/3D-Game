#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "Vec.h"
#include "Cube.h"
#include "ArrayList.h"
#include "Car.h"
#include "Aim.h"

#include <GL/glut.h>
#include "GL/gl.h"


typedef struct Human{
    Vec3 pos;
    Vec3 start;
    Vec3 dest;
    float speed;
    int dir;

}Human;

Human* newHuman(Vec3 pos,int** grid,int rows,int cols);
void updateHuman(Human* h);
void drawHuman(Human* h);
int humanCollidePlayer(Human* h,float x,float z);

#endif
