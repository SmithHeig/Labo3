/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "point.h"
#include <cmath>

Point::Point(double X, double Y){
   this->X = X;
   this->Y = Y;
}

double Point::getX() const{
   return X;
}

double Point::getY() const{
   return Y;
}

void Point::setX(const double X){
   this->X = X;
}

void Point::setY(const double Y){
   this->Y = Y;
}

void Point::translate(const double translation_X, const double translation_Y){
   this->X += translation_X;
   this->Y += translation_Y;
}

void Point::rotate(const Point& A, const double angle){
   const double M_PI = 3.1415;
   double angle_in_radian = angle * (M_PI/ 180);
   double diff_X = this->X - A.X;
   double diff_Y = this->Y - A.Y;
   this->X = diff_X * cos(angle_in_radian) - diff_Y * sin(angle_in_radian) + A.X;
   this->Y = diff_X * sin(angle_in_radian) + diff_Y * cos(angle_in_radian) + A.Y;
}

ostream& operator << (ostream& stream, const Point& A){
   stream << "(" << A.X << "," << A.Y << ")";
   return stream;
}