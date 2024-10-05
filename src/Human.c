#ifndef _HUMAN_C_
#define _HUMAN_C_


#include "../include/Human.h"

Human* newHuman(Vec3 pos,int** grid,int rows,int cols){
    Human* human = (struct Human*)malloc( sizeof(struct Human));
    human->pos = pos;
    human->start = newVec3(pos.x,pos.y,pos.z);
    human->dir = -1;
    human->speed = 0.02f;
    
    int tileSize = 2;

    return human;
}


void updateHuman(Human* h){
    
    if(h->dir == -1){
        h->pos.x -= h->speed ;
    }else{
        h->pos.x -= h->speed ;
    }
    
    if(h->pos.x <= h->dest.x){
        h->dir = 1;
    }
    if(-h->pos.x >= h->start.x){
        h->dir = -1;
        h->pos = h->start;
    }

}

void drawHuman(Human* h){

    glTranslatef(h->pos.x,h->pos.y,h->pos.z);


    // body
    glPushMatrix();
    glTranslatef(0,0,0);
    glColor3f(0,0,0.8f);
    glutSolidSphere(1,18,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0.8f,0);
    glColor3f(0,0,0.8f);
    glutSolidSphere(1,18,15);
    glPopMatrix();

    // head
    glPushMatrix();
    glTranslatef(0,2.2f,0);
    glColor3f(0,0.8f,0.1f);
    glutWireSphere(0.6f,18,15);
    glPopMatrix();

    // left leg
    glPushMatrix();
    glTranslatef(-0.6f,-1.0f,0);
    glColor3f(0,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.6f,-1.4f,0);
    glColor3f(0,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.6f,-1.8f,0);
    glColor3f(0,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();

    // right leg
    glPushMatrix();
    glTranslatef(0.6f,-1.0f,0);
    glColor3f(0,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.6f,-1.4f,0);
    glColor3f(0,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.6f,-1.8f,0);
    glColor3f(0,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();


    // left Hand
    glPushMatrix();
    glTranslatef(-0.8f,1.0f,0);
    glColor3f(0.8f,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.4f,1.0f,0);
    glColor3f(0.8f,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.8f,1.0f,0);
    glColor3f(0.8f,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();

    // right Hand
    glPushMatrix();
    glTranslatef(0.8f,1.0f,0);
    glColor3f(0.8f,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.4f,1.0f,0);
    glColor3f(0.8f,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.8f,1.0f,0);
    glColor3f(0.8f,0.8f,0.8f);
    glutWireSphere(0.3f,18,15);
    glPopMatrix();


}


int humanCollidePlayer(Human* h,float x,float z){
    float d = 100;
    d = distance(x,z,h->pos.x,h->pos.z);
    if(d <= 3){
        return 1;
    }
    return 0;
}

int humanCollideCar(Human* h,float x,float z){
    float d = 100;
    d = distance(x,z,h->pos.x,h->pos.z);
    if(d <= 3){
        return 1;
    }
    return 0;
}

#endif
