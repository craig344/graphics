// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<Windows.h> 
#include<gl/glew.h>
#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h>
#include "pch.h"
//reference:https://www.wikihow.com/Make-a-Cube-in-OpenGL
// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();
void addCubeLeft(float offset);
void addCubeRight(float offset);
// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
static double rotate_y = 0;
static double rotate_x = 0;
static float yLeft = 0.1;
static float yRight = 0.1;
static int cubeLeft = 0;
static int cubeRight = 0;

// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void drawScene() {

	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Other Transformations
	// glTranslatef( 0.1, 0.0, 0.0 );      // Not included
	// glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included

	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	// Other Transformations
	// glScalef( 2.0, 2.0, 0.0 );          // Not included

	//--------------------------------------------------
	//Left side code
	//--------------------------------------------------
	//Red - FRONT(Left)
	glBegin(GL_POLYGON);

	glColor3f(0.835, 0.125, 0.176);
	glVertex3f(-0.7, -0.3 + yLeft, -0.3);      // P1 is red
	glVertex3f(-0.7, -0.25 + yLeft, -0.3);      // P2 is red
	glVertex3f(-0.2, -0.25 + yLeft, -0.3);      // P3 is red
	glVertex3f(-0.2, -0.3 + yLeft, -0.3);      // P4 is red

	glEnd();

	// Red - BACK(Left)
	glBegin(GL_POLYGON);
	glColor3f(0.835, 0.125, 0.176);
	glVertex3f(-0.7, -0.3 + yLeft, 0.2);
	glVertex3f(-0.7, -0.25 + yLeft, 0.2);
	glVertex3f(-0.2, -0.25 + yLeft, 0.2);
	glVertex3f(-0.2, -0.3 + yLeft, 0.2);
	glEnd();

	// Red - RIGHT(Left)
	glBegin(GL_POLYGON);
	glColor3f(0.874, 0.149, 0.2);
	glVertex3f(-0.2, -0.3 + yLeft, -0.3);
	glVertex3f(-0.2, -0.25 + yLeft, -0.3);
	glVertex3f(-0.2, -0.25 + yLeft, 0.2);
	glVertex3f(-0.2, -0.3 + yLeft, 0.2);
	glEnd();

	// Red - LEFT(Left)
	glBegin(GL_POLYGON);
	glColor3f(0.874, 0.149, 0.2);
	glVertex3f(-0.7, -0.3 + yLeft, -0.3);
	glVertex3f(-0.7, -0.25 + yLeft, -0.3);
	glVertex3f(-0.7, -0.25 + yLeft, 0.2);
	glVertex3f(-0.7, -0.3 + yLeft, 0.2);
	glEnd();

	// Red - TOP(Left)
	glBegin(GL_POLYGON);
	glColor3f(0.937, 0.164, 0.219);
	glVertex3f(-0.7, -0.25 + yLeft, 0.2);
	glVertex3f(-0.7, -0.25 + yLeft, -0.3);
	glVertex3f(-0.2, -0.25 + yLeft, -0.3);
	glVertex3f(-0.2, -0.25 + yLeft, 0.2);
	glEnd();

	// Red - BOTTOM(Left)
	glBegin(GL_POLYGON);
	glColor3f(0.937, 0.164, 0.219);
	glVertex3f(-0.7, -0.3 + yLeft, 0.2);
	glVertex3f(-0.7, -0.3 + yLeft, -0.3);
	glVertex3f(-0.2, -0.3 + yLeft, -0.3);
	glVertex3f(-0.2, -0.3 + yLeft, 0.2);
	glEnd();

	//--------------------------------------------------
	//Right side code
	//--------------------------------------------------
	//Red - FRONT(Right)
	glBegin(GL_POLYGON);

	glColor3f(0.835, 0.125, 0.176);
	glVertex3f(0.7, -0.3 + yRight, -0.3);      // P1 is red
	glVertex3f(0.7, -0.25 + yRight, -0.3);      // P2 is red
	glVertex3f(0.2, -0.25 + yRight, -0.3);      // P3 is red
	glVertex3f(0.2, -0.3 + yRight, -0.3);      // P4 is red

	glEnd();

	// Red - BACK(Right)
	glBegin(GL_POLYGON);
	glColor3f(0.835, 0.125, 0.176);
	glVertex3f(0.7, -0.3 + yRight, 0.2);
	glVertex3f(0.7, -0.25 + yRight, 0.2);
	glVertex3f(0.2, -0.25 + yRight, 0.2);
	glVertex3f(0.2, -0.3 + yRight, 0.2);
	glEnd();

	// Red - RIGHT(Right)
	glBegin(GL_POLYGON);
	glColor3f(0.874, 0.149, 0.2);
	glVertex3f(0.2, -0.3 + yRight, -0.3);
	glVertex3f(0.2, -0.25 + yRight, -0.3);
	glVertex3f(0.2, -0.25 + yRight, 0.2);
	glVertex3f(0.2, -0.3 + yRight, 0.2);
	glEnd();

	// Red - LEFT(Right)
	glBegin(GL_POLYGON);
	glColor3f(0.874, 0.149, 0.2);
	glVertex3f(0.7, -0.3 + yRight, -0.3);
	glVertex3f(0.7, -0.25 + yRight, -0.3);
	glVertex3f(0.7, -0.25 + yRight, 0.2);
	glVertex3f(0.7, -0.3 + yRight, 0.2);
	glEnd();

	// Red - TOP(Right)
	glBegin(GL_POLYGON);
	glColor3f(0.937, 0.164, 0.219);
	glVertex3f(0.7, -0.25 + yRight, 0.2);
	glVertex3f(0.7, -0.25 + yRight, -0.3);
	glVertex3f(0.2, -0.25 + yRight, -0.3);
	glVertex3f(0.2, -0.25 + yRight, 0.2);
	glEnd();

	// Red - BOTTOM(Right)
	glBegin(GL_POLYGON);
	glColor3f(0.937, 0.164, 0.219);
	glVertex3f(0.7, -0.3 + yRight, 0.2);
	glVertex3f(0.7, -0.3 + yRight, -0.3);
	glVertex3f(0.2, -0.3 + yRight, -0.3);
	glVertex3f(0.2, -0.3 + yRight, 0.2);
	glEnd();


	//--------------------------------------------------
	//Middle bar code
	//--------------------------------------------------
	//Yello - FRONT(Bar)
	glBegin(GL_POLYGON);

	glColor3f(0.949, 0.886, 0.192);
	glVertex3f(-0.05, -0.8, -0.1);
	glVertex3f(-0.05, 0.7, -0.1);
	glVertex3f(0.05, 0.7, -0.1);
	glVertex3f(0.05, -0.8, -0.1);

	glEnd();

	// Yellow - BACK(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.949, 0.886, 0.192);
	glVertex3f(-0.05, -0.8, 0.0);
	glVertex3f(-0.05, 0.7, 0.0);
	glVertex3f(0.05, 0.7, 0.0);
	glVertex3f(0.05, -0.8, 0.0);
	glEnd();

	// Yellow - RIGHT(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.835, 0.776, 0.082);
	glVertex3f(0.05, -0.8, -0.1);
	glVertex3f(0.05, 0.7, -0.1);
	glVertex3f(0.05, 0.7, 0.0);
	glVertex3f(0.05, -0.8, 0.0);
	glEnd();

	// Yellow - LEFT(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.835, 0.776, 0.082);
	glVertex3f(-0.05, -0.8, -0.1);
	glVertex3f(-0.05, 0.7, -0.1);
	glVertex3f(-0.05, 0.7, 0.0);
	glVertex3f(-0.05, -0.8, 0.0);
	glEnd();

	// Yellow - TOP(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.690, 0.639, 0.090);
	glVertex3f(-0.05, 0.7, 0.0);
	glVertex3f(-0.05, 0.7, -0.1);
	glVertex3f(0.05, 0.7, -0.1);
	glVertex3f(0.05, 0.7, 0.0);
	glEnd();

	// Yellow - BOTTOM(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.690, 0.639, 0.090);
	glVertex3f(-0.05, -0.8, 0.0);
	glVertex3f(-0.05, -0.8, -0.1);
	glVertex3f(0.05, -0.8, -0.1);
	glVertex3f(0.05, -0.8, 0.0);
	glEnd();

	//--------------------------------------------------
	//Connecting bar code Left Side
	//--------------------------------------------------
	//Blue - FRONT(Bar)
	glBegin(GL_POLYGON);

	glColor3f(0.082, 0.078, 0.921);
	glVertex3f(-0.2, -0.29 + yLeft, -0.1);
	glVertex3f(-0.2, -0.26 + yLeft, -0.1);
	glVertex3f(-0.05, -0.26 + yLeft, -0.1);
	glVertex3f(-0.05, -0.29 + yLeft, -0.1);

	glEnd();

	// Blue - BACK(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.082, 0.078, 0.921);
	glVertex3f(-0.2, -0.29 + yLeft, 0.0);
	glVertex3f(-0.2, -0.26 + yLeft, 0.0);
	glVertex3f(-0.05, -0.26 + yLeft, 0.0);
	glVertex3f(-0.05, -0.29 + yLeft, 0.0);
	glEnd();

	// Blue - TOP(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.066, 0.062, 0.635);
	glVertex3f(-0.2, -0.26 + yLeft, 0.0);
	glVertex3f(-0.2, -0.26 + yLeft, -0.1);
	glVertex3f(-0.05, -0.26 + yLeft, -0.1);
	glVertex3f(-0.05, -0.26 + yLeft, 0.0);
	glEnd();

	// Blue - BOTTOM(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.066, 0.062, 0.635);
	glVertex3f(-0.2, -0.29 + yLeft, 0.0);
	glVertex3f(-0.2, -0.29 + yLeft, -0.1);
	glVertex3f(-0.05, -0.29 + yLeft, -0.1);
	glVertex3f(-0.05, -0.29 + yLeft, 0.0);
	glEnd();

	//--------------------------------------------------
	//Connecting bar code Right Side
	//--------------------------------------------------
	//Blue - FRONT(Bar)
	glBegin(GL_POLYGON);

	glColor3f(0.082, 0.078, 0.921);
	glVertex3f(0.2, -0.29 + yRight, -0.1);
	glVertex3f(0.2, -0.26 + yRight, -0.1);
	glVertex3f(0.05, -0.26 + yRight, -0.1);
	glVertex3f(0.05, -0.29 + yRight, -0.1);

	glEnd();

	// Blue - BACK(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.082, 0.078, 0.921);
	glVertex3f(0.2, -0.29 + yRight, 0.0);
	glVertex3f(0.2, -0.26 + yRight, 0.0);
	glVertex3f(0.05, -0.26 + yRight, 0.0);
	glVertex3f(0.05, -0.29 + yRight, 0.0);
	glEnd();

	// Blue - TOP(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.066, 0.062, 0.635);
	glVertex3f(0.2, -0.26 + yRight, 0.0);
	glVertex3f(0.2, -0.26 + yRight, -0.1);
	glVertex3f(0.05, -0.26 + yRight, -0.1);
	glVertex3f(0.05, -0.26 + yRight, 0.0);
	glEnd();

	// Blue - BOTTOM(Bar)
	glBegin(GL_POLYGON);
	glColor3f(0.066, 0.062, 0.635);
	glVertex3f(0.2, -0.29 + yRight, 0.0);
	glVertex3f(0.2, -0.29 + yRight, -0.1);
	glVertex3f(0.05, -0.29 + yRight, -0.1);
	glVertex3f(0.05, -0.29 + yRight, 0.0);
	glEnd();

	switch (cubeLeft)
	{
	case 5:
	{
		addCubeLeft(0.810);
	}
	case 4:
	{
		addCubeLeft(0.608);
	}case 3:
	{
		addCubeLeft(0.406);
	}
	case 2:
	{
		addCubeLeft(0.202);
	}
	case 1:
	{
		addCubeLeft(0.0);
	}
	}

	switch (cubeRight)
	{
	case 5:
	{
		addCubeRight(0.810);
	}
	case 4:
	{
		addCubeRight(0.608);
	}case 3:
	{
		addCubeRight(0.406);
	}
	case 2:
	{
		addCubeRight(0.202);
	}
	case 1:
	{
		addCubeRight(0.0);
	}
	}

	glFlush();
	glutSwapBuffers();
}

