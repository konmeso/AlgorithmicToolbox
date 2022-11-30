#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

using std::vector;

vector<size_t> sortIndexes(vector<double> s){
  
  vector<size_t> idx(s.size());
  iota(idx.begin(), idx.end(), 0);

  stable_sort(idx.begin(), idx.end(), [&s](size_t i1, size_t i2){ return (s[i1] < s[i2]); } );

  return idx;

}

double maxWeightofProductInBag(int productAvailable, double capacityLeft){

  if (productAvailable > capacityLeft){
    return capacityLeft;
  }
  else{
    return productAvailable;
  }

}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  
  // Initialize value in bag
  double value = 0.0;

  // Define specific value (value per weight)
  int numElements = weights.size();
  vector<double> weightValue(numElements,0.0);

  for (int i = 0; i < numElements; i++){
    weightValue[i] = values[i] / (double) weights[i];
  }

  // Sort items according to the weight value
  vector<size_t> sortedElements = sortIndexes(weightValue);

  // Initialize weight in the bag and in store
  double inBag = 0.0;
  double inStore = accumulate(weights.begin(),weights.end(),0);

  // Initialize element to put in bag
  size_t element = sortedElements.size()-1;

  while ((inBag < capacity) && (inStore > 0)){
    double currentProductWeight = maxWeightofProductInBag(weights[sortedElements[element]],capacity-inBag);
    inBag += currentProductWeight;
    inStore -= currentProductWeight;
    value += currentProductWeight*weightValue[sortedElements[element]];
    element--;
  }

  return value;

}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(4);
  std::cout << fixed << optimal_value << std::endl;
  return 0;
}
