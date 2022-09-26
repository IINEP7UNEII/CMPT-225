/*
* 
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
        Circle(); 
        
        // Constructor
        Circle(int x_cord, int y_cord, double radius_val);
        
        // Getters which return their relative values
        int getX() const;
        int getY() const;
        int getRadius() const;

        // Setters which set their relative values
        void move(int horiz, int vert);
        void setRadius(int w);
        
        // Description: Compute and return the area of "this" circle.
        double computeArea() const;   
        
        // Description: Prints the circles's height and width.
        void displayCircle() const;

        // Returns true if c intersects the calling circle
        bool intersect(Circle c);
};
// End of Circle.h