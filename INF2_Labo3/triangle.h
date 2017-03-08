/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   triangle.h
 * Author: James
 *
 * Created on 8. mars 2017, 18:22
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include "segment.h"
#include "point.h"

class Triangle {
public:
   Triangle(const Segment&, const Point&);
   Triangle(const Point&, const Point&, const Point&);
   void translate(const double, const double);
   double perimeter();
   void rotate(const Point&, const double);
   double intersect(const Triangle&, const vector<Point>&);
private:
   
};

#endif /* TRIANGLE_H */

