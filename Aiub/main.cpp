
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
static GLfloat spin = 0.0;
float spin_x=1.0;
float spin_y=0.0;
float spin_z=0.0;
bool day=true;

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1024, 0.0, 768.0);
}

void Full()
{
    glColor3ub(131,183,231);
    glBegin(GL_QUADS);
    glVertex3i(-200,0,0);
    glVertex3i(1324,0,0);
    glVertex3i(1324,768,0);
    glVertex3i(-200,768,0);
}
//Road
void Road()
{
    glColor3ub(78,78,78);
    glBegin(GL_QUADS);
    glVertex3i(-200,0,0);
    glVertex3i(1324,0,0);
    glVertex3i(1324,120,0);
    glVertex3i(-200,120,0);
    glEnd();
}
void roadBorder()
{
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex3i(-200,120,0);
    glVertex3i(1324,120,0);
    glVertex3i(1324,130,0);
    glVertex3i(-200,130,0);
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
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+50,y,z);
    glVertex3i(x+50,y+10,z);
    glVertex3i(x,y+10,z);
    glEnd();
    //Sleep(50);
    //TranslateRoadLine(x,y,z);
}

void playGround()
{
    //Grass
    glColor3ub(42,95,17);
    glBegin(GL_QUADS);
    glVertex3i(-200,120,0);
    glVertex3i(1324,120,0);
    glVertex3i(1324,260,0);
    glVertex3i(-200,260,0);
    glEnd();

    //Walkway
    glColor3ub(140,88,54);
    glBegin(GL_QUADS);
    glVertex3i(-200,250,0);
    glVertex3i(1324,250,0);
    glVertex3i(1324,260,0);
    glVertex3i(-200,260,0);

}
//dynamic lamp post function
void lampPost(int x,int y,int z)
{
    //verticle
    glColor3ub(222,250,50);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+7,y,z);
    glVertex3i(x+7,y+100,z);
    glVertex3i(x,y+100,z);
    glEnd();

    //horizontal
    glColor3ub(222,250,50);
    glBegin(GL_QUADS);
    glVertex3i(x,y+93,z);
    glVertex3i(x+70,y+93,z);
    glVertex3i(x+70,y+100,z);
    glVertex3i(x,y+100,z);
    glEnd();

    //lightcarry
    glColor3ub(222,250,50);
    glBegin(GL_TRIANGLES);
    glVertex3i(x+50,y+85,z);
    glVertex3i(x+70,y+85,z);
    glVertex3i(x+60,y+93,z);
    glEnd();
}
//light
void Light(int x,int y,int z)
{
    //light
    glColor3ub(200,200,200);
    glBegin(GL_TRIANGLES);
    glVertex3i(x+9,y,z);
    glVertex3i(x+110,y,z);
    glVertex3i(x+60,y+85,z);
    glEnd();

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
   int windowsXf=-310,windowsXl=556;

    //Left Building
    glColor3ub(56,46,47);
    glBegin(GL_QUADS);
    glVertex3i(-200,260,0);
    glVertex3i(396,260,0);
    glVertex3i(396,375,0);
    glVertex3i(-200,375,0);
    glEnd();

    //Right Building
    glBegin(GL_QUADS);
    glVertex3i(628,260,0);
    glVertex3i(1324,260,0);
    glVertex3i(1324,375,0);
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
    for(int i=6;i>=0;i--)
    {
        windowsXf+=90;
        Windows(windowsXf,280,0);
    }
    //Last 4 Windows
    for(int i=7;i>=0;i--)
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
    //Left One
    glBegin(GL_QUADS);
    glVertex3i(-200,375,0);
    glVertex3i(396,375,0);
    glVertex3i(396,390,0);
    glVertex3i(-200,390,0);
    glEnd();

    //Right One
    glBegin(GL_QUADS);
    glVertex3i(628,375,0);
    glVertex3i(1324,375,0);
    glVertex3i(1324,390,0);
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
    glVertex3i(-200,390,0);
    glVertex3i(396,390,0);
    glVertex3i(396,395,0);
    glVertex3i(-200,395,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(628,390,0);
    glVertex3i(1324,390,0);
    glVertex3i(1324,395,0);
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

//HEAD
//========
//Middle Top Corridor Functions
void VerticalLine(int x,int y,int z)
{
    for(int i=10;i>=0;i--)
    {
        glColor3ub(166,166,166);
        glBegin(GL_QUADS);
        glVertex3i(x,y,0);
        glVertex3i(x+2,y,0);
        glVertex3i(x+2,y+35,0);
        glVertex3i(x,y+35,0);
        glEnd();
        x+=10;
    }
}

void HorizontalLine(int x,int y,int z)
{
    for(int i=3;i>=0;i--)
    {
        glColor3ub(166,166,166);
        glBegin(GL_QUADS);
        glVertex3i(x,y,0);
        glVertex3i(x+105,y,0);
        glVertex3i(x+105,y+2,0);
        glVertex3i(x,y+2,0);
        glEnd();
        y+=10;
    }
}


//Middle top Corridor Main Function
void MiddleTop()
{
    //Top
    glColor3ub(205,205,205);
    glBegin(GL_QUADS);
    glVertex3i(300,430,0);
    glVertex3i(405,430,0);
    glVertex3i(405,450,0);
    glVertex3i(300,450,0);
    glEnd();
    glColor3ub(255,0,0);
    //Pillar
    glColor3ub(166,166,166);
    glBegin(GL_QUADS);
    glVertex3i(300,395,0);
    glVertex3i(303,395,0);
    glVertex3i(303,430,0);
    glVertex3i(300,430,0);
    glEnd();

    glColor3ub(166,166,166);
    glBegin(GL_QUADS);
    glVertex3i(402,420,0);
    glVertex3i(405,420,0);
    glVertex3i(405,430,0);
    glVertex3i(402,430,0);
    glEnd();
    //Line
    VerticalLine(300,395,0);
    HorizontalLine(300,395,0);
    //Shadow
    glColor3ub(5,5,5);
    glBegin(GL_QUADS);
    glVertex3i(300,427,0);
    glVertex3i(405,427,0);
    glVertex3i(405,431,0);
    glVertex3i(300,431,0);
    glEnd();
<<<<<<< HEAD
}
=======
>>>>>>> 1de34999e01a29612ae83718535e82db72570895
}
<<<<<<< HEAD
=======

<<<<<<< HEAD
=======
<<<<<<< HEAD

//Middle top Corridor Main Function
void MiddleTop()
{
//Top
glColor3ub(205,205,205);
glBegin(GL_QUADS);
glVertex3i(300,430,0);
glVertex3i(405,430,0);
glVertex3i(405,450,0);
glVertex3i(300,450,0);
glEnd();
glColor3ub(255,0,0);
//Pillar
glColor3ub(166,166,166);
glBegin(GL_QUADS);
glVertex3i(300,395,0);
glVertex3i(303,395,0);
glVertex3i(303,430,0);
glVertex3i(300,430,0);
glEnd();

glColor3ub(166,166,166);
glBegin(GL_QUADS);
glVertex3i(402,420,0);
glVertex3i(405,420,0);
glVertex3i(405,430,0);
glVertex3i(402,430,0);
glEnd();
//Line
VerticalLine(300,395,0);
HorizontalLine(300,395,0);
//Shadow
glColor3ub(5,5,5);
glBegin(GL_QUADS);
glVertex3i(300,427,0);
glVertex3i(405,427,0);
glVertex3i(405,431,0);
glVertex3i(300,431,0);
glEnd();
}
=======
=======
>>>>>>> 9497a98602a69509c7ee9012eba6c272290e790d
>>>>>>> 1de34999e01a29612ae83718535e82db72570895
>>>>>>> 0469f7b89d1285efdadab4c75acbb71e59c665d4
>>>>>>> 267d49676f9b7251fba1889fff9f5c093344c07c
>>>>>>> fa00a27ace647f02ea73d5e1b933c4682521ba8e
void reshape(int w,int h)
{
glViewport(0,0, (GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}


void drawFilledCircle(GLfloat x, GLfloat y,GLfloat z, GLfloat radius){
	int i;
	int triangleAmount = 50; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.1416;
    int color=137;
    int counter=0;
    glColor3ub(color,color,color);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x, y,z); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			counter+=1;
			glVertex3f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount)),z
			);
			if(counter<25)
            {
                color+=3;
                glColor3ub(color,color,color);
            }
            else
            {
                color-=3;
                glColor3ub(color,color,color);
            }
		}
	glEnd();
}


