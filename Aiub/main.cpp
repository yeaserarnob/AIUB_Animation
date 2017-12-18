
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <iostream>
using namespace std;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = 0.0;

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
//Road
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
void TranslateRoadLine(int x,int y,int z)
{
    x-=50;
    if(x<=0)
    {
        x=1050;
    }
    glutPostRedisplay();
    Sleep(50);
}
//ROad Line
void RoadLine(int x,int y,int z)
{
    static float a=.0f;
    a+=.002f;
    if(a==49)
    {
        x=x-49;
    }
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(a,.0f,.0f);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+50,y,z);
    glVertex3i(x+50,y+10,z);
    glVertex3i(x,y+10,z);
    glEnd();

    glPopMatrix();
    glutPostRedisplay();
    //Sleep(50);
    //TranslateRoadLine(x,y,z);
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
//Buildings
void FirstBuilding()
{
   int windowsXf=-74,windowsXl=556;

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

    //First 4 Windows
    for(int i=3;i>=0;i--)
    {
        windowsXf+=90;
        Windows(windowsXf,280,0);
    }
    //Last 4 Windows
    for(int i=4;i>=0;i--)
    {
        windowsXl+=90;
        Windows(windowsXl,280,0);
    }
}
//Cross For Tin Shade;
void Cross(int x,int y,int z)
{
    glColor3b(10,150,12);
    glBegin(GL_QUADS);

    glVertex3i(x,y,z);
    glVertex3i(x+2,y,z);
    glVertex3i(x+2,y+15,z);
    glVertex3i(x,y+15,z);
    glEnd();

}
//TinShade
void TinShade()
{
    glColor3ub(233,235,238);
    //Right One
    glBegin(GL_QUADS);
    glVertex3i(0,375,0);
    glVertex3i(396,375,0);
    glVertex3i(396,390,0);
    glVertex3i(0,390,0);
    glEnd();

    //Left One
    glBegin(GL_QUADS);
    glVertex3i(628,375,0);
    glVertex3i(1024,375,0);
    glVertex3i(1024,390,0);
    glVertex3i(628,390,0);
    glEnd();

    //Middle One
    glBegin(GL_QUADS);
    glVertex3i(386,400,0);
    glVertex3i(638,400,0);
    glVertex3i(638,420,0);
    glVertex3i(386,420,0);
    glEnd();
    //Green Top
    glColor3ub(42,85,6);
    glBegin(GL_QUADS);
    glVertex3i(0,390,0);
    glVertex3i(396,390,0);
    glVertex3i(396,395,0);
    glVertex3i(0,395,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(628,390,0);
    glVertex3i(1024,390,0);
    glVertex3i(1024,395,0);
    glVertex3i(628,395,0);
    glEnd();

    //Left Top Side
    glColor3ub(140,140,130);
    glBegin(GL_QUADS);
    glVertex3i(0,395,0);
    glVertex3i(125,395,0);
    glVertex3i(120,410,0);
    glVertex3i(0,410,0);
    glEnd();
    //Cross
    int CrossX=0;
    for(int i=15;i>0;i--)
    {
        Cross(CrossX,395,0);
        CrossX+=8;
    }

    glColor3b(10,150,12);
    glBegin(GL_QUADS);
    glVertex3i(0,400,0);
    glVertex3i(125,400,0);
    glVertex3i(122,402,0);
    glVertex3i(0,402,0);
    glEnd();
}

void Pillar(int x,int y,int z)
{
    glColor3ub(166,166,166);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+3,y,z);
    glVertex3i(x+3,y+45,z);
    glVertex3i(x,y+45,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+15,y,z);
    glVertex3i(x+18,y,z);
    glVertex3i(x+18,y+40,z);
    glVertex3i(x+15,y+40,z);
    glEnd();
}

void FrontTop()
{
    int pillarX=0;
    //Back
    //glColor4ub(229,229,229,250);
    glColor3ub(147,154,174);
    glBegin(GL_QUADS);
    glVertex3i(3,395,0);
    glVertex3i(120,395,0);
    glVertex3i(120,440,0);
    glVertex3i(3,442,0);
    glEnd();

    glColor3ub(147,154,174);
    glBegin(GL_QUADS);
    glVertex3i(120,395,0);
    glVertex3i(220,395,0);
    glVertex3i(220,410,0);
    glVertex3i(120,410,0);
    glEnd();

    //Green Tin Shade
    glColor3ub(83,186,60);
    glBegin(GL_QUADS);
    glVertex3i(0,440,0);
    glVertex3i(200,440,0);
    glVertex3i(210,455,0);
    glVertex3i(10,455,0);
    glEnd();
    //Front Triangle
    glColor3ub(48,56,67);
    glBegin(GL_TRIANGLES);
    glVertex3i(190,435,0);
    glVertex3i(220,435,0);
    glVertex3i(210,455,0);
    glEnd();
    //Shadow
    glBegin(GL_QUADS);
    glVertex3i(0,436,0);
    glVertex3i(200,435,0);
    glVertex3i(210,440,0);
    glVertex3i(0,440,0);
    glEnd();
    //Pillar
    for(int i=6;i>=0;i--)
    {

        Pillar(pillarX,395,0);
        pillarX+=32;
    }

//    glBegin(GL_QUADS);
//    glVertex3i(208,395,0);
//    glVertex3i(211,395,0);
//    glVertex3i(211,454,0);
//    glVertex3i(208,454,0);
//    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(217,395,0);
    glVertex3i(220,395,0);
    glVertex3i(220,435,0);
    glVertex3i(217,435,0);
    glEnd();
}

void reshape(int w,int h)
{
glViewport(0,0, (GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//glLoadIdentity();

    int roadlineX=-2048,treeXf=-104,treeXl=528;

   //Full Body
    Full();

    //Road
    Road();
    //RoadLine
    for(int i=33;i>0;i--)
    {
        roadlineX+=100;
        RoadLine(roadlineX,55,0);
    }
    //Play Ground
    playGround();
    //Building
    FirstBuilding();

    //First 4 Tree
    for(int i=3;i>=0;i--)
    {
        treeXf+=120;
        Tree(treeXf,260,0);
    }
    //Last 4 Tree
    for(int i=3;i>=0;i--)
    {
        treeXl+=120;
        Tree(treeXl,260,0);
    }


    //Front top
    FrontTop();
    //TinShade
    TinShade();

    glFlush();

//------- custom code ends -------
//******************************************//
glutSwapBuffers();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1024, 768);
glutInitWindowPosition (0, 0);
glutCreateWindow ("AIUB");
myInit ();
glutDisplayFunc(myDisplay);
glutMainLoop();
return 0;
}
