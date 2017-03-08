/**
 * @brief Lab3: Geometry (part 2)
 *
 * In this lab we do some basic geometry stuff.
 *
 * @author Romain Maffina
 * @date 26.02.2016
 * @file main.cpp
 */

#include "point.h"
#include "segment.h"
#include "geometrydrawing.h"
#include <iostream>

using namespace std;

int main(void) {

    // create a new square drawing surface with default PPCM
    const size_t surface_side = 10;
    GeometryDrawing drawing(surface_side, surface_side);

    cout << "Lab3 - Geometry (part 2)" << endl;

    /* main part code */

    // declare some geometry elements
    Segment s1(Point{6,5},Point{4,2});
    Segment s2({2,3},{4,5});
    Segment s3(1,6,4,7);

    cout << "s1 length=" << s1.length() << endl;

    // translate using offset x/y
    s1.translate(-0.5,-1);
    cout << "s1.a = " << s1.getA() << endl;

    // rotate given a rotation point and an offset angle in degrees
    s2.rotate(s2.getB(), 87);
    cout << "s2 is " << s2 << endl;

    // draw elements
    drawing.draw(s1);
    drawing.draw(s2);
    drawing.draw(s3);

    /* output */
    drawing.saveToBmp("geometry.bmp");

    return EXIT_SUCCESS;
}