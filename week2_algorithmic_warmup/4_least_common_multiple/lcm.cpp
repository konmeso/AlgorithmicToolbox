#include <iostream>

using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd(long long a, long long b){
  long long maxValue = max(a,b);
  long long minValue = min(a,b);
  long long minValueTemp = min(a,b);
  
  while((maxValue % minValue) != 0){
    minValue = maxValue % minValue;
    maxValue = minValueTemp;
    minValueTemp = minValue;
  }

  return minValue;
}

long long lcm(long long a, long long b) {
  return abs(a*b)/gcd(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
