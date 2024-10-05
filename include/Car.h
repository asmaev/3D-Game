#ifndef _CAR_H_
#define _CAR_H_

#include "Vec.h"
#include "Cube.h"
#include <GL/glut.h>
#include "GL/gl.h"

typedef struct Car{
    Vec3 pos;
    Vec3 start;
    Vec3 dest;
    int dir;
    float speed;
}Car;


Car* newCar(Vec3 pos,Vec3 dest);
void updateCar(Car* car);
void drawCar(Car* car);
int carCollidePlayer(Car* car,float x,float z);

#endif
