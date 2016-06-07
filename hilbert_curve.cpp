#include <iostream>
#include <GL/glut.h>
#include <math.h>

#define LEVEL 3

GLfloat oldX=-0.5, oldY=0;

void hilbert() {
    GLfloat newX = oldX + 0.5;
	GLfloat newY = oldY;
    glVertex2f(oldX, oldY);
    glVertex2f(newX, newY);
}

void mydisplay(){
	 glClear( GL_COLOR_BUFFER_BIT );
	 glBegin(GL_LINES);
	 glColor3f(1.0, 0.0, 0.0); // make it red

     hilbert();

	 glEnd();
	 glFlush();
}

void setup()
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hilbert Curve");
	setup();
	glutDisplayFunc(mydisplay);
	glutMainLoop();
}



/*


                Theories
            ================

Problem: Hilbert Curve

Hilbert Curve:
--------------
Hilbert curve (also known as a Hilbert space-filling curve) is a continuous fractal space-filling curve.

          ______________
                        |
                        |
                        |
                        |
                        |
          ______________|         (LEVEL 0)

                ________
          |    |        |
          |____|    ____|
                   |
           ____    |____
          |    |        |
          |    |________|         (LEVEL 1)

Start with the basic staple-like shape as depicted on the first diagram. All the rest of the curves are
created sequentially one from another using the same algorithm. Shrink the previous curve to half its size.
Simultaneously, decrease the grid size by the factor of two. Place four copies of the curve on the grid.
The lower two must be placed directly as they are. The upper two must be rotated a quarter turn - one left,
another right. Lastly, connect the four pieces with short straight segments to obtain the next step curve.
Sometimes the connecting segments are horizontal, sometimes they are vertical but, otherwise, the construction
is straightforward.

The curves become longer and longer but, since it's always possible to move from one step to another,
the process will never end. For this very reason none of the curves thus obtained ever fills the square
your or my impression to the contrary notwithstanding. (Let me observe in passing that, by construction,
none of the curves self-intersects.) What does fill the square is the limiting curve whose existence
(or, for that matter, the definition) is not at all obvious.


*/


/*
    This is a Glut Project.
    Follow: http://wiki.codeblocks.org/index.php/Using_FreeGlut_with_Code::Blocks
    for installing glut on Code::Blocks
*/

