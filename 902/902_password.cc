#include <iostream>
#include <map>
#include <string>

int main(int argc, char** argv){
    std::map<std::string, int> frequencies;

    int N, pos, maxFreq;
    std::string message;
    std::string subTemp;
    std::string password;

    while(std::cin >> N >> message){
        frequencies.clear();
        
        pos = 0;
        maxFreq = 0;
        subTemp = message.substr(pos++, N);
        while(subTemp.size() == N){
            if(++frequencies[subTemp] > maxFreq){
                maxFreq = frequencies[subTemp];
                password = subTemp;
            }
            subTemp = message.substr(pos++, N);
        }
        std::cout << password << std::endl;
    }

    return 0;
}