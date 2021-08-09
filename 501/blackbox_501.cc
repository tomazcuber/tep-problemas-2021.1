#include <iostream>
#include <set>
#include <vector>

int main(int argc, char** argv){
    int K, M, N;
    int currentValue;
    std::cin >> K;
    while(K--){
        std::cin >> M >> N;

        std::multiset<int> blackBox;
        std::vector<int> items;

        while(M--){
            std::cin >> currentValue;
            items.push_back(currentValue);
        }

        auto it = items.begin();
        auto blackBoxIt = blackBox.begin();

        while(N--){
            std::cin >> currentValue;
            while(blackBox.size() < currentValue){
                blackBox.insert(*it);
                if(blackBoxIt == blackBox.end() || *blackBoxIt > *it) blackBoxIt--;
                it++;
            }
            std::cout << *blackBoxIt++ << std::endl;
        }

        if(K) std::cout << std::endl;

    }

    return 0;
}