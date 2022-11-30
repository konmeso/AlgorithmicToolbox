#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dpSequence(int n){
  vector<int> sequence(0,1);
  vector<int> minOperations;
  int numOfOper;
  int operation;

  minOperations.push_back(0);

  for (size_t i = 1; i <= n ; i++){
    minOperations.push_back(n+1);
      
    // Check for minimum value
    numOfOper = minOperations[i-1] + 1;
    minOperations[i] = numOfOper;
    sequence = dpSequence(i-1);
    sequence.push_back(i);
    operation = 1;

    if ( (i%2 == 0) ){
      if ( (minOperations[i/2] + 1) < numOfOper ){
        numOfOper = minOperations[i/2] + 1;

        if (numOfOper < minOperations[i]){
          minOperations[i] = numOfOper;
          operation = 2;
        }
      }
    }

    if ( (i%3 == 0) ){
      if ( (minOperations[i/3] + 1) < numOfOper ){
        numOfOper = minOperations[i/3] + 1;

        if (numOfOper < minOperations[i]){
          minOperations[i] = numOfOper;
          operation = 3;
        }
      }

    }
  }
  
  return minOperations;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dpSequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
