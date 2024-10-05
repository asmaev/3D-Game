#ifndef _CUBE_C_
#define _CUBE_C_



#include "../include/Cube.h"


//dessin d'une face 
void quad(int a,int b,int c,int d){
      //8 sommets

    float ver[8][3] = {
        {-1.0,-1.0,1.0},
        {-1.0,1.0,1.0},
        {1.0,1.0,1.0},
        {1.0,-1.0,1.0},
        {-1.0,-1.0,-1.0},
        {-1.0,1.0,-1.0},
        {1.0,1.0,-1.0},
        {1.0,-1.0,-1.0},
    };
    //8 couleurs
    GLfloat color[8][3] = {
        {0.0,0.0,0.0},
        {1.0,0.0,0.0},
        {1.0,1.0,0.0},
        {0.0,1.0,0.0},
        {0.0,0.0,1.0},
        {1.0,0.0,1.0},
        {1.0,1.0,1.0},
        {0.0,1.0,1.0},
    };
    //dessin d'une face 
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,1.0);
    glVertex3fv(ver[a]);

    glColor3fv(color[b]);
    glVertex3fv(ver[b]);

    glColor3fv(color[c]);
    glVertex3fv(ver[c]);

    glColor3fv(color[d]);
    glVertex3fv(ver[d]);
    glEnd();
}

void quad1Color(int a,int b,int c,int d, float r,float g,float blue ){
    float ver[8][3] ={
            {-1.0,-1.0,1.0},
            {-1.0,1.0,1.0},
            {1.0,1.0,1.0},
            {1.0,-1.0,1.0},
            {-1.0,-1.0,-1.0},
            {-1.0,1.0,-1.0},
            {1.0,1.0,-1.0},
            {1.0,-1.0,-1.0},
        };

    GLfloat color2[3] = {r,g,blue};
    glBegin(GL_QUADS);
    glColor3fv(color2);
    glVertex3fv(ver[a]);

    glColor3fv(color2);
    glVertex3fv(ver[b]);

    glColor3fv(color2);
    glVertex3fv(ver[c]);

    glColor3fv(color2);
    glVertex3fv(ver[d]);
    glEnd();
}

//dessin global du cube 
void colorcube(){
    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);
}

void color1Cube(float r,float g,float b){
    quad1Color(0,3,2,1,r,g,b);
    quad1Color(2,3,7,6,r,g,b);
    quad1Color(0,4,7,3,r,g,b);
    quad1Color(1,2,6,5,r,g,b);
    quad1Color(4,5,6,7,r,g,b);
    quad1Color(0,1,5,4,r,g,b);
}

//Creation et initialisation d'un nouveau cube
Cube* newCube(Vec3 pos,Vec3 scale){
    Cube* cube = (struct Cube*)malloc( sizeof(struct Cube));
    cube->pos = pos;
    cube->scale = scale;
    return cube;
}

//Dessin du cube tout en le mettant a l'echelle et en transformant ces coordonees
void drawCube(Cube* cube){
    glTranslatef(cube->pos.x, cube->pos.y, cube->pos.z);
    glScalef(cube->scale.x, cube->scale.y, cube->scale.z);
    colorcube();
}

void draw1ColorCube(Cube* cube,float r,float g,float b){
    glTranslatef(cube->pos.x, cube->pos.y, cube->pos.z);
    glScalef(cube->scale.x, cube->scale.y, cube->scale.z);
    color1Cube(r,g,b);
}


//test de collision du joueur avec un cube
int cubeCollidePlayer(Cube* cube,float x,float z){
    float d ;
     d = distance(x,z,cube->pos.x,cube->pos.z);
    // d = distance(cube->pos.x, cube->pos.y, x, z);// peut passer a travers le cube si on compare avec l'axe z
    if(d <= 1){
        return 1;
    }
    return 0;
}



#endif
