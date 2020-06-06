#ifndef _HEAD_H_
#define _HEAD_H_

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies/SOIL/include/SOIL.h"
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

class point {
public:
	float x, y, z;
};

static const float PI = 3.141592;
const int height = 500, width = 889;
static GLfloat curAngleCube = 0.0;		//Current rotaional angle of cube
static GLfloat curAnglePyramid = 0.0;	//Current rotational angle of pyramid
static GLfloat curAngleCylinder = 0.0;
static GLfloat curAngleSphere = 0.0;
static GLfloat curAngleCone = 0.0;
static int refreshMills = 15;				//refresh interval in milliseconds
static GLuint texture[6];					//storage for textures
static int textureSize = 6;

void GLinit();
void display();
void reshape(GLsizei width, GLsizei height);
void timer(int value);						//Called back when timer expired
int loadGLTexttures();						//Load texture from file
static double rad(double x) { return (PI * (x)) / 180.0; }

#endif