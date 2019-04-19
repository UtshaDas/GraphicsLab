#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
float angle=0.0f;
void drawing()
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
void star()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i=0;i<5;i++)
    {
        glPushMatrix();
        glRotatef(i*72,0,0,1);
        drawing();
        glPopMatrix();
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(angle>=360.0)
        angle=0.0f;

    glPushMatrix();
    glRotatef(angle,0,0,1);
    star();
    glFlush();
    glPopMatrix();
    angle+=.1;
    glutSwapBuffers();
    glutPostRedisplay();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(500,0);
    glutCreateWindow("Practice");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
