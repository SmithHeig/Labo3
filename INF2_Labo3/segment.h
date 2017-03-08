/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   segment.h
 * Author: James
 *
 * Created on 8. mars 2017, 14:22
 */

#ifndef SEGMENT_H
#define SEGMENT_H

#include "point.h"
#include <iostream>

using namespace std;

class Segment {
   friend ostream& operator << (ostream& stream, const Segment&);
public:
   Segment(Point&, Point&);
   double length() const;
   Point getA() const;
   Point getB() const;
   void translate(double, double);
   void rotate(Point&, double);
private:
   void setLenght();
   Point A;
   Point B;
   double length_segment;
};

#endif /* SEGMENT_H */