void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void addCubeLeft(float offset)
{
	//--------------------------------------------------
	//Cube addition code
	//--------------------------------------------------
	//Violet - FRONT
	glBegin(GL_POLYGON);

	glColor3f(0.674, 0.470, 0.690);
	glVertex3f(-0.55, -0.15 + yLeft - 0.1 + offset, -0.15);      // P1 is red
	glVertex3f(-0.55, 0.05 + yLeft - 0.1 + offset, -0.15);      // P2 is red
	glVertex3f(-0.35, 0.05 + yLeft - 0.1 + offset, -0.15);      // P3 is red
	glVertex3f(-0.35, -0.15 + yLeft - 0.1 + offset, -0.15);      // P4 is red

	glEnd();

	// Violet - BACK
	glBegin(GL_POLYGON);
	glColor3f(0.674, 0.470, 0.690);
	glVertex3f(-0.55, -0.15 + yLeft - 0.1 + offset, 0.05);
	glVertex3f(-0.55, 0.05 + yLeft - 0.1 + offset, 0.05);
	glVertex3f(-0.35, 0.05 + yLeft - 0.1 + offset, 0.05);
	glVertex3f(-0.35, -0.15 + yLeft - 0.1 + offset, 0.05);
	glEnd();

	// Violet - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(0.674, 0.407, 0.694);
	glVertex3f(-0.35, -0.15 + yLeft - 0.1 + offset, -0.15);
	glVertex3f(-0.35, 0.05 + yLeft - 0.1 + offset, -0.15);
	glVertex3f(-0.35, 0.05 + yLeft - 0.1 + offset, 0.05);
	glVertex3f(-0.35, -0.15 + yLeft - 0.1 + offset, 0.05);
	glEnd();

	// Violet - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.674, 0.407, 0.694);
	glVertex3f(-0.55, -0.15 + yLeft - 0.1 + offset, -0.15);
	glVertex3f(-0.55, 0.05 + yLeft - 0.1 + offset, -0.15);
	glVertex3f(-0.55, 0.05 + yLeft - 0.1 + offset, 0.05);
	glVertex3f(-0.55, -0.15 + yLeft - 0.1 + offset, 0.05);
	glEnd();

	// Violet - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.725, 0.411, 0.749);
	glVertex3f(-0.55, 0.05 + yLeft - 0.1 + offset, -0.15);
	glVertex3f(-0.55, 0.05 + yLeft - 0.1 + offset, 0.05);
	glVertex3f(-0.35, 0.05 + yLeft - 0.1 + offset, 0.05);
	glVertex3f(-0.35, 0.05 + yLeft - 0.1 + offset, -0.15);
	glEnd();

	// Violet - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(0.725, 0.411, 0.749);
	glVertex3f(-0.55, -0.15 + yLeft - 0.1 + offset, -0.15);
	glVertex3f(-0.55, -0.15 + yLeft - 0.1 + offset, 0.05);
	glVertex3f(-0.35, -0.15 + yLeft - 0.1 + offset, 0.05);
	glVertex3f(-0.35, -0.15 + yLeft - 0.1 + offset, -0.15);
	glEnd();

}

