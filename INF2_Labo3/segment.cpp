/**
 * @brief Contain all the functions of the class Segment
 *
 * @author James Smith
 * @headerfile segment.h "segment.h"
 * @date    14.03.2017
 * @file    segment.cpp
 * @remark  The intersect function as been inspired by the web site 
 *          https://openclassrooms.com/forum/sujet/calcul-du-point-d-intersection-de-deux-segments-21661
 * 
 *          Compilateur : MinGW-g++ 5.3.0
 */

#include "segment.h"
#include <cmath>
#include <vector>
#include <limits>

Segment::Segment(const Point& A, const Point& B) {
    this->A = A;
    this->B = B;
    setLenght();
}

Segment::Segment(const double X1, const double Y1, const double X2, const double Y2) {
    this->A = {X1, Y1};
    this->B = {X2, Y2};
    setLenght();
}

double Segment::length() const {
    return length_segment;
}

Point Segment::getA() const {
    return A;
}

Point Segment::getB() const {
    return B;
}

void Segment::translate(const double X, const double Y) {
    A.translate(X,Y);
    B.translate(X,Y);
    setLenght();
}

void Segment::rotate(const Point& C, const double angle) {
    A.rotate(C, angle);
    B.rotate(C, angle);
}

void Segment::setLenght() {
    length_segment = sqrt((A.getX() - B.getX()) * (A.getX() - B.getX()) + (A.getY() - B.getY()) * (A.getY() - B.getY()));
}

bool Segment::intersect(const Segment& S, vector<Point>& intersectionPoints) const {
    bool controle = false;
    double yCommun;
    double xCommun;
    // Test if the two segment are not parallels
    if (getPente() != S.getPente()) {
        // Test if the "main" segment is vertical
        if (A.getX() == B.getX()) {
            yCommun = S.getPente() * A.getX() + S.getOrdonneOriginie();
            xCommun = A.getX();
            controle = true;
            
        // Test if the other segment is vertical
        } else if (S.A.getX() == S.B.getX()) {
            yCommun = getPente() * S.A.getX() + getOrdonneOriginie();
            xCommun = S.A.getX();
            controle = true;
        } else {
            xCommun = abs((getOrdonneOriginie() - S.getOrdonneOriginie()) / (getPente() - S.getPente()));
            yCommun = getPente() * xCommun + getOrdonneOriginie();
            controle = true;
        }
        // Controle if the intersection point is in the interval
        if (controle) {
            Point pointIntersection(xCommun, yCommun);
            Segment s1(A, pointIntersection);
            Segment s2(B, pointIntersection);
            if (length() > s1.length() && length() > s2.length()) {
                intersectionPoints.push_back(pointIntersection);
                return true;
            }
        }
    }
    return false;
}

ostream& operator<<(ostream& stream, const Segment& S) {
    stream << "a:" << S.A << " b:" << S.B;
    return stream;
}

double Segment::getPente() const {
    if (B.getX() > A.getX()) {
        return (B.getY() - A.getY()) / (B.getX() - A.getX());
    } else {
        return (A.getY() - B.getY()) / (A.getX() - B.getX());
    }
    return 0;
}

double Segment::getOrdonneOriginie() const {
    return A.getY() - (getPente() * A.getX());
}