#include<stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

float drop=-5;
double op=0,in=0.05;
void draw_pixel(GLint cx, GLint cy)
{

    glBegin(GL_POINTS);
    glVertex2i(cx,cy);
    glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
    draw_pixel(x+h,y+k);
    draw_pixel(-x+h,y+k);
    draw_pixel(x+h,-y+k);
    draw_pixel(-x+h,-y+k);
    draw_pixel(y+h,x+k);
    draw_pixel(-y+h,x+k);
    draw_pixel(y+h,-x+k);
    draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
    GLint d=1-r, x=0, y=r;
    while(y>x)
    {
        plotpixels(h,k,x,y);
        if(d<0)
            d+=2*x+3;
        else
        {
            d+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
    plotpixels(h,k,x,y);
}
void snowf()
{
    double i=.04,x=3,j,y=4,k,l;
    for(l=-6;l<10;l+=0.2)
    {for(k=-20;k<20;k++)
    {
    j=0.5*pow(-1,k);
    x=3+k;
    y=l+j;
     int f= rand();
     f=f%4;
     double g=f;
     y=y+(g/4)*pow(-1,k);
     x=x+(g/4)*pow(-1,k);
    glBegin(GL_POLYGON);
    glColor4ub(255,255,255,200);
    glVertex2d(6*i+x,1.6*i+y);
    glVertex2d(8*i+x,3*i+y);
    glVertex2d(8*i+x,5*i+y);
    glVertex2d(6*i+x,6.4*i+y);
    glVertex2d(4*i+x,5*i+y);
    glVertex2d(4*i+x,3*i+y);
    glEnd();
    }}

}
void snow()
{
int i,j,k;
if(drop>10)
drop=-5;


drop+=.020;

    glPushMatrix();
    glTranslatef(drop,drop,0);
    snowf();
    glPopMatrix();

}
void daynight()
{
    op+=in;
    if(op>150)
        in=-0.05;
    if(op<0)
        in=0.05;
    glBegin(GL_QUADS);
    glColor4ub(0,0,0,op);
    glVertex2d(0,0);
    glVertex2d(0,18);
    glVertex2d(20,18);
    glVertex2d(20,0);
    glEnd();
}

void draw_object()
{

//sky N
        glColor3f(0.5,0.8,1);
        glBegin(GL_POLYGON);
        glVertex2f(2,4.5);
        glVertex2f(18,5.125);
        glVertex2f(18,1);
        glVertex2f(2,1);
        glEnd();


//Mountains N
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(2,4.25);
        glVertex2f(3.75,3.25);
        glVertex2f(4.625,4);
        glVertex2f(2,6.125);

        glEnd();


//Mountains N
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(4,7);
        glVertex2f(8.375,3.125);
        glVertex2f(11.625,7);


        glEnd();

//Mountains N
        glColor3f(0.8,0.8,0.8);
        glBegin(GL_POLYGON);
        glVertex2f(8,7);
        glVertex2f(13,7);
        glVertex2f(11.125,3.125);


        glEnd();


//Mountains N
        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(18,3);
        glVertex2f(18,7);
        glVertex2f(13,7);


        glEnd();


//Mountains N
        glColor3f(0.8,0.8,0.8);
        glBegin(GL_POLYGON);
        glVertex2f(2,7);
        glVertex2f(2,6);
        glVertex2f(4.875, 3.625);
        glVertex2f(5.375, 4.625);

        glVertex2f(5.75,4.125);
        glVertex2f(6.1875,4.8828);
        glVertex2f(6.625,3.625);
        glVertex2f(7,4.375);
        glVertex2f(9,7);

        glEnd();

//Mountains N
        glColor3f(0.7,0.7,0.7);
        glBegin(GL_POLYGON);
        glVertex2f(5.5,7);
        glVertex2f(6.25,4.25);
        glVertex2f(7.875,4.75);
        glVertex2f( 8.125, 4.125);

        glVertex2f(8.875, 5.25);
        glVertex2f(9.101,4.404);
        glVertex2f(9.625,5);
        glVertex2f(10.375, 4.125);
        glVertex2f(11.5,5);

        glVertex2f(12.37, 4.37);
        glVertex2f(13.625, 4.75);
        glVertex2f(14.11, 3.93);
        glVertex2f(14.5,4.5);
        glVertex2f(15,3.25);

        glVertex2f(18,5.25);
        glVertex2f(18,7);


        glEnd();



//house N1

        glColor3f(0.9,0.3,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(13,7);
        glVertex2f(13,5.5);
        glVertex2f( 13.625,5.5);
        glVertex2f( 13.625,7);

        glEnd();

        glColor3f(0.9,0.5,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(13.625,5.5);
        glVertex2f(14.125,5);
        glVertex2f( 14.625, 5.5);
        glVertex2f( 14.625, 7);
        glVertex2f( 13.625,7);


        glEnd();


        glColor3f(1,1,1);
        glBegin(GL_POLYGON);

        glVertex2f(13,5.5);
        glVertex2f( 13.625,5.5);
        glVertex2f( 14.125,5);
        glVertex2f(13.5,5);

        glEnd();


        glColor3f(0.4,0.1,0.0);
        glBegin(GL_POLYGON);

        glVertex2f(13.125,5.75);
        glVertex2f( 13.125,6);
        glVertex2f( 13.5,6);
        glVertex2f(13.5,5.75);

        glEnd();


        glColor3f(0.4,0.1,0.0);
        glBegin(GL_POLYGON);

        glVertex2f(13.875,5.75);
        glVertex2f( 14.125,5.75);
        glVertex2f( 14.125,6.125);
        glVertex2f(13.875,6.125);

        glEnd();


        glColor3f(0.4,0.1,0.0);
        glBegin(GL_POLYGON);

        glVertex2f(14.25,5.75);
        glVertex2f( 14.5,5.75);
        glVertex2f( 14.5,6.125);
        glVertex2f(14.25,6.125);

        glEnd();


        glColor3f(0.4,0.1,0.0);
        glBegin(GL_POLYGON);

        glVertex2f(14.25,6.375);
        glVertex2f( 14.5,6.375);
        glVertex2f( 14.5,6.75);
        glVertex2f(14.25,6.75);

        glEnd();


        glColor3f(0.4,0.1,0.0);
        glBegin(GL_POLYGON);

        glVertex2f(14.125,6.375);
        glVertex2f( 13.875,6.375);
        glVertex2f( 13.875,6.75);
        glVertex2f(14.125,6.75);

        glEnd();


        glColor3f(0.4,0.1,0.0);
        glBegin(GL_POLYGON);

        glVertex2f(13.25,7);
        glVertex2f( 13.5, 7);
        glVertex2f( 13.5, 6.5);
        glVertex2f(13.25,6.5);

        glEnd();




//home N2

        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);

        glVertex2f(12,7);
        glVertex2f( 11,7);
        glVertex2f( 11,6.25);
        glVertex2f(12,6.25);

        glEnd();


        glColor3f(0.8,0.0,0.0);
        glBegin(GL_POLYGON);

        glVertex2f(12.25,6);
        glVertex2f( 12.5, 6.25);
        glVertex2f( 12.5, 7);
        glVertex2f(12,7);
        glVertex2f(12,6.25);

        glEnd();


        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);

        glVertex2f( 11,6.25);
        glVertex2f(12,6.25);
        glVertex2f(12.25,6);
        glVertex2f( 11.25,6);

        glEnd();



        glColor3f(1.0,0.9,1.0);
        glBegin(GL_POLYGON);

        glVertex2f( 11.125,7);
        glVertex2f(11.375,7);
        glVertex2f(11.375,6.5);
        glVertex2f( 11.125,6.5);

        glEnd();



        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);

        glVertex2f( 11.625,6.75);
        glVertex2f(11.875,6.75);
        glVertex2f(11.875,6.5);
        glVertex2f( 11.625,6.5);

        glEnd();



        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);

        glVertex2f( 12.125, 6.5);
        glVertex2f(12.125, 6.75);
        glVertex2f(12.375,6.75);
        glVertex2f( 12.375,6.5);

        glEnd();



//house N3
        glColor3f(0.8,0.3,0.9);
        glBegin(GL_POLYGON);

        glVertex2f( 8.125,7);
        glVertex2f(8.625,7);
        glVertex2f(8.625,6.375);
        glVertex2f(8.375,6);
        glVertex2f( 8.125,6.375);

        glEnd();


        glColor3f(0.8,0.1,0.7);
        glBegin(GL_POLYGON);

        glVertex2f(8.625,7);
        glVertex2f(9.375,7);
        glVertex2f(9.375,6.375);
        glVertex2f( 8.625, 6.375);

        glEnd();



        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);

        glVertex2f(9.375,6.375);
        glVertex2f( 8.625, 6.375);
        glVertex2f(8.375,6);
        glVertex2f(9.125,6);

        glEnd();


        glColor3f(1.0,1.0,0.5); //yellow
        glBegin(GL_POLYGON);

        glVertex2f(8.25,7);
        glVertex2f( 8.5,7);
        glVertex2f(8.5, 6.625);
        glVertex2f(8.25,6.625);

        glEnd();



        glColor3f(1.0,1.0,0.5); //yellow
        glBegin(GL_POLYGON);

        glVertex2f(8.75,6.875);
        glVertex2f( 8.875,6.875);
        glVertex2f(8.875, 6.625);
        glVertex2f(8.75,6.625);

        glEnd();



        glColor3f(1.0,1.0,0.5); //yellow
        glBegin(GL_POLYGON);

        glVertex2f(9.125,6.875);
        glVertex2f( 9.25,6.875);
        glVertex2f(9.25, 6.625);
        glVertex2f(9.125,6.625);

        glEnd();



