#include<windows.h>
#include<gl/glut.h>

void putpixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}


void bresenhamLine(int x1,int y1,int x2, int y2)
{
    int x,y,dx,dy;
    int d;
    x=x1;
    y=y1;
    dx=x2-x1;
    dy=y2-y1;
    d=2*dy-dx;

    while(x<=x2)
    {
        putpixel(x,y);
        x++;
        if(d<0)
        {
            d=d+2*dy;
        }
        else
        {
            d=d+2*dy-2*dx;
            y++;
        }
    }
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    bresenhamLine(10,20,70,80);

    glFlush();
}





void initialize()
{
    glClearColor(0.0,0.0,0.0,0.0);///color
    glMatrixMode(GL_PROJECTION);///matrix display
    glLoadIdentity();///for checking
    glOrtho(-100,100,-100,100,-1,1);///
}

int main(int Argc, char **Argv)
{
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    ///single, double buffer, why use buffer, use of single double buffer
    glutInitWindowSize(850,900);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    ///glutDisplayFunc(initialize);
    initialize();


    glutDisplayFunc(draw);


    ///glutDisplayFunc(bresenhamLine(1,2,6,8));
    glutMainLoop();///event gula show kore

    return 0;
}
