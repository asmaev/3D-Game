#ifndef _VEC_C_
#define _VEC_C_

#include "../include/Vec.h"

//Creation et initialisation d'un pt
Point newPoint(int row,int col){
	Point p;
	p.row = row;
	p.col = col;
	return p;
}

//Creation et initialisation d'un vec 2D
Vec2i* newVec2P(int x,int y){
	Vec2i* v = (struct Vec2i*)malloc( sizeof(struct Vec2i));
	v->x = x;
	v->y = y;
	return v;
}
Vec2i newVec2(int x,int y){
	Vec2i v;
	v.x = x;
	v.y = y;
	return v;
}

//Creation et initialisation d'un vec 3D
Vec3 newVec3(int x,int y,int z){
	Vec3 p;
	p.x = x;
	p.y = y;
	p.z = z;
	return p;
}

//Calcul du produit vectoriel de deux vecteurs 3D
Vec3 Vec3Cross(Vec3 v1, Vec3 v2) {
	Vec3 result;

    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
	
    return result;
}

//Calcul du produit scalaire de deux vesteurs 3D
float Vec3Dot( Vec3 v1, Vec3 v2 ) {
    return(v1.x * v2.x)+ (v1.y * v2.y) + (v1.z * v2.z);
    
}

//Calcul de la longueur du vecteur
float Vec3Length( Vec3 v ) {
	return sqrt( Vec3Dot( v, v ) );
}

//Calcul du vecteur normalise
Vec3 Vec3Normalize(Vec3 v) {
    Vec3 result;
    result.x = v.x / Vec3Length(v);
    result.y = v.y / Vec3Length(v);
    result.z = v.z / Vec3Length(v);
    return result;
}

//Calcul du vecteur resultant du produit d'un vecteur avec un float
Vec3 Vec3MulF( Vec3 v,float a ) {
    Vec3 result;
	result.x = a * v.x;
	result.y = a * v.y; 
	result.z = a * v.z;
    return result;
}

//Calcul de la somme de deux vecteurs 3D
Vec3 Vec3Add( Vec3 v1, Vec3 v2 ) {
	Vec3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
    return result;
}

//Calcul de la difference de deux vecteurs 3D
Vec3 Vec3Minus( Vec3 v1, Vec3 v2 ) {
	Vec3 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
    return result;
}

//Rotation autour d'un axe
Vec3 rotateVec3(Vec3 v, float rad, Vec3 k) {
	double cos_theta = cos(rad);
	double sin_theta = sin(rad);

    Vec3 a = Vec3MulF(v,cos_theta);
    Vec3 b = Vec3MulF(Vec3Cross(k, v),sin_theta);
    Vec3 c = Vec3MulF(Vec3MulF(k,Vec3Dot(k, v)),(1-cos_theta));

    Vec3 rotated = Vec3Add(Vec3Add(a,b),c);

    return rotated;
}

//Calcul de distance entre deux pts
float distance(float x1,float y1,float x2,float y2) {
    return sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
}

#endif
