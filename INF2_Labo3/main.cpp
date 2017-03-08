/**
 * @brief Lab3: Geometry (part1)
 *
 * In this lab we do some basic geometry stuff.
 *
 * @author Romain Maffina
 * @date 26.02.2016
 * @file main.cpp
 */

#include "point.h"
#include "geometrydrawing.h"
#include "bmp.h"
#include <iostream>

using namespace std;

int main(void) {

    // create a new square drawing surface with default PPCM
    const size_t surface_side = 10;
    GeometryDrawing drawing(surface_side, surface_side);

    cout << "Lab3 - Geometry (part 1)" << endl;

    /* main code */

    // declare some points
    Point p1(5,5);
    Point p2;
    Point p3{4.3,3};
    Point p4 = {7,2};
    Point p5(p3);

    cout << "p2=(" << p2.getX() << "," << p2.getY() << ")" << endl;

    cout << "translate p2" << endl;
    p2.translate(3,2);  // translate using offset x/y
    cout << "p2=(" << p2.getX() << "," << p2.getY() << ")" << endl;

    p3.setX(2);
    p3.setY(4);

    // draw the points
    drawing.draw(p1);
    drawing.draw(p2);
    drawing.draw(p3);
    drawing.draw(p4);
    drawing.draw(p5);

    /* output */
    drawing.saveToBmp("geometry.bmp");
	
	return EXIT_SUCCESS;
}