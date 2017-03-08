/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "segment.h"
#include <cmath>

Segment::Segment(Point& A, Point& B) {
   this->A = A;
   this->B = B;
   setLenght();
}

double Segment::length() {
   return length_segment;
}

Point Segment::getA() {
   return A;
}

Point Segment::getB() {
   return B;
}

void Segment::translate(double X, double Y) {
   
}

void Segment::rotate(Point& C, double angle){
   
}

void Segment::setLenght(){
   length_segment = sqrt((A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y));
}