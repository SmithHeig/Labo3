/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "triangle.h"

Triangle::Triangle(const Segment& s, const Point& p) {
   A = s.getA();
   B = s.getB();
   C = p;
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) {
   A = p1;
   B = p2;
   C = p3;
}

void Triangle::rotate(const Point& p, const double angle){
   A.rotate(p,angle);
   B.rotate(p,angle);
   C.rotate(p,angle);
}

void Triangle::translate(const double X, const double Y) {
   A.translate(X,Y);
   B.translate(X,Y);
   C.translate(X,Y);
}

double Triangle::perimeter() {
   Segment s1(A,B);
   Segment s2(B,C);
   Segment s3(A,C);
   return s1.length() + s2.length() + s3.length();
}

bool Triangle::intersect(const Triangle& t1, vector<Point>&){
   
}