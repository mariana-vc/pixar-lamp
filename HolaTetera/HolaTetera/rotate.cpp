//MCC Nestor Gomez
//
//"Hola Tetera"

#ifdef _WIN32
#include "glut.h"
#elif __APPLE__
#include <GLUT/GLUT.h>
#endif

GLfloat ang = 0;
GLfloat ang2 = 0;
GLfloat ang3 = 0;
GLfloat ang4 = 0;

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
	ang += 0.05;
	ang2 += 0.05;
	ang3 += 0.05;
	ang4 -= 0.05;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glColor3f(1, 0, 0);
	glRotatef(ang, 0, 0, 1);
	glTranslatef(0, .25, 0);
	glPushMatrix();
	glScalef(0.1, 0.5, 1);
	glutWireCube(1);

	glPopMatrix();
	glTranslatef(0, .25, 0);
	glRotatef(ang2, 0, 0, 1);
	glTranslatef(0, .25, 0);
	glPushMatrix();
	glScalef(0.1, 0.5, 1);
	glutWireCube(1);

	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, .25, 0);
	glRotatef(ang3, 0, 0, 1);
	glTranslatef(0, .25, 0);
	glScalef(0.1, 0.5, 1);
	glutWireCube(1);

	glPopMatrix();
	glTranslatef(0, .25, 0);
	glRotatef(ang4, 0, 0, 1);
	glTranslatef(0, .25, 0);
	glScalef(0.1, 0.5, 1);
	glutWireCube(1);

	glutSwapBuffers();
	glutPostRedisplay();

}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);   //actualizar la ventana
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -10, 10);
}



int main(int artcp, char **argv)
{
	glutInit(&artcp, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	//glutInitWindowSize(1000, 1000);
	glutCreateWindow("Rotating teapot"); //crear una ventana
	glutDisplayFunc(Display);  //callback principal
	glutReshapeFunc(Reshape); //callback de reshape
	Init();			// Inicializaciones
	glutMainLoop();   //loop del programa
	return 0;

}