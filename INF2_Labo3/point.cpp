/**
 * @brief Contain all the functions of the class Point
 *
 * @author James Smith
 * @headerfile point.h "point.h"
 * @date    14.03.2017
 * @file    point.cpp
 * @remark  the rotate function as been inspired from the web site:
 *          https://www.maths-forum.com/superieur/rotation-point-par-rapport-point-qqonque-t153035.html
 * 
 *          Compilateur : MinGW-g++ 5.3.0
 */


#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include "point.h"
#include <cmath>

Point::Point(double X, double Y) {
    this->X = X;
    this->Y = Y;
}

double Point::getX() const {
    return X;
}

double Point::getY() const {
    return Y;
}

void Point::setX(const double X) {
    this->X = X;
}

void Point::setY(const double Y) {
    this->Y = Y;
}

void Point::translate(const double translation_X, const double translation_Y) {
    this->X += translation_X;
    this->Y += translation_Y;
}

void Point::rotate(const Point& A, const double angle) {
    double angle_in_radian = angle * (M_PI / 180);
    double diff_X = this->X - A.X;
    double diff_Y = this->Y - A.Y;
    this->X = diff_X * cos(angle_in_radian) - diff_Y * sin(angle_in_radian) + A.X;
    this->Y = diff_X * sin(angle_in_radian) + diff_Y * cos(angle_in_radian) + A.Y;
}

ostream& operator<<(ostream& stream, const Point& A) {
    stream << "(" << A.X << "," << A.Y << ")";
    return stream;
}