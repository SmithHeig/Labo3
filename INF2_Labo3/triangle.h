/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   triangle.h
 * Author: James
 *
 * Created on 8. mars 2017, 18:22
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include "segment.h"
#include "point.h"

using namespace std;

class Triangle {
public:
   /**
    * @brief Constructor of the Triangle class (with a segment and a point)
    * @param S segment of the triangle(on side of the triangle)
    * @param A point who connect both side of the segment to create the triangle
    */
   Triangle(const Segment& S, const Point& A);
   
   /**
    * @brief Constructor of the Triangle class (with three points)
    * @param A one of the 3 point who form the triangle
    * @param B one of the 3 point who form the triangle
    * @param C one of the 3 point who form the triangle
    */
   Triangle(const Point& A, const Point& B, const Point& C);
   
   /**
    * @brief translate the triangle on the plan
    * @param X the horizontal distance to translate the trinagle
    * @param Y the vertical distance to translate the triangle
    */
   void translate(const double X, const double Y);
   
   /**
    * @return return the perimeter of the triangle
    */
   double perimeter();
   
   /**
    * @brief rotate the triangle relative to a point
    * @param p point where is calculated the angle
    * @param angle of the rotation
    * @remark the rotation is from the right to the left
    */
   void rotate(const Point& p1, const double angle);
   
   /**
    * @brief calcul all the intersections of two triangle.
    * @param t2 is the triangle to calculate if it intersect with the other triangle
    * @param intersectionPoints container of all the intersectionPoints
    * @return a booleen if the two triangle intersect each other or not
    */
   bool intersect(const Triangle& t2, vector<Point>& intersectionPoints) const;
   
   /**
    * @return return the segment between the point A and B of the triangle
    */
   Segment getAB() const {return Segment(A,B);}
   
   /**
    * @return return the segment between the point C and A of the triangle
    */
   Segment getCA() const {return Segment(C,A);}
   
   /**
    * @return return the segment between the point B and C of the triangle
    */
   Segment getBC() const {return Segment(B,C);}
private:
   Point A;
   Point B;
   Point C;
   double t_perimeter;
};

#endif /* TRIANGLE_H */

