#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>

int main(int argc, char** argv){
    int tests{0};
    int snowflakes{0}; 
    int currentValue{0};

    std::cin >> tests;

    while(tests--){
        std::cin >> snowflakes;

        std::unordered_map<int,int> uniqueSnowflakes;
        int indexWithoutDuplicate{0};
        int output{0};

        for(int i = 1; i <= snowflakes; i++){
            std::cin >> currentValue;
            int lastUnique = uniqueSnowflakes[currentValue];
            indexWithoutDuplicate = std::max(lastUnique, indexWithoutDuplicate);
            output = std::max(i-indexWithoutDuplicate, output);
            uniqueSnowflakes[currentValue] = i;
        }

        std::cout << output << std::endl;
    }
    return 0;
}