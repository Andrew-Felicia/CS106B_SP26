#include "Plotter.h"
#include <iostream>
#include "vector.h"
#include "strlib.h"
#include "string.h"

using namespace std;

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
