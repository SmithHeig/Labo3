/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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
    A.X += X;
    B.X += X;
    A.Y += Y;
    B.Y += Y;
    setLenght();
}

void Segment::rotate(const Point& C, const double angle) {
    A.rotate(C, angle);
    B.rotate(C, angle);
}

void Segment::setLenght() {
    length_segment = sqrt((A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y));
}

bool Segment::intersect(const Segment& S, vector<Point>& intersectionPoints) const {
    bool controle = false;
    double yCommun;
    double xCommun;
    if (A.X == B.X) {
        yCommun = S.getPente() * A.X + S.getOrdonneOriginie();
        xCommun = A.X;
        controle = true;
    } else if (S.A.X == S.B.X) {
        yCommun = getPente() * S.A.X + getOrdonneOriginie();
        xCommun = S.A.X;
        controle = true;
    } else if (getPente() - S.getPente() != 0) {
        xCommun = abs((getOrdonneOriginie() - S.getOrdonneOriginie()) / (getPente() - S.getPente()));
        yCommun = getPente() * xCommun + getOrdonneOriginie();
        controle = true;
    }
    if (controle) {
        Point pointIntersection(xCommun, yCommun);
        Segment s1(A, pointIntersection);
        Segment s2(B, pointIntersection);
        if (length() > s1.length() && length() > s2.length()) {
            intersectionPoints.push_back(pointIntersection);
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& stream, const Segment& S) {
    stream << "a:" << S.A << " b:" << S.B;
    return stream;
}

double Segment::getPente() const {
    if (B.X > A.X) {
        return (B.Y - A.Y) / (B.X - A.X);
    } else {
        return (A.Y - B.Y) / (A.X - B.X);
    }
    return 0;
}

double Segment::getOrdonneOriginie() const {
    return A.Y - (getPente() * A.X);
}