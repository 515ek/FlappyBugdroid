#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<time.h>

bool gameover = false;
bool click = false;
GLfloat bugdroid[3][37] = { { 50.0, 50.0, 150.0, 150.0, 35.0, 35.0, 45.0, 45.0, 155.0, 155.0, 165.0, 165.0, 60.0, 60.0, 75.0, 75.0, 125.0, 125.0,
140.0, 140.0, 70.0, 70.0, 80.0, 80.0, 120.0, 120.0, 130.0, 130.0, 100.0, 70.0, 70.0, 75.0, 75.0, 120.0, 120.0, 125.0, 125.0 },
{ 300.0, 400.0, 400.0, 300.0, 300.0, 400.0, 400.0, 300.0, 300.0, 400.0, 400.0, 300.0, 275.0, 300.0, 300.0, 275.0, 275.0, 300.0,
300.0, 275.0, 420.0, 430.0, 430.0, 420.0, 420.0, 430.0, 430.0, 420.0, 405.0, 450.0, 475.0, 475.0, 405.0, 450.0, 475.0, 475.0, 450.0 },
{ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 } };
GLfloat lollipop[3][8] = { { 640.0, 640.0, 660.0, 660.0, 640.0, 640.0, 660.0, 660.0 }, { 0.0, 200.0, 200.0, 0.0, 800.0, 1000.0, 1000.0, 800.0 }, { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 } };
GLfloat yloc = 0, xloc = 0, lxloc = 0;
int count = 0, flag = 0, score = 0, theta = 0.0, height[4] = { 100, 200, 300, 400 }, i = 0;
char tmp[50], tmp1[50];

void msg(char *string)
{
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void drawpoly(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glVertex2f(bugdroid[0][a], bugdroid[1][a]);
	glVertex2f(bugdroid[0][b], bugdroid[1][b]);
	glVertex2f(bugdroid[0][c], bugdroid[1][c]);
	glVertex2f(bugdroid[0][d], bugdroid[1][d]);
	glEnd();
}

void drawpoly1(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glVertex2f(lollipop[0][a], lollipop[1][a]);
	glVertex2f(lollipop[0][b], lollipop[1][b]);
	glVertex2f(lollipop[0][c], lollipop[1][c]);
	glVertex2f(lollipop[0][d], lollipop[1][d]);
	glEnd();
}

void DrawHead(int c, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 1.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + bugdroid[0][c], y + bugdroid[1][c]);//output vertex 

	}
	glEnd();
}

void drawbugdroid()
{
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	drawpoly(0, 1, 2, 3);
	glPopMatrix();

	glPushMatrix();
	drawpoly(4, 5, 6, 7);
	glPopMatrix();

	glPushMatrix();
	drawpoly(8, 9, 10, 11);
	glPopMatrix();

	glPushMatrix();
	drawpoly(12, 13, 14, 15);
	glPopMatrix();

	glPushMatrix();
	drawpoly(16, 17, 18, 19);
	glPopMatrix();

	glPushMatrix();
	drawpoly(29, 30, 31, 32);
	glPopMatrix();

	glPushMatrix();
	drawpoly(33, 34, 35, 36);
	glPopMatrix();

	glPushMatrix();
	DrawHead(28, 50.0, 1000);
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	drawpoly(20, 21, 22, 23);
	glPopMatrix();

	glPushMatrix();
	drawpoly(24, 25, 26, 27);
	glPopMatrix();


	glFlush();
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glVertex2f(x + cx, y + cy);

	}
	glEnd();
}

void Drawlollipop()
{
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	drawpoly1(0, 1, 2, 3);
	glPopMatrix();

	glPushMatrix();
	drawpoly1(4, 5, 6, 7);
	glPopMatrix();

	glColor3d(1.0, 0.6, 0.0);
	glPushMatrix();
	DrawCircle(650.0, 250.0, 50.0, 1000);
	glPopMatrix();

	glPushMatrix();
	DrawCircle(650.0, 750.0, 50.0, 1000);
	glPopMatrix();

	glFlush();
}

void update()
{
	i = rand() % 4;
	if (!flag)
	{
		theta -= 5.0;
		xloc += 2.0;
		yloc += 10.0;
		if (yloc + bugdroid[1][30] > 700.0 + height[i])
			flag = 1;
	}
	if (flag)
	{
		theta = 180.0;
		yloc -= 10.0;
		if (count == 1)
		{
			flag = 0;
			count = 0;
			xloc = 0.0;
		}
	}
	if (lxloc + lollipop[0][4] < 0)
	{
		lxloc = 360;
		score += 1;
	}
}

int iscollision()
{
	int ret = 1;
	for (int i = 0; i < 36; i++)
	{
		if (625 + lxloc < xloc + bugdroid[0][i] && xloc + bugdroid[0][i] < lxloc + 675)
		{
			if (0 < yloc + bugdroid[1][i] && yloc + bugdroid[1][i] < 275)
				ret = 0;
			if (675 < yloc + bugdroid[1][i] && yloc + bugdroid[1][i] < 1000)
				ret = 0;
		}
	}
	return ret;
}

void bitmap_output(int x, int y, char *string, void * font)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i<len; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}