void otherCircle(GLfloat x, GLfloat y,GLfloat z, GLfloat radius,int r,int g,int b)
{
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.1416;
    int counter=0;
    glColor3ub(r,g,b);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x, y,z); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			counter+=1;
			glVertex3f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount)),z
			);
		}
	glEnd();
}

void car()
{
    static float a=-200.0f;
    if(a>=1324)
    {
         a=-200.0f;

    }
    else
    {
        a+=0.5f;
        //glColor3ub(r,g,b);
    }
    glColor3ub(255,0,0);
    glPushMatrix();
    glTranslatef(a,0,0);
    glBegin(GL_QUADS);
    glVertex3i(20,40,0);
    glVertex3i(220,40,0);
    glVertex3i(220,80,0);
    glVertex3i(20,80,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(40,80,0);
    glVertex3i(200,80,0);
    glVertex3i(160,110,0);
    glVertex3i(80,110,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(115,80,0);
    glVertex3i(190,80,0);
    glVertex3i(155,105,0);
    glVertex3i(115,105,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(45,80,0);
    glVertex3i(110,80,0);
    glVertex3i(110,105,0);
    glVertex3i(80,105,0);
    glEnd();

    //handle
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(115,70,0);
    glVertex3i(135,70,0);
    glVertex3i(135,75,0);
    glVertex3i(115,75,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(45,70,0);
    glVertex3i(65,70,0);
    glVertex3i(65,75,0);
    glVertex3i(45,75,0);
    glEnd();

    //backbumper
    otherCircle(30.0f,60.0f,0.0f,19.0f,255,0,0);
    //front bumper
    otherCircle(210.0f,60.0f,0.0f,19.0f,255,0,0);

//Light
    glColor3ub(22,120,15);
    glBegin(GL_QUADS);
    glVertex3i(225,55,0);
    glVertex3i(230,55,0);
    glVertex3i(230,65,0);
    glVertex3i(225,65,0);
    glEnd();

    otherCircle(60.0f,40.0f,0.0f,18.0f,0,0,0);
    otherCircle(60.0f,40.0f,0.0f,10.0f,137,137,137);
    otherCircle(170.0f,40.0f,0.0f,18.0f,0,0,0);
    otherCircle(170.0f,40.0f,0.0f,10.0f,137,137,137);

    glPopMatrix();
    glutPostRedisplay();
}

void truck()
{
    static float a=550.0f;
    if(a<=-1300)
    {
         a=550.0f;

    }
    else
    {
        a-=0.3f;
        //glColor3ub(r,g,b);
    }
    glColor3ub(0,0,255);
    //frontbumper
    glPushMatrix();
    glTranslatef(a,0,0);
    otherCircle(780.0f,130.0f,0.0f,41.0f,0,0,255);
    //main body
    glBegin(GL_QUADS);
    glVertex3i(750,90,0);
    glVertex3i(1000,90,0);
    glVertex3i(1000,140,0);
    glVertex3i(750,140,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(750,140,0);
    glVertex3i(860,140,0);
    glVertex3i(860,160,0);
    glVertex3i(750,160,0);
    glEnd();
    //window
    glBegin(GL_QUADS);
    glVertex3i(750,160,0);
    glVertex3i(860,160,0);
    glVertex3i(860,190,0);
    glVertex3i(800,190,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(760,160,0);
    glVertex3i(855,160,0);
    glVertex3i(855,185,0);
    glVertex3i(800,185,0);
    glEnd();

    //handle
    glBegin(GL_QUADS);
    glVertex3i(840,145,0);
    glVertex3i(855,145,0);
    glVertex3i(855,150,0);
    glVertex3i(840,150,0);
    glEnd();

    //gril
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex3i(860,160,0);
    glVertex3i(1000,160,0);
    glVertex3i(860,159,0);
    glVertex3i(1000,159,0);
    glVertex3i(1000,160,0);
    glVertex3i(1000,140,0);
    glVertex3i(990,160,0);
    glVertex3i(990,140,0);
    glVertex3i(980,160,0);
    glVertex3i(980,140,0);
    glVertex3i(970,160,0);
    glVertex3i(970,140,0);
    glVertex3i(960,160,0);
    glVertex3i(960,140,0);
    glVertex3i(950,160,0);
    glVertex3i(950,140,0);
    glVertex3i(940,160,0);
    glVertex3i(940,140,0);
    glVertex3i(930,160,0);
    glVertex3i(930,140,0);
    glVertex3i(920,160,0);
    glVertex3i(920,140,0);
    glVertex3i(910,160,0);
    glVertex3i(910,140,0);
    glVertex3i(900,160,0);
    glVertex3i(900,140,0);
    glVertex3i(890,160,0);
    glVertex3i(890,140,0);
    glVertex3i(880,160,0);
    glVertex3i(880,140,0);
    glVertex3i(870,160,0);
    glVertex3i(870,140,0);
    glEnd();



    //wheel
    otherCircle(800.0f,90.0f,0.0f,21.0f,0,0,0);
    otherCircle(800.0f,90.0f,0.0f,15.0f,131,131,131);
    otherCircle(950.0f,90.0f,0.0f,21.0f,0,0,0);
    otherCircle(950.0f,90.0f,0.0f,15.0f,131,131,131);

    //backlight
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex3i(1000,110,0);
    glVertex3i(1005,110,0);
    glVertex3i(1005,120,0);
    glVertex3i(1000,120,0);
    glEnd();

    //frontlignt
    glColor3ub(255,255,0);
    glBegin(GL_QUADS);
    glVertex3i(740,90,0);
    glVertex3i(750,90,0);
    glVertex3i(750,102,0);
    glVertex3i(740,102,0);
    glEnd();

<<<<<<< HEAD
    glPopMatrix();
    glutPostRedisplay();

=======
<<<<<<< HEAD
    glPopMatrix();
    glutPostRedisplay();

=======

    glPopMatrix();
    glutPostRedisplay();

<<<<<<< HEAD

=======
>>>>>>> 9497a98602a69509c7ee9012eba6c272290e790d
>>>>>>> 1de34999e01a29612ae83718535e82db72570895
>>>>>>> 0469f7b89d1285efdadab4c75acbb71e59c665d4
>>>>>>> 267d49676f9b7251fba1889fff9f5c093344c07c
>>>>>>> fa00a27ace647f02ea73d5e1b933c4682521ba8e
}

//Plane

void plane()
{
    static float a=-200.0f;
    static float b=0.0f;
    if(a>=1324)
    {
         a=-200.0f;

    }
    else
    {
        a+=0.1f;
        //glColor3ub(r,g,b);
    }
    //Body
    glColor3ub(128, 0, 0);
    glPushMatrix();
    glTranslatef(a,b,0);
    glBegin(GL_QUADS);
    glVertex3i(30,700,0);
    glVertex3i(100,700,0);
    glVertex3i(100,715,0);
    glVertex3i(35,715,0);
    glEnd();

    //front
    glColor3ub(128,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3i(100,700,0);
    glVertex3i(110,707,0);
    glVertex3i(100,715,0);
    glEnd();

    //fanback
    glColor3ub(128, 0, 0);
    glBegin(GL_QUADS);
    glVertex3i(37,715,0);
    glVertex3i(57,715,0);
    glVertex3i(40,730,0);
    glVertex3i(20,730,0);
    glEnd();

    //fanFrontUp
    glColor3ub(128, 0, 0);
    glBegin(GL_QUADS);
    glVertex3i(70,715,0);
    glVertex3i(80,715,0);
    glVertex3i(60,735,0);
    glVertex3i(50,735,0);
    glEnd();

    //FanFrontDown
    glColor3ub(128,0,0);
    glBegin(GL_QUADS);
    glVertex3i(70,700,0);
    glVertex3i(80,700,0);
    glVertex3i(60,680,0);
    glVertex3i(50,680,0);
    glEnd();

    //window
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    glVertex3i(95,710,0);
    glVertex3i(90,710,0);
    glVertex3i(85,710,0);
    glVertex3i(80,710,0);
    glVertex3i(75,710,0);
    glVertex3i(70,710,0);
    glVertex3i(65,710,0);
    glVertex3i(60,710,0);
    glVertex3i(55,710,0);
    glEnd();
    glPopMatrix();
    glutPostRedisplay();

}

void planeTwo()
{
     static float a=550.0f;
    if(a<=-1300)
    {
         a=550.0f;

    }
    else
    {
        a-=0.2f;
        //glColor3ub(r,g,b);
    }


    //Body
    glColor3ub(128, 0, 0);
    glPushMatrix();
    glTranslatef(a,0,0);
    glBegin(GL_QUADS);
    glVertex3i(919,650,0);
    glVertex3i(989,650,0);
    glVertex3i(989,665,0);
    glVertex3i(919,665,0);
    glEnd();

    //Front
    glColor3ub(128,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3i(919,650,0);
    glVertex3i(909,657,0);
    glVertex3i(919,665,0);
    glEnd();

    //FanBack
    glColor3ub(128,0,0);
    glBegin(GL_QUADS);
    glVertex3i(987,665,0);
    glVertex3i(1010,680,0);
    glVertex3i(990,680,0);
    glVertex3i(967,665,0);
    glEnd();

    //FanFrontUp
    glColor3ub(128,0,0);
    glBegin(GL_QUADS);
    glVertex3i(949,665,0);
    glVertex3i(959,665,0);
    glVertex3i(979,685,0);
    glVertex3i(969,685,0);
    glEnd();

    //FanFrontDown
    glColor3ub(128,0,0);
    glBegin(GL_QUADS);
    glVertex3i(949,650,0);
    glVertex3i(969,630,0);
    glVertex3i(979,630,0);
    glVertex3i(959,650,0);
    glEnd();

    int x=924;
    //Window
    glColor3ub(255,255,255);
    glBegin(GL_POINTS);
    for(int i=9;i>=0;i--)
    {
        glVertex3i(x,660,0);
        x+=5;
    }
    glEnd();
    glPopMatrix();
    glutPostRedisplay();

}

//Main Display Function
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int roadlineX=-4096;
    int treeXf=-350;
    int treeXl=528;
    int lamp=-350;
    int light=-350;
    glPushMatrix();
    glTranslatef(translate_x,translate_y,translate_z);
   //Full Body
    Full();
    //Road
    Road();
    //RoadLine
    for(int i=55;i>0;i--)
    {
        roadlineX+=100;
        RoadLine(roadlineX,55,0);
    }
<<<<<<< HEAD
    plane();
    planeTwo();
=======
<<<<<<< HEAD
    plane();
    planeTwo();
=======


    plane();
    planeTwo();

>>>>>>> 267d49676f9b7251fba1889fff9f5c093344c07c
>>>>>>> fa00a27ace647f02ea73d5e1b933c4682521ba8e
    //Play Ground
    playGround();
    //Middle Top Corridor
    MiddleTop();

    drawFilledCircle(950.0f,500.0f,0.0f,170.0f);
    //Building
    FirstBuilding();

    //First 4 Tree
    for(int i=5;i>=0;i--)
    {
        treeXf+=120;
        Tree(treeXf,260,0);
    }
    //Last 4 Tree
    for(int i=5;i>=0;i--)
    {
        treeXl+=120;
        Tree(treeXl,260,0);
    }
    //Front top corridor
    FrontTop();

    //TinShade

    TinShade();

    //lamp post
    for(int i=9;i>=0;i--)
    {
        lamp+=310;
        lampPost(lamp,130,0);
    }
    //light
    for(int i=9;i>=0;i--)
    {
        light+=310;
        Light(light,130,0);
    }
    roadBorder();
    TinShade();
    glPopMatrix();

    truck();
    car();
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======



>>>>>>> 267d49676f9b7251fba1889fff9f5c093344c07c
>>>>>>> fa00a27ace647f02ea73d5e1b933c4682521ba8e
    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
//-------- spin --------
if(key=='d')
{
    day=true;
}
else if(key=='n')
{
    day=false;
}
}
void SpecialKeys(int key, int x, int y)
{
    switch (key)
	{
		case GLUT_KEY_LEFT:
            if(translate_x<200)
            {
                translate_x+=5;
                glutPostRedisplay();
            }
			break;

		case GLUT_KEY_RIGHT:
            if(translate_x>-300)
            {
                translate_x-=5;
                glutPostRedisplay();
            }
			break;

        case GLUT_KEY_UP:
            spin-=5;
            if(spin>=360)
            {
                spin=0;
            }
            glutPostRedisplay();
			break;

        case GLUT_KEY_DOWN:
            spin+=5;
            if(spin<=360)
            {
                spin=0;
            }
            glutPostRedisplay();
			break;
	}
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1024, 768);
glutInitWindowPosition (0, 0);
glutCreateWindow ("AIUB");
myInit();
glutDisplayFunc(myDisplay);
//glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutSpecialFunc(SpecialKeys);
glutMainLoop();
return 0;
}
