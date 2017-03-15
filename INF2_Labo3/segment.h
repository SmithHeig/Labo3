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
   /**
    * @brief Constructor of the Segment class
    * @param A point of a end of the segment
    * @param B point of the other end of the segment
    */
   Segment(const Point& A, const Point& B);
   
   /**
    * @brief Constructor of the Segment class
    * @param X1 is the horizontal position of the point A
    * @param Y1 is the vertical position of the point A
    * @param X2 is the horizontal position of the point B
    * @param Y2 is the vertical position of the point B
    */
   Segment(const double X1, const double Y1, const double X2, const double Y2);
   
   /**
    * @return the length of the segment
    */
   double length() const;
   
   /**
    * @return the Point A of the segment
    */
   Point getA() const;
   /**
    * @return the Point B of the segment
    */
   Point getB() const;
   
   /**
    * @brief translate the segment on the plan
    * @param X is the horizontal distance to translate the segment
    * @param Y is the vertical distance to translate the segment
    */
   void translate(const double X, const double Y);
   
   /**
    * @brief rotate the segment relative to a point
    * @param A point where is calculated the angle
    * @param angle the angle of the rotation
    * @remark the rotation is from the right to the left
    */
   void rotate(const Point& A, const double angle);
   
   /**
    * @brief calcul the intersection of two segments.
    * @param S Segment to calculate if it intersect with the other segment
    * @param intersectionPoints container of all the intersectionPoints
    * @return a booleen if the two segment intersect each other or not
    */
   bool intersect(const Segment& S, vector<Point>& intersectionPoints) const; 
   
    /**
    * @brief overload of the redirection operator of the ostream class to show a custom
    *       display of the segment. a:(X1,Y1) b:(X2,Y2)
    * @param stream is the curent stream.
    * @param Segment si the segment to show.
    */
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

