#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "GL/glut.h"
#include "Conversion.h"
#include "math.h"
#include "Vec.h"
#include <stdlib.h>

typedef struct Camera{
    //same vectors as gluLookAt
    Vec3 eye;
    Vec3 center ;
    Vec3 up;
    
    int keys[5];
    
    int mouseX;
    int mouseY;

    float speed;

}Camera;


Camera* createCamera(float p_X, float p_Y, float p_Z,float speed);
void updateCamera(Camera* camera);
void cameraKeyDown(Camera* camera,unsigned char Key);
void cameraKeyUp(Camera* camera,unsigned char Key);

#endif
