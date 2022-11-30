#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  int remaining = n;

  int idx = 1;
  int number;

  while (remaining != 0){
    if ((remaining -idx) > 1){
      number = remaining % (remaining - idx);
    }
    else{
      number = remaining;
    }
    //cout << "Number: " << number << endl;
    if ((!binary_search(summands.begin(), summands.end(), number)) && (number != 0)){
      summands.push_back(number);
      remaining -= number;
      //cout << "Remaining: " << remaining << endl;
    }
    idx++;
    //cout << "Index: " << idx << endl;
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
