#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <time.h>
#include <iostream>
#include <MMSystem.h>
using namespace std;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = 0.0;
static GLfloat spin = 0.0;
float spin_x=1.0;
float spin_y=0.0;
float spin_z=0.0;
int day=1;
bool rain=false;
bool carv=false;
bool planev=false;
bool top=false;
int flag=0;
bool help=false;


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1024, 0.0, 768.0);
}


void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{
		glutBitmapCharacter(currentfont,*c);
	}
}

void Full(int r,int g,int b)
{
    glColor3ub(r,g,b);
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

void tprint(int x, int y,int z, char *string)
{
    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x,y);
    //get the length of the string to display
    int len = (int) strlen(string);

    //loop to display character by character
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
    }
};
void ttprint(int x, int y,int z, char *string)
{
    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x,y);
    //get the length of the string to display
    int len = (int) strlen(string);

    //loop to display character by character
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
};


void playGround(int r,int g,int b)
{
    //Grass
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex3i(-200,120,0);
    glVertex3i(1324,120,0);
    glVertex3i(1324,260,0);
    glVertex3i(-200,260,0);
    glEnd();

    //Walkway
    glColor3ub(94, 65, 33);
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
    glBegin(GL_QUADS);
    glVertex3i(x+9,y,z);
    glVertex3i(x+110,y,z);
    glVertex3i(x+70,y+85,z);
    glVertex3i(x+50,y+85,z);
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
void FirstBuilding(int r,int g,int b)
{
   int windowsXf=-310,windowsXl=556;

    //Left Building
    glColor3ub(r,g,b);
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
    glColor3ub(205,205,204);
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
void reshape(int w,int h)
{
glViewport(0,0, (GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}


void drawFilledCircle(GLfloat x, GLfloat y,GLfloat z, GLfloat radius,int color){
	int i;
	int triangleAmount = 50; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.1416;
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
    static float a=-400.0f;
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
    static float a=-400.0f;
=======
<<<<<<< HEAD
    static float a=-400.0f;
=======
    static float a=-300.0f;
>>>>>>> a1354934d1fbf0ac029967e711a0472efbcecb04
>>>>>>> aec637b28d67700676c4c318975cc29ea895aeb9
<<<<<<< HEAD
>>>>>>> 8625d0087f64fec91d4e1223b0d6c4964e164bde
=======
>>>>>>> 8625d0087f64fec91d4e1223b0d6c4964e164bde
    if(a>=1324)
    {
         a=-400.0f;

    }
    else
    {
        a+=0.2f;
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
    glColor3ub(250,250,0);
    glBegin(GL_QUADS);
    glVertex3i(225,55,0);
    glVertex3i(230,55,0);
    glVertex3i(230,65,0);
    glVertex3i(225,65,0);
    glEnd();

    //carlight
    if(day==2)
    {
        glColor3ub(200,200,200);
        glBegin(GL_QUADS);
        glVertex3i(230,55,0);
        glVertex3i(280,20,0);
        glVertex3i(280,95,0);
        glVertex3i(225,65,0);
        glEnd();
    }

    otherCircle(60.0f,40.0f,0.0f,18.0f,0,0,0);
    otherCircle(60.0f,40.0f,0.0f,10.0f,137,137,137);
    otherCircle(170.0f,40.0f,0.0f,18.0f,0,0,0);
    otherCircle(170.0f,40.0f,0.0f,10.0f,137,137,137);

    glPopMatrix();
    glutPostRedisplay();
}


void car2()
{
    static float a=-1100.0f;
    if(a>=1324)
    {
         a=-1100.0f;

    }
    else
    {
        a+=0.2f;
        //glColor3ub(r,g,b);
    }
    glColor3ub(0,0,255);
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
    otherCircle(30.0f,60.0f,0.0f,19.0f,0,0,255);
    //front bumper
    otherCircle(210.0f,60.0f,0.0f,19.0f,0,0,255);

    //Light
    glColor3ub(250,250,0);
    glBegin(GL_QUADS);
    glVertex3i(225,55,0);
    glVertex3i(230,55,0);
    glVertex3i(230,65,0);
    glVertex3i(225,65,0);
    glEnd();

    //carlight
    if(day==2)
    {
        glColor3ub(200,200,200);
        glBegin(GL_QUADS);
        glVertex3i(230,55,0);
        glVertex3i(280,20,0);
        glVertex3i(280,95,0);
        glVertex3i(225,65,0);
        glEnd();
    }

    otherCircle(60.0f,40.0f,0.0f,18.0f,0,0,0);
    otherCircle(60.0f,40.0f,0.0f,10.0f,137,137,137);
    otherCircle(170.0f,40.0f,0.0f,18.0f,0,0,0);
    otherCircle(170.0f,40.0f,0.0f,10.0f,137,137,137);

    glPopMatrix();
    glutPostRedisplay();
}



void truck()
{
    static float a=650.0f;
    if(a<=-1300)
    {
         a=550.0f;

    }
    else
    {
        a-=0.2f;
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



    //trucklight
    if(day==2)
    {
        glColor3ub(200,200,200);
        glBegin(GL_QUADS);
        glVertex3i(680,60,0);
        glVertex3i(740,90,0);
        glVertex3i(740,102,0);
        glVertex3i(680,130,0);
        glEnd();
    }
    glColor3ub(255,255,255);
    ttprint(860,110,0,"AIUB");
    glPopMatrix();
    glutPostRedisplay();
}

//Plane

void plane()
{
    static float a=-300.0f;
    static float b=0.0f;
    if(a>=1324)
    {
         a=-300.0f;
         b=0.0f;

    }
    else
    {
        a+=0.1f;
        b+=0.005f;
        //glColor3ub(r,g,b);
    }
    //Body
    glColor3ub(66, 66, 66);
    glPushMatrix();
    glTranslatef(a,b,0);
    glBegin(GL_QUADS);
    glVertex3i(30,700,0);
    glVertex3i(100,700,0);
    glVertex3i(100,715,0);
    glVertex3i(35,715,0);
    glEnd();

    //front
    glBegin(GL_TRIANGLES);
    glVertex3i(100,700,0);
    glVertex3i(110,707,0);
    glVertex3i(100,715,0);
    glEnd();

    //fanback
    glBegin(GL_QUADS);
    glVertex3i(37,715,0);
    glVertex3i(57,715,0);
    glVertex3i(40,730,0);
    glVertex3i(20,730,0);
    glEnd();

    //fanFrontUp
    glBegin(GL_QUADS);
    glVertex3i(70,715,0);
    glVertex3i(80,715,0);
    glVertex3i(60,735,0);
    glVertex3i(50,735,0);
    glEnd();

    //FanFrontDown
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
     static float b=0.0f;
    if(a<=-1300)
    {
         a=550.0f;
         b=0.0f;

    }
    else
    {
        a-=0.2f;
        b-=0.02f;
        //glColor3ub(r,g,b);
    }


    //Body
    glColor3ub(128, 128, 128);
    glPushMatrix();
    glTranslatef(a,b,0);
    glBegin(GL_QUADS);
    glVertex3i(919,650,0);
    glVertex3i(989,650,0);
    glVertex3i(989,665,0);
    glVertex3i(919,665,0);
    glEnd();

    //Front
    glBegin(GL_TRIANGLES);
    glVertex3i(919,650,0);
    glVertex3i(909,657,0);
    glVertex3i(919,665,0);
    glEnd();

    //FanBack
    glBegin(GL_QUADS);
    glVertex3i(987,665,0);
    glVertex3i(1010,680,0);
    glVertex3i(990,680,0);
    glVertex3i(967,665,0);
    glEnd();

    //FanFrontUp
    glBegin(GL_QUADS);
    glVertex3i(949,665,0);
    glVertex3i(959,665,0);
    glVertex3i(979,685,0);
    glVertex3i(969,685,0);
    glEnd();

    //FanFrontDown
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

//clouds
void clouds(float x,float y,float z,int m,int l,int n)
{
    static float a=-1300.0f;
    if(a>=1324)
    {
         a=-1300.0f;

    }
    else
    {
        a+=0.005f;
        //glColor3ub(r,g,b);
    }
    glPushMatrix();
    glTranslatef(a,0,0);


    //cloud1
    otherCircle(x,y,z,50.0f,m,l,n);
    otherCircle(x-50,y,z,40.0f,m,l,n);
    otherCircle(x+50,y,z,40.0f,m,l,n);
    glPopMatrix();
    glutPostRedisplay();
}
//circleline
void circleLine()
{
    glColor3ub(240,240,240);
    glBegin(GL_LINES);
    glLineWidth(5.0f);
    glVertex3i(780,500,0);
    glVertex3i(1120,500,0);
    glVertex3i(788,550,0);
    glVertex3i(1112,550,0);
    glVertex3i(812,600,0);
    glVertex3i(1088,600,0);
    glVertex3i(788,450,0);
    glVertex3i(1112,450,0);
    glVertex3i(812,400,0);
    glVertex3i(1088,400,0);
    glEnd();
}

void rainf()
{
    int x=0;
    int y=778;
    static float a=-760.0f;
    if(a<=-768)
    {
         a=-760.0f;

    }
    else
    {
        a-=0.5f;
        //glColor3ub(r,g,b);
    }
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(0.0f,a,0.0f);
    glBegin(GL_LINES);
    for(int i=500;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            glVertex3i(x,y,0);
            glVertex3i(x+3,y+10,0);
            x+=rand()%1050;
        }
        y+=rand()%15;
        x=0;

    }
    glEnd();
    glPopMatrix();
    glutPostRedisplay();

}
//LampStand
void toplampPost(int x,int y,int z)
{
    otherCircle(x+60,y+3,0,5,222,250,50);
    glColor3ub(222,250,50);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+70,y,z);
    glVertex3i(x+70,y+5,z);
    glVertex3i(x,y+5,z);
    glEnd();
}
//Car

void topCar()
{
    static float a=-400.0f;
    if(a>=1324)
    {
         a=-500.0f;

    }
    else
    {
        a+=0.5f;
        //glColor3ub(r,g,b);
    }
    glPushMatrix();
    glTranslatef(a,0,0);
    otherCircle(-100,18,0,23,255,0,0);
    otherCircle(-130,18,0,23,255,0,0);
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex3i(-100,0,0);
    glVertex3i(-135,0,0);
    glVertex3i(-135,40,0);
    glVertex3i(-100,40,0);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(-105,5,0);
    glVertex3i(-90,10,0);
    glVertex3i(-90,30,0);
    glVertex3i(-105,35,0);
    glEnd();

    glPopMatrix();
    glutPostRedisplay();
}
//Top View

void topView(int x,int y,int z)
{
    int roadlineX=-300;
    int LamppostX=-350;
    int treeXf=-350;
    int treeXl=528;
//    Road
    glColor3ub(58,58,58);
    glBegin(GL_QUADS);
    glVertex3i(-200,0,0);
    glVertex3i(1324,0,0);
    glVertex3i(1324,100,0);
    glVertex3i(-200,100,0);
    glEnd();

    for(int i=25;i>0;i--)
    {
        roadlineX+=100;
        RoadLine(roadlineX,40,0);
    }
    //RoadBorder
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex3i(-200,95,0);
    glVertex3i(1324,95,0);
    glVertex3i(1324,110,0);
    glVertex3i(-200,110,0);
    glEnd();

    for(int i=10;i>0;i--)
    {
        toplampPost(LamppostX,100,0);
        LamppostX+=310;
    }

    topCar();
    //topTruck();

    //PlayGround

    glColor3ub(52,135,37);
    glBegin(GL_QUADS);
    glVertex3i(-200,110,0);
    glVertex3i(1324,110,0);
    glVertex3i(1324,240,0);
    glVertex3i(-200,240,0);
    glEnd();

    //walkway

    glColor3ub(150,90,50);
    glBegin(GL_QUADS);
    glVertex3i(-200,240,0);
    glVertex3i(1324,240,0);
    glVertex3i(1324,260,0);
    glVertex3i(-200,260,0);
    glEnd();

    //Tree

    for(int i=5;i>=0;i--)
    {
        treeXf+=120;
        otherCircle(treeXf,250,0,10,70,180,50);

    }

    for(int i=5;i>=0;i--)
    {
        treeXl+=120;
        otherCircle(treeXl,250,0,10,70,180,50);

    }

    //Top Tin Shade

    //left
    glColor3ub(42,85,66);
    glBegin(GL_QUADS);
    glVertex3i(0,260,0);
    glVertex3i(396,260,0);
    glVertex3i(396,360,0);
    glVertex3i(0,360,0);
    glEnd();

    glColor3ub(25,25,25);
    glBegin(GL_QUADS);
    glVertex3i(-200,260,0);
    glVertex3i(0,260,0);
    glVertex3i(0,320,0);
    glVertex3i(-200,320,0);
    glEnd();
    //right
    glColor3ub(42,85,66);
    glBegin(GL_QUADS);
    glVertex3i(628,260,0);
    glVertex3i(1324,260,0);
    glVertex3i(1324,360,0);
    glVertex3i(628,360,0);
    glEnd();
    //white shade bottom
    glColor3ub(242,255,255);
    glBegin(GL_QUADS);
    glVertex3i(0,260,0);
    glVertex3i(1324,260,0);
    glVertex3i(1324,265,0);
    glVertex3i(0,265,0);
    glEnd();
    //white shade top
    glColor3ub(242,255,255);
    glBegin(GL_QUADS);
    glVertex3i(0,360,0);
    glVertex3i(1324,360,0);
    glVertex3i(1324,355,0);
    glVertex3i(0,355,0);
    glEnd();

    //middle

    glColor3ub(42,105,86);
    glBegin(GL_QUADS);
    glVertex3i(396,255,0);
    glVertex3i(628,255,0);
    glVertex3i(628,365,0);
    glVertex3i(396,365,0);
    glEnd();
    //white shade middle
    glColor3ub(242,255,255);
    glBegin(GL_QUADS);
    glVertex3i(396,255,0);
    glVertex3i(628,255,0);
    glVertex3i(628,260,0);
    glVertex3i(396,260,0);
    glEnd();

    glColor3ub(242,255,255);
    glBegin(GL_QUADS);
    glVertex3i(396,360,0);
    glVertex3i(628,360,0);
    glVertex3i(628,365,0);
    glVertex3i(396,365,0);
    glEnd();

    glColor3ub(242,255,255);
    glBegin(GL_QUADS);
    glVertex3i(396,255,0);
    glVertex3i(400,255,0);
    glVertex3i(400,365,0);
    glVertex3i(396,365,0);
    glEnd();

    glColor3ub(242,255,255);
    glBegin(GL_QUADS);
    glVertex3i(624,255,0);
    glVertex3i(628,255,0);
    glVertex3i(628,365,0);
    glVertex3i(624,365,0);
    glEnd();

//    Anex-2
    glColor3ub(42,85,45);
    glBegin(GL_QUADS);
    glVertex3i(-200,320,0);
    glVertex3i(0,320,0);
    glVertex3i(0,410,0);
    glVertex3i(-200,410,0);
    glEnd();
//    white shade
    //bottom
    glColor3ub(255,255,225);
    glBegin(GL_QUADS);
    glVertex3i(-200,320,0);
    glVertex3i(0,320,0);
    glVertex3i(0,325,0);
    glVertex3i(-200,325,0);
    glEnd();
//    top
    glColor3ub(255,255,225);
    glBegin(GL_QUADS);
    glVertex3i(-200,405,0);
    glVertex3i(0,405,0);
    glVertex3i(0,410,0);
    glVertex3i(-200,410,0);
    glEnd();
    //Right
    glColor3ub(255,255,225);
    glBegin(GL_QUADS);
    glVertex3i(-5,260,0);
    glVertex3i(0,260,0);
    glVertex3i(0,410,0);
    glVertex3i(-5,410,0);
    glEnd();

    //Coridor
    glColor3ub(40,90,100);
    glBegin(GL_QUADS);
    glVertex3i(0,340,0);
    glVertex3i(100,340,0);
    glVertex3i(100,400,0);
    glVertex3i(0,400,0);
    glEnd();

    //Middle Coridor Top
    glColor3ub(42,105,85);
    glBegin(GL_QUADS);
    glVertex3i(0,400,0);
    glVertex3i(200,400,0);
    glVertex3i(200,410,0);
    glVertex3i(0,410,0);
    glEnd();

//    middle coridor Top

    glColor3ub(42,105,85);
    glBegin(GL_QUADS);
    glVertex3i(0,410,0);
    glVertex3i(200,410,0);
    glVertex3i(200,510,0);
    glVertex3i(0,510,0);
    glEnd();

//    annex 3

    glColor3ub(42,95,45);
    glBegin(GL_QUADS);
    glVertex3i(-200,510,0);
    glVertex3i(200,510,0);
    glVertex3i(200,660,0);
    glVertex3i(-200,660,0);
    glEnd();

//    Annex 4


    glColor3ub(42,95,45);
    glBegin(GL_QUADS);
    glVertex3i(100,610,0);
    glVertex3i(300,610,0);
    glVertex3i(300,770,0);
    glVertex3i(100,770,0);
    glEnd();

    glColor3ub(42,105,85);
    glBegin(GL_QUADS);
    glVertex3i(300,610,0);
    glVertex3i(500,610,0);
    glVertex3i(500,650,0);
    glVertex3i(300,650,0);
    glEnd();

//    annex 5
    glColor3ub(42,85,45);
    glBegin(GL_QUADS);
    glVertex3i(500,620,0);
    glVertex3i(700,620,0);
    glVertex3i(700,770,0);
    glVertex3i(500,770,0);
    glEnd();

//Ashiq Chattor
    glColor3ub(42,90,45);
    glBegin(GL_QUADS);
    glVertex3i(700,640,0);
    glVertex3i(800,640,0);
    glVertex3i(800,690,0);
    glVertex3i(700,690,0);
    glEnd();

    glColor3ub(42,85,45);
    glBegin(GL_QUADS);
    glVertex3i(750,640,0);
    glVertex3i(900,640,0);
    glVertex3i(900,770,0);
    glVertex3i(750,770,0);
    glEnd();

    drawFilledCircle(900,520,0,110,177);

}

void nightMode()
{
    int roadlineX=-300;
    int treeXf=-350;
    int treeXl=528;
    int lamp=-350;
    int light=-350;
    //Full Body
        Full(55,55,55);
        //Road
        Road();
        //RoadLine
        for(int i=55;i>0;i--)
        {
            roadlineX+=100;
            RoadLine(roadlineX,55,0);
        }

        //moon
        otherCircle(300.0f,670.0f,0.0f,32.0f,250,250,250);
        //cloud-1
        clouds(-450.0f,670.0f,0.0f,173, 173, 133);
        //cloud0
        clouds(-150.0f,630.0f,0.0f,173, 173, 133);
        //cloud1
        clouds(150.0f,670.0f,0.0f,173, 173, 133);
        if(planev)
        {
            plane();
            planeTwo();
        }
        //cloud2
        clouds(450.0f,600.0f,0.0f,205, 205, 177);
        //cloud3
        clouds(750.0f,690.0f,0.0f,173, 173, 133);
        //cloud4
        clouds(1050.0f,680.0f,0.0f,173, 173, 133);
        playGround(42,55,17);
        //Middle Top Corridor
        MiddleTop();

        drawFilledCircle(950.0f,500.0f,0.0f,170.0f,55.0f);
        //Building
        FirstBuilding(56,46,47);

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
        circleLine();
        glColor3ub(0,0,255);
        tprint(330,433,0,"AIUB");
        if(carv)
        {
            truck();
            car();
            car2();
        }
        glPopMatrix();

        if(rain)
        {

            rainf();
            //PlaySound(TEXT("D:\\GraohicsProject\\AIUB\\Aiub\\rain-07.wav"), NULL,SND_FILENAME|SND_LOOP);
        }
}

void dayMode()
{
        int roadlineX=-300;
        int treeXf=-350;
        int treeXl=528;
        int lamp=-350;
        int light=-350;

        Full(131,183,231);
        //Road
        Road();
        //RoadLine
        for(int i=55;i>0;i--)
        {
            roadlineX+=100;
            RoadLine(roadlineX,55,0);
        }
        //cloud0
        clouds(-100.0f,630.0f,0.0f,250,250,250);
        //cloud1
        clouds(150.0f,670.0f,0.0f,250,250,250);
       if(planev)
        {
            plane();
            planeTwo();
        }
        //cloud2
        clouds(450.0f,600.0f,0.0f,250,250,250);
        //cloud3
        clouds(750.0f,690.0f,0.0f,250,250,250);
        //cloud4
        clouds(1050.0f,710.0f,0.0f,250,250,250);
        //Play Ground
        playGround(42,95,17);
        //Middle Top Corridor
        MiddleTop();

        drawFilledCircle(950.0f,500.0f,0.0f,170.0f,137.0f);
        //Building
        FirstBuilding(134, 89, 45);

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
        roadBorder();
        TinShade();
        circleLine();
        glColor3ub(0,0,255);
        tprint(330,433,0,"AIUB");
        if(carv)
        {
            truck();
            car();
            car2();
        }
        glPopMatrix();

        if(rain)
        {
            rainf();
        }
}

void topViewf()
{
    Full(181,153,131);
    topView(0,0,0);
    glPopMatrix();

}


void startscreen(void)
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClearColor(0.000, 0.000, 0.000,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    drawstring(200.0,700.0,0.0,"AMERICAN INTERNATIONAL UNIVERSITY-BANGLADESH");
    glColor3f(0,0,1);
    drawstring(200,650,0.0,"FACULTY OF SCIENCE AND INFORMATION TECHNOLOGY");
    glColor3f(0.7,0.7,0.7);
    drawstring(450,530,0.0,"PROJECT ON");
    drawstring(250,500,0.0,"COMPUTER GRAPHICS: AIUB CAMPUS 2D VIEW");
    glColor3f(1,0.5,0);
    drawstring(100,400,0.0,"SUBMITTED BY:");
    glColor3f(1,1,1);
    drawstring(100,370,0.0,"UZZAMAN,MD.HASAN              (15-28858-1)");
    drawstring(100,290,0.0,"BABUL,MAHMODUL HASAN   (15-29262-1)");
    drawstring(100,210,0.0,"ARNOB,MD.YEASER                  (15-28915-1)");
    drawstring(100,130,0.0,"RAHMAN,MD.MOBINUR          (15-28878-1)");
    glColor3f(1,0.5,0);
    drawstring(700,400,0.0,"SUBMITTED TO:");
    glColor3f(1,1,1);
    drawstring(700,370,0.0,"MD. SAEF ULLAH MIAH");
    glColor3f(0,1,0);
    drawstring(400,80,0.0,"PRESS ENTER TO START");
    glFlush();
}
void controlsScreen()
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClearColor(0.000, 0.000, 0.000,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.596, 0.984, 0.596);
    drawstring(370.0,700.0,0.0,"INSTRUCTIONS");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(250.0,640.0,0.0,"DAY MODE");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(600.0,640.0,0.0,"PRESS 'D'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(250.0,640.0,0.0,"DAY MODE");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(600.0,640.0,0.0,"PRESS 'D'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(250.0,600.0,0.0,"NIGHT MODE");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(600.0,600.0,0.0,"PRESS 'N'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(250.0,560.0,0.0,"CAR MOVING");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(600.0,560.0,0.0,"PRESS 'C'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(250.0,520.0,0.0,"RAIN MODE");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(600.0,520.0,0.0,"PRESS 'R'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(250.0,480.0,0.0,"NO RAIN");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(600.0,480.0,0.0,"PRESS 'E'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(250.0,440.0,0.0,"TOP VIEW");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(600.0,440.0,0.0,"PRESS 'T'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(250.0,400.0,0.0,"PLANE MOVEMENT");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(600.0,400.0,0.0,"PRESS 'P'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(250.0,360.0,0.0,"Help");

    glColor3f(1.000, 0.980, 0.941);
    drawstring(600.0,360.0,0.0,"PRESS 'H'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(250.0,320.0,0.0,"Escape");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(600.0,320.0,0.0,"PRESS 'ESC'");
    glColor3f(0.596, 0.984, 0.596);
    drawstring(360.0,200.0,0.0,"NOW PRESS ENTER");
    glFlush();
}

void display()
{
    glPushMatrix();
    glTranslatef(translate_x,translate_y,translate_z);

    if(day==2)
    {
       nightMode();
    }
    else if(day==1)
    {
        dayMode();
    }

    else if(day==3)
    {
        topViewf();
    }
    glFlush();
    glutSwapBuffers();
}


//Main Display Function
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(flag==0){

        startscreen();

    }
    if(flag==1)
        controlsScreen();
        //controlsScreen();
    if(flag>1)
        display();

    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
//-------- spin --------
if(key=='d')
{
    day=1;
}
else if(key=='n')
{
    day=2;
}
else if(key=='t')
{
    day=3;
}
else if(key=='r')
{
    rain=true;
}
else if(key=='e')
{
    rain=false;
}
else if(key=='c')
{
    carv=true;
}
else if(key=='v')
{
    carv=false;
}
else if(key=='p')
{
    planev=true;
}
else if(key=='o')
{
    planev=false;
}
else if(key==13)
{
    flag++;
    myDisplay();
}
else if(key=='h')
{
    flag=1;
    myDisplay();
}
else if(key==27)
{
    exit(0);
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
