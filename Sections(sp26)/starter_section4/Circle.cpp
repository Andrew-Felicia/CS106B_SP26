#include "Circle.h"
using namespace std;
#include "gmath.h"
#include "strlib.h"

/**
 * TODO: write a method comment
 */
Circle::Circle(double radius) {
    r = radius;
}


/**
 * TODO: write a method comment
 */
double Circle::area() const {
    return PI * r * r;
}

/**
 * TODO: write a method comment
 */
double Circle::circumference() const{
    return 2 * PI * r;
}

/**
 * TODO: write a method comment
 */
double Circle::getRadius() const{
    return r;
}

/**
 * TODO: write a method comment
 */
string Circle::toString() const{
    return string("Circle{radius=") + realToString(r) + string("}");
}

/* Provided Tests Below This Line */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Simple Example") {
    Circle c(2.5);
    EXPECT_EQUAL(c.getRadius(), 2.5);
    EXPECT_EQUAL(c.circumference(), 2 * PI * 2.5);
    EXPECT_EQUAL(c.area(), PI * 2.5 * 2.5);
    EXPECT_EQUAL(c.toString(), "Circle{radius=2.5}");
}
