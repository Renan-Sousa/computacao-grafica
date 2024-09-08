#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int win_id;
float cameraAngle = 0.0f;
float cameraRadius = 30.0f;
float cameraHeight = 2.0f;
float centerX = 0.0f;
float centerZ = 0.0f;

void myKeyboard(unsigned char key, int x, int y)
{
  switch (key) {
    case 27:
     glutDestroyWindow(win_id);
     exit(0);
     break;
  }
  glutPostRedisplay();
}

void init(void) {
  	glClearColor(0.416, 0.902, 0.824, 0.0);
  	glShadeModel(GL_SMOOTH);
  	glEnable(GL_COLOR_MATERIAL);
  	glEnable(GL_DEPTH_TEST);
  	glColor3f(0.5, 1.0, 0.5);
}

void drawGround() {
  	glColor3f(0.929, 0.835, 0.51);
  	glBegin(GL_QUADS);
  	glVertex3f(-60.0f, 0.0f, -60.0f);
  	glVertex3f(-60.0f, 0.0f, 60.0f);
  	glVertex3f(60.0f, 0.0f, 60.0f);
  	glVertex3f(60.0f, 0.0f, -60.0f);
  	glEnd();
}

void DrawEllipsoid(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC) {
	float tStep = (3.14) / (float)uiSlices;
	float sStep = (3.14) / (float)uiStacks;

	for (float t = -3.14 / 2; t <= (3.14 / 2) + .0001; t += tStep) {
		glBegin(GL_TRIANGLE_STRIP);
		for (float s = -3.14; s <= 3.14 + .0001; s += sStep) {
			glVertex3f(fA * cos(t) * cos(s), fB * cos(t) * sin(s), fC * sin(t));
			glVertex3f(fA * cos(t + tStep) * cos(s), fB * cos(t + tStep) * sin(s), fC * sin(t + tStep));
		}
		glEnd();
	}
}

#define PI 3.14159265358979323846
#define numVertices 50

