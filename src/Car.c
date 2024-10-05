#ifndef _CAR_C_
#define _CAR_C_

#include "../include/Car.h"

//Creation et initialisation d'une voiture
Car* newCar(Vec3 pos,Vec3 dest){
    Car* car = (struct Car*)malloc( sizeof(struct Car));
    car->pos = pos;
    car->start = newVec3(pos.x,pos.y,pos.z);
    car->dest = dest;
    car->dir = -1;
    car->speed = 0.03f;
    
    return car;
}


//MAJ du mouvement de la voiture en fct de sa direction et de sa vitesse
void updateCar(Car* car){

    if(car->dir == -1){        //left
        car->pos.x -= car->speed ;
    }else{                    //right
        car->pos.x -= car->speed ;
    }
    
    if(car->pos.x <= car->dest.x){
        car->dir = 1;
    }
    if(-car->pos.x >= car->start.x){
        car->dir = -1;
        car->pos = car->start;
    }

}

//dessin de la voiture
void drawCar(Car* car){
    if(car->dir == 1){
        glScalef(-1,1,1);
    }else{
        glScalef(1,1,1);
    }

    // try change the value then see what happen
    //back
    glPushMatrix();
    glTranslatef(car->pos.x, car->pos.y, car->pos.z);
    color1Cube(0.8f,0.1f,0.1f);
    glPopMatrix();

    //cockpit ;)
    glPushMatrix();
    glTranslatef(car->pos.x - 1.5f, car->pos.y - 0.1f, car->pos.z + 0.0f);
    glScalef(0.5f,0.5f,0.5f);
    color1Cube(0.9f,0.8f,0.1f);
    glPopMatrix();

     //right front wheel
    glPushMatrix();
    glTranslatef(car->pos.x - 1.0f, car->pos.y - 1.0f, car->pos.z - 1.0f);
    glColor3f(0,0,0.8f);
    glutWireSphere(0.4f,18,18);
    glPopMatrix();

     //right back wheel
    glPushMatrix();
    glTranslatef(car->pos.x + 1.0f, car->pos.y - 1.0f, car->pos.z - 1.0f);
    glColor3f(0,0,0.8f);
    glutWireSphere(0.4f,18,18);
    glPopMatrix();

     //left front wheel
    glPushMatrix();
    glTranslatef(car->pos.x - 1.0f, car->pos.y - 1.0f, car->pos.z + 1.0f);
    glColor3f(0,0,0.8f);
    glutWireSphere(0.4f,18,18);
    glPopMatrix();

    //left back wheel     
    glPushMatrix();
    glTranslatef(car->pos.x + 1.0f, car->pos.y - 1.0f, car->pos.z + 1.0f);
    glColor3f(0,0,0.8f);
    glutWireSphere(0.4f,18,18);
    glPopMatrix();


}


//test de collision avec la voiture
int carCollidePlayer(Car* car,float x,float z){
    float d;
    if(car->dir == -1){
        d = distance(x,z,car->pos.x,car->pos.z);
    }
    else{
        d = distance(x,z,-car->pos.x,car->pos.z);
    }

    if(d <= 3){
        return 1;
    }
    return 0;
}


#endif
