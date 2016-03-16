//MCC Nestor Gomez
//
//"Hola Tetera"

#ifdef _WIN32
#include "glut.h"
#elif __APPLE__
#include <GLUT/GLUT.h>
#endif

#include <stdio.h>

GLfloat rx = 0;
GLfloat ry = 0;
GLfloat rz = 0;

GLfloat x0 = 0;
GLfloat y0 = 0;
GLfloat z0 = 0;

GLfloat x1 = 1;
GLfloat y1 = 0;
GLfloat z1 = 0;

GLfloat x2 = 0;
GLfloat y2 = 1;
GLfloat z2 = 0;

void Init();
void Display();
void Reshape();

void Init()
{
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);

}

void Display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//camera transformations
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-2, 2, -2, 2, -10, 10);
	//gluLookAt(5, 2, 5, 0, 0, 0, 0, 1, 0);


	//modelview transformations
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(rx, 1, 0, 0);
	glRotatef(ry, 0, 1, 0);
	glRotatef(rz, 0, 0, 1);

	glColor3f(1,0,0);

	GLfloat v1x = x1 - x0;
	GLfloat v1y = y1 - y0;
	GLfloat v1z = z1 - z0;
	GLfloat v2x = x2 - x0;
	GLfloat v2y = y2 - y0;
	GLfloat v2z = z2 - z0;

	for (GLfloat i = -1; i < 1; i+=0.01) {
		for (GLfloat j = -1; j < 1; j+=0.01) {
			glBegin(GL_POINTS);
			GLfloat x = x0 + (i*v1x) + (j*v2x);
			GLfloat y = y0 + (i*v1y) + (j*v2y);
			GLfloat z = z0 + (i*v1z) + (j*v2z);
			glVertex3f(x,y,z);
			glEnd();
		}
	}

	glutSwapBuffers();
	glutPostRedisplay();

}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);   //actualizar la ventana

}

//detecta teclas como las flechas, teclas de funciones, home, end, etc. Para referencia buscar glutSpecialFunc
void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		printf("UP\n");
	}
	else if (key == GLUT_KEY_DOWN)
	{
		printf("DOWN\n");
	}
}

//detecta letras, números y espacio. Hay diferencia entre 'a' y 'A'. Espacio es ' '
void Keyboard(unsigned char key,
	int x, int y)
{
	if (key == 'a')
	{
		rx += 1;
	}
	else if (key == 'z')
	{
		rx -= 1;
	}
	else if (key == 's') {
		ry += 1;
	}
	else if (key == 'x') {
		ry -= 1;
	}
	else if (key == 'd') {
		rz += 1;
	}
	else if (key == 'c') {
		rz -= 1;
	}
}



int main(int artcp, char **argv)
{
	glutInit(&artcp, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Rotating teapot"); //crear una ventana
	glutDisplayFunc(Display);  //callback principal
	glutReshapeFunc(Reshape); //callback de reshape
	glutSpecialFunc(SpecialKeys);
	glutKeyboardFunc(Keyboard);
	Init();			// Inicializaciones
	glutMainLoop();   //loop del programa
	return 0;

}