//MCC Nestor Gomez
//
//"Hola Tetera"

#ifdef _WIN32
#include<stdlib.h>
#include "glut.h"
#elif __APPLE__
#include <GLUT/GLUT.h>
#endif

#include <stdio.h>
#include <random>
#include <iostream>
#include <map>
#include <list>
GLfloat rx = 0;
GLfloat ry = 0;
GLfloat rz = 0;

int randeros [1000];

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

	int diez[10];

	for (int i = 0; i < 10; i++) {
		diez[i] = randeros[i];
	}

	std::map<int,int> diezL;
	std::list<int> repetidos;

	for (int i = 0; i < 10; i++) {
		int bb = diez[i];
		repetidos.push_back(bb);
		int counter = 0;
		for (int j = i + 1; j < 10; j++) {
			if (diez[j] == bb) {
				counter++;
			}
		}
		if (std::find(repetidos.begin(), repetidos.end(), repetidos) != repetidos.end()){
			diezL.insert(std::pair<int, int>(bb, counter));
		}
	}

	int xe = diezL.size();
	int cc = -1;

	for (std::map<int, int>::iterator it = diezL.begin(); it != diezL.end(); it++) {

		glBegin(GL_POINTS);
		GLfloat x0 = cc;
		GLfloat y0 = it->second;
		GLfloat z0 = 0;
		glVertex3f(x0,y0,z0);

		cc += 2 / xe;
	}


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(rx, 1, 0, 0);
	glRotatef(ry, 0, 1, 0);
	glRotatef(rz, 0, 0, 1);

	glColor3f(1, 0, 0);

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
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 1000);

	for (int n = 0; n < 1000; ++n) {
		randeros[n] = dis(gen);
		std::cout << randeros[n] << ' ';
	}

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