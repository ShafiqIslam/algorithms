#include <iostream>
#include <math.h>

#define MIN_X 0
#define MAX_X 5
#define INTERVAL 0.5

using namespace std;

double expr_rslt (double x)
{
    double y = 1 + x + sin(x);
    return y;
}

double RectangaleRule ()
{
    double x,y;

    double total_area = 0;

    for(x=MIN_X; x<=MAX_X; x=x+INTERVAL) {
        // the basic
        // total_area = total_area + expr_rslt(x) * INTERVAL;

        // extra tweak
        total_area = total_area + expr_rslt(x);
    }

    total_area = total_area * INTERVAL;
    return total_area;
}

double TrapezoidRule ()
{
    double x,y;

    double total_area = 0;

    for(x=MIN_X+INTERVAL; x<MAX_X; x=x+INTERVAL) {
        // the basic
        // loop from MIN_X to MAX_X
        // total_area = total_area + ( ( expr_rslt(x) + expr_rslt(x+INTERVAL) ) / 2 ) * INTERVAL;

        // extra tweak
        total_area = total_area + expr_rslt(x);
    }

    total_area = (total_area * 2) + expr_rslt(MIN_X) + expr_rslt(MIN_X);
    total_area = total_area  * INTERVAL / 2;
    return total_area;
}

int main()
{
    cout<<"Integration with Rectangle Rule: ";
    cout<<RectangaleRule();
    cout<<endl;
    cout<<"Integration with Trapezoid Rule: ";
    cout<<TrapezoidRule();
    cout<<endl;

    cout<<endl;
    return 0;
}


/*

                    Theories
                =================

Integration can be calculated numerically by dividing the curve in smaller area and adding up the areas.

Two methods is use:
Rectangular Rule:
-----------------
Divide in rectangles(same width, multiple width range can be used, which gives better result, but coding that is bit tough).
Starting from min x up to max x, for every x, calculate y(height), and multiply with dx (width).
Add the areas.
Now, as multiplication of dx is happening every time, it can be take out.

Trapezoid Rule:
---------------
Divide in trapezoids. Which gives more coverage of the curve.
Now, area of trapezoid = (h1+h2)/2 * w
Starting from min x up to max x, calculate y1 and y2, and calculate area.
Add the areas.
Now, as before, multiplication of dx/2 is happening every time, so it can be take out.
And also, the process is going to add y(x) for the middle points twice.
So, add up y(x) with only the middle points, then double it, and then add up first and last point.

*/
