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
//ground
    glColor3ub(0, 168, 0);
    glPointSize(10.0);
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
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(126,108,0);
    glVertex3i(536,138,0);
    glVertex3i(538,181,0);
    glVertex3i(126,152,0);
    glEnd();

    glColor3ub(153, 77, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(629,145,0);
    glVertex3i(995,171,0);
    glVertex3i(999,212,0);
    glVertex3i(631,188,0);
    glEnd();

}

void TinBar(){

    glColor3ub(0, 0, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(123,151,0);
    glVertex3i(538,181,0);
    glVertex3i(538,192,0);
    glVertex3i(123,162,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(631,187,0);
    glVertex3i(1003,212,0);
    glVertex3i(1003,222,0);
    glVertex3i(631,196,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(529,195,0);
    glVertex3i(638,202,0);
    glVertex3i(638,215,0);
    glVertex3i(532,208,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(529,195,0);
    glVertex3i(532,208,0);
    glVertex3i(510,308,0);
    glVertex3i(508,297,0);
    glEnd();
}

void Tin(){

    glColor3ub(0, 153, 51);
    glPointSize(10.0);
    glBegin(GL_POLYGON);
    glVertex3i(117,160,0);
    glVertex3i(537,192,0);
    glVertex3i(520,292,0);
    glVertex3i(256,280,0);
    glVertex3i(245,245,0);
    glVertex3i(146,240,0);
    glEnd();

    glColor3ub(0, 153, 51);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(631,196,0);
    glVertex3i(1003,222,0);
    glVertex3i(956,315,0);
    glVertex3i(606,299,0);
    glEnd();

}

void UpTin(){

    glColor3ub(0, 0, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(529,195,0);
    glVertex3i(638,202,0);
    glVertex3i(638,215,0);
    glVertex3i(532,208,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(529,195,0);
    glVertex3i(532,208,0);
    glVertex3i(510,308,0);
    glVertex3i(508,297,0);
    glEnd();

    glColor3ub(0, 0,0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(529,195,0);
    glVertex3i(638,215,0);
    glVertex3i(601,312,0);
    glVertex3i(510,308,0);
    glEnd();

}

void SideBuilding(){

    glColor3ub(153, 77, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(0,180,0);
    glVertex3i(126,190,0);
    glVertex3i(131,273,0);
    glVertex3i(0,265,0);
    glEnd();

    glColor3ub(179, 89, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(126,190,0);
    glVertex3i(147,200,0);
    glVertex3i(147,298,0);
    glVertex3i(131,273,0);
    glEnd();

    glColor3ub(255, 170, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(128,234,0);
    glVertex3i(209,244,0);
    glVertex3i(249,315,0);
    glVertex3i(172,313,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glPointSize(10.0);
    glBegin(GL_QUADS);
    glVertex3i(140,270,0);
    glVertex3i(146,274,0);
    glVertex3i(146,304,0);
    glVertex3i(140,300,0);
    glEnd();

}


void myDisplay()
{
    glClear (GL_COLOR_BUFFER_BIT);
    SideBuilding();
    TopView();
    Wall();
    TinBar();
    Tin();
    UpTin();


    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1024, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("AIUB CAMPUS");
    glutDisplayFunc(myDisplay);

    myInit ();
    srand(clock());
    glutMainLoop();
    return 0;
}
