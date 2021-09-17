#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::cout << "This assignment is made by Rens van Vendeloo (0923416) " << std::endl;
    std::cout << "Made with Clion - Written in C++23" << std::endl << std::endl ;

    std::vector<std::vector<int>> renderBuffer; //2 dimensional array contains brightness values

    auto circleX = 0;
    auto circleY = 0;
    auto circleR = 10;
    auto horizontalResolution = 99;
    auto verticalResolution = 40;
    auto alternatorCols = 0;
    auto alternatorRows = 0;
    auto maxBrightness = 100;
    auto checkerboardSize = 10;
   // auto brightnessChars[] = {'.',':','-','=','+','*','#','%'};

    //calculate position of circle on screen canvas

    for(auto rows = 0; rows <= verticalResolution; rows++){
        for(auto cols = 0; cols < horizontalResolution; cols++){
            if(cols != 0) {
                if (alternatorCols % 2 == 0) {
                    std::cout << ".";
                } else {
                    //renderBuffer[rows][cols]= maxBrightness * 0.25;
                    std:
                    std::cout << "#";
                }
            }

            if(cols%checkerboardSize == 0) {
                alternatorCols++;
            }
        }
        std::cout << std::endl;
        alternatorRows++;
        if(alternatorRows == 4) {
            alternatorRows = 0;
            alternatorCols++;
        }

    }
    /*
    for(auto rows = 0;  rows <= verticalResolution; rows++){
        for (auto cols = 0; cols < horizontalResolution; ++cols) {
            auto charIndex = renderBuffer[rows][cols]/32;
            std::cout << charIndex << " ";
        }
        std::cout << std::endl;
    }




*/
    return 0;
}
