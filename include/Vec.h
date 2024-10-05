#ifndef _VEC_H_
#define _VEC_H_


#include "math.h"
#include <stdlib.h>

//vecteur 3d
typedef struct Vec3{
    float x;
    float y;
    float z;
}Vec3;

//Point
typedef struct Point{
    int row;
    int col;
}Point;

//vecteur 2d
typedef struct Vec2i{
   float x;
   float y;
} Vec2i;



Point newPoint(int row,int col);
Vec2i* newVec2P(int x,int y);
Vec2i newVec2(int x,int y);
Vec3 newVec3(int x,int y,int z);
Vec3 Vec3Cross(Vec3 v1, Vec3 v2) ;
float Vec3Dot( Vec3 v1, Vec3 v2) ;
float Vec3Length( Vec3 v ) ;
Vec3 Vec3Normalize(Vec3 v) ;
Vec3 Vec3MulF( Vec3 v,float a ) ;
Vec3 Vec3Add( Vec3 v1, Vec3 v2 ) ;
Vec3 Vec3Minus( Vec3 v1, Vec3 v2 ) ;
Vec3 rotateVec3(Vec3 v, float rad, Vec3 k) ;
float distance(float x1,float y1,float x2,float y2) ;

#endif
