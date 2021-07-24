#include <iostream>
#include <map>
#include <string>
#include <set>

void fillBalanceSide(std::set<char>& balanceSide){
    balanceSide.clear();
    std::string coins;
    std::cin >> coins;
    for(auto &coin : coins){
        balanceSide.insert(coin);
    }
}

void printBalanceSide(const std::set<char>& balanceSide){
    for(auto coin: balanceSide){
        std::cout << coin << " ";
    }
}

void removeFromSet(std::set<char>& setRemovedFrom, const std::set<char>& removedValues)
{
    for (std::set<char>::const_iterator iter = removedValues.begin(); iter != removedValues.end(); ++iter)
        setRemovedFrom.erase(*iter);
}

std::set<char> combineSets(const std::set<char>& left, const std::set<char>& right)
{
    std::set<char> combined;
    
    for (std::set<char>::const_iterator iter = left.begin(); iter != left.end(); ++iter)
        combined.insert(*iter);
    
    for (std::set<char>::const_iterator iter = right.begin(); iter != right.end(); ++iter)
        combined.insert(*iter);
        
    return combined;
}

std::set<char> joinSets(const std::set<char>& left, const std::set<char>& right){
    std::set<char> joined;
    for(std::set<char>::const_iterator iter = left.begin(); iter != left.end(); ++iter){
        if(right.find(*iter) != right.end()){
            joined.insert(*iter);
        }
    }
    return joined;    
}

int main(int argc, char** argv){
    int cases{0};
    int count{1};
    std::cin >> cases;

    
    while(cases){

        std::set<char> lightCoins;

        for(char i = 'A'; i <= 'L'; ++i){
            lightCoins.insert(i);
        }

        std::set<char> heavyCoins = lightCoins;
        char counterfeit{'\0'};

        for(int readings = 1; readings <= 3; ++readings){
            std::set<char> leftBalance{};
            std::set<char> rightBalance{};
            std::string balanceResult{};

            fillBalanceSide(leftBalance);
            fillBalanceSide(rightBalance);
            std::cin >> balanceResult;

            // std::cout << "Case " << count << " Reading " << readings << std::endl
                    // << "\tLeft Balance: ";
            // printBalanceSide(leftBalance);
            // std::cout << std::endl << "\tRight Balance: ";
            // printBalanceSide(rightBalance);
            // std::cout << std::endl << "\tResult: " << balanceResult << std::endl;
            



            
            if(!counterfeit){

                if(balanceResult == "even"){
                    removeFromSet(lightCoins, leftBalance);
                    removeFromSet(lightCoins, rightBalance);
                    removeFromSet(heavyCoins, leftBalance);
                    removeFromSet(heavyCoins, rightBalance);
                }
                else if(balanceResult == "up"){
                    lightCoins = joinSets(lightCoins, rightBalance);
                    removeFromSet(lightCoins,leftBalance);
                    heavyCoins = joinSets(heavyCoins,leftBalance);
                    removeFromSet(heavyCoins, rightBalance);
                }
                else if(balanceResult == "down"){
                    lightCoins = joinSets(lightCoins,leftBalance);
                    removeFromSet(lightCoins, rightBalance);
                    heavyCoins = joinSets(heavyCoins, rightBalance);
                    removeFromSet(heavyCoins, leftBalance);
                }


            }
        }


        if(lightCoins.size() + heavyCoins.size() == 1) {
            if(lightCoins.size() == 1){
                counterfeit = *lightCoins.begin();
                std::cout << counterfeit << " is the counterfeit coin and it is light.\n";
            } else {
                counterfeit = *heavyCoins.begin();
                std::cout << counterfeit << " is the counterfeit coin and it is heavy.\n";
            }
        }

        ++count;
        --cases;
    } 
    // std::cout << std::endl;
    return 0;
}