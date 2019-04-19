#include<windows.h>
#include <stdio.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
/*
void display(void)
{
    float x1,y1,x2,y2;
float angle;
double radius=0.1;

x1 = 0.5,y1=0.6;
glColor3f(1.0,0.0,0.0);

glBegin(GL_TRIANGLE_FAN);
glVertex2f(x1,y1);

for (angle=1.0f;angle<361.0f;angle+=0.2)
{
    x2 = x1+sin(angle)*radius;
    y2 = y1+cos(angle)*radius;
    glVertex2f(x2,y2);
}

glEnd();

	glFlush();
}
*/
void display()
{
    //Rectangle draw
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
		 glVertex2f (-0.5, -0.3);
		 glVertex2f (0.5, -0.3);
		 glVertex2f (0.5, 0.3);
		 glVertex2f (-0.5, 0.3);
	 glEnd();

    //Cercle draw
    /*
    float angle;
    float center_x=0.0,center_y=0.0;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
        for(int i=0;i<=360;i++){
            angle=i*3.1416/180;
            glVertex2f(center_x+0.1*cos(angle),center_y+0.1*sin(angle));
        }
    glEnd();*/
    glFlush();

}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(500,0);
	glutCreateWindow("Lab-1");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
