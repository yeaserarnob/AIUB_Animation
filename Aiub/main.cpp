
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <iostream>
using namespace std;

int height = 50, width = 50;
int window_width = 1024, window_height = 768;
int mx = window_width / 2 - width / 2, my = 10;
int r1x = rand() % window_width + 1, r1y = window_height;
int r2x = rand() % window_width + 1, r2y = window_height;
int r3x  = rand() % window_width + 1, r3y = window_height;

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1024, 0.0, 768.0);

}



void SpecialKeys(int key, int x, int y)
{
    switch (key)
	{
		case GLUT_KEY_LEFT:
            mx -= 10;
            glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
            mx += 10;
            glutPostRedisplay();
			break;
	}
}




void translate()
{
    r1y -= 10;
    r2y -= 10;
    r3y -= 10;
    if(r1y <= 0)
    {
        r1x = rand() % window_width + 1;
        r1y = rand() % (window_height * 2) + window_height;

    }
    if(r2y <= 0)
    {
        r2x = rand() % window_width + 1;
        r2y = rand() % (window_height * 2) + window_height;
    }
    if(r3y <= 0)
    {
        r3x = rand() % window_width + 1;
        r3y = rand() % (window_height * 2) + window_height;
    }
    glutPostRedisplay();
}

void myDisplay()
{

    glClear (GL_COLOR_BUFFER_BIT);
//    window_height = GLUT_WINDOW_HEIGHT;
//    window_width = GLUT_WINDOW_WIDTH;

    glColor3ub(200,150,225);
    glBegin(GL_QUADS);
    glVertex2i(mx, my);
    glVertex2i(mx + width, my);
    glVertex2i(mx + width, my + height);
    glVertex2i(mx, my + height);
    glEnd();

    glColor3ub(255,0,100);
    glBegin(GL_QUADS);
    glVertex2i(r1x, r1y);
    glVertex2i(r1x + width, r1y);
    glVertex2i(r1x + width, r1y + height);
    glVertex2i(r1x, r1y + height);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(r2x, r2y);
    glVertex2i(r2x + width, r2y);
    glVertex2i(r2x + width, r2y + height);
    glVertex2i(r2x, r2y + height);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(r3x, r3y);
    glVertex2i(r3x + width, r3y);
    glVertex2i(r3x + width, r3y + height);
    glVertex2i(r3x, r3y + height);
    glEnd();

    glFlush();

    translate();
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1024, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Translate");
    glutDisplayFunc(myDisplay);
    //glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialKeys);
    myInit ();
    srand(clock());
    glutMainLoop();
    return 0;
}