void display2()
{
	glClearColor(0.0, 1.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	bitmap_output(350, 500, "GAME OVER", GLUT_BITMAP_HELVETICA_18);

	glColor3f(0, 0, 0);
	glRasterPos2f(350, 400);
	sprintf(tmp1, "Your Score is : %d", score);
	msg(tmp1);

	glEnd();
}

void gameplay()
{
	glClearColor(0.66f, 0.72f, 0.96f, 1.0f);
	glColor3f(0, 0, 0);
	glRasterPos2f(50, 900);
	sprintf(tmp, "%d", score);
	msg(tmp);

	if (yloc + bugdroid[1][15] <= 0.0 || yloc + bugdroid[1][30] >= 1000.0)
	{
		gameover = true;
		display2();
	}
	if (iscollision() == 0)
	{
		gameover = true;
		display2();
	}
	if (!gameover)
	{

		glPushMatrix();
		glTranslatef(xloc + 100.0, yloc + 350.0, 0.0);
		glRotatef(theta, 0.0, 0.0, 1.0);
		glScalef(0.5, 0.5, 0.0);
		glTranslatef(-100.0, -350.0, 0.0);
		drawbugdroid();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(lxloc -= 5, 0.0, 0.0);
		Drawlollipop();
		glPopMatrix();

		update();
	}
	Sleep(22);
	glutPostRedisplay();
	glutSwapBuffers();
}

void init()
{
	glClearColor(0.66f, 0.72f, 0.96f, 1.0f);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
	glutPostRedisplay();
}

void display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.4, 1.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex2f(10, 10);
	glVertex2f(990, 10);
	glVertex2f(990, 990);
	glVertex2f(10, 990);
	glEnd();

	glColor3f(0.0, 0, 1);
	bitmap_output(250, 850, "BAPUJI INSTITUTE OF ENGINEERING AND TECHNOLOGY", GLUT_BITMAP_TIMES_ROMAN_24);
	//	bitmap_output(450, 550, "DAVANGERE", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0.5, 0, 1);
	bitmap_output(325, 800, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING", GLUT_BITMAP_HELVETICA_18);

	glColor3f(1, 1.0, 1.5);
	bitmap_output(380, 750, "A Mini Project ", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0, 0, 1);
	bitmap_output(415, 700, "On", GLUT_BITMAP_TIMES_ROMAN_24);


	glColor3f(0, 0, 1);
	bitmap_output(380, 630, "PROJECT GUIDES:", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0, 0, 1);
	bitmap_output(150, 580, "Miss ANU C.S", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0, 0, 1);
	bitmap_output(270, 580, "M.Tech, M.I.S.T.E.", GLUT_BITMAP_TIMES_ROMAN_10);

	glColor3f(0, 0, 1);
	bitmap_output(150, 530, "Asst.Professor", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0, 0, 1);
	bitmap_output(150, 480, "Department of CS&E", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0, 0, 1);
	bitmap_output(150, 420, "B.I.E.T., DAVANGERE", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0, 0, 1);
	bitmap_output(380, 750, "A Mini Project ", GLUT_BITMAP_TIMES_ROMAN_24);



	glColor3f(1, 0, 0);
	bitmap_output(390, 670, "Flappy Bugdroid", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0, 0, 1);
	bitmap_output(650, 580, "Mr.WASEEM KHAN", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0, 0, 1);
	bitmap_output(830, 580, "B.E.,M.TECH", GLUT_BITMAP_TIMES_ROMAN_10);


	bitmap_output(650, 530, "Asst.Professor", GLUT_BITMAP_TIMES_ROMAN_24);
	

	glColor3f(0, 0, 1);
	bitmap_output(650, 480, "Deparment of CS&E", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0, 0, 1);
	bitmap_output(650, 420, "B.I.E.T Davangere", GLUT_BITMAP_TIMES_ROMAN_24);


	glColor3f(0, 1.0, 0);
	bitmap_output(310, 300, "Click Left Mouse Button to PLAY", GLUT_BITMAP_TIMES_ROMAN_24);


	glColor3f(0, 1.0, 0);
	bitmap_output(310, 200, "Submitted by", GLUT_BITMAP_TIMES_ROMAN_24);


	glColor3f(0, 1.0, 0);
	bitmap_output(320, 150, "Vivek Babu G.R.", GLUT_BITMAP_TIMES_ROMAN_24);


	glColor3f(0, 1.0, 0);
	bitmap_output(320, 100, "Santhosh R.G.", GLUT_BITMAP_TIMES_ROMAN_24);

	glEnd();

	glutSwapBuffers();
	glFlush();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(2.0);
	if (!click)
	{
		display1();
	}
	if (!gameover && click)
	{
		gameplay();
	}
	if (gameover)
	{
		display2();
	}
	glFlush();
}

void mouse(int btn, int state, int x, int)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		click = true;
		count = 1;
		if (click)
		{
			gameplay();
		}
	}
}

void mymenu(int id)
{
	switch (id)
	{
	case 1:
		count = 0; flag = 0; score = 0; theta = 0.0;
		gameover = false; click = false;
		yloc = 0; xloc = 0; lxloc = 0;
		display1();
		break;
	case 2:
		exit(0);
	}
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Flappy Droid");
	glutDisplayFunc(display);
	glutCreateMenu(mymenu);
	glutAddMenuEntry("Restart", 1);
	glutAddMenuEntry("EXIT", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
}