#ifndef _AIM_H_
#define _AIM_H_

#include "Vec.h"
#include <GL/glut.h>
#include "GL/gl.h"

typedef struct Aim{
    Vec3 pos;
}Aim;


Aim* newAim(Vec3 pos);
void drawAim(Aim* a);
int aimCollidePlayer(Aim* a,float x,float z);

#endif
