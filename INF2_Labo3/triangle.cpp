/**
 * @brief Contain all the functions of the class Triangle
 *
 * @author James Smith
 * @headerfile triangle.h "triangle.h"
 * @date    14.03.2017
 * @file    triangle.cpp
 * @remark  Compilateur : MinGW-g++ 5.3.0
 */

#include "triangle.h"

Triangle::Triangle(const Segment& s, const Point& p) {
    A = s.getA();
    B = s.getB();
    C = p;
}

Triangle::Triangle(const Point& A, const Point& B, const Point& C) {
    this->A = A;
    this->B = B;
    this->C = C;
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