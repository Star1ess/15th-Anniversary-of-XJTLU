#define FREEGLUT_STATIC
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/freeglut.h>
#include <iostream>


float t = 0.0;
float r = 0.0;
float s = 1.0;

typedef struct { GLfloat x, y; } point; // define a 2D point
point p0 = { -0.2979, 0.5437 };
GLfloat step = 0.01; // declare incremental step
int time_interval = 10; // declare refresh interval in ms


void OnTimer(int value)
{
	p0.x += step;
	if (p0.x >= 0.99)
		p0.x = -1;
	else if (p0.x <= -1)
		p0.x = 0.9999;

	//when_in_mainloop();
	glutTimerFunc(time_interval, OnTimer, 1);
}


void when_in_mainloop() // idle callback function
{
	glutPostRedisplay(); // force OpenGL to redraw the current window
}


void keyboard_input(unsigned char key, int x, int y) // keyboard interaction
{
	if (key == 'q' || key == 'Q')
	{
		exit(0);
	}

	//transformation
	else if (key == 'd' || key == 'D')//move to the right
		t += 0.05;
	else if (key == 'a' || key == 'A')//move to the left
		t -= 0.05;
	else if (key == 'c' || key == 'C')//right rotation
		r--;
	else if (key == 'z' || key == 'Z')//left rotation
		r++;
	else if (key == 'w' || key == 'W')//turn bigger
		s += 0.01;
	else if (key == 's' || key == 'S')//turn smaller
		s -= 0.01;

	//animation
	else if (key == 'e' || key == 'E') // change direction of movement
		step = -step;
	else if (key == 'f' || key == 'F') // stop movement
		step = 0;
	else if (key == 'r' || key == 'R') // reset step (resume movement)
		step = 0.01;

}


void mouse_input(int button, int state, int x, int y) // mouse interactions
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && step >= -1)
		step -= 0.001; // decrement step
	else if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON && step <= 1)
		step += 0.001; // increment step
}



void DrawMiddleCap()
{
	//cap top
	glColor3f(25.0 / 255.0, 25.0 / 255.0, 25.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.7465 + 0.4711, 0.0855);
	glVertex2f(-0.4704 + 0.4711, 0.2082);
	glVertex2f(-0.1957 + 0.4711, 0.0855);
	glVertex2f(-0.4704 + 0.4711, -0.0297);
	glEnd();
	//cap middle left
	glColor3f(50.0 / 255.0, 50.0 / 255.0, 50.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6082 + 0.4711, 0.0605);
	glVertex2f(-0.4704 + 0.4711, 0.0833);
	glVertex2f(-0.4704 + 0.4711, -0.0108);
	glVertex2f(-0.6082 + 0.4711, -0.0386);
	glEnd();
	//cap middle right
	glColor3f(50.0 / 255.0, 50.0 / 255.0, 50.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.4704 + 0.4711, 0.0833);
	glVertex2f(-0.3316 + 0.4711, 0.0605);
	glVertex2f(-0.3316 + 0.4711, -0.0386);
	glVertex2f(-0.4704 + 0.4711, -0.0108);
	glEnd();
	//cap bottom
	glColor3f(25.0 / 255.0, 25.0 / 255.0, 25.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6082 + 0.4711, -0.0386);
	glVertex2f(-0.4704 + 0.4711, -0.0108);
	glVertex2f(-0.3316 + 0.4711, -0.0386);
	glVertex2f(-0.4704 + 0.4711, -0.0693);
	glEnd();
	//pendant1
	glColor3f(250.0 / 255.0, 211.0 / 255.0, 101.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2513 + 0.4711, 0.0619);
	glVertex2f(-0.2409 + 0.4711, 0.0663);
	glVertex2f(-0.2409 + 0.4711, -0.0762);
	glVertex2f(-0.2513 + 0.4711, -0.0762);
	glEnd();
	//pendant2
	glColor3f(250.0 / 255.0, 211.0 / 255.0, 101.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2513 + 0.4711, -0.0762);
	glVertex2f(-0.2409 + 0.4711, -0.0762);
	glVertex2f(-0.2166 + 0.4711, -0.1386);
	glVertex2f(-0.2741 + 0.4711, -0.1386);
	glEnd();
}


