#include <iostream>
#include <vector>

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
    virtual std::string getName() const = 0;
    virtual void setName(const std::string& newName) = 0;

    virtual ~Shape() {}
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
    std::string name;

public:
    /**
     * @brief Construct a new Rectangle object.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     * @param name The name of the Shape
     */
    Rectangle(double width = 0.0, double height = 0.0) : width(width), height(height) {}

    double calculateArea() const override {
      // std::cout << getName() << ": ";
        return width * height;
    }

    std::string getName() const override {
        return name;
    }

    void setName(const std::string& newName) override {
        name = newName;
    }
};

// Derived class Triangle
class Triangle : public Shape {
private:
    double base;
    double height;
    std::string name;

public:
    /**
     * @brief Construct a new Triangle object.
     * @param base The base length of the triangle.
     * @param height The height of the triangle.

     */
    Triangle(double base = 0.0, double height = 0.0) : base(base), height(height) {}

    double calculateArea() const override {
       // std::cout << getName() << ": ";
        return (base * height) / 2;
    }

    std::string getName() const override {
        return name;
    }

    void setName(const std::string &newName) override {
        name = newName;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;
    std::string name;

public:
    /**
     * @brief Construct a new Square object.
     * @param side The length of the square's side.
     */
    Square(double side = 0.0) : side(side) {}

    double calculateArea() const override {
        // std::cout << getName() << ": ";
        return side * side;
    }

    std::string getName() const override {
        return name;
    }

    void setName(const std::string& newName) override {
        name = newName;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
    std::string name;

public:
    /**
     * @brief Construct a new Circle object.
     * @param radius The radius of the circle.
     */
    Circle(double radius = 0.0) : radius(radius) {}

    double calculateArea() const override {
       // std::cout << getName() << ": ";
        return 3.14159 * radius * radius;
    }

    std::string getName() const override {
        return name;
    }

    void setName(const std::string& newName) override {
        name = newName;
    }
};


// Function to display the area of a shape
// passing the shape parameter by reference in displayArea() is essential for achieving polymorphic behavior and efficiently utilizing the derived class functionality.
// Uses polymorphism to call the appropriate calculateArea() function based on the actual type of the object

void displayArea(const Shape& shape) {
    std::cout << "\n_______________________________________________\n\n";
    std::cout << "\tName: " << shape.getName() << ", \n";
    std::cout << "\tArea: " << shape.calculateArea() << "\n";
    std::cout << "_______________________________________________\n\n";

}
int main() {
    // Create objects of different shapes
    Rectangle rectangle1(4, 6);
    rectangle1.setName("Rectangle");

    Triangle triangle1(3, 5);
    triangle1.setName("Triangle");

    Square square1(5);
    square1.setName("Square");

    Circle circle1(3);
    circle1.setName("Circle");

    // Calculate and display the areas of the shapes
    displayArea(rectangle1);
    displayArea(triangle1);
    displayArea(square1);
    displayArea(circle1);

    /////////// Now example using dynamic allocation, Dynamic Binding using pointers.
    std::cout << "\n\n=================================================\n\n";
    std::vector<Shape*> shapes;

// Create a Rectangle object and set its name
    Rectangle* rectangle2 = new Rectangle(4, 6);
    rectangle2->setName("Rectangle");

// Add the Rectangle object to the vector
    shapes.push_back(rectangle2);

// Create a Triangle object and set its name
    Triangle* triangle2 = new Triangle(3, 5);
    triangle2->setName("Triangle");

// Add the Triangle object to the vector
    shapes.push_back(triangle2);

// Create a Square object and set its name
    Square* square2 = new Square(5);
    square2->setName("Square");

// Add the Square object to the vector
    shapes.push_back(square2);

// Create a Circle object and set its name
    Circle* circle2 = new Circle(3);
    circle2->setName("Circle");

// Add the Circle object to the vector
    shapes.push_back(circle2);

// Display the area of each shape
    for (const auto shape : shapes) {
        displayArea(*shape);
    }

// Clean up the dynamically allocated objects
    for (const auto shape : shapes) {
        delete shape;
    }


    return 0;
}