void addCubeRight(float offset)
{

	//--------------------------------------------------
	//Cube addition code
	//--------------------------------------------------
	//Violet - FRONT
	glBegin(GL_POLYGON);

	glColor3f(0.674, 0.470, 0.690);
	glVertex3f(0.55, -0.15 + yRight - 0.1 + offset, -0.15);      // P1 is red
	glVertex3f(0.55, 0.05 + yRight - 0.1 + offset, -0.15);      // P2 is red
	glVertex3f(0.35, 0.05 + yRight - 0.1 + offset, -0.15);      // P3 is red
	glVertex3f(0.35, -0.15 + yRight - 0.1 + offset, -0.15);      // P4 is red

	glEnd();

	// Violet - BACK
	glBegin(GL_POLYGON);
	glColor3f(0.674, 0.470, 0.690);
	glVertex3f(0.55, -0.15 + yRight - 0.1 + offset, 0.05);
	glVertex3f(0.55, 0.05 + yRight - 0.1 + offset, 0.05);
	glVertex3f(0.35, 0.05 + yRight - 0.1 + offset, 0.05);
	glVertex3f(0.35, -0.15 + yRight - 0.1 + offset, 0.05);
	glEnd();

	// Violet - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.674, 0.407, 0.694);
	glVertex3f(0.35, -0.15 + yRight - 0.1 + offset, -0.15);
	glVertex3f(0.35, 0.05 + yRight - 0.1 + offset, -0.15);
	glVertex3f(0.35, 0.05 + yRight - 0.1 + offset, 0.05);
	glVertex3f(0.35, -0.15 + yRight - 0.1 + offset, 0.05);
	glEnd();

	// Violet - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(0.674, 0.407, 0.694);
	glVertex3f(0.55, -0.15 + yRight - 0.1 + offset, -0.15);
	glVertex3f(0.55, 0.05 + yRight - 0.1 + offset, -0.15);
	glVertex3f(0.55, 0.05 + yRight - 0.1 + offset, 0.05);
	glVertex3f(0.55, -0.15 + yRight - 0.1 + offset, 0.05);
	glEnd();

	// Violet - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.725, 0.411, 0.749);
	glVertex3f(0.55, 0.05 + yRight - 0.1 + offset, -0.15);
	glVertex3f(0.55, 0.05 + yRight - 0.1 + offset, 0.05);
	glVertex3f(0.35, 0.05 + yRight - 0.1 + offset, 0.05);
	glVertex3f(0.35, 0.05 + yRight - 0.1 + offset, -0.15);
	glEnd();

	// Violet - BOTTOM(Left)
	glBegin(GL_POLYGON);
	glColor3f(0.725, 0.411, 0.749);
	glVertex3f(0.55, -0.15 + yRight - 0.1 + offset, -0.15);
	glVertex3f(0.55, -0.15 + yRight - 0.1 + offset, 0.05);
	glVertex3f(0.35, -0.15 + yRight - 0.1 + offset, 0.05);
	glVertex3f(0.35, -0.15 + yRight - 0.1 + offset, -0.15);
	glEnd();

}

