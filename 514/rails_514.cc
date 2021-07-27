#include <iostream>
#include <limits>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

void possibleExitOrder(int cars) {
  std::vector<int> arrivals;
 
  for(int i = 1; i <= cars; ++i){
      arrivals.push_back(i);
      
  }

  while (true) {
    std::stack<int> carsInStation;
    int carToLeave{0};
    int carArrived{0};
    for (int i = cars; i > 0; --i) {
      std::cin >> carToLeave;
      if (carToLeave == 0) {
        std::cout << std::endl;
        return;
      }
      

      while(carArrived < cars){
        if(carArrived == carToLeave){
          
          break;
        }
        if(carsInStation.size() > 0 && carToLeave == carsInStation.top()){
          
          break;
        }
        carArrived++;
        carsInStation.push(carArrived);
        
      }
        
      if (carsInStation.top() == carToLeave) {
        
        carsInStation.pop();
      }
    }
    
    carsInStation.size() == 0 ? std::cout << "Yes\n" : std::cout << "No\n";
  }
}

int main(int argc, char **argv) {

  int cars{0};

  while (true) {
    std::cin >> cars;
    

    if (cars == 0) {
      
      break;
    }

    possibleExitOrder(cars);
    
  }
  return 0;
}
