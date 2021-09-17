#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::cout << "This assignment is made by Rens van Vendeloo (0923416) " << std::endl;
    std::cout << "Made with Clion - Written in C++23" << std::endl << std::endl ;

    std::vector<std::vector<int>> renderBuffer; //2 dimensional array contains brightness values

    int circleX = 0;
    int circleY = 0;
    int circleR = 10;
    int horizontalResolution = 100;
    int verticalResolution = 100;
    int alternatorCols = 0;
    int alternatorRows = 0;
    int maxBrightness = 100;
    int checkerboardSize = 10;
    char brightnessChars[8] = {'.',':','-','=','+','*','#','%'};

    //calculate position of circle on screen canvas

    for(int rows = 0; rows <= verticalResolution; rows++){
        for(int cols = 0; cols < horizontalResolution; cols++){
            if(alternatorCols%2 == 0){
                renderBuffer[rows][cols] = maxBrightness - maxBrightness;
            } else {
                renderBuffer[rows][cols]= maxBrightness * 0.25;
            }
            if(cols%checkerboardSize == 0) {
                alternatorCols++;
            }
        }
    }
    
    for(int rows = 0;  rows <= verticalResolution; rows++){
        for (int cols = 0; cols < horizontalResolution; ++cols) {
            auto charIndex = renderBuffer[rows][cols]/32;
            std::cout << charIndex << " ";
        }
        std::cout << std::endl;
    }





    return 0;
}