void print(void)
{
	system("CLS");
	std::cout << "Left side value: " << yLeft << std::endl;
	std::cout << "Right side value: " << yRight << std::endl;
	std::cout << "Left side cubes: " << cubeLeft << std::endl;
	std::cout << "Right side cubes: " << cubeRight << std::endl;

}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys(int key, int x, int y) {

	//  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
	{
		//rotate_x += 5;

		if (yRight > -0.22 && cubeRight < 5)
		{
			yLeft += 0.08;
			yRight -= 0.08;
		}
		if (cubeRight < 5)
		{
			cubeRight += 1;
		}
		print();
	}

	//  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
	{
		if (yRight < 0.06)
		{
			yLeft -= 0.08;
			yRight += 0.08;
		}
		else if (yRight > 0.06 && cubeLeft > 0 && cubeRight > 0)
		{
			yLeft -= 0.08;
			yRight += 0.08;
		}

		if (cubeRight > 0)
		{
			cubeRight -= 1;
		}
		print();
	}
	else if (key == GLUT_KEY_UP)
	{
		if (yLeft > -0.22 && cubeLeft < 5)
		{
			yLeft -= 0.08;
			yRight += 0.08;
		}
		if (cubeLeft < 5)
		{
			cubeLeft += 1;
		}
		print();
	}
	else if (key == GLUT_KEY_DOWN)
	{
		if (yLeft < 0.06)
		{
			yLeft += 0.08;
			yRight -= 0.08;
		}
		else if (yLeft > 0.06 && cubeRight > 0 && cubeLeft > 0)
		{
			yLeft += 0.08;
			yRight -= 0.08;
		}
		if (cubeLeft > 0)
		{
			cubeLeft -= 1;
		}
		print();
	}

	//  Request display update
	glutPostRedisplay();

}

void NormalKeyHandler(unsigned char key, int x, int y)
{
	//  d - increase rotation by 5 degree

	if (key == 'd')
	{
		rotate_y += 5;
		glutPostRedisplay();
	}

	//  a - decrease rotation by 5 degree
	else if (key == 'a')
	{
		rotate_y -= 5;
		glutPostRedisplay();
	}
	else if (key == 'w')
	{
		rotate_x += 5;
		glutPostRedisplay();
	}
	else if (key == 's')
	{
		rotate_x -= 5;
		glutPostRedisplay();
	}

	// and so on...
}

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]) {
	glClear(GL_COLOR_BUFFER_BIT);

	//  Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(750, 750);/*set the initial window size*/
	glutInitWindowPosition(420, 30);/*set the initial window position*/

	// Create window
	glutCreateWindow("3D Scale");

	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions
	glutDisplayFunc(drawScene);
	glutSpecialFunc(specialKeys);//for special keys call
	glutKeyboardFunc(NormalKeyHandler);// for  normal keys call

	//Background Color
	setup();


	//  Pass control to GLUT for events
	glutMainLoop();

	//  Return to OS
	return 0;

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
