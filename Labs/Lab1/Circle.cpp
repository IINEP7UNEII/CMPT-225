#include <iostream>
#include <math.h>

using namespace std;

/*
* Circle.cpp
*
* Description: This class models a circle
* Class Invariant: ???
*
* Author: Daniel Tolsky
* Creation date: 17/09/22
*/

class Circle 
{
    private: 
        int x;
        int y;
        double radius; //must be greater that 0.0

    public: 
        // Default constructor
        Circle()
        : x(0), y(0), radius(10)
        { };
        
        // Constructor
        Circle(int x_cord, int y_cord, double radius_val)
        : x(x_cord), y(y_cord), radius(radius_val)
        { };
        
        // Getters which return their relative values
        int getX() const
        {
            return x;
        }

        int getY() const
        {
            return y;
        }

        int getRadius() const
        {
            return radius;
        }

        // Moves the circle by the specified values
        void move(int horiz, int vert)
        {
            x += horiz;
            y += vert;
        }

        // Sets radius to specified value
        void setRadius(double r)
        {
            radius = r;
        }
        
        // Description: Compute and return the area of "this" circle.
        double computeArea() const
        {
            return (M_PI * (radius * radius));
        }
        
        // Description: Prints the circles's height and width.
        void displayCircle() const
        {
            cout << "x = " << x;
            cout << ", y = " << y;
            cout << ", radius = " << radius << endl;
        }

        // Returns true if c intersects the calling circle
        bool intersect(Circle c)
        {
            int xDif = abs(x - c.x);
            int yDif = abs(y - c.y);

            double distance = sqrt(xDif * xDif + yDif * yDif);

            if (distance < (radius + c.radius))
            {
                return true;
            }
            return false;
        }
};
// End of Circle.cpp