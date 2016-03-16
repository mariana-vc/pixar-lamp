//MCC Nestor Gomez
//
//"Hola Tetera"

#ifdef _WIN32
#include "glut.h"
#elif __APPLE__
#include <GLUT/GLUT.h>
#endif

#include <stdio.h>

GLfloat x0 = -1;
GLfloat y0 = 1;
GLfloat z0 = 0;

GLfloat x1 = -0.5;
GLfloat y1 = 0.5;
GLfloat z1 = 0;

GLfloat x2 = 0;
GLfloat y2 = 0;
GLfloat z2 = 0;

GLfloat x3 = 0.5;
GLfloat y3 = -0.5;
GLfloat z3 = 0;

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

	glColor3f(1, 0, 0);

	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex3f(x0, y0, z0);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glVertex3f(x3, y3, z3);
	glEnd();

	glColor3f(0,0,0);

	glBegin(GL_LINE_STRIP);
	for (GLfloat i = 0; i < 1; i += 0.001) {

		GLfloat b0 = (1-i)*(1 - i)*(1 - i);
		GLfloat b1 = (1 - i)*(1 - i) * 3 * i;
		GLfloat b2 = (1 - i)*3*i*i;
		GLfloat b3 = i*i*i;

		GLfloat x = (x0*b0) + (x1*b1) + (x2*b2) + (x3*b3);
		GLfloat y = (y0*b0) + (y1*b1) + (y2*b2) + (y3*b3);
		GLfloat z = (z0*b0) + (z1*b1) + (z2*b2) + (z3*b3);
		glVertex3f(x, y, z);

	}
	glEnd();

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
		x0 += 0.1;
	}
	else if (key == 'z')
	{
		x0 -= 0.1;
	}
	else if (key == 's') {
		y0 += 0.1;
	}
	else if (key == 'x') {
		y0 -= 0.1;
	}
	else if (key == 'd') {
		x1 += 0.1;
	}
	else if (key == 'c') {
		x1 -= 0.1;
	}
	else if (key == 'f') {
		y1 += 0.1;
	}
	else if (key == 'v') {
		y1 -= 0.1;
	}
	else if (key == 'g') {
		x2 += 0.1;
	}
	else if (key == 'b') {
		x2 -= 0.1;
	}
	else if (key == 'h') {
		y2 += 0.1;
	}
	else if (key == 'n') {
		y2 -= 0.1;
	}
	else if (key == 'j') {
		x3 += 0.1;
	}
	else if (key == 'm') {
		x3 -= 0.1;
	}
	else if (key == 'k') {
		y3 += 0.1;
	}
	else if (key == ',') {
		y3 -= 0.1;
	}

}



int main(int artcp, char **argv)
{
	glutInit(&artcp, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	//glutInitWindowSize(640, 640);
	glutCreateWindow("Rotating teapot"); //crear una ventana
	glutDisplayFunc(Display);  //callback principal
	glutReshapeFunc(Reshape); //callback de reshape
	glutSpecialFunc(SpecialKeys);
	glutKeyboardFunc(Keyboard);
	Init();			// Inicializaciones
	glutMainLoop();   //loop del programa
	return 0;

}