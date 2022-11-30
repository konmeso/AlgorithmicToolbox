#include <iostream>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd(int a, int b){
  int maxValue = max(a,b);
  int minValue = min(a,b);
  int minValueTemp = min(a,b);
  
  while((maxValue % minValue) != 0){
    minValue = maxValue % minValue;
    maxValue = minValueTemp;
    minValueTemp = minValue;
  }

  return minValue;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
