#include<windows.h>
#include<gl/glut.h>

void putpixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}

void midpointcircle(int r)
{
    int x,y,p;
    x=0;
    y=r;
    p=1-r;
    while(x<=y)
    {
        putpixel(x,y);
        putpixel(x,-y);
        putpixel(-x,y);
        putpixel(-x,-y);
        putpixel(y,x);

        putpixel(-y,x);
        putpixel(y,-x);
        putpixel(-y,-x);

        if(p<0)
           {
               x++;
               p=p+2*x+1;
           }
            ///p=p+4*x+6 bresenham circle
        else
        {
            x++;
            p=p+2*(x-y)+1;
            ///p=p+*(x-y)+10 bresenham circle
            y--;
        }

    }
}

void bresenhamcircle(int r)
{
    int x,y,p;
    x=0;
    y=r;
    p=3-2*r;
    while(x<=y)
    {
        putpixel(x,y);
        putpixel(x,-y);
        putpixel(-x,y);
        putpixel(-x,-y);
        putpixel(y,x);
        putpixel(-y,x);
        putpixel(y,-x);
        putpixel(-y,-x);
        if(p<0)
           {
               p=p+4*x+6;
           }
        else
        {

            p=p+4*(x-y)+10;
            y--;
        }
        x++;
    }
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
   /// midpointcircle(200);
    bresenhamcircle(200);

    glFlush();
}

void initialize()
{
    glClearColor(0.0,0.0,0.0,0.0);///color
    glMatrixMode(GL_PROJECTION);///matrix display
    glLoadIdentity();///for checking
    glOrtho(-500,500,-500,500,-1,1);///
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

