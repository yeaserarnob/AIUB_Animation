
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <iostream>
using namespace std;

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1024, 0.0, 768.0);

}

void TopView(){

    glColor3ub(0, 169, 0);
    glPointSize(1.0);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(1024,0);
    glVertex2i(1024,175);
    glVertex2i(0,99);       //Green Grass
    glEnd();

    glColor3ub(0, 169, 0);
    glPointSize(1.0);
    glBegin(GL_QUADS);
    glVertex2i(0,99);
    glVertex2i(0,196);
    glVertex2i(126,196);
    glVertex2i(106,105);
    glEnd();



    glFlush ();
}


/*void SpecialKeys(int key, int x, int y)
{
    switch (key)
	{
		case GLUT_KEY_LEFT:

            glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
          glutPostRedisplay();
			break;
	}
} */


void myDisplay()
{

    glClear (GL_COLOR_BUFFER_BIT);
    TopView();
    glFlush();
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1024, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("AIUB");
    glutDisplayFunc(myDisplay);
    //glutKeyboardFunc(keyboard);
    //glutSpecialFunc(SpecialKeys);
    myInit ();
    srand(clock());
    glutMainLoop();
    return 0;
}
