#include <iostream>
#include <GL/glut.h>
#include <math.h>

#define LEVEL 3

GLfloat oldx=-0.7, oldy=0.5;

void drawkoch(GLfloat dir, GLfloat len, GLint iter) {
	GLdouble dirRad = 0.0174533 * dir;
	GLfloat newX = oldx + len * cos(dirRad);
	GLfloat newY = oldy + len * sin(dirRad);
	if (iter==0) {
		glVertex2f(oldx, oldy);
		glVertex2f(newX, newY);
		oldx = newX;
		oldy = newY;
	} else {
		iter--;
		//draw the four parts of the side _/\_
		drawkoch(dir, len, iter);
		dir += 60.0;
		drawkoch(dir, len, iter);
		dir -= 120.0;
		drawkoch(dir, len, iter);
		dir += 60.0;
		drawkoch(dir, len, iter);
	}
}

void mydisplay(){
	 glClear( GL_COLOR_BUFFER_BIT );
	 glBegin(GL_LINES);
	 glColor3f(1.0, 0.0, 0.0); // make it red

	 //call drawkoch 3 times, one for each side of the triangle, changing direction each time
	 double len = 1.0;
	 int i = LEVEL;
	 while(i) {
        len = len / 3;
        i--;
	 }

	 drawkoch(0.0, len, LEVEL);
	 drawkoch(-120.0, len, LEVEL);
	 drawkoch(120.0, len, LEVEL);

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
	glutCreateWindow("Koch Snowflake");
	setup();
	glutDisplayFunc(mydisplay);
	glutMainLoop();
}



/*


                Theories
            ================

Problem: Koch Curve (Snowflake)

Koch Curve:
-----------
Begin with a straight line. Divide it into three equal segments and replace the middle segment by the two
sides of an equilateral triangle of the same length as the segment being removed.


            ______________________________          (LEVEL 0)

                          /\
                         /  \
                        /    \
                       /      \
            __________/        \__________          (LEVEL 1)

Repeat this process for each section of the line.

Koch Snowflake is a triangle of Koch curve.

The Koch snowflake can be constructed by starting with an equilateral triangle,
then recursively altering each line segment as follows:
1. divide the line segment into three segments of equal length.
2. draw an equilateral triangle that has the middle segment from step 1 as its base and points outward.
3. remove the line segment that is the base of the triangle from step 2.
After one iteration of this process, the resulting shape is the outline of a hexagram.


*/


/*
    This is a Glut Project.
    Follow: http://wiki.codeblocks.org/index.php/Using_FreeGlut_with_Code::Blocks
    for installing glut on Code::Blocks
*/

