#include <windows.h>
#include <gl\glut.h>  // glut.h must come before gl.h and glu.h
#include <gl\gl.h>
#include <gl\glu.h>
#include<vector>
int pntX1, pntY1, choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
int shearingX, shearingY;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glVertex2f(20, 20);
    glVertex2f(20, 70);
    glVertex2f(70, 70);
    glVertex2f(70, 20);
    glEnd();

    //glScalef(0.86,0.86,0.86);
    //glTranslatef(200,0,0);
    //glRotatef(30, 0, 0,1);

    void drawPolygonShearing()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);

	if (shearingAxis == 'x' || shearingAxis == 'X')
	{
		glVertex2i(pntX[0], pntY[0]);

		glVertex2i(pntX[1] + shearingX, pntY[1]);
		glVertex2i(pntX[2] + shearingX, pntY[2]);

		glVertex2i(pntX[3], pntY[3]);
	}
	else if (shearingAxis == 'y' || shearingAxis == 'Y')
	{
		glVertex2i(pntX[0], pntY[0]);
		glVertex2i(pntX[1], pntY[1]);

		glVertex2i(pntX[2], pntY[2] + shearingY);
		glVertex2i(pntX[3], pntY[3] + shearingY);
	}
	glEnd();
}

    glBegin(GL_QUADS);
    glVertex2f(100, 120);
    glVertex2f(200, 120);
    glVertex2f(200, 220);
    glVertex2f(100, 220);

    glEnd();

    glFlush();
}


void init()
{
    glClearColor(0.5,0.5,0.0, 0.0);
    glColor3f(1,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,      // left
        800,  // right
        800, // bottom
        0,      // top
        0,      // zNear
        1       // zFar
        );
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(900, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Simple");

    glutDisplayFunc(display);

    init();

    glutMainLoop();
}