void define_to_OpenGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//background
	glColor3f(182.0 / 255.0, 220.0 / 255.0, 255.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(1, 1);
	glVertex2f(1, -1);
	glVertex2f(-1, -1);
	glVertex2f(-1, 1);
	glEnd();

	//1blue
	glColor3f(7.0 / 255.0, 28.0 / 255.0, 117.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3253, -0.3659);
	glVertex2f(-0.1412, -0.3138);
	glVertex2f(-0.1322, -0.4070);
	glVertex2f(-0.2290, -0.5104);
	glVertex2f(-0.2664, -0.5195);
	glVertex2f(-0.3155, -0.5225);
	glEnd();
	//2grey
	glColor3f(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.1412, -0.3138);
	glVertex2f(-0.0885, -0.2989);
	glVertex2f(-0.0885, -0.3934);
	glVertex2f(-0.1322, -0.4070);
	glEnd();
	//3blue
	glColor3f(7.0 / 255.0, 28.0 / 255.0, 117.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.0885, -0.2989);
	glVertex2f(0.0702, -0.2540);
	glVertex2f(0.0702, -0.3716);
	glVertex2f(-0.0885, -0.3934);
	glEnd();
	//4blue
	glColor3f(7.0 / 255.0, 28.0 / 255.0, 117.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.1322, -0.4070);
	glVertex2f(-0.0885, -0.3934);
	glVertex2f(0.0702, -0.3716);
	glVertex2f(0.0702, -0.5958);
	glVertex2f(-0.1481, -0.6196);
	glVertex2f(-0.2290, -0.5104);
	glEnd();
	//5blue
	glColor3f(7.0 / 255.0, 28.0 / 255.0, 117.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3155, -0.5225);
	glVertex2f(-0.2664, -0.5195);
	glVertex2f(-0.2664, -0.6283);
	glVertex2f(-0.3078, -0.6467);
	glEnd();
	//6grey
	glColor3f(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2664, -0.5195);
	glVertex2f(-0.2290, -0.5104);
	glVertex2f(-0.1481, -0.6196);
	glVertex2f(-0.2664, -0.6283);
	glEnd();
	//7»ÒÉ«
	glColor3f(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3078, -0.6467);
	glVertex2f(-0.2664, -0.6283);
	glVertex2f(-0.1481, -0.6196);
	glVertex2f(-0.2219, -0.6507);
	glVertex2f(-0.3060, -0.6742);
	glEnd();
	//8grey
	glColor3f(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.1481, -0.6196);
	glVertex2f(0.0702, -0.5958);
	glVertex2f(0.0702, -0.6974);
	glVertex2f(-0.2219, -0.6507);
	glEnd();
	//9blue
	glColor3f(7.0 / 255.0, 28.0 / 255.0, 117.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3060, -0.6742);
	glVertex2f(-0.2219, -0.6507);
	glVertex2f(0.0702, -0.6974);
	glVertex2f(0.0702, -0.8037);
	glVertex2f(-0.2971, -0.8181);
	glEnd();
	//10blue
	glColor3f(7.0 / 255.0, 28.0 / 255.0, 117.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0702, -0.2540);
	glVertex2f(0.2610, -0.3124);
	glVertex2f(0.2425, -0.6217);
	glVertex2f(0.0702, -0.5958);
	glEnd();
	//11blue
	glColor3f(7.0 / 255.0, 28.0 / 255.0, 117.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.2598, -0.3331);
	glVertex2f(0.3040, -0.3464);
	glVertex2f(0.2986, -0.4883);
	glVertex2f(0.2510, -0.4799);
	glEnd();
	//12blue
	glColor3f(7.0 / 255.0, 28.0 / 255.0, 117.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.3048, -0.3258);
	glVertex2f(0.3964, -0.3572);
	glVertex2f(0.3832, -0.5666);
	glVertex2f(0.2970, -0.5312);
	glEnd();
	//13grey
	glColor3f(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.2510, -0.4799);
	glVertex2f(0.2986, -0.4883);
	glVertex2f(0.2970, -0.5312);
	glVertex2f(0.2425, -0.6217);
	glEnd();
	//14grey
	glColor3f(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.2970, -0.5312);
	glVertex2f(0.3294, -0.5445);
	glVertex2f(0.3305, -0.6241);
	glVertex2f(0.3059, -0.6217);
	glVertex2f(0.2425, -0.6217);
	glEnd();
	//15blue
	glColor3f(7.0 / 255.0, 28.0 / 255.0, 117.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.3294, -0.5445);
	glVertex2f(0.3685, -0.5606);
	glVertex2f(0.3608, -0.6271);
	glVertex2f(0.3305, -0.6241);
	glEnd();
	//16grey
	glColor3f(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0702, -0.5958);
	glVertex2f(0.2425, -0.6217);
	glVertex2f(0.3059, -0.6217);
	glVertex2f(0.0702, -0.6974);
	glEnd();
	//17blue
	glColor3f(7.0 / 255.0, 28.0 / 255.0, 117.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0702, -0.6974);
	glVertex2f(0.3059, -0.6217);
	glVertex2f(0.3780, -0.6217);
	glVertex2f(0.3634, -0.8028);
	glVertex2f(0.0702, -0.8037);
	glEnd();
	//18grey
	glColor3f(128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.4314, -0.8181);
	glVertex2f(0.0702, -0.8037);
	glVertex2f(0.3634, -0.8028);
	glVertex2f(0.3634, -0.8900);
	glVertex2f(0.2817, -0.9167);
	glVertex2f(-0.2127, -0.9166);
	glVertex2f(-0.4516, -0.8422);
	glEnd();
	//middle line
	glColor3f(107.0 / 255.0, 105.0 / 255.0, 118.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0700, -0.2540);
	glVertex2f(0.0703, -0.2540);
	glVertex2f(0.0700, -0.8037);
	glVertex2f(0.0703, -0.8037);
	glEnd();

	//xjtlu x
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.4929, 0.9932 - 0.1);
	glVertex2f(-0.4248, 0.9932 - 0.1);
	glVertex2f(-0.2809, 0.7940 - 0.1);
	glVertex2f(-0.3531, 0.7940 - 0.1);
	glEnd();
	//xjtlu x
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3543, 0.9932 - 0.1);
	glVertex2f(-0.2883, 0.9932 - 0.1);
	glVertex2f(-0.4294, 0.7940 - 0.1);
	glVertex2f(-0.4996, 0.7940 - 0.1);
	glEnd();
	//xjtlu j
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.1799, 0.9928 - 0.1);
	glVertex2f(-0.1176, 0.9928 - 0.1);
	glVertex2f(-0.1176, 0.7963 - 0.1);
	glVertex2f(-0.1799, 0.8481 - 0.1);
	glEnd();
	//xjtlu j
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2689, 0.8481 - 0.1);
	glVertex2f(-0.1799, 0.8481 - 0.1);
	glVertex2f(-0.1176, 0.7963 - 0.1);
	glVertex2f(-0.2689, 0.7940 - 0.1);
	glEnd();
	//xjtlu t
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.0900, 0.9928 - 0.1);
	glVertex2f(0.0986, 0.9928 - 0.1);
	glVertex2f(0.0986, 0.9473 - 0.1);
	glVertex2f(-0.0900, 0.9473 - 0.1);
	glEnd();
	//xjtlu t
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.0289, 0.9473 - 0.1);
	glVertex2f(0.0363, 0.9473 - 0.1);
	glVertex2f(0.0363, 0.7928 - 0.1);
	glVertex2f(-0.0289, 0.7928 - 0.1);
	glEnd();
	//xjtlu l
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.1229, 0.9928 - 0.1);
	glVertex2f(0.1882, 0.9928 - 0.1);
	glVertex2f(0.1882, 0.8448 - 0.1);
	glVertex2f(0.1229, 0.7928 - 0.1);
	glEnd();
	//xjtlu l
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.1882, 0.8448 - 0.1);
	glVertex2f(0.2854, 0.8448 - 0.1);
	glVertex2f(0.2854, 0.7928 - 0.1);
	glVertex2f(0.1229, 0.7928 - 0.1);
	glEnd();
	//xjtlu u
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.3043, 0.9928 - 0.1);
	glVertex2f(0.3679, 0.9928 - 0.1);
	glVertex2f(0.3697, 0.8448 - 0.1);
	glVertex2f(0.3043, 0.7928 - 0.1);
	glEnd();
	//xjtlu u
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.3697, 0.8448 - 0.1);
	glVertex2f(0.4323, 0.8448 - 0.1);
	glVertex2f(0.4982, 0.7928 - 0.1);
	glVertex2f(0.3043, 0.7928 - 0.1);
	glEnd();
	//xjtlu u
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.4323, 0.9928 - 0.1);
	glVertex2f(0.4982, 0.9928 - 0.1);
	glVertex2f(0.4982, 0.7928 - 0.1);
	glVertex2f(0.4323, 0.8448 - 0.1);
	glEnd();

	//animation part
	//15th 1
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x, p0.y);
	glVertex2f(p0.x, p0.y - 0.0739);
	glVertex2f(p0.x - 0.0422, p0.y - 0.0739);
	glEnd();
	//15th 1
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x, p0.y);
	glVertex2f(p0.x + 0.0572, p0.y);
	glVertex2f(p0.x + 0.0572, p0.y - 0.2034);
	glVertex2f(p0.x, p0.y - 0.2034);
	glEnd();
	//15th 5
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.1378, p0.y - 0.0039);
	glVertex2f(p0.x + 0.2717, p0.y - 0.0039);
	glVertex2f(p0.x + 0.2717, p0.y - 0.0518);
	glVertex2f(p0.x + 0.1808, p0.y - 0.0518);
	glEnd();
	//15th 5
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.1378, p0.y - 0.0039);
	glVertex2f(p0.x + 0.1808, p0.y - 0.0518);
	glVertex2f(p0.x + 0.1808, p0.y - 0.0828);
	glVertex2f(p0.x + 0.1378, p0.y - 0.1191);
	glEnd();
	//15th 5
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.1808, p0.y - 0.0828);
	glVertex2f(p0.x + 0.2717, p0.y - 0.0828);
	glVertex2f(p0.x + 0.2238, p0.y - 0.1191);
	glVertex2f(p0.x + 0.1378, p0.y - 0.1191);
	glEnd();
	//15th 5
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.2238, p0.y - 0.1191);
	glVertex2f(p0.x + 0.2717, p0.y - 0.0828);
	glVertex2f(p0.x + 0.2717, p0.y - 0.2034);
	glVertex2f(p0.x + 0.2238, p0.y - 0.1608);
	glEnd();
	//15th 5
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.1378, p0.y - 0.1608);
	glVertex2f(p0.x + 0.2238, p0.y - 0.1608);
	glVertex2f(p0.x + 0.2717, p0.y - 0.2034);
	glVertex2f(p0.x + 0.1378, p0.y - 0.2034);
	glEnd();
	//15th t
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.3896, p0.y - 0.0593);
	glVertex2f(p0.x + 0.498, p0.y - 0.0593);
	glVertex2f(p0.x + 0.4983, p0.y - 0.1039);
	glVertex2f(p0.x + 0.3896, p0.y - 0.1039);
	glEnd();
	//15th t
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.4099, p0.y - 0.0038);
	glVertex2f(p0.x + 0.4665, p0.y - 0.004);
	glVertex2f(p0.x + 0.4665, p0.y - 0.1654);
	glVertex2f(p0.x + 0.4099, p0.y - 0.2046);
	glEnd();
	//15th t
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.4665, p0.y - 0.1654);
	glVertex2f(p0.x + 0.4983, p0.y - 0.1654);
	glVertex2f(p0.x + 0.4983, p0.y - 0.2046);
	glVertex2f(p0.x + 0.4099, p0.y - 0.2046);
	glEnd();
	//15th h
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.5224, p0.y - 0.0035);
	glVertex2f(p0.x + 0.5798, p0.y - 0.0035);
	glVertex2f(p0.x + 0.5798, p0.y - 0.2034);
	glVertex2f(p0.x + 0.5219, p0.y - 0.2034);
	glEnd();
	//15th h
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.5798, p0.y - 0.0568);
	glVertex2f(p0.x + 0.6798, p0.y - 0.0568);
	glVertex2f(p0.x + 0.6207, p0.y - 0.1039);
	glVertex2f(p0.x + 0.5798, p0.y - 0.1039);
	glEnd();
	//15th h
	glColor3f(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(p0.x + 0.6798, p0.y - 0.0568);
	glVertex2f(p0.x + 0.6798, p0.y - 0.2034);
	glVertex2f(p0.x + 0.6207, p0.y - 0.2034);
	glVertex2f(p0.x + 0.6207, p0.y - 0.1039);
	glEnd();

	//left cap
	//cap top
	glColor3f(25.0 / 255.0, 25.0 / 255.0, 25.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.7465 - 0.2, 0.0855);
	glVertex2f(-0.4704 - 0.2, 0.2082);
	glVertex2f(-0.1957 - 0.2, 0.0855);
	glVertex2f(-0.4704 - 0.2, -0.0297);
	glEnd();
	//cap middle left
	glColor3f(50.0 / 255.0, 50.0 / 255.0, 50.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6082 - 0.2, 0.0605);
	glVertex2f(-0.4704 - 0.2, 0.0833);
	glVertex2f(-0.4704 - 0.2, -0.0108);
	glVertex2f(-0.6082 - 0.2, -0.0386);
	glEnd();
	//cap middle right
	glColor3f(50.0 / 255.0, 50.0 / 255.0, 50.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.4704 - 0.2, 0.0833);
	glVertex2f(-0.3316 - 0.2, 0.0605);
	glVertex2f(-0.3316 - 0.2, -0.0386);
	glVertex2f(-0.4704 - 0.2, -0.0108);
	glEnd();
	//caps bottom
	glColor3f(25.0 / 255.0, 25.0 / 255.0, 25.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6082 - 0.2, -0.0386);
	glVertex2f(-0.4704 - 0.2, -0.0108);
	glVertex2f(-0.3316 - 0.2, -0.0386);
	glVertex2f(-0.4704 - 0.2, -0.0693);
	glEnd();
	//pendant1
	glColor3f(250.0 / 255.0, 211.0 / 255.0, 101.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2513 - 0.2, 0.0619);
	glVertex2f(-0.2409 - 0.2, 0.0663);
	glVertex2f(-0.2409 - 0.2, -0.0762);
	glVertex2f(-0.2513 - 0.2, -0.0762);
	glEnd();
	//pendant2
	glColor3f(250.0 / 255.0, 211.0 / 255.0, 101.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2513 - 0.2, -0.0762);
	glVertex2f(-0.2409 - 0.2, -0.0762);
	glVertex2f(-0.2166 - 0.2, -0.1386);
	glVertex2f(-0.2741 - 0.2, -0.1386);
	glEnd();

	//right cap
	//cap top
	glColor3f(25.0 / 255.0, 25.0 / 255.0, 25.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.7465 + 0.2, 0.0855);
	glVertex2f(0.4704 + 0.2, 0.2082);
	glVertex2f(0.1957 + 0.2, 0.0855);
	glVertex2f(0.4704 + 0.2, -0.0297);
	glEnd();
	//cap middle left
	glColor3f(50.0 / 255.0, 50.0 / 255.0, 50.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.6082 + 0.2, 0.0605);
	glVertex2f(0.4704 + 0.2, 0.0833);
	glVertex2f(0.4704 + 0.2, -0.0108);
	glVertex2f(0.6082 + 0.2, -0.0386);
	glEnd();
	//cap middle right
	glColor3f(50.0 / 255.0, 50.0 / 255.0, 50.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.4704 + 0.2, 0.0833);
	glVertex2f(0.3316 + 0.2, 0.0605);
	glVertex2f(0.3316 + 0.2, -0.0386);
	glVertex2f(0.4704 + 0.2, -0.0108);
	glEnd();
	//cap bottom
	glColor3f(25.0 / 255.0, 25.0 / 255.0, 25.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.6082 + 0.2, -0.0386);
	glVertex2f(0.4704 + 0.2, -0.0108);
	glVertex2f(0.3316 + 0.2, -0.0386);
	glVertex2f(0.4704 + 0.2, -0.0693);
	glEnd();
	//pendant1
	glColor3f(250.0 / 255.0, 211.0 / 255.0, 101.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.2513 + 0.2, 0.0619);
	glVertex2f(0.2409 + 0.2, 0.0663);
	glVertex2f(0.2409 + 0.2, -0.0762);
	glVertex2f(0.2513 + 0.2, -0.0762);
	glEnd();
	//pendant2
	glColor3f(250.0 / 255.0, 211.0 / 255.0, 101.0 / 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.2513 + 0.2, -0.0762);
	glVertex2f(0.2409 + 0.2, -0.0762);
	glVertex2f(0.2166 + 0.2, -0.1386);
	glVertex2f(0.2741 + 0.2, -0.1386);
	glEnd();

	glPushMatrix();
	glTranslatef(t, 0, 0); // the order of these transformations may affect the result
	glScalef(s, s, 0); // because of the non-commutative features
	glRotatef(r, 0, 0, 1); // here the translation is applied last
	DrawMiddleCap();
	glPopMatrix();

	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("XJTLU 15th anniversary");
	glutDisplayFunc(define_to_OpenGL);
	glutIdleFunc(when_in_mainloop);
	glutTimerFunc(time_interval, OnTimer, 1);
	glutKeyboardFunc(keyboard_input);
	glutMouseFunc(mouse_input); // mouse callback function

	glutMainLoop();
}
