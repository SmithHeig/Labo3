/**
 * @brief   Contain all the functions of the class Point
 *
 * @author  James Smith
 * @date    14.03.2017
 * @file    point.h
 * @remark  Compilateur : MinGW-g++ 5.3.0
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

/**
 * @class Point
 * @brief This class represent a point in a plan and contain different operation on it.
 */
class Point{
public:
   /**
    * @brief Constructor of the class Point
    * @param X is the horizontal position of the point
    * @param Y is the vertical position of the point
    */
   Point(double X = 0.0, double Y = 0.0);
   
   /**
    * @brief Get the value of the horizontal position (x)
    * @return X the value of the horizontal position
    */
   double getX() const;
   
   /**
    * @brief Get the value of the vertical position (y)
    * @return Y the value of the vertical position
    */
   double getY() const;
   
   /**
    * @brief change or set the value of X (position horizontal of the point)
    * @param X the new value of X
    */
   void setX(const double);
   
   /**
    * @brief change or set the value of Y (position vertical of the point)
    * @param Y the new value of Y
    */
   void setY(const double);
   
   /**
    * @brief Translate the point on the plan
    * @param X the horizontal distance of the translation
    * @param Y the vertical distance of the translation
    */
   void translate(const double, const double);
   
   /**
    * @brief rotate the point relative to another point
    * @param A point where is calculated the angle
    * @param angle the angle of the rotation
    * @remark the rotation is from the right to the left
    */
   void rotate (const Point&, const double);
   
   /**
    * @brief overload of the redirection operator of the ostream class to show a custom
    *       display of the point. (X,Y)
    * @param stream is the curent stream
    * @param Point si the point to show.
    */
   friend ostream& operator << (ostream& stream, const Point&);
private:
   double X;
   double Y;
};

#endif /* POINT_H */ 

