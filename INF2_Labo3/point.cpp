/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "point.h"

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

void Point::setX(double X){
   this->X = X;
}

void Point::setY(double Y){
   this->Y = Y;
}

void Point::translate(double translation_X, double translation_Y){
   this->X += translation_X;
   this->Y += translation_Y;
}