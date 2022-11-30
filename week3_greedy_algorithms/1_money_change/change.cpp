#include <iostream>
#include <cmath>

using namespace std;

int get_change(int m) {

  int nTens = 0;
  int nFives = 0;
  int nOnes = 0;
  int nTotal = 0;

  if (m >= 10){
    nTens = floor(m/10);
    m -= 10*nTens; 
  }
  
  if(m >=5){
    nFives = floor(m/5);
    m -= 5*nFives;
  }

  nOnes = m;

  nTotal = nOnes + nFives + nTens;
  
  return nTotal;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
