#include <iostream> 
#include <string>
#include <algorithm>
#include <map>

bool palindrome(const std::string& word){
    for(auto left=std::begin(word), right=std::end(word); left < right;){
        if(*left++ != *--right)
            return false;
    }
    return true;
}

std::map<char, char> reverses {
    {'A','A'},{'E','3'},{'H','H'}, 
    {'I','I'},{'J','L'},{'L','J'}, 
    {'M','M'},{'O','O'},{'S','2'}, 
    {'T','T'},{'U','U'},{'V','V'},
    {'W','W'},{'X','X'},{'Y','Y'},
    {'Z','5'},{'1','1'},{'2','S'},
    {'3','E'},{'5','Z'},{'8','8'}
     };

bool isReverse(const char& a, const char& b){
    if(reverses.find(a) != reverses.end()){
        if(b == reverses.at(a)) {
            //std::cout << "Reverse of character \'" << a << "\' is: \'" << reverses.at(a) << std::endl;
            return true;
        }   
    }
    return false;
}

bool mirrored(const std::string& word){
    for(auto left=std::begin(word), right=std::end(word); left < right;){
        char a = *left++;
        char b = *--right;
        //std::cout << "Testing if " << a << " and " << b << " are reverses." << std::endl;
        if(!isReverse(a, b)){
            return false;
        }
    }
    return true;
}

void listReverses(){
    for(char test = '1'; test <= 'Z'; ++test)
    if(reverses.find(test) != reverses.end()) std::cout << "Reverse of "<< test <<" is: " << reverses.at(test) << std::endl;
}

int main(int argc, char** argv){
    std::string currentWord;
    while(std::getline(std::cin, currentWord)){
        std::cout <<  currentWord;
        bool palindromeFlag = palindrome(currentWord);
        bool mirroredFlag = mirrored(currentWord);
        if(palindromeFlag){
            if(mirroredFlag)
                std::cout << " -- is a mirrored palindrome." << std::endl;
            else    
                std::cout << " -- is a regular palindrome." << std::endl; 
        }
        else {
            if(mirroredFlag)
                std:: cout << " -- is a mirrored string." << std::endl;
            else
                std::cout << " -- is not a palindrome." << std::endl;
        }
        std::cout << std::endl;
    }
    
}