//Tree middle

        glColor3f(0.7,0.3,0.0); //coffe
        glBegin(GL_POLYGON);

        glVertex2f(10.375,7);
        glVertex2f(10.5,7 );
        glVertex2f(10.5,6);
        glVertex2f(10.375,6);

        glEnd();



        glColor3f(0.4,0.6,0.0); //1 green
        glBegin(GL_POLYGON);

        glVertex2f(10, 6.625);
        glVertex2f(10.875,6.625 );
        glVertex2f(10.41,6);

        glEnd();



        glColor3f(0.4,0.7,0.0); //2 green
        glBegin(GL_POLYGON);

        glVertex2f(10, 6.375);
        glVertex2f(10.875,6.375 );
        glVertex2f(10.41,5.75);

        glEnd();



        glColor3f(0.4,0.8,0.0); //3 green
        glBegin(GL_POLYGON);

        glVertex2f(10, 6.125);
        glVertex2f(10.875,6.125 );
        glVertex2f(10.41,5.55);

        glEnd();


        glColor3f(0.4,0.9,0.0); //4 green
        glBegin(GL_POLYGON);

        glVertex2f(10, 5.875);
        glVertex2f(10.875,5.875 );
        glVertex2f(10.41,5.25);

        glEnd();


        glColor3f(0.4,1.0,0.0); //5 green
        glBegin(GL_POLYGON);


        glVertex2f(10, 5.625);
        glVertex2f(10.875,5.625 );
        glVertex2f(10.41,4.95);

        glEnd();



//tree Right
        glColor3f(0.7,0.3,0); //coffee
        glBegin(GL_POLYGON);


        glVertex2f(15.25, 7);
        glVertex2f(15.375,7 );
        glVertex2f(15.375,6);
        glVertex2f(15.25,6);


        glEnd();


        glColor3f(0.4,0.6,0.0); //1 green
        glBegin(GL_POLYGON);

        glVertex2f(14.875, 6.625);
        glVertex2f(15.75,6.625 );
        glVertex2f(15.310,6);

        glEnd();


        glColor3f(0.4,0.7,0.0); //2 green
        glBegin(GL_POLYGON);
        glVertex2f(14.875, 6.375);
        glVertex2f(15.75,6.375 );
        glVertex2f(15.310,5.75);

        glEnd();


        glColor3f(0.4,0.8,0.0); //3 green
        glBegin(GL_POLYGON);

        glVertex2f(14.875, 6.125);
        glVertex2f(15.75,6.125 );
        glVertex2f(15.310,5.55);

        glEnd();


        glColor3f(0.4,0.9,0.0); //4 green
        glBegin(GL_POLYGON);

        glVertex2f(14.875, 5.875);
        glVertex2f(15.75,5.875 );
        glVertex2f(15.310,5.25);

        glEnd();






//tree Left
        glColor3f(0.7,0.3,0); //coffee
        glBegin(GL_POLYGON);


        glVertex2f(7.5, 7);
        glVertex2f(7.625,7 );
        glVertex2f(7.625,6);
        glVertex2f(7.5,6);


        glEnd();


        glColor3f(0.4,0.6,0.0); //1 green
        glBegin(GL_POLYGON);

        glVertex2f(7.125, 6.625);
        glVertex2f(8,6.625 );
        glVertex2f(7.56,6);

        glEnd();


        glColor3f(0.4,0.7,0.0); //2 green
        glBegin(GL_POLYGON);
        glVertex2f(7.125, 6.375);
        glVertex2f(8,6.375 );
        glVertex2f(7.56,5.75);

        glEnd();


        glColor3f(0.4,0.8,0.0); //3 green
        glBegin(GL_POLYGON);

        glVertex2f(7.125, 6.125);
        glVertex2f(8,6.125 );
        glVertex2f(7.56,5.55);

        glEnd();


        glColor3f(0.4,0.9,0.0); //4 green
        glBegin(GL_POLYGON);

        glVertex2f(7.125, 5.875);
        glVertex2f(8,5.875 );
        glVertex2f(7.56,5.25);

        glEnd();



//tree 1
        glColor3f(0.7,0.3,0); //coffee
        glBegin(GL_POLYGON);

        glVertex2f(3.0, 7);
        glVertex2f(3.125,7 );
        glVertex2f(3.125,6);
        glVertex2f(3.0,6);

        glEnd();


        glColor3f(0.4,0.7,0.0); //2 green
        glBegin(GL_POLYGON);
        glVertex2f(2.625, 6.625);
        glVertex2f(3.5,6.625 );
        glVertex2f(3.,5);

        glEnd();



//tree 1
        glColor3f(0.7,0.3,0); //coffee
        glBegin(GL_POLYGON);

        glVertex2f(16.25, 7);
        glVertex2f(16.375,7 );
        glVertex2f(16.375,6);
        glVertex2f(16.25,6);

        glEnd();


        glColor3f(0.4,0.7,0.0); //2 green
        glBegin(GL_POLYGON);
        glVertex2f(15.875, 6.625);
        glVertex2f(16.75,6.625 );
        glVertex2f(16.310,5);

        glEnd();



//tree 1
        glColor3f(0.7,0.3,0); //coffee
        glBegin(GL_POLYGON);

        glVertex2f(17.25, 7);
        glVertex2f(17.375,7 );
        glVertex2f(17.375,6);
        glVertex2f(17.25,6);

        glEnd();


        glColor3f(0.4,0.7,0.0); //2 green
        glBegin(GL_POLYGON);
        glVertex2f(16.875, 6.625);
        glVertex2f(17.75,6.625 );
        glVertex2f(17.310,5);

        glEnd();



//Ground

        glColor3f(0.9,0.9,0.9); //1 grey
        glBegin(GL_POLYGON);

        glVertex2f(2,7);
        glVertex2f(18,7);
        glVertex2f(18,8);
        glVertex2f(2,9);

        glEnd();


        glColor3f(1,1,1); //white
        glBegin(GL_POLYGON);

        glVertex2f(4,8.75);
        glVertex2f(18,10.75);
        glVertex2f(18,8);

        glEnd();

        glColor3f(0.7,1.0,0.8); //Lake
        glBegin(GL_POLYGON);

        glVertex2f(2,11);
        glVertex2f(2,9);
        glVertex2f(4,8.75);
        glVertex2f(18,10.75);
        glVertex2f(18,11);

        glEnd();




        glColor3f(0.6,0.3,0.0); //swing stand
        glBegin(GL_POLYGON);

        glVertex2f(3.75,8);
        glVertex2f(4,8);
        glVertex2f(4,5.875);
        glVertex2f(3.75,5.875);

        glEnd();


        glColor3f(0.6,0.3,0.0); //swing stand
        glBegin(GL_POLYGON);

        glVertex2f(6.25,8);
        glVertex2f(6.5,8);
        glVertex2f(6.5,5.875);
        glVertex2f(6.25,5.875);

        glEnd();

        glColor3f(0.6,0.3,0.0); //swing stand
        glBegin(GL_POLYGON);

        glVertex2f(3.75,6.125);
        glVertex2f(6.5, 6.125);
        glVertex2f(6.5,5.875);
        glVertex2f(3.75,5.875);

        glEnd();



        glColor3f(0.5,0.1,0.0); //swing rope
        glBegin(GL_POLYGON);

        glVertex2f(4.5, 5.875);
        glVertex2f(4.625, 5.875);
        glVertex2f(4.625,7.5);
        glVertex2f(4.5,7.5);

        glEnd();



        glColor3f(0.5,0.1,0.0); //swing rope
        glBegin(GL_POLYGON);

        glVertex2f(5.5, 5.875);
        glVertex2f(5.625, 5.875);
        glVertex2f(5.625,7.5);
        glVertex2f(5.5,7.5);

        glEnd();


        glColor3f(0.8,0.1,0.4); //swing bench
        glBegin(GL_POLYGON);

        glVertex2f(4.5, 7.25);
        glVertex2f(4.5, 7.375);
        glVertex2f(5.625,7.375);
        glVertex2f(5.625,7.25);

        glEnd();


        glColor3f(0.8,0.3,0.5); //swing bench
        glBegin(GL_POLYGON);

        glVertex2f(4.5, 7.5);
        glVertex2f(4.5, 7.375);
        glVertex2f(5.625,7.375);
        glVertex2f(5.625,7.5);


        glEnd();

//tule
        glColor3f(0.8,0.3,0.5); //tule bench
        glBegin(GL_POLYGON);

        glVertex2f(7.5, 7.6);
        glVertex2f(7.5, 7.375);
        glVertex2f(8.625,7.375);
        glVertex2f(8.625,7.6);


        glEnd();

//tule
        glColor3f(0.8,0.3,0.5); //tule pa
        glBegin(GL_POLYGON);

        glVertex2f(7.6, 7.9);
        glVertex2f(7.7, 7.9);
        glVertex2f(7.7,7.375);
        glVertex2f(7.6,7.375);


        glEnd();

//tule
        glColor3f(0.8,0.3,0.5); //tule pa
        glBegin(GL_POLYGON);

        glVertex2f(8.4, 7.9);
        glVertex2f(8.5, 7.9);
        glVertex2f(8.5,7.375);
        glVertex2f(8.4,7.375);

        glEnd();

//tule2
        glColor3f(0.8,0.3,0.5); //tule bench
        glBegin(GL_POLYGON);

        glVertex2f(10.9, 7.6);
        glVertex2f(10.9, 7.375);
        glVertex2f(12.025,7.375);
        glVertex2f(12.025,7.6);
        glEnd();

//tule
        glColor3f(0.8,0.3,0.5); //tule pa
        glBegin(GL_POLYGON);

        glVertex2f(11.0, 7.9);
        glVertex2f(11.1, 7.9);
        glVertex2f(11.1,7.375);
        glVertex2f(11.0,7.375);

        glEnd();

//tule
        glColor3f(0.8,0.3,0.5); //tule pa
        glBegin(GL_POLYGON);

        glVertex2f(11.8, 7.9);
        glVertex2f(11.9, 7.9);
        glVertex2f(11.9,7.375);
        glVertex2f(11.8,7.375);

        glEnd();
glColor3f(1,1,1); //snowman body
        glBegin(GL_POLYGON);
        glVertex2f(9.25, 8.25);
        glVertex2f(9.625, 8.25);
        glVertex2f(10, 8.4085);
         glVertex2f(10.2652, 8.6737);
        glVertex2f(10.25,9);
         glVertex2f(10.125, 9.375);
        glVertex2f(9.8622, 9.5279);
        glVertex2f(9.5, 9.625);
         glVertex2f(9.044, 9.6104);
        glVertex2f(8.5929,9.2664);
        glVertex2f(8.5929, 8.8614);
         glVertex2f(8.7804,8.5366);
        glEnd();


          glColor3f(0.0f,0.0f,0.0f); //outline body
    glBegin(GL_LINE_STRIP);

        glVertex2f(9.25, 8.25);
        glVertex2f(9.625, 8.25);
        glVertex2f(10, 8.4085);
         glVertex2f(10.2652, 8.6737);
        glVertex2f(10.25,9);
         glVertex2f(10.125, 9.375);
        glVertex2f(9.8622, 9.5279);
        glVertex2f(9.5, 9.625);
         glVertex2f(9.044, 9.6104);
        glVertex2f(8.5929,9.2664);
        glVertex2f(8.5929, 8.8614);
         glVertex2f(8.7804,8.5366);
         glVertex2f(9.25, 8.25);


        glEnd();





        glColor3f(1,1,1); //snowman head
        glBegin(GL_POLYGON);
        glVertex2f(9.2415,7.4688);
        glVertex2f(9.4915, 7.4688);
        glVertex2f(9.708,7.5938);
        glVertex2f(9.805, 7.956);
         glVertex2f(9.6875,8.1998);
        glVertex2f(9.375,8.375);
        glVertex2f(9, 8.25);
         glVertex2f(8.875,8);
        glVertex2f(8.875,7.75);
        glVertex2f(9,7.5335);

        glEnd();



        glColor3f(0.0f,0.0f,0.0f); //outline head
    glBegin(GL_LINE_STRIP);
      glVertex2f(9.2415,7.4688);
        glVertex2f(9.4915, 7.4688);
        glVertex2f(9.708,7.5938);
        glVertex2f(9.805, 7.956);
         glVertex2f(9.6875,8.1998);
        glVertex2f(9.375,8.375);
        glVertex2f(9, 8.25);
         glVertex2f(8.875,8);
        glVertex2f(8.875,7.75);
        glVertex2f(9,7.5335);
          glVertex2f(9.2415,7.4688);

        glEnd();


         glColor3f(0.0,0.0,0.0); //snowman hat
        glBegin(GL_POLYGON);
        glVertex2f(8.875,7.5);
        glVertex2f(9.875,7.5);
        glVertex2f(9.75, 7.375);
        glVertex2f(8.75, 7.375);
        glEnd();


          glColor3f(0.0,0.0,0.0); //snowman hat
        glBegin(GL_POLYGON);
        glVertex2f(9, 7);
        glVertex2f(9.125, 7.375);
         glVertex2f(9.5,7.375);
         glVertex2f(9.625, 7);
        glEnd();



         glColor3f(0.9,0.3,0.0); //snowman nose
        glBegin(GL_POLYGON);

        glVertex2f(9.25, 8);
         glVertex2f(9.375, 8.125);
         glVertex2f(8.75, 8.25);
        glEnd();



         glColor3f(0.0,0.0,0.0); //snowman hand
        glBegin(GL_POLYGON);

        glVertex2f(9.625, 8.5);
         glVertex2f(10.625, 8.125);
         glVertex2f(10.625, 8);
        glEnd();


         glColor3f(0.0,0.0,0.0); //snowman hand
        glBegin(GL_POLYGON);

        glVertex2f(9.125, 8.625);
         glVertex2f(8, 8.375);
         glVertex2f(8,8.25);
        glEnd();



        glColor3f(0.0,0.0,0.0); //snowman button
        glBegin(GL_POLYGON);

        glVertex2f(9.375, 8.625);
         glVertex2f(9.5, 8.625);
         glVertex2f(9.5,8.75);
          glVertex2f(9.375,8.75);
        glEnd();


          glColor3f(0.0,0.0,0.0); //snowman button
        glBegin(GL_POLYGON);

        glVertex2f(9.375, 8.875);
         glVertex2f(9.5, 8.875);
         glVertex2f(9.5,9);
          glVertex2f(9.375,9);
        glEnd();


        glColor3f(0.0,0.0,0.0); //snowman eye
        glBegin(GL_POLYGON);

        glVertex2f(9.125, 7.75);
         glVertex2f(9.125, 7.875);
         glVertex2f(9.2457, 7.8426);
        glEnd();

          glColor3f(0.0,0.0,0.0); //snowman eye
        glBegin(GL_POLYGON);

        glVertex2f(9.5, 7.75);
         glVertex2f(9.5, 7.875);
         glVertex2f(9.375, 7.875);
        glEnd();


      glColor3f(1.0,0.0,0.0); //snowman tie
        glBegin(GL_POLYGON);

        glVertex2f(9.125,8.375);
         glVertex2f(9.375, 8.375);
         glVertex2f(9.625,8.25);

        glVertex2f(9.75, 8.25);
         glVertex2f(9.5,8.5);
         glVertex2f(9.25, 8.5);

        glVertex2f(9.125,8.442);
         glVertex2f(8.875,8.875);
         glVertex2f(8.8125,8.6998);
         glVertex2f(9,8.375);
        glEnd();


}


void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    snow();
     daynight();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();

}

void myInit(void)
{
    glClearColor(0.0, 0.0, 1.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    gluOrtho2D(2,18,11,1);
}
int main(int argc, char** argv)
{

    //drop++;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(2000, 1500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Snow Falling Scenario");
    glutDisplayFunc(myDisplay);
    sndPlaySound("snow.wav",SND_ASYNC);
    myInit();
    glutMainLoop();
}