void drawCylinder() {
    int i;
    float angle;
    float radius = 0.5f; 
    float height = 1.0f; 

    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= numVertices; i++) {
        angle = 2.0f * PI * i / numVertices;
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        glVertex3f(x, y, 0.0f);
        glVertex3f(x, y, height);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (i = 0; i < numVertices; i++) {
        angle = 2.0f * PI * i / numVertices;
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        glVertex3f(x, y, height);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (i = 0; i < numVertices; i++) {
        angle = 2.0f * PI * i / numVertices;
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

void desenhaSemicirculo() {
    int i;
    int lados = 100; 
    GLfloat raio = 0.5f; 
    GLfloat x, y;
    GLfloat angulo;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); 
    for (i = 0; i <= lados; ++i) {
        angulo = PI * i / lados;
        x = raio * cos(angulo);
        y = raio * sin(angulo);
        glVertex2f(x, -y); 
    }
    glEnd();
}

void display(void) {
  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
  	float cameraX = centerX + cameraRadius * cos(cameraAngle);
  	float cameraZ = centerZ + cameraRadius * sin(cameraAngle);
  	gluLookAt(cameraX, cameraHeight, cameraZ, centerX, 0.0f, centerZ, 0.0f, 1.0f, 0.0f);

  	drawGround();

 ///////////////////////////////////////////////////////////////////////////
 	//CASA DO BOB ESPONJA
	/*base*/
  	glPushMatrix();
  		glColor3f(0.98, 0.514, 0.012);
		glTranslatef(-12, 5, -6);
  		DrawEllipsoid(50, 50, 7, 12, 7);
  	glPopMatrix();

	/*porta*/
  	glPushMatrix();
  		glColor3f(0.459, 0.459, 0.447);
		glTranslatef(-5, 2, -6);
		glRotatef(-90, 0, 1, 0);
		glScalef(1, 2, 1);
  		glutSolidCone(2,1,50,50);
  	glPopMatrix();

  	glPushMatrix();
  		glColor3f(0.671, 0.671, 0.643);
		glTranslatef(-4.9, 2, -6);
		glRotatef(-90, 0, 1, 0);
		glScalef(0.7, 1.7, 1);
  		glutSolidCone(2,1,50,50);
  	glPopMatrix();

  	glPushMatrix();
  		glColor3f(0.388, 0.388, 0.353);
		glTranslatef(-4.8, 2.5, -6);
		glRotatef(-90, 0, 1, 0);
  		glutSolidCone(0.6, 1, 50, 50);
  	glPopMatrix();

	/*janela*/
  	glPushMatrix();
  		glColor3f(0.459, 0.459, 0.447);
		glTranslatef(-5.4, 9, -5);
		glRotatef(-100, 0, 1, 0);
		glRotatef(10, 1, 0, 0);
  		glutSolidCone(1.5, 3, 50, 50);
  	glPopMatrix();

  	glPushMatrix();
  		glColor3f(0.671, 0.671, 0.643);
		glTranslatef(-5.3, 9, -5);
		glRotatef(-100, 0, 1, 0);
		glRotatef(10, 1, 0, 0);
  		glutSolidCone(1.2, 3, 50, 50);
  	glPopMatrix();
	//---------------------------------
  	glPushMatrix();
  		glColor3f(0.459, 0.459, 0.447);
		glTranslatef(-7, 3.7, -11);
		glRotatef(-50, 0, 1, 0);
		glRotatef(-5, 1, 0, 0);
  		glutSolidCone(1.5, 3, 50, 50);
  	glPopMatrix();
  	
	glPushMatrix();
  		glColor3f(0.671, 0.671, 0.643);
		glTranslatef(-6.9, 3.7, -11);
		glRotatef(-50, 0, 1, 0);
		glRotatef(-5, 1, 0, 0);
  		glutSolidCone(1.2, 3, 50, 50);
  	glPopMatrix();

  	/*folhas*/
	glPushMatrix();
  		glColor3f(0.055, 0.761, 0.067);
		glTranslatef(-10, 19, -6);
		glScalef(0.7, 1, 0.7);
		glRotatef(-15, 0, 0, 1);
  		DrawEllipsoid(50, 50, 1, 6, 1);
	glPopMatrix();
	glPushMatrix();
  		glColor3f(0.055, 0.761, 0.067);
		glTranslatef(-14, 19, -6);
		glScalef(0.7, 1, 0.7);
		glRotatef(15, 0, 0, 1);
  		DrawEllipsoid(50, 50, 1, 6, 1);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.055, 0.761, 0.067);
		glTranslatef(-12, 19, -6);
		glScalef(0.7, 1, 0.7);
  		DrawEllipsoid(50, 50, 1, 6, 1);
	glPopMatrix();
	
	glPushMatrix();
  		glColor3f(0.055, 0.761, 0.067);
		glTranslatef(-12, 19, -8);
		glRotatef(-15, 1, 0, 0);
		glScalef(0.7, 1, 0.7);
  		DrawEllipsoid(50, 50, 1, 6, 1);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.055, 0.761, 0.067);
		glTranslatef(-12, 19, -10);
		glRotatef(-25, 1, 0, 0);
		glScalef(0.7, 1, 0.7);
  		DrawEllipsoid(50, 50, 1, 6, 1);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.055, 0.761, 0.067);
		glTranslatef(-12, 19, -4);
		glRotatef(15, 1, 0, 0);
		glScalef(0.7, 1, 0.7);
  		DrawEllipsoid(50, 50, 1, 6, 1);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.055, 0.761, 0.067);
		glTranslatef(-12, 19, -2);
		glRotatef(25, 1, 0, 0);
		glScalef(0.7, 1, 0.7);
  		DrawEllipsoid(50, 50, 1, 6, 1);
	glPopMatrix();

	/*chamine*/
	glPushMatrix();
  		glColor3f(0.459, 0.459, 0.447);
		glTranslatef(-12, 11, -14);
		glScalef(0.8, 0.8, 3);
  		drawCylinder();
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.459, 0.459, 0.447);
		glTranslatef(-12, 12.2, -14);
		glRotatef(90, 1, 0, 0);
  		glutSolidCone(0.7, 1.5, 50, 50);
  	glPopMatrix();
	

 //////////////////////////////////////////////////////////////////////////
	//BOB ESPONJA
	/*cabeça*/
  	glPushMatrix();
  		glColor3f(1, 0.906, 0);
		glTranslatef(0,4.40,0);
		glScalef(1,3,3);
  		glutSolidCube(1);
  	glPopMatrix();

	/*manchas*/
	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0.5,5.5,-1);
		glScalef(0.01,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0.5,5.5,0.8);
		glScalef(0.01,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0.5,3.8,1);
		glScalef(0.01,0.1,0.1);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0.5,5,-1.2);
		glScalef(0.01,0.1,0.1);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0.5,3.5,-1);
		glScalef(0.01,0.2,0.1);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0.5,3,-1.2);
		glScalef(0.01,0.1,0.1);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();
	//-----------------------------------------
	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(-0.5,5.5,1);
		glScalef(0.01,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(-0.5,4.5,0);
		glScalef(0.01,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(-0.5,5.5,-0.8);
		glScalef(0.01,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(-0.5,3.8,-1);
		glScalef(0.01,0.1,0.1);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(-0.5,5,1.2);
		glScalef(0.01,0.1,0.1);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(-0.5,3.5,1);
		glScalef(0.01,0.2,0.1);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(-0.5,3,1.2);
		glScalef(0.01,0.1,0.1);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	//--------------------------------
	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0,3.5,1.5);
		glRotatef(90,0,1,0);
		glScalef(0.01,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(-0.2,5.5,1.5);
		glRotatef(90,0,1,0);
		glScalef(0.01,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0,4.5,1.5);
		glRotatef(90,0,1,0);
		glScalef(0.01,0.1,0.1);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();
	//--------------------------------
	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0,3.5,-1.5);
		glRotatef(90,0,1,0);
		glScalef(0.01,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0.2,5.5,-1.5);
		glRotatef(90,0,1,0);
		glScalef(0.01,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.682, 0.702, 0.106);
		glTranslatef(0,4.5,-1.5);
		glRotatef(90,0,1,0);
		glScalef(0.01,0.1,0.1);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();


	/*olhos*/
	glPushMatrix();
  		glColor3f(1,1,1);
		glTranslatef(0.5,4.7,0.5);
		glScalef(0.1,0.4,0.4);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.224, 0.514, 0.961);
		glTranslatef(0.55,4.7,0.5);
		glScalef(0.1,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0,0,0);
		glTranslatef(0.57,4.7,0.5);
		glScalef(0.1,0.15,0.15);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();
	//----------------------
	glPushMatrix();
  		glColor3f(1,1,1);
		glTranslatef(0.5,4.7,-0.5);
		glScalef(0.1,0.4,0.4);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.224, 0.514, 0.961);
		glTranslatef(0.55,4.7,-0.5);
		glScalef(0.1,0.2,0.2);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0,0,0);
		glTranslatef(0.57,4.7,-0.5);
		glScalef(0.1,0.15,0.15);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	/*nariz*/
  	glPushMatrix();
  		glColor3f(0.8, 0.788, 0);
		glTranslatef(0.6,4.2,0);
		glRotatef(90, 0, 0, 1);
  		DrawEllipsoid(50, 50, 0.15, 0.8, 0.15);
  	glPopMatrix();

	/*boca*/
	glPushMatrix();
  		glColor3f(0.639, 0.243, 0.176);
		glTranslatef(0.52,3.8,0);
		glRotatef(90,0,1,0);
		glScalef(1.5,1.5,1);
  		desenhaSemicirculo();
  	glPopMatrix();
	
	/*dentes*/
	glPushMatrix();
  		glColor3f(1, 1, 1);
		glTranslatef(0.5,3.70,0.3);
		glScalef(0.1,0.2,0.2);
  		glutSolidCube(1);
  	glPopMatrix();
	glPushMatrix();
  		glColor3f(1, 1, 1);
		glTranslatef(0.5,3.70,-0.3);
		glScalef(0.1,0.2,0.2);
  		glutSolidCube(1);
  	glPopMatrix();

	/*camisa*/
	glPushMatrix();
  		glColor3f(1, 1, 1);
		glTranslatef(0,2.65,0);
		glScalef(1,0.5,3);
  		glutSolidCube(1);
  	glPopMatrix();

	/*gravata*/
	glPushMatrix();
  		glColor3f(1, 0, 0);
		glTranslatef(0.5,2.7,0);
		glRotatef(45, 1, 0, 0);
		glScalef(0.1,0.3,0.3);
  		glutSolidCube(1);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(1, 0, 0);
		glTranslatef(0.5,2.2,0);
		glScalef(0.1,0.7,0.27);
  		glutSolidCube(1);
  	glPopMatrix();

	/*calça*/
	glPushMatrix();
  		glColor3f(0.71, 0.404, 0.09);
		glTranslatef(0,2,0);
		glScalef(1,0.8,3);
  		glutSolidCube(1);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.71, 0.404, 0.09);
		glTranslatef(0,1.65,0.7);
		glRotatef(90, 1,0,0);
		glScalef(0.7,0.7,0.2);
		drawCylinder();
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.71, 0.404, 0.09);
		glTranslatef(0,1.65,-0.7);
		glRotatef(90, 1,0,0);
		glScalef(0.7,0.7,0.2);
		drawCylinder();
  	glPopMatrix();

	/*perna*/
	glPushMatrix();
  		glColor3f(1, 0.906, 0);
		glTranslatef(0,1.7,0.7);
		glRotatef(90, 1,0,0);
		glScalef(0.3,0.3,1);
		drawCylinder();
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(1, 1, 1);
		glTranslatef(0,0.7,0.7);
		glRotatef(90, 1,0,0);
		glScalef(0.3,0.3,0.9);
		drawCylinder();
  	glPopMatrix();
	
	//----------------------------
	glPushMatrix();
  		glColor3f(1, 0.906, 0);
		glTranslatef(0,1.7,-0.7);
		glRotatef(90, 1,0,0);
		glScalef(0.3,0.3,1);
		drawCylinder();
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(1, 1, 1);
		glTranslatef(0,0.7,-0.7);
		glRotatef(90, 1,0,0);
		glScalef(0.3,0.3,0.9);
		drawCylinder();
  	glPopMatrix();

	/*braço*/
	glPushMatrix();
  		glColor3f(1, 0.906, 0);
		glTranslatef(0, 4, -2.8);
		glRotatef(45, 1,0,0);
		glScalef(0.3,0.3,2);
		drawCylinder();
  	glPopMatrix();
	
	glPushMatrix();
  		glColor3f(1, 0.906, 0);
		glTranslatef(0, 2.6, 1.4);
		glRotatef(-45, 1,0,0);
		glScalef(0.3,0.3,2);
		drawCylinder();
  	glPopMatrix();

	

	/*sapato*/
	glPushMatrix();
  		glColor3f(0,0,0);
		glTranslatef(0.1,0.1,-0.7);
		glScalef(0.4,0.2,0.3);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0,0,0);
		glTranslatef(0.1,0.1,0.7);
		glScalef(0.4,0.2,0.3);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

 //////////////////////////////////////////////////////////////////////////
 //PLANKTON
 	/*corpo*/
 	glPushMatrix();
  		glColor3f(0.227, 0.569, 0.361);
		glTranslatef(-1, 1.2, 3);
		glScalef(0.3, 0.3, 0.3);
  		DrawEllipsoid(50, 50, 1, 3, 1);
	glPopMatrix();
 	
	/*olho*/
	glPushMatrix();
  		glColor3f(0.875, 0.98, 0.537);
		glTranslatef(-0.8, 1.6, 3);
		glScalef(0.1,0.18,0.18);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.878, 0.22, 0.161);
		glTranslatef(-0.75, 1.6, 3);
		glScalef(0.1,0.09,0.09);
  		glutSolidSphere(1,50,50);
  	glPopMatrix();
 	
	/*boca*/
	glPushMatrix();
  		glColor3f(0.639, 0.243, 0.176);
		glTranslatef(-0.70, 1.4, 3);
		glRotatef(90,0,1,0);
		glScalef(0.25 ,0.3, 0.25);
  		desenhaSemicirculo();
  	glPopMatrix();

	glPushMatrix();
  		glColor3f(1, 1, 1);
		glTranslatef(-0.69, 1.39, 3);
		glScalef(0.001,0.02,0.2);
  		glutSolidCube(1);
  	glPopMatrix();
 	
	/*antenas*/
	glPushMatrix();
  		glColor3f(0.125, 0.541, 0.286);
		glTranslatef(-1, 2.2, 2.9);
		glRotatef(15, 0, 0, 1);
		glRotatef(-15, 1, 0, 0);
		glScalef(0.04, 0.15, 0.04);
  		DrawEllipsoid(50, 50, 1, 3, 1);
	glPopMatrix();
	
	glPushMatrix();
  		glColor3f(0.125, 0.541, 0.286);
		glTranslatef(-1, 2.2, 3.1);
		glRotatef(15, 0, 0, 1);
		glRotatef(15, 1, 0, 0);
		glScalef(0.04, 0.15, 0.04);
  		DrawEllipsoid(50, 50, 1, 3, 1);
	glPopMatrix();
 	
	/*pernas*/
 	glPushMatrix();
  		glColor3f(0.227, 0.569, 0.361);
		glTranslatef(-1, 0.25, 2.9);
		glRotatef(10, 1, 0, 0);
		glScalef(0.05, 0.1, 0.05);
  		DrawEllipsoid(50, 50, 1, 3, 1);
	glPopMatrix();
 	
	glPushMatrix();
  		glColor3f(0.227, 0.569, 0.361);
		glTranslatef(-1, 0.25, 3.1);
		glRotatef(-10, 1, 0, 0);
		glScalef(0.05, 0.1, 0.05);
  		DrawEllipsoid(50, 50, 1, 3, 1);
	glPopMatrix();
	
	/*braços*/
	glPushMatrix();
  		glColor3f(0.227, 0.569, 0.361);
		glTranslatef(-1, 1, 2.65);
		glRotatef(10, 1, 0, 0);
		glScalef(0.05, 0.1, 0.05);
  		DrawEllipsoid(50, 50, 1, 3, 1);
	glPopMatrix();
 	
	glPushMatrix();
  		glColor3f(0.227, 0.569, 0.361);
		glTranslatef(-1, 1, 3.35);
		glRotatef(-10, 1, 0, 0);
		glScalef(0.05, 0.1, 0.05);
  		DrawEllipsoid(50, 50, 1, 3, 1);
	glPopMatrix();

	////////////////////////////////////////////////////////////////////
	//PAISAGEM
	/*pedras*/
	glPushMatrix();
  		glColor3f(0.302, 0.322, 0.302);
		glTranslatef(-10,0,10);
  		glutSolidSphere(2, 50, 50);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.588, 0.251, 0.741);
		glTranslatef(-10,4,10);
		glScalef(0.4, 1, 0.4);
  		DrawEllipsoid(50, 50, 1, 3, 1);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.588, 0.251, 0.741);
		glTranslatef(-10,5,11);
		glRotatef(45,1,0,0);
		glScalef(0.4, 1, 0.4);
  		DrawEllipsoid(50, 50, 1, 2, 1);
	glPopMatrix();
	
	glPushMatrix();
  		glColor3f(0.588, 0.251, 0.741);
		glTranslatef(-10,6,9);
		glRotatef(-45,1,0,0);
		glScalef(0.4, 1, 0.4);
  		DrawEllipsoid(50, 50, 1, 2, 1);
	glPopMatrix();
	//------------------------------------
	
	glPushMatrix();
  		glColor3f(0.302, 0.322, 0.302);
		glTranslatef(5,0,12);
  		glutSolidSphere(2, 50, 50);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.302, 0.322, 0.302);
		glTranslatef(-1,0,-19);
  		glutSolidSphere(2, 50, 50);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.941, 0.51, 0.647);
		glTranslatef(-1,4,-19);
		glScalef(0.4, 1, 0.4);
  		DrawEllipsoid(50, 50, 1, 3, 1);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.941, 0.51, 0.647);
		glTranslatef(-1,5,-18);
		glRotatef(45,1,0,0);
		glScalef(0.4, 1, 0.4);
  		DrawEllipsoid(50, 50, 1, 2, 1);
	glPopMatrix();
	
	glPushMatrix();
  		glColor3f(0.941, 0.51, 0.647);
		glTranslatef(-1,6,-20);
		glRotatef(-45,1,0,0);
		glScalef(0.4, 1, 0.4);
  		DrawEllipsoid(50, 50, 1, 2, 1);
	glPopMatrix();

	/*bolhas*/
	glPushMatrix();
  		glColor3f(0.902, 0.949, 0.949);
		glTranslatef(-1,15,-19);
  		glutSolidSphere(1, 50, 50);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.902, 0.949, 0.949);
		glTranslatef(-7,15,19);
  		glutSolidSphere(1, 50, 50);
	glPopMatrix();

	glPushMatrix();
  		glColor3f(0.902, 0.949, 0.949);
		glTranslatef(-5,12,14);
  		glutSolidSphere(2, 50, 50);
	glPopMatrix();



  	glutSwapBuffers();
}

void reshape(int w, int h) {
  	glViewport(0, 0, w, h);
  	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();
  	gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
  	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
}

void update(int value) {
  	cameraAngle += 0.007f;
  	glutPostRedisplay();
  	glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
  	glutInit(&argc, argv);
  	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
  	glutInitWindowSize(500, 500);
  	glutInitWindowPosition(100, 100);
  	win_id = glutCreateWindow(argv[0]);
  	init();
  	glutDisplayFunc(display);
  	glutReshapeFunc(reshape);
	glutKeyboardFunc(myKeyboard);
  	glutTimerFunc(16, update, 0);
  	glutMainLoop();
  	return 0;
}
