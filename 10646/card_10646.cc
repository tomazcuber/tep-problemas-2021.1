/* --------------------------------------------------------|
|Onlinejudge.org - Problema 10646: What is the card?       |
|Autor: Tomaz Cuber Guimarães                              |
|Última edição: 13/07/2021                                 |
------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Card {
public:
    Card(char value, char suit): m_value(value), m_suit(suit){
        this->setPoints();
    }

    inline void setPoints() {
        int valueInt = m_value - '0';
        if(valueInt >= 2 && valueInt <= 9){
            m_points = valueInt;
        } 
        else {
            m_points = 10;
        }
    }

    inline int getPoints() {
        return m_points;
    }

    inline char getValue() { return m_value; }
    inline char getSuit() { return m_suit; }

private:
    char m_value;
    char m_suit;
    int m_points;
};

int main(int argc, char** argv){
    int cases{0};
    int count{0};
    std::cin >> cases;
    std::vector<Card> initialDeck;
    while(cases > 0){
        count++;
        char currentValue, currentSuit;
        for(int i = 0; i < 52; ++i){
            std::cin >> currentValue;
            std::cin >> currentSuit;
            initialDeck.emplace_back(Card(currentValue, currentSuit));
        }

          
        int Y = 0;
        int topPos = 26;
        std::vector<Card> awayPile;
        std::vector<Card> hand{initialDeck.begin() + (topPos+1), initialDeck.end()};
        std::vector<Card> remainingPile{initialDeck.begin(), initialDeck.begin() + topPos};
        for(int i = 0; i < 3; i++){
            Card topCard = remainingPile.back();
            int X = topCard.getPoints();
            std::cout << "Top card is: " << topCard.getValue() << topCard.getSuit() << " with X = " << X << std::endl;
            for(int i = 0; i < (10-X) + 1; ++i){
                awayPile.emplace_back(topCard);
                remainingPile.pop_back();
                topCard = remainingPile.back();
            }
            Y += X;
            std::cout << "Y = " << Y << std::endl;
        }

        for(auto card: hand){
            remainingPile.emplace_back(card);
        }
        Card yCard = remainingPile.at(Y);
        std::cout << "Case " << cases << ": " << yCard.getValue() << yCard.getSuit() << std::endl;
        
        --cases;
        initialDeck.clear();
    }

    return 0;
}
