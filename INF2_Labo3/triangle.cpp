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

void Triangle::rotate(const Point& p, const double angle) {
    A.rotate(p, angle);
    B.rotate(p, angle);
    C.rotate(p, angle);
}

void Triangle::translate(const double X, const double Y) {
    A.translate(X, Y);
    B.translate(X, Y);
    C.translate(X, Y);
}

double Triangle::perimeter() {
    Segment s1(A, B);
    Segment s2(B, C);
    Segment s3(A, C);
    return s1.length() + s2.length() + s3.length();
}

bool Triangle::intersect(const Triangle& t2, vector<Point>& intersectionPoints) const {
    bool isIntersecting = false;
    Segment t1_s1(A, B);
    Segment t1_s2(B, C);
    Segment t1_s3(A, C);
    Segment t2_s1(t2.A, t2.B);
    Segment t2_s2(t2.B, t2.C);
    Segment t2_s3(t2.A, t2.C);

    isIntersecting += t1_s1.intersect(t2_s1, intersectionPoints);
    isIntersecting += t1_s1.intersect(t2_s2, intersectionPoints);
    isIntersecting += t1_s1.intersect(t2_s3, intersectionPoints);
    isIntersecting += t1_s2.intersect(t2_s1, intersectionPoints);
    isIntersecting += t1_s2.intersect(t2_s2, intersectionPoints);
    isIntersecting += t1_s2.intersect(t2_s3, intersectionPoints);
    isIntersecting += t1_s3.intersect(t2_s1, intersectionPoints);
    isIntersecting += t1_s3.intersect(t2_s2, intersectionPoints);
    isIntersecting += t1_s3.intersect(t2_s3, intersectionPoints);

    return isIntersecting;
}