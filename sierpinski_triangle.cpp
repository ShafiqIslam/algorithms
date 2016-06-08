#include <GL/glut.h>
#include <stdlib.h>

#define LEVEL 4

GLfloat xRot, yRot, zRot, scale;
GLuint object = 0;

struct Point {
	float x;
	float y;
};

void drawSierpinski(Point a, Point b, Point c, int level);

void paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // set the zoom according to the scale variable
    glScalef(scale, scale, scale);
    // set the image rotation up according to xRot, yRot, zRot
    glRotatef( xRot, 1.0, 0.0, 0.0);
    glRotatef( yRot, 0.0, 1.0, 0.0);
    glRotatef( zRot, 0.0, 0.0, 1.0);

    glCallList(object);
    glFlush();
}

// creates a display list full of OpenGL commands that are executed whenever glCallList is called
GLuint makeObject()
{
    GLuint list;
    list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    glColor3f( 1.0, 0.0, 0.0 );

    // points for triangle to draw Sierpinski Gasket
    Point a, b, c;
    a.x=-0.5; a.y=-0.5;
    b.x=0.5; b.y=-0.5;
    c.x=0.0; c.y=0.5;

    drawSierpinski(a, b, c, LEVEL);
    glEndList();
    return list;
}

void initializeGL()
{
    xRot = yRot = zRot = 0.0;
    scale = 1.25;
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glEnable( GL_DEPTH_TEST );
    object = makeObject();
    glShadeModel( GL_SMOOTH );
}

void drawTriangle(Point a, Point b, Point c)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(a.x, a.y);
    glVertex2f(b.x, b.y);
    glVertex2f(c.x, c.y);
    glEnd();
}

void drawSierpinski(Point a, Point b, Point c, int level)
{
   Point m0, m1, m2;
   if (level > 0) {
        m0.x = (a.x+b.x) /2.0;
        m0.y = (a.y+b.y) /2.0;
        m1.x = (a.x+c.x) /2.0;
        m1.y = (a.y+c.y) /2.0;
        m2.x = (b.x+c.x) /2.0;
        m2.y = (c.y+b.y) /2.0;
        drawSierpinski(a, m0, m1, level-1);
        drawSierpinski(b, m2, m0, level-1);
        drawSierpinski(c, m1, m2, level-1);
   } else {
       drawTriangle(a, b, c);
   }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sierpinski Triangle");
    initializeGL();
    glutDisplayFunc(paintGL);
    glutMainLoop();
    return 0;
}


/*


                Theories
            ================

Problem: Sierpinski Triangle

The Sierpinski triangle, also called the Sierpinski gasket or the Sierpinski Sieve,
is a fractal and attractive fixed set with the overall shape of an equilateral triangle,
subdivided recursively into smaller equilateral triangles.


If level is 0 then fill the triangle.
Else Calculate mid points and draw 3 triangles with decremented level.

Complexity: O( 3^n )

*/


/*
    This is a Glut Project.
    Follow: http://wiki.codeblocks.org/index.php/Using_FreeGlut_with_Code::Blocks
    for installing glut on Code::Blocks
*/
