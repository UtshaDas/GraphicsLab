#include<windows.h>
#include <stdio.h>
#include<GL/glut.h>
float fovy=45.0f;
float aspect=1.0f;
float farr=5.0f;
float nearr=20.0f;

float ex=0.0;
float ey=0.0;
float ez=5.0;
float cx=0.0;
float cy=0.0;
float cz=0.0;

float upx=0.0;
float upy=1.0;
float upz=1.0;
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}
void cubedesign(void)
{
     glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  // End of drawing color-cube
   glFlush ();
   //glutSwapBuffers();
}
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    //glEnable(GL_DEPTH_TEST);
    //glLoadIdentity (); /* clear the matrix */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity (); /* clear the matrix */
    gluPerspective(fovy,aspect,nearr,farr);
    //glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    /* viewing transformation */
    gluLookAt (ex, ey, ez, cx, cy, cz, upx, upy, upz);
    //glScalef (1.0, 1.0, 1.0); /* modeling transformation */
    //glutWireCube (1.0);
    cubedesign();

//    glTranslatef(0.0, 0.0, -1.0);
//    glRotatef(60, 1.0, 0.0, 0.0);
//    glRotatef(-20, 0.0, 0.0, 1.0);

}

//void reshape (int w, int h)
//{
//    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
//    glMatrixMode (GL_PROJECTION);
//    glLoadIdentity ();
//    //glPushMatrix();
//    //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
//    printf("fovy=%f\n",fovy);
//    printf("aspect=%f\n",aspect);
//    printf("far =%f\n",farr);
//    printf("Near =%f\n",nearr);
//    gluPerspective(fovy,aspect,nearr,farr);
//   // glPushMatrix();
//    glMatrixMode (GL_MODELVIEW);
//}
void Keyboard(unsigned char c, int x, int y)
{
    printf("%d\n",c);
    glLoadIdentity();
    switch(c)
    {
    case 97:
    case 65:
        glClear(GL_COLOR_BUFFER_BIT);
        fovy=fovy+5.0;
       // printf("%f\n",fovy);
        //glutDisplayFunc(display);
        //glPushMatrix();
        //printf("Display called\n");
        //glutReshapeFunc(reshape);
        //printf("RESHAPE called\n");
        //glPopMatrix();
        glutPostRedisplay();
        break;
    case 98:
    case 66:
        glClear(GL_COLOR_BUFFER_BIT);
        fovy=fovy-5.0;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    case 99:
    case 67:
        glClear(GL_COLOR_BUFFER_BIT);
        aspect=aspect*2;
        glPushMatrix();
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
//        glPopMatrix();
        glutPostRedisplay();
        break;
    case 100:
    case 68:
        glClear(GL_COLOR_BUFFER_BIT);
        aspect=aspect/2;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    case 101:
    case 69:
        glClear(GL_COLOR_BUFFER_BIT);
        nearr=nearr+2;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    case 102:
    case 70:
        glClear(GL_COLOR_BUFFER_BIT);
        nearr=nearr-2;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);

        glutPostRedisplay();
        break;
    case 103:
    case 71:
        glClear(GL_COLOR_BUFFER_BIT);
        farr=farr+2;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    case 104:
    case 72:
        glClear(GL_COLOR_BUFFER_BIT);
        farr=farr-2;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    case 105:
    case 73:
        glClear(GL_COLOR_BUFFER_BIT);
        ex=ex+0.1;
        ey=ey+0.1;
        ez=ez+0.1;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    case 106:
    case 74:
        glClear(GL_COLOR_BUFFER_BIT);
        ex=ex-0.1;
        ey=ey-0.1;
        ez=ez-0.1;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    case 107:
    case 75:
        glClear(GL_COLOR_BUFFER_BIT);
        cx=cx+0.1;
        cy=cy+0.1;
        cz=cz+0.1;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    case 108:
    case 76:
        glClear(GL_COLOR_BUFFER_BIT);
        cx=cx-0.1;
        cy=cy-0.1;
        cz=cz-0.1;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    case 109:
    case 77:
        glClear(GL_COLOR_BUFFER_BIT);
        upx=upx+0.1;
        upy=upy+0.1;
        upz=upz+0.1;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    case 110:
    case 78:
        glClear(GL_COLOR_BUFFER_BIT);
        upx=upx-0.1;
        upy=upy-0.1;
        upz=upz-0.1;
//        glutDisplayFunc(display);
//        glutReshapeFunc(reshape);
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutDisplayFunc(display);
    //glutReshapeFunc(reshape);
    //scanf("%f",&aspect);
    //glutReshapeFunc(reshape);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
return 0;
}
