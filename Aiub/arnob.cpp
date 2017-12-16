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
//Ground
    glColor3ub(0, 169, 0);
    glPointSize(1.0);
    glBegin(GL_QUADS);
    glVertex3i(0,0,0);
    glVertex3i(1024,0,0);
    glVertex3i(1024,175,0);
    glVertex3i(0,99,0);       //Green Grass
    glEnd();

    //corner Side
    /*glColor3ub(0, 169, 0);
    glPointSize(1.0);
    glBegin(GL_QUADS);
    glVertex3i(0,99,0);
    glVertex3i(0,196,0);
    glVertex3i(126,196,0);
    glVertex3i(106,105,0);
    glEnd();
    glFlush (); */
}


void Wall()
{
    //wall
    glColor3ub(153, 77, 0);
    glPointSize(1.0);
    glBegin(GL_QUADS);
    glVertex3i(126,108,0);
    glVertex3i(536,138,0);
    glVertex3i(538,181,0);
    glVertex3i(126,152,0);
    glEnd();

    glColor3ub(153, 77, 0);
    glPointSize(1.0);
    glBegin(GL_QUADS);
    glVertex3i(629,145,0);
    glVertex3i(995,171,0);
    glVertex3i(999,212,0);
    glVertex3i(631,188,0);
    glEnd();


}

void Tin(){
    glColor3ub(0, 0, 0);
    glPointSize(1.0);
    glBegin(GL_QUADS);
    glVertex3i(123,151,0);
    glVertex3i(538,181,0);
    glVertex3i(538,192,0);
    glVertex3i(123,162,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glPointSize(1.0);
    glBegin(GL_QUADS);
    glVertex3i(631,187,0);
    glVertex3i(1003,212,0);
    glVertex3i(1003,222,0);
    glVertex3i(631,196,0);
    glEnd();



}

void myDisplay()
{

    glClear (GL_COLOR_BUFFER_BIT);
    TopView();
    Wall();
    Tin();
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

    myInit ();
    srand(clock());
    glutMainLoop();
    return 0;
}
