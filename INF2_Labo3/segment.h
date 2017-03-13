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
#include <vector>

using namespace std;

class Segment {
public:
   Segment(const Point&, const Point&);
   Segment(const double, const double, const double, const double);
   double length() const;
   Point getA() const;
   Point getB() const;
   void translate(const double, const double);
   void rotate(const Point&, const double);
   bool intersect(const Segment& S, vector<Point>& intersectionPoints) const;
   friend ostream& operator << (ostream& stream, const Segment&);
private:
   void setLenght();
   double getPente() const; //mettre en anglais
   double getOrdonneOriginie() const; // mettre en anglais
   Point A;
   Point B;
   double length_segment;
};

#endif /* SEGMENT_H */

