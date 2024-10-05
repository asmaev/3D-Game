#ifndef _AIM_C_
#define _AIM_C_

#include "../include/Aim.h"

//Creation et initialisation d'un but
Aim* newAim(Vec3 pos){
    Aim* aim = (struct Aim*)malloc( sizeof(struct Aim));
    aim->pos = pos;
    return aim;
}

// dessin du but (teapot,tore,cube...)
void drawAim(Aim* aim){
    glPushMatrix();
    glTranslatef(aim->pos.x,aim->pos.y,aim->pos.z);
    glColor3f(1.0f,0.0f,0.0f);
    glutSolidTorus(0.2, 0.5, 20, 30);
    //glutWireTorus(0.2, 0.5, 20, 30);

    glPopMatrix();
}

//test de collision avec le but(fin)
int aimCollidePlayer(Aim* aim,float x,float z){
    float d = 100;
    d = distance(x,z,aim->pos.x,aim->pos.z);

    if(d <= 1){
        return 1;
    }
    return 0;
}

#endif
