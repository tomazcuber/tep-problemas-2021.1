#include <iostream>
#include <string>
#include <map>

int main(int argc, char** argv){
    std::string word1, word2;
    std::map<char, int> frequency1, frequency2;

    while(std::getline(std::cin, word1)){
        std::getline(std::cin, word2);

        frequency1.clear();
        frequency2.clear();
        
        for(auto x : word1){
            frequency1[x]++;
        }

        for(auto y : word2){
            frequency2[y]++;
        }

        for(char i = 'a'; i <= 'z'; ++i){
            int timesSeen = std::min(frequency1[i], frequency2[i]);
            for(int j = 0; j < timesSeen; ++j){
                std::cout << i;
            } 
        }

        std::cout << std::endl;
    }

    return 0;
}