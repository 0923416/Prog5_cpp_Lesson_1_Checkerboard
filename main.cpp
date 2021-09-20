#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::cout << "This assignment is made by Rens van Vendeloo (0923416) " << std::endl;
    std::cout << "Made with Clion - Written in C++23" << std::endl << std::endl ;

    std::vector<std::vector<int>> renderBuffer; //2 dimensional array contains brightness values

    bool trigger = false;
    auto horizontalResolution = 100;
    auto verticalResolution = 100;
    auto checkerboardHeight = verticalResolution /10;
    auto checkerboardWidth = horizontalResolution /10;
    int iterator = 1;
    int circleRadius = 10;
    int circleCenterX = 0;
    int circleCenterY = 0;
    int circleThickness = 5;

    int maxBrightness = 255;
    auto checkerboardSize = 10;
    char brightnessChars[] = {' ',':','-','=','+','*','#','%'};

    if(true) {
        //Fill renderbuffer with Checkerboard
        for (int i = 0; i < verticalResolution; ++i) {
            renderBuffer.emplace_back();
            for (int j = 0; j < horizontalResolution; ++j) {
                if(trigger) {
                    if ((j / checkerboardWidth) % 2 == 0) {
                        renderBuffer[i].emplace_back(floor(maxBrightness * 0.25));
                    } else {
                        renderBuffer[i].emplace_back(maxBrightness - maxBrightness);
                    }
                } else {
                    if ((j / checkerboardWidth) % 2 == 0) {
                        renderBuffer[i].emplace_back(maxBrightness - maxBrightness);
                    } else {
                        renderBuffer[i].emplace_back(floor(maxBrightness * 0.25));
                    }
                }

            }

            if(iterator == checkerboardHeight) {
                if (trigger) {
                    trigger = false;
                } else {
                    trigger = true;
                }
                iterator = 0;
            }
            
            iterator++;
        }

        //overlay circle on renderbuffer
        for (int i = 0; i < verticalResolution; ++i) {
            for (int j = 0; j < horizontalResolution; ++j) {
                for (int k = 0; k < circleThickness; ++k) {
                    if((int) sqrt(pow(i - (verticalResolution/2),2) + pow(j - (horizontalResolution/2),2)) == (circleRadius + k) ){
                        renderBuffer[i][j] += floor(maxBrightness * 0.5);
                    }
                }

            }
        }



        //Draw renderbuffer
        for (int i = 0; i < renderBuffer.size(); ++i) {
            for (int j = 0; j < renderBuffer[i].size(); ++j) {
                int charId = ceil(renderBuffer[i][j] / 32);
                std::cout << brightnessChars[charId];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
