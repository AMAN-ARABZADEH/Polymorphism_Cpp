#include <iostream>

/*
 * Author: Aman Arabzadeh
 * Polymorphism is a Greek word that means "many-shaped" 
 *
 * Description: This code demonstrates polymorphism in C++. The base class Shape contains a pure virtual function calculateArea()
 * which is not implemented in the base class, making Shape an abstract class. The derived classes Rectangle, Triangle, Square, and Circle
 * inherit from the Shape base class and provide their own implementation of the calculateArea() function.
 *
 * The displayArea() function accepts a const reference to a Shape object and uses polymorphism to call the appropriate calculateArea()
 * function based on the actual type of the object. This showcases the power of polymorphism, where a single function can work with
 * different derived classes and produce the correct behavior based on the runtime type of the object.
 *
 * By creating objects of different shapes and passing them to displayArea(), we can calculate and display the areas of each shape
 * using the overridden calculateArea() function.
 *
 * Polymorphism allows for code flexibility, extensibility, and modularity, as new derived classes can be added without modifying existing
 * code that operates on the base class interface. It promotes code reusability and makes the code more maintainable and scalable.
 */
// Base class Shape

class Shape {
public:
    /**
     * @brief Pure virtual function to calculate the area of the shape.
     * @return The calculated area of the shape.
     */
    virtual double calculateArea() const = 0;
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    /**
     * @brief Construct a new Rectangle object.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     */
    Rectangle(double width = 0.0, double height = 0.0) : width(width), height(height) {}

    double calculateArea() const override {
        return width * height;
    }
};

// Derived class Triangle
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    /**
     * @brief Construct a new Triangle object.
     * @param base The base length of the triangle.
     * @param height The height of the triangle.
     */
    Triangle(double base = 0.0, double height = 0.0) : base(base), height(height) {}

    double calculateArea() const override {
        return (base * height) / 2;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;

public:
    /**
     * @brief Construct a new Square object.
     * @param side The length of the square's side.
     */
    Square(double side = 0.0) : side(side) {}

    double calculateArea() const override {
        return side * side;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    /**
     * @brief Construct a new Circle object.
     * @param radius The radius of the circle.
     */
    Circle(double radius = 0.0) : radius(radius) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

// Function to display the area of a shape
// passing the shape parameter by reference in displayArea() is essential for achieving polymorphic behavior and efficiently utilizing the derived class functionality.
void displayArea(const Shape& shape) {
    // Uses polymorphism to call the appropriate calculateArea() function based on the actual type of the object
    std::cout << "Area: " << shape.calculateArea() << std::endl;
}


int main() {
    // Create objects of different shapes
    Rectangle rectangle(4, 6);
    Triangle triangle(3, 5);
    Square square(5);
    Circle circle(3);

    // Calculate and display the areas of the shapes
    std::cout << "Rectangle:" << std::endl;
    displayArea(rectangle);

    std::cout << "Triangle:" << std::endl;
    displayArea(triangle);

    std::cout << "Square:" << std::endl;
    displayArea(square);

    std::cout << "Circle:" << std::endl;
    displayArea(circle);

    return 0;
}
