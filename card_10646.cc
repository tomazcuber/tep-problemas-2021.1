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
    Card(char value, char suit): m_value(value), m_suit(suit){}

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
    std::cin >> cases;
    while(cases > 0){
        std::vector<Card> deck;  
        std::vector<Card> hand; 
        char currentValue;
        char currentSuit;

        for(int i = 0; i <= 26; ++i){
            std::cin >> currentValue;
            std::cin >> currentSuit;
            Card currentCard{currentValue, currentSuit};
            deck.emplace_back(currentCard);
        }

        for(int j = 27; j < 52; ++j){
            std::cin >> currentValue;
            std::cin >> currentSuit;
            Card currentCard{currentValue, currentSuit};
            hand.emplace_back(currentCard);
        }

        std::cout << "Deck: " << std::endl << "\t";
         for(auto card : deck){
            std::cout << card.getValue() << card.getSuit() << " ";
        }
        std::cout << std::endl;
        std::cout << "Hand: " << std::endl << "\t";
        for(auto card : hand){
            std::cout << card.getValue() << card.getSuit() << " ";
        }

        
        int Y = 0;
        Card topCard = deck.back();
        int X = topCard.getPoints();
        Y += X;
        std::vector<Card> remainingDeck{deck.end() - (10+X), deck.end() - 1};
        std::cout << "\nRemaining deck: " << std::endl << "\t";
        for(auto card : remainingDeck){
            std::cout << card.getValue() << card.getSuit() << " ";
        }
        std::cout << std::endl;
        remainingDeck.insert(remainingDeck.end(), hand.begin(), hand.end());


          
        
        cases--;
    }

    return 0;
}
