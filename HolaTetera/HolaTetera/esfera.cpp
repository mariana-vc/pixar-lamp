//MCC Nestor Gomez
//
//"Hola Tetera"

#ifdef _WIN32
    #include "glut.h"
#elif __APPLE__
    #include <GLUT/GLUT.h>
#endif
#include <math.h>

GLfloat ang=0;

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
	ang+=0.5;
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glColor3f(1,0,0);
	
    float u=0,v=0;
    int lados = 20;
    float PI = 3.141592;
    float step = 1.0f/lados;
    
    glPointSize(4);
    
    glRotatef(ang, 1, 1, 1);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    v=0;
    for(int j=0 ; j<lados ; j++)
    {
        u=0;
        glBegin(GL_QUAD_STRIP);
        for(int i=0 ; i<=lados ; i++)
        {
            glVertex3f(sin(v*PI)*sin(u*PI*2),
                       cos(v*PI),
                       sin(v*PI)*cos(u*PI*2) );
            glVertex3f(sin((v+step)*PI)*sin(u*PI*2),
                       cos((v+step)*PI),
                       sin((v+step)*PI)*cos(u*PI*2) );
            u += step;
        }
        glEnd();
        v+=step;
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



int main (int artcp, char **argv)
{
    glutInit(&artcp, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Rotating teapot"); //crear una ventana
    glutDisplayFunc(Display);  //callback principal
    glutReshapeFunc(Reshape); //callback de reshape
    glutTimerFunc(16, Timer, 0);
    Init();			// Inicializaciones
    glutMainLoop();   //loop del programa
    return 0;        
    
}