/**
 * @brief Lab3: Geometry (part 3)
 *
 * In this lab we do some basic geometry stuff.
 *
 * @author Romain Maffina
 * @date 26.02.2016
 * @file main.cpp
 */


#include "point.h"
#include "segment.h"
#include "triangle.h"
#include "geometrydrawing.h"
#include "bmp.h"
#include <iostream>

using namespace std;

int main(void) {

    // create a new square drawing surface with default PPCM
    const size_t surface_side = 10;
    GeometryDrawing drawing(surface_side, surface_side);

    cout << "Lab3 - Geometry (part 3)" << endl << endl;

    /* main part code */

    vector<Point> intersectionPoints; // reusable
    bool isIntersecting = false; // reusable

    // declare some points for part1
    Point p1(5,5);
    Point p2;
    Point p3{4.3,3};
    Point p4 = {7,2};
    Point p5(p3);

    // declare some geometry elements for part2
    Segment s1(Point{6,5},Point{4,2});
    Segment s2({2,3},{4,5});
    Segment s3(1,6,4,7);

    // declare some geometry elements for part3
    Point p6(0,0);
    Point p7(4,3);
    Point p8(3,5);

    Segment s4(p6,p7);

    Triangle t1(s4,p8);
    Triangle t2(Point{2,6},Point{6,8},Point{8,4});
    Triangle t3({1,9},{2,7},{1,6});
	
    // 
    // part 1 start
    //
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
    //
    // part 1 end 
    //

    // 
    // part 2 start
    //
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
    //
    // part 2 end 
    //

    // 
    // part 3 start
    //
    cout << "p2=(" << p2.getX() << "," << p2.getY() << ")" << endl;

    cout << "translate p2" << endl;
    p2.translate(3,2);  // translate using offset x/y
    cout << "p2=(" << p2.getX() << "," << p2.getY() << ")" << endl;

    p3.setX(2);
    p3.setY(4);

    // translate using offset x/y
    t1.translate(3,3);
    cout << "t1 perimeter=" << t1.perimeter() << endl;

    // rotate given a rotation point and an offset angle in degrees
    t2.rotate({5,5},-57);

    // test intersection between t1/t2 returning the resulting point(s)
    isIntersecting = t1.intersect(t2, intersectionPoints);

    cout << "t1 intersects t2? " << (isIntersecting ? "yes" : "no") << endl;

    for (Point& p : intersectionPoints) {
        drawing.draw(p);
    }

    // test intersection between t3/t1
    isIntersecting = t3.intersect(t1, intersectionPoints);

    cout << "t3 intersects t1? " << (isIntersecting ? "yes" : "no") << endl;

    for (Point& p : intersectionPoints) {
        drawing.draw(p);
    }

    // draw triangles
    //drawing.draw(t1);
    //drawing.draw(t2);
    //drawing.draw(t3);
    //
    // part 3 end 
    //

    /* output */
    drawing.saveToBmp("geometry.bmp");
	
	return EXIT_SUCCESS;
}