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

GLfloat rx = 0;
GLfloat ry = 0;
GLfloat rz = 0;

void Init();
void Display();
void Reshape();

void Init()
{
	glClearColor(1,1,1,1);
	glEnable(GL_DEPTH_TEST);
	
}

void Display()
{
	ang+=0.075;
	ang2 += 0.05;
	ang3 += 0.1;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4, 4, -3, 3, 5, -5);
    
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	glColor3f(1,0,0);
	glTranslatef(0,0,0);
	glRotatef(ang, 0, 1, 0);
	glutSolidSphere(.15, 10, 10);
    
	glLoadIdentity();
	glColor3f(0, 1, 0);
	glTranslatef(0, 0, 0);
	glRotatef(ang, 0, 0, 1);
	glTranslatef(0.4, 0, 0);
	glRotatef(ang, 0, 1, 0);
	glutSolidSphere(.1, 10, 10);
	
	glLoadIdentity();
	glColor3f(0, 0, 1);
	glTranslatef(0, 0, 0);
	glRotatef(ang2, 0, 0, 1);
	glTranslatef(0.75, 0, 0);
	glPushMatrix();
	glRotatef(ang2, 0, 1, 0);
	glutSolidSphere(.07, 10, 10);

	glPopMatrix();
	glColor3f(0.32, 0, 0.82);
	glRotatef(ang3, 0, 0, 1);
	glTranslatef(0.18, 0, 0);
	glRotatef(ang3, 0, 1, 0);
	glutSolidSphere(.05, 10, 10);
	
	/*glLoadIdentity();
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();*/

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

int main (int artcp, char **argv)
{
    glutInit(&artcp, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Rotating teapot"); //crear una ventana
    glutDisplayFunc(Display);  //callback principal
    glutReshapeFunc(Reshape); //callback de reshape
	glutKeyboardFunc(Keyboard);
    Init();			// Inicializaciones
    glutMainLoop();   //loop del programa
    return 0;        
    
}