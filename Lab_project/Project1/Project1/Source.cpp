#include <stdio.h>
#include<glut.h>
void train(void)
{
	glBegin(GL_TRIANGLES);
		glColor3f (1, 0.0, 0.0); 
		glVertex2f(0,0);
		glVertex2f(.06/2,-.16/2);
		glVertex2f(.16/2,-0.06/2);
	glEnd();

	glBegin(GL_POLYGON);
	    glColor3f (0, 1.0, 0.0);
		glVertex2f(0.1/2,-0.1/2);
		glVertex2f(.1/2,-.32/2);
		glVertex2f(.32/2,-0.32/2);
		glVertex2f(.32/2,-.1/2);
	glEnd();

	glBegin(GL_POLYGON);
	    glColor3f (0, 0.0, 1.0);
		glVertex2f(.32/2,-0.32/2);
		glVertex2f(.3/2,-.58/2);
		glVertex2f(.46/2,-0.6/2);
		glVertex2f(.6/2,-.46/2);
		glVertex2f(.58/2,-0.3/2);
	glEnd();

	glBegin(GL_POLYGON);
	    glColor3f (0.2, 0.0, 0.05);
		glVertex2f(.46/2,-0.6/2);
		glColor3f (0.3, 0.2, 0.1);
		glVertex2f(.5/2,-0.78/2);
		glColor3f (.1, 0.1, 0.1);
		glVertex2f(.9/2,-0.9/2);
		glColor3f (0.3/2, 0.2, 0.2/2);
		glVertex2f(.78/2,-0.5/2);
		glColor3f (0.1, 0.2, 0.1);
		glVertex2f(.6/2,-.46/2);
	glEnd();
}

void chockro(void)
{
	
	int division=5;
	float angle=360/division;
	for(int i=0;i<=360/division;i++)
	{
		glPushMatrix();
		glRotatef(i*angle,0,0,1);
	    train();
	    glPopMatrix();
	}
	/*
	glPushMatrix();
	train();
	glPopMatrix();

	glPushMatrix();
	glRotatef(72,0,0,1);
	train();
	glPopMatrix();

	glPushMatrix();
	glRotatef(144,0,0,1);
	train();
	glPopMatrix();

	glPushMatrix();
	glRotatef(216,0,0,1);
	train();
	glPopMatrix();

	glPushMatrix();
	glRotatef(288,0,0,1);
	train();
	glPopMatrix();
	glFlush();

	*/
}

void display(void)
{
	chockro();

	
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(700,980);
	glutInitWindowPosition(500,-320);
	glutCreateWindow("Graphics Design");
	glutDisplayFunc(display);
	//glScalef(.5,.5,1);
	//glRotatef(72,0,0,1;)
	glutMainLoop();
	return 0;
}