#include "Head.h"

void GLinit()
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);	//Set background color to black and opaque
	glClearDepth(1.0f);					//Set background depth to farthest
	glEnable(GL_DEPTH_TEST);			//Enable depth testing for z-culling 
										//to remove hidden surface
	//glEnable(GLUT_DEPTH);
	glDepthFunc(GL_LEQUAL);				//Set type of depth-test
	glShadeModel(GL_SMOOTH);			//Enable smooth shading
										//in color transition
										//try GL_FLAT
	//Trade-off between processing speed and visual quality
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
										//Nice perspective correction
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
										//Clear color and depth buffer
	glMatrixMode(GL_MODELVIEW);			//Operate on model view matrix

	//********************************************************************************************************* CUBE 
	//Render a color-cube consisting of 6 quads with different colors
	glLoadIdentity();					//Reset model-view matrix
	glTranslatef(3.0f, 0.0f, -20.0f);	//Move to the right & to the screen
	glRotatef(curAngleCube, 0.0, 1.0, 0.0);	//Rotate about (1,1,1)-axis

	//Map texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	//Begin drawing the color cube with 6 quads
	//Define vertices in counter-clockwise (CCW) order with normal pointing out
	
	glBegin(GL_QUADS);
		//top face (y = 1.0f)
		//glColor3f(0.0, 1.0, 0.0);		//Green
		glVertex3f(1.0, 1.0, -1.0);		
		glVertex3f(-1.0, 1.0, -1.0);	
		glVertex3f(-1.0, 1.0, 1.0);		
		glVertex3f(1.0, 1.0, 1.0);		
		//Bottom face (y = -1.0f)
		//glColor3f(1.0, 0.5, 0.0);		//Orange
		glVertex3f(1.0, -1.0, 1.0);		
		glVertex3f(-1.0, -1.0, 1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(1.0, -1.0, -1.0);
		//Front face (z = 1.0f)
		//glColor3f(1.0, 0.0, 0.0);		//Red
		glTexCoord2f(1.0, 1.0);			glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 1.0);			glVertex3f(-1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 0.0);			glVertex3f(-1.0, -1.0, 1.0);
		glTexCoord2f(1.0, 0.0);			glVertex3f(1.0, -1.0, 1.0);
		//Back face (z = -1.0f)
		//glColor3f(1.0, 1.0, 0.0);		//Yellow
		glTexCoord2f(1.0, 1.0);			glVertex3f(-1.0, 1.0, -1.0);
		glTexCoord2f(0.0, 1.0);			glVertex3f(1.0, 1.0, -1.0);
		glTexCoord2f(0.0, 0.0);			glVertex3f(1.0, -1.0, -1.0);
		glTexCoord2f(1.0, 0.0);			glVertex3f(-1.0, -1.0, -1.0);
		//Left face (x = -1.0f)
		//glColor3f(0.0, 0.0, 1.0);		//Blue
		glTexCoord2f(1.0, 1.0);			glVertex3f(-1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 1.0);			glVertex3f(-1.0, 1.0, -1.0);
		glTexCoord2f(0.0, 0.0);			glVertex3f(-1.0, -1.0, -1.0);
		glTexCoord2f(1.0, 0.0);			glVertex3f(-1.0, -1.0, 1.0);
		//Right face (x = 1.0f)
		//glColor3f(1.0, 0.0, 1.0);		//Magenta
		glTexCoord2f(1.0, 1.0);			glVertex3f(1.0, 1.0, -1.0);
		glTexCoord2f(0.0, 1.0);			glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 0.0);			glVertex3f(1.0, -1.0, 1.0);
		glTexCoord2f(1.0, 0.0);			glVertex3f(1.0, -1.0, -1.0);
	glEnd();							//End of drawing color cube
	glDisable(GL_TEXTURE_2D);


	//********************************************************************************************************* PYRAMID 
	//Begin drawing the pyramid with 4 triangles
	glLoadIdentity();
	glTranslatef(-1.5f, 0.0f, -20.0f);
	glRotatef(curAnglePyramid, 0.0, 1.0, 0.0);

	//Map texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glBegin(GL_TRIANGLES);
		//Front
		glTexCoord2f(0.5, 1.0);			glVertex3f(0.0, 1.0, 0.0);
		glTexCoord2f(0.0, 0.0);			glVertex3f(-1.0, -1.0, 1.0);
		//glColor3f(0.0, 0.0, 1.0);		//blue
		glTexCoord2f(1.0, 0.0);			glVertex3f(1.0, -1.0, 1.0);
		//Right
		//glColor3f(1.0, 0.0, 0.0);		//red
		glTexCoord2f(0.5, 1.0);			glVertex3f(0.0, 1.0, 0.0);
		//glColor3f(0.0, 1.0, 0.0);		//green
		glTexCoord2f(0.0, 0.0);			glVertex3f(1.0, -1.0, 1.0);
		//glColor3f(0.0, 0.0, 1.0);		//blue
		glTexCoord2f(1.0, 0.0);			glVertex3f(1.0, -1.0, -1.0);
		//Back
		//glColor3f(1.0, 0.0, 0.0);		//red
		glTexCoord2f(0.5, 1.0);			glVertex3f(0.0, 1.0, 0.0);
		//glColor3f(0.0, 1.0, 0.0);		//green
		glTexCoord2f(0.0, 0.0);			glVertex3f(1.0, -1.0, -1.0);
		//glColor3f(0.0, 0.0, 1.0);		//blue
		glTexCoord2f(1.0, 0.0);			glVertex3f(-1.0, -1.0, -1.0);
		//Left
		//glColor3f(1.0, 0.0, 0.0);		//red
		glTexCoord2f(0.5, 1.0);			glVertex3f(0.0, 1.0, 0.0);
		//glColor3f(0.0, 1.0, 0.0);		//green
		glTexCoord2f(0.0, 0.0);			glVertex3f(-1.0, -1.0, -1.0);
		//glColor3f(0.0, 0.0, 1.0);		//blue
		glTexCoord2f(1.0, 0.0);			glVertex3f(-1.0, -1.0, 1.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//********************************************************************************************************* CYLINDER
	glLoadIdentity();
	glTranslatef(-3.0f, 0.0f, -10.0f);
	glRotatef(curAngleCylinder, 0.0, 1.0, 0.0);

	//Map texture
	//cout << "Mapping texture " << texture[0] << endl;
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, texture[0]);

	/*GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;
	GLfloat radius = 0.4;
	GLfloat height = 1.0;*/

	/** Draw the tube */
	/*glColor3ub(215, 120, 60);

	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();*/

	/** Draw the circle on top of cylinder */
	/*glColor3ub(255, 200, 140);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();*/

	/** Draw the bottom circle of cylinder */
	/*glColor3ub(255, 200, 140);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, 0.0);
	glEnd();*/

	float radius = 0.5;
	float height = 2.0;
	int faces = 360;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	glBegin(GL_QUAD_STRIP);
	double x, y, z;
	y = height/2;
	for (int i = 0; i <= faces; i++) {
		double u = i / (double)faces;
		x = radius * cos(2 * PI * u);
		z = radius * sin(2 * PI * u);
		/* Bottom vertex*/
		glTexCoord2d(u, 0.0); glVertex3d(x, -y, z);
		/* Top vertex*/
		glTexCoord2d(u, 1.0); glVertex3d(x, y, z);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	//********************************************************	SPHERE	************************************************* 
	glLoadIdentity();
	glTranslatef(-1.0f, 2.0f, -10.0f);
	glRotatef(curAngleSphere, 0.0, 1.0, 0.0);

	//Map texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);

	x = 0.0;
	y = 0.0;
	z = 0.0;
	float xy;				                          // vertex position
	float s, t;                                     // texCoord
	radius = 0.5;
	int sectorCount = 100;
	int stackCount = 100;

	float sectorStep = 2 * PI / sectorCount;
	float stackStep = PI / stackCount;
	float sectorAngle, stackAngle;

	point globe[101][101];
	coor mapPoint[101][101];

	for (int i = 0; i <= stackCount; ++i)
	{
		point spherePoint;
		stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
		xy = radius * cosf(stackAngle);             // r * cos(u)
		z = radius * sinf(stackAngle);              // r * sin(u)

		// add (sectorCount+1) vertices per stack
		// the first and last vertices have same position and normal, but different tex coords
		for (int j = 0; j <= sectorCount; ++j)
		{
			sectorAngle = j * sectorStep;           // starting from 0 to 2pi

			// vertex position
			x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
			y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)

			spherePoint.x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
			spherePoint.y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)

			// vertex tex coord between [0, 1]
			s = (float)j / sectorCount;
			t = (float)i / stackCount;

			coor newCoor;
			newCoor.s = (float)j / sectorCount; 
			newCoor.t = (float)i / stackCount;
			
			//glTexCoord2f(s, t);
			//glColor3f(1.0, 1.0, 0.0);
			glBegin(GL_POINTS);
			glTexCoord2f(s, t);
			glVertex3f(x, y, z);
			glEnd();
			//globe[i][j] = spherePoint;
			//mapPoint[i][j] = newCoor;
		}
	}
	/*for (int i = 0; i < 51; ++i) {
		for (int j = 0; j < 51; ++j) {
			//cout << "Point " << i << " " << j << endl;
			glBegin(GL_TRIANGLES);
			//glTexCoord2f(mapPoint[i][j].s, mapPoint[i][j].t);
			glVertex3f(globe[i][j].x, globe[i][j].y, globe[i][j].z);
			//glTexCoord2f(mapPoint[i + 1][j].s, mapPoint[i + 1][j].t);
			glVertex3f(globe[i + 1][j].x, globe[i + 1][j].y, globe[i + 1][j].z);
			//glTexCoord2f(mapPoint[i][j + 1].s, mapPoint[i][j + 1].t);
			glVertex3f(globe[i][j + 1].x, globe[i][j + 1].y, globe[i][j + 1].z);
			glEnd();
		}
	}*/

	glutSwapBuffers();

	//Update rotational angle after each refresh
	curAngleCube -= 0.15f;
	curAnglePyramid -= 0.2f;
	curAngleCylinder -= 0.2f;
	curAngleSphere -= 0.2f;
}
void timer(int value)					//Called back when timer expired
{
	glutPostRedisplay();
	//Next timer call milliseconds later
	//Registers a timer callback to be triggered in a specified number of milliseconds.
	glutTimerFunc(refreshMills, timer, 0);
}
void reshape(GLsizei width, GLsizei height)
{
	//GLsizei for non-negative int
	//Compute aspect ratio of new window
	if (height == 0)
		height = 1;						//avoid divided by 1
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	//Set viewport to cover the new window
	glViewport(0, 0, width, height);
	//Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);		//Operate on the projection matrix
	glLoadIdentity();					//Reset
	//Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0, aspect, 0.1, 100.0);
}
int loadGLTexttures()					//Load bitmaps and convert to textures
{
	//Load img file directly as a new OpenGL texture
	texture[0] = SOIL_load_OGL_texture(
		"Data/img0.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[1] = SOIL_load_OGL_texture(
		"Data/img1.BMP",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[2] = SOIL_load_OGL_texture(
		"Data/img2.BMP",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	texture[3] = SOIL_load_OGL_texture(
		"Data/img3.BMP",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	
	for (int i = 0; i < textureSize; ++i) {
		if (texture[i] == 0)
			return false;
		cout << "Texture " << i << " = " << texture[i] << endl;
	}
	
	//Typical texture generation using data from bitmap
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}