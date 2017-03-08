/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "segment.h"
#include <cmath>

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


double Segment::length() const{
   return length_segment;
}

Point Segment::getA() const{
   return A;
}

Point Segment::getB() const{
   return B;
}

void Segment::translate(const double X, const double Y) {
   A.X += X;
   B.X += X;
   A.Y += Y;
   B.Y += Y;
   setLenght();
}

void Segment::rotate(const Point& C, const double angle){
   A.rotate(C,angle);
   B.rotate(C,angle);
}

void Segment::setLenght(){
   length_segment = sqrt((A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y));
}

Point Segment::intersect(const Segment& S) {
   //y = ax + b formule d'une droite
}

ostream& operator << (ostream& stream, const Segment& S){
   stream << "a:" << S.A << " b:" << S.B;
   return stream;
}

double getPente(){ //TODO
   return ;
}