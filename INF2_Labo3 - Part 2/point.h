/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   point.h
 * Author: James
 *
 * Created on 8. mars 2017, 13:40
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point{
public:
   Point(double X = 0.0, double Y = 0.0);
   double getX() const;
   double getY() const;
   void setX(const double);
   void setY(const double);
   void translate(const double, const double);
   void rotate (const Point&, const double);
   friend ostream& operator << (ostream& stream, const Point&);
public:
   double X;
   double Y;
};

#endif /* POINT_H */ 

