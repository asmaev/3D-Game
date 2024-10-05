#ifndef _CONVERSION_C_
#define _CONVERSION_C_

#include "../include/Conversion.h"

int GAMESTATE;
float deltaTime;

int mouseX;
int mouseY;

float toRadian(float aAngle) {
	float pi = 3.14159265359;
	float radians = aAngle * pi / 180;
	return radians;
}
float toDegree(float ra) {
	float pi = 3.14159265359;
	float angle = ra * 180 / pi;
	return angle;
}


#endif
