// ISA1734.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <iostream>
#include <iostream>
#include<Windows.h> 
#include<gl/glew.h>
#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h> 

#define PI 3.14159265

static float xV = 3.0, yV = 3.0, xV1 = 1.2, yV1 = 1.2;
static int N = 1000;

static int XCircle = 9;
static int YCircle = 25;
static int XCircle1 = 5;
static int YCircle1 = 21;
static int XCircle2 = 16;
static int YCircle2 = 21;
static float XYSquare[8] = {3, 21.5, 3, 25, 22, 25, 22, 21.5};

static int reverseFlag = 0;

void DrawCar() {

	double th = 0.0;
	int i = 0;

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; i++) {
		glVertex2f(XCircle + xV * cos(th), YCircle + yV * sin(th));
		th += 2 * PI / N;
	}
	glEnd();

	th = 0.0;
	i = 0;

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; i++) {
		glVertex2f(XCircle1 + xV1 * cos(th), YCircle1 + yV1 * sin(th));
		th += 2 * PI / N;
	}
	glEnd();

	th = 0.0;
	i = 0;

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; i++) {
		glVertex2f(XCircle2 + xV1 * cos(th), YCircle2 + yV1 * sin(th));
		th += 2 * PI / N;
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(XYSquare[0], XYSquare[1]);

	glVertex2f(XYSquare[2], XYSquare[3]);

	glVertex2f(XYSquare[4], XYSquare[5]);

	glVertex2f(XYSquare[6], XYSquare[7]);
	glEnd();


}

void DrawSurface() {


	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(0, 20);

	glVertex2f(0, 30);

	glVertex2f(3, 30);

	glVertex2f(3, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(97, 20);

	glVertex2f(97, 30);

	glVertex2f(100, 30);

	glVertex2f(100, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.2, 0.1);
	glVertex2f(0, 0);
	
	glVertex2f(0, 20);
	
	glVertex2f(100, 20);
	
	glVertex2f(100, 0);
	glEnd();


}


void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutPostRedisplay();
	DrawSurface();
	DrawCar();

	glFlush();


}

void moveFunc(unsigned char c, int x, int y) {
	if (c == 'a') {
		if (XYSquare[2] > 3 && reverseFlag == 1) {
			XCircle -= 1;
			XCircle1 -= 1;
			XCircle2 -= 1;
			for (int i = 0; i < 8; i += 2) {
				XYSquare[i]--;
			}
		}
		else if (XYSquare[2] == 3 && reverseFlag == 1) {
			reverseFlag = 0;
			XCircle -= 7;
			XCircle1 -= 4;
			XCircle2 -= 4;
		}
		else if (XYSquare[6] < 97 && reverseFlag == 0) {
			XCircle += 1;
			XCircle1 += 1;
			XCircle2 += 1;
			for (int i = 0; i < 8; i += 2) {
				XYSquare[i]++;
			}
		}
		else {
			reverseFlag = 1;
			XCircle += 7;
			XCircle1 += 4;
			XCircle2 += 4;
		}

	}
}

void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("OpenGLIntro.cpp");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);

	glutKeyboardFunc(moveFunc);

	setup();

	glutMainLoop();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
