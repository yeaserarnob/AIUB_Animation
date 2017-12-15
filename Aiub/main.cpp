
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



void SpecialKeys(int key, int x, int y)
{
    switch (key)
	{
		case GLUT_KEY_LEFT:
//            mx -= 10;
            glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
//            mx += 10;
            glutPostRedisplay();
			break;
	}
}

void Full()
{
    glColor3ub(131,183,231);
    glBegin(GL_QUADS);
    glVertex3i(0,0,0);
    glVertex3i(1024,0,0);
    glVertex3i(1024,768,0);
    glVertex3i(0,768,0);
}

void Road()
{
    glColor3ub(78,78,78);
    glBegin(GL_QUADS);
    glVertex3i(0,0,0);
    glVertex3i(1024,0,0);
    glVertex3i(1024,120,0);
    glVertex3i(0,120,0);
    glEnd();
}

void playGround()
{
    //Grass
    glColor3ub(42,95,17);
    glBegin(GL_QUADS);
    glVertex3i(0,120,0);
    glVertex3i(1024,120,0);
    glVertex3i(1024,260,0);
    glVertex3i(0,260,0);
    glEnd();

    //Walkway
    glColor3ub(140,88,54);
    glBegin(GL_QUADS);
    glVertex3i(0,250,0);
    glVertex3i(1024,250,0);
    glVertex3i(1024,260,0);
    glVertex3i(0,260,0);

}
//Dynamic Tree Function
void Tree(int x,int y,int z)
{
    //Timber
    glColor3ub(90,70,60);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+7,y,z);
    glVertex3i(x+7,y+20,z);
    glVertex3i(x,y+20,z);
    glEnd();

    //Lower Leaf
    glColor3ub(14,120,14);
    glBegin(GL_TRIANGLES);
    glVertex3i(x-15,y+19,z);
    glVertex3i(x+22,y+19,z);
    glVertex3f(x+3.5,y+45,z);
    glEnd();

    //Upper Leaf
    glBegin(GL_TRIANGLES);
    glVertex3i(x-10,y+35,z);
    glVertex3i(x+17,y+35,z);
    glVertex3f(x+3.5,y+60,z);
    glEnd();
}

//Buildings
void FirstBuilding()
{
    //Left Building
    glColor3ub(56,46,47);
    glBegin(GL_QUADS);
    glVertex3i(0,260,0);
    glVertex3i(396,260,0);
    glVertex3i(396,375,0);
    glVertex3i(0,375,0);
    glEnd();

    //Right Building
    glBegin(GL_QUADS);
    glVertex3i(628,260,0);
    glVertex3i(1024,260,0);
    glVertex3i(1024,375,0);
    glVertex3i(628,375,0);
    glEnd();

    //Middle
    glColor3ub(48,49,54);
    glBegin(GL_QUADS);
    glVertex3i(396,260,0);
    glVertex3i(628,260,0);
    glVertex3i(628,400,0);
    glVertex3i(396,400,0);
    glEnd();
}
//Dynamic Windows Function
void Windows(int x,int y,int z)
{
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+60,y,z);
    glVertex3i(x+60,y+70,z);
    glVertex3i(x,y+70,z);
    glEnd();

    //Black

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(x+7,y+7,z);
    glVertex3i(x+27,y+7,z);
    glVertex3i(x+27,y+33,z);
    glVertex3i(x+7,y+33,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+33,y+7,z);
    glVertex3i(x+54,y+7,z);
    glVertex3i(x+54,y+33,z);
    glVertex3i(x+33,y+33,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+7,y+40,z);
    glVertex3i(x+27,y+40,z);
    glVertex3i(x+27,y+63,z);
    glVertex3i(x+7,y+63,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+33,y+40,z);
    glVertex3i(x+54,y+40,z);
    glVertex3i(x+54,y+63,z);
    glVertex3i(x+33,y+63,z);
    glEnd();
}


void myDisplay()
{

    glClear (GL_COLOR_BUFFER_BIT);
    //Full Body
    Full();
    //Road
    Road();
    //Play Ground
    playGround();
    //Building
    FirstBuilding();
    //Windows
    Windows(16,280,0);
    Windows(106,280,0);
    Windows(196,280,0);
    Windows(286,280,0);
    Windows(646,280,0);
    Windows(736,280,0);
    Windows(826,280,0);
    Windows(916,280,0);
    Windows(1006,280,0);
    //Tree
    Tree(36,260,0);
    Tree(196,260,0);
    Tree(356,260,0);
    Tree(676,260,0);
    Tree(836,260,0);
    Tree(996,260,0);
    glFlush();

    //translate();
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
    glutSpecialFunc(SpecialKeys);
    myInit ();
    srand(clock());
    glutMainLoop();
    return 0;
}
