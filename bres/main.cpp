#include<windows.h>
#include<gl/glut.h>
#include<iostream>

using namespace std;

int x1,x2,y1,y2,dx,dy;
void put_pixel(GLint x,GLint y)
{
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}

void bresline()
{

    int x=x1;
    int y=y1;
    dx=x2-x1;
    dy=y2-y1;
    int d;
    d=2*dy-dx;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    put_pixel(x,y);

    while(x<=x2)
    {
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

          put_pixel(x,y);
    }
    glFlush();
}
void bresline1()
{
    int x=x1;
    int y=y1;
    dx=x2-x1;
    dy=y2-y1;
    int d=2*dx-dy;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1,1.0,1.0);
    put_pixel(x,y);

    while(y<=y2)
    {


        if(d<0)
        {
           d=d+2*dx;

        }

        else
        {
            d=d+2*dx-2*dy;
            x++;
        }
          y++;
          put_pixel(x,y);

    }
    glFlush();
}

void initialize()
{
    glClearColor(0.1,1.0,1.1,0.1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200,200,-200,200,-1,1);
}

int main(int Argc, char **Argv)
{
    cout<<"Enter the co-ordinates of to points: "<<endl;
    cout<<"Enter x1,y1: ";
    cin>>x1>>y1;
    cout<<"Enter x2,y2: ";
    cin>>x2>>y2;
    int dx=x2-x1;
    int dy=y2-y1;
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(850,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    initialize();
    if((dy/dx)>1)
    {
        glutDisplayFunc(bresline1);
    }
    else
    {
        glutDisplayFunc(bresline);
    }
    glutMainLoop();
    return 0;
}

