#include "Head.h"

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(300, 50);
	glutInitWindowSize(width, height); 
	glutCreateWindow("Lab04 - Vy Huynh - 1751027");
	loadGLTexttures();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	GLinit();							//OpenGL initialization
	glutTimerFunc(0, timer, 0);			//First timer call immediately
	glutMainLoop();
	return 0;
}