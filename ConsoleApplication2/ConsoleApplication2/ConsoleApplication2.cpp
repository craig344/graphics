
#include "pch.h"
#include <iostream>
#include <iostream>
#include<Windows.h> 
#include<gl/glew.h>
#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h> 

#define PI 3.14159265

static float xV = 5.0, yV = 5.0;
static int N = 1000;

static int XCircle = 50;
static int YCircle = 50;

void DrawCircle() {

	double th = 0.0;
	int i = 0;

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < N; i++) {
		glVertex2f(XCircle + xV * cos(th), YCircle + yV * sin(th));
		th += 2 * PI / N;
	}
	glEnd();


}

void DrawSquare() {

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(10, 10);
	//glVertex2f(10, 50);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(10, 50);
	//glVertex2f(50, 50);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(50, 50);
	//glVertex2f(50, 10);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(50, 10);
	//glVertex2f(10, 10);
	glEnd();


}


void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


	//glRotatef((GLfloat) 2.0, 0.0, 0.0, 1.0);
	//glTranslated((GLfloat) 10.0, 0.0, 0.0);
	glutPostRedisplay();
	DrawCircle();
	DrawSquare();

	glFlush();


}

void moveFunc(unsigned char lol, int x, int y) {
	if (lol == 'd') {
		XCircle += 1;
		//YCircle += 1;
	}
	else if (lol == 'a') {
		XCircle -= 1;
	}
	else if (lol == 'w') {
		YCircle += 1;
	}
	else if (lol == 's') {
		YCircle -= 1;
	}
}

void movewithMouseFunc(int lol, int state, int x, int y) {

	std::cout << x << " " << y << std::endl;

	if (lol == GLUT_RIGHT_BUTTON) {
		XCircle = x;
		YCircle = y;
		//YCircle += 1;
	}
	//glutPostRedisplay();

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
	glutInitWindowPosition(100, 100);

	glutCreateWindow("OpenGLIntro.cpp");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);

	glutKeyboardFunc(moveFunc);
	glutMouseFunc(movewithMouseFunc);

	setup();

	glutMainLoop();
}