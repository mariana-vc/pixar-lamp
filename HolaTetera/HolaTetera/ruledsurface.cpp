//MCC Nestor Gomez
//
//"Hola Tetera"

#ifdef _WIN32
#include "glut.h"
#elif __APPLE__
#include <GLUT/GLUT.h>
#endif
#include <math.h>

GLfloat ang = 0;
int lados = 20;

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
	ang += 0.5;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glColor3f(1, 0, 0);

	float u = 0;
	float v = 0;
	float PI = 3.141592;
	float step = 1.0f / lados;


	glRotatef(ang, 1, 1, 1);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	for (v = 0; v <= 1; v += step) {
		glBegin(GL_QUAD_STRIP);
		glColor3f(v, 0, 0);
		for (u = -1; u <= 1; u += step) {
			glVertex3f(sin(2 * PI*v) - u*sin(2 * PI*v) + u*cos(4 * PI*v), v, 0);
			glVertex3f(sin(2 * PI*(v + step)) - u*sin(2 * PI*(v+step)) + u*cos(4 * PI*(v + step)), v + step, 1);
		}
		glEnd();
	}


	glutSwapBuffers();
	//glutPostRedisplay();

}

void Timer(int val)
{
	glutPostRedisplay();
	glutTimerFunc(16, Timer, 0);
}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);   //actualizar la ventana
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3, 3, -3, 3, -10, 10);
}


void Keyboard(unsigned char key,
	int x, int y)
{
	if (key == 'a')
	{
		lados++;
	}
	else if (key == 'z')
	{
		if (lados > 0) {
			lados--;
		}
	}
}


int main(int artcp, char **argv)
{
	glutInit(&artcp, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("Rotating teapot"); //crear una ventana
	glutDisplayFunc(Display);  //callback principal
	glutReshapeFunc(Reshape); //callback de reshape
	glutTimerFunc(16, Timer, 0);
	glutKeyboardFunc(Keyboard);
	Init();			// Inicializaciones
	glutMainLoop();   //loop del programa
	return 0;

}