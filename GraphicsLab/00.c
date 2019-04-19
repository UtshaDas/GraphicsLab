#include<windows.h>
#include <stdio.h>
#include<GL/glut.h>
void Keyboard(unsigned char c, int x, int);
void display(void)
{

	glBegin(GL_TRIANGLES);
		glColor3f (1, 0.0, 0.0);
		glVertex2f(0/2,0/2);
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
		glColor3f (0.3, 0.2, 0.2);
		glVertex2f(.78/2,-0.5/2);
		glColor3f (0.1, 0.2, 0.1);
		glVertex2f(.6/2,-.46/2);
	glEnd();
	glFlush();
}

void display2()
{
    glBegin(GL_POLYGON);
	    glColor3f (0, 1.0, 0.0);
		glVertex2f(0.1/2,-0.1/2);
		glVertex2f(.1/2,-.32/2);
		glVertex2f(.32/2,-0.32/2);
		glVertex2f(.32/2,-.1/2);
	glEnd();
	glFlush();
}
void Keyboard2(unsigned char c, int x, int y)
{
    printf("%d\n",c);
    switch(c)
    {
    case 116:

        glClear(GL_COLOR_BUFFER_BIT);
        glTranslatef(.5,.3,.2);
        glutDisplayFunc(display2);
        glutPostRedisplay();
        break;
    case 115:
        glClear(GL_COLOR_BUFFER_BIT);
        glScalef(.5,.5,.5);
        glutDisplayFunc(display2);
        glutPostRedisplay();
        break;
    case 114:
        glClear(GL_COLOR_BUFFER_BIT);
        glRotatef(30,0,0,1);
        glutDisplayFunc(display2);
        glutPostRedisplay();
        break;
    case 101:
        glClear(GL_COLOR_BUFFER_BIT);
        glScalef(1.5,1.5,1.5);
        glutDisplayFunc(display2);
        glutPostRedisplay();
        break;
    case 111:
        glClear(GL_COLOR_BUFFER_BIT);
        glutDisplayFunc(display);
        glutPostRedisplay();
        glutKeyboardFunc(Keyboard);
        break;
    case 120:
        exit(1);
    }
}
void Keyboard(unsigned char c, int x, int y)
{
    printf("%d\n",c);
    switch(c)
    {
    case 116:

        glClear(GL_COLOR_BUFFER_BIT);
        glTranslatef(.5,.3,.2);
        glutDisplayFunc(display);
        glutPostRedisplay();
        break;
    case 115:
        glClear(GL_COLOR_BUFFER_BIT);
        glScalef(.5,.5,.5);
        glutDisplayFunc(display);
        glutPostRedisplay();
        break;
    case 114:
        glClear(GL_COLOR_BUFFER_BIT);
        glRotatef(15,0,0,1);
        glutDisplayFunc(display);
        glutPostRedisplay();
        break;
    case 101:
        glClear(GL_COLOR_BUFFER_BIT);
        glScalef(1.5,1.5,1.5);
        glutDisplayFunc(display);
        glutPostRedisplay();
        break;
    case 113:
        glClear(GL_COLOR_BUFFER_BIT);
        glutDisplayFunc(display2);
        glutPostRedisplay();
        glutKeyboardFunc(Keyboard2);
        break;
    case 120:
        exit(1);
    }
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(500,0);
	glutCreateWindow("Lab-1");
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutDisplayFunc(display);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}
