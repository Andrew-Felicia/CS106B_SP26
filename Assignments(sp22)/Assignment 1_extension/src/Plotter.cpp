#include "Plotter.h"
#include <iostream>
#include "vector.h"
#include "strlib.h"
#include "string.h"


#include <fstream>
#include <cmath>
#include "GUI/SimpleTest.h"

using namespace std;



//draw the pictures using the .plot file.

void runPlotterScript(istream& input) {
    PenStyle style = {1, "black"};
    bool isPenDown = false;
    double penX = 0;
    double penY  = 0;


    for(string line ; getline(input, line);) {
        Vector<string> line_contents = stringSplit(line, " ");
        string first = toLowerCase(line_contents[0]);

        if(first == "penwidth") {
            style.width = stringToReal(line_contents[1]);
        } else if(first == "pencolor") {
            style.color = toLowerCase(line_contents[1]);
        } else if(first == "penup") {
            isPenDown = false;
        } else if(first == "pendown") {
            isPenDown = true;
        } else if(first == "moveabs") {
            double penX_after = stringToReal(line_contents[1]);
            double penY_after = stringToReal(line_contents[2]);

            if(isPenDown) {
                drawLine(penX, penY, penX_after, penY_after, style);
                penX = penX_after;
                penY = penY_after;
            } else {
                penX = penX_after;
                penY = penY_after;
            }
        } else if(first == "moverel") {
            double dx = stringToReal(line_contents[1]);
            double dy = stringToReal(line_contents[2]);

            if(isPenDown) {
                drawLine(penX, penY, penX + dx, penY + dy, style);
                penX += dx;
                penY += dy;
            } else {
                penX += dx;
                penY += dy;
            }
        }
    }
}


//-----------------------------------------------------------------------------------------------------------
//due to cs106b specific pattern, i generate code here, call generate method inside student test clause.



// 1.GENERATOR for test.plot
void generateCustomPlotFile(string filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) return;

    // Example: Generate a simple square pattern
    outFile << "PenWidth 2\n";
    outFile << "PenColor Blue\n";
    outFile << "PenUp\n";
    outFile << "MoveAbs 0 0\n";
    outFile << "PenDown\n";
    outFile << "MoveAbs 1 0\n";
    outFile << "MoveAbs 1 1\n";
    outFile << "MoveAbs 0 1\n";
    outFile << "MoveAbs 0 0\n";

    outFile.close();
}


// 2.GENERATOR for RoseCurve.plot
void generateRoseCurve(string filename, int petals) {
    ofstream outFile(filename);
    if (!outFile.is_open()) return;

    outFile << "PenWidth 1\n";
    outFile << "PenColor Purple\n";
    outFile << "PenUp\n";

    // Center of the canvas (adjust based on your GUI canvas scale)
    double centerX = 0.0;
    double centerY = 0.0;
    double scale = 2.0; // Scale factor to make it fit nicely

    bool first = true;
    // Loop through 360 degrees (in radians) to draw the shape
    for (double theta = 0; theta < 2 * M_PI; theta += 0.01) {
        // Rose curve formula: r = cos(k * theta)
        double r = cos(petals * theta) * scale;

        // Convert polar to cartesian
        double x = centerX + r * cos(theta);
        double y = centerY + r * sin(theta);

        if (first) {
            outFile << "MoveAbs " << x << " " << y << "\n";
            outFile << "PenDown\n";
            first = false;
        } else {
            outFile << "MoveAbs " << x << " " << y << "\n";
        }
    }

    outFile.close();
}


// 3.GENERATOR for MysticRose.plot
void generateMysticRose(string filename, int numPoints, double radius) {
    ofstream outFile(filename);
    if (!outFile.is_open()) return;

    outFile << "PenWidth 1\n";
    outFile << "PenColor #00FFCC\n"; // You can use hex codes too!

    // 1. Calculate and store all the vertices of the polygon
    double xPoints[numPoints];
    double yPoints[numPoints];

    for (int i = 0; i < numPoints; i++) {
        double theta = (2 * M_PI * i) / numPoints;
        xPoints[i] = radius * cos(theta);
        yPoints[i] = radius * sin(theta);
    }

    // 2. Double loop to connect every point to every other point
    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            outFile << "PenUp\n";
            outFile << "MoveAbs " << xPoints[i] << " " << " " << yPoints[i] << "\n";
            outFile << "PenDown\n";
            outFile << "MoveAbs " << xPoints[j] << " " << " " << yPoints[j] << "\n";
        }
    }

    outFile.close();
}


// 4.GENERATOR for Sierpinski.plot

// The helper function that does the heavy lifting recursively
void drawTriangle(ofstream& outFile, double x, double y, double size, int order) {
    if (order == 0) {
        // Base case: Draw a single solid triangle
        outFile << "PenUp\n";
        outFile << "MoveAbs " << x << " " << y << "\n";
        outFile << "PenDown\n";
        outFile << "MoveAbs " << (x + size) << " " << y << "\n";
        outFile << "MoveAbs " << (x + size / 2) << " " << (y + size * sqrt(3) / 2) << "\n";
        outFile << "MoveAbs " << x << " " << y << "\n"; // Close triangle
    } else {
        // Recursive case: Break into three smaller triangles
        double subSize = size / 2;
        drawTriangle(outFile, x, y, subSize, order - 1); // Bottom left
        drawTriangle(outFile, x + subSize, y, subSize, order - 1); // Bottom right
        drawTriangle(outFile, x + subSize / 2, y + subSize * sqrt(3) / 2, subSize, order - 1); // Top center
    }
}

// The main wrapper function called by your test
void generateSierpinski(string filename, int order) {
    ofstream outFile(filename);
    if (!outFile.is_open()) return;

    outFile << "PenWidth 1\n";
    outFile << "PenColor Red\n";

    // Start recursion at order N, bottom-left at (-2, -2), width of 4
    drawTriangle(outFile, -2.0, -2.0, 4.0, order);

    outFile.close();
}





//TRIGGER IT INSIDE A STUDENT_TEST
STUDENT_TEST("Generated mystic.plot and sierpinski.plot") {
    // This will run and create the file when you click "Run Tests"
    //generateCustomPlotFile("res/test1.plot");
    //generateRoseCurve("res/RoseCurve.plot", 7);
    generateMysticRose("res/mystic.plot", 30, 2.5);
    generateSierpinski("res/sierpinski.plot", 5);
}

