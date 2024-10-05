#ifndef _CAMERA_C_
#define _CAMERA_C_

#include "../include/Camera.h"

extern Camera * camera;
extern float deltaTime;
extern int mouseX;
extern int mouseY;

//creation et initialisation de la camera
Camera* createCamera(float x, float y, float z,float speed){
    Camera* camera = (struct Camera*)malloc( sizeof(struct Camera));
    camera->eye.x = x;
    camera->eye.y = y;
    camera->eye.z = z;
    camera->speed = speed;
    
  
    camera->center.x = 0;
    camera->center.y = 0;
    camera->center.z = -1;


    camera->up.x = 0;
    camera->up.y = 1;
    camera->up.z = 0;

    camera->keys[0] = 0;
    camera->keys[1] = 0;
    camera->keys[2] = 0;
    camera->keys[3] = 0;
    camera->keys[4] = 0;
    
    camera->mouseX = 0;
    camera->mouseY = 0;

    return camera;
}

//MAJ de la camera
void updateCamera(Camera* camera){
    Vec3 center = Vec3Add(camera->eye,camera->center);

    gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, center.x,center.y,center.z, camera->up.x,camera->up.y,camera->up.z);


    // handles keys inputs
    if(camera->keys[0] == 1){ // up
        camera->eye = Vec3Add(camera->eye, Vec3MulF(camera->center,camera->speed * deltaTime));
    }
    if(camera->keys[1] == 1){ // down
        camera->eye = Vec3Minus(camera->eye, Vec3MulF(camera->center,camera->speed * deltaTime));
    }
    if(camera->keys[2] == 1){ //left
        camera->eye = Vec3Minus(camera->eye, Vec3MulF(Vec3Normalize(Vec3Cross(camera->center,camera->up)),camera->speed * deltaTime));
    }
    if(camera->keys[3] == 1){ //right
         camera->eye = Vec3Add(camera->eye, Vec3MulF(Vec3Normalize(Vec3Cross(camera->center,camera->up)),camera->speed * deltaTime));
    }

    // handles mouse inputs
    if(camera->keys[4] == 1){
        float sensitivity = 300;

        float rotY = sensitivity * (float)(mouseX - WINDOW_WIDTH/2) / WINDOW_WIDTH;
        float rotX = sensitivity * (float)(mouseY - WINDOW_HEIGHT/2) / WINDOW_HEIGHT;

        Vec3 newOrientation = rotateVec3(camera->center, toRadian(-rotX), Vec3Normalize(Vec3Cross(camera->center, camera->up)));

        camera->center = rotateVec3(newOrientation, toRadian(-rotY), camera->up);
        if(mouseX !=  WINDOW_WIDTH/2 || mouseY != WINDOW_HEIGHT/2){
            glutWarpPointer(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        }
    }
   
    
}


//appuie sur les touches
void cameraKeyDown(Camera* c,unsigned char Key){
    switch (Key) {


    case 's':                    //upfront
        c->keys[0] = 1;          
        break;
    case 'w':                   //back
        c->keys[1] = 1;
        break;
    case 'q':                   //left
        c->keys[2] = 1;
        break;
    case 'd':                   //right
        c->keys[3] = 1;
        break;
    }
}

// relachement des touches
void cameraKeyUp(Camera* camera,unsigned char Key){
    switch (Key) {

    case 's':
        camera->keys[0] = 0;
        break;
    case 'w':
        camera->keys[1] = 0;
        break;
    case 'q':
        camera->keys[2] = 0;
        break;
    case 'd':
        camera->keys[3] = 0;
        break;
    }
}

#endif
