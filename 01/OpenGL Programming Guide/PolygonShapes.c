#include<windows.h>
#include <stdio.h>
#include<GL/glut.h>
void display(void)
{
	glBegin(GL_TRIANGLES);
		glVertex2f(-0.3,-0.7);
		glVertex2f(0.0,-0.9);
		glVertex2f(0.3,-0.7);
	glEnd();
	glBegin(GL_POLYGON); 
	    glVertex2f (0.0, -0.7);   
	    glVertex2f (0.7, -0.3);  
	    glVertex2f (0.0, 0.0);  
	 glVertex2f (-0.7, -0.3);  
	
	 glEnd(); 

    glBegin(GL_POLYGON);  
		 glVertex2f (0.0, 0.0);  
		 glVertex2f (0.85, 0.2); 
		 glVertex2f (0.05, 0.5);
		 glVertex2f (0.6, 0.6);
		 glVertex2f (0.0, 0.95);
		 glVertex2f (-0.6, 0.6);
		 glVertex2f (-0.05, 0.5); 
		 glVertex2f (-0.85,0.2 );    
	 glEnd(); 

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