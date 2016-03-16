#ifdef _WIN32
#include "glut.h"
#elif __APPLE__
#include <GLUT/GLUT.h>
#endif
#include <stdio.h> //esta es para poder usar printf
#include <math.h>

float angle = 0;
float tranY = 0;
float tranX = -2;
float t1,t2,t3,t4;
float PI = 3.14159;

void update(float dt,const int curMs) //cada frame
{
	//USANDO EL TIEMPO ACTUAL
	int curT = curMs / 100; //Current Time - 1.5 segundos serían 15 
	//printf("%f\n", t);

	float actualY = tranY;
	float actualX = tranX;

	printf("%f\n", actualX);
	
	if (curT >= 10 && curT <12 ) {//rango del 10 al 15 (sube)
		printf("sube");
		tranY = actualY + ((cos(t1*PI - PI / 2) + 1) / 2)*(1.5 - actualY);   //EASE OUT (desacelera al salir) 
		tranX += 0.08;
		t1 += .05;
	} else if (curT >= 12 && curT < 14) { //baja
		printf("baja");							//se divide entre dos porque solo recorre la mitad del ciclo del seno (o coseno)
		tranY = actualY + ((sin(t2*PI - PI / 2) + 1) / 2)*(0 - actualY);  //EASE IN (desacelera al entrar)
		tranX += 0.08;
		t2 += .05;
	}
	else if (curT >= 16 && curT < 18) { //sube
		printf("SUBE");
		tranY = actualY + ((cos(t3*PI - PI / 2) + 1) / 2)*(1.5 - actualY);  //EASE OUT (desacelera al entrar)
		tranX += 0.08;
		t3 += .05;
	}
	else if (curT >= 18 && curT < 20) { //baja
		printf("BAJA");
		tranY = actualY + ((sin(t4*PI - PI / 2) + 1) / 2)*(0 - actualY);  //EASE IN (desacelera al entrar)
		tranX += 0.08;
		t4 += .05;
	}
}

void Init()
{
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
}

void display()
{
	// GLUT_ELAPSED_TIME is in milliseconds
	static int prvMs = glutGet(GLUT_ELAPSED_TIME); //tiempo del frame pasado
	const int curMs = glutGet(GLUT_ELAPSED_TIME);  //tiempo de este frame

	float dt = (curMs - prvMs) / 1000.0;   //tiempo delta en SEGUNDOS (es el aproximado entre cada frame (0.016 segundos porque va a 60fps)
	prvMs = curMs;

	// update world state
	update(dt,curMs);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// reset projection/modelview matrices each frame;
	// this makes sure we have a known-good matrix 
	// stack each time through display()
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//BASE DE LA LAMPARA
	//glRotatef(angle, 0, 0, 1);
	glTranslatef(tranX, tranY, 0);

	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex2f(-1, -1.5);
	glVertex2f(1, -1.5);
	glVertex2f(0.5, -1);
	glVertex2f(-0.5, -1);
	glEnd();

	glutSwapBuffers();
}

void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0); //se ejecuta en 16ms (60fps) si quiero que sea en 24fps, (1/24)*1000 =  41 milisegundos
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Animacion");
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}