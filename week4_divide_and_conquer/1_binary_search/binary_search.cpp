#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int) a.size()-1; 
  int midIdx;

  while (right >= left){
    midIdx = floor((left+right)/2);
    if (a[midIdx] == x){
      return midIdx;
    }
    else if (a[midIdx] < x){
      left = midIdx + 1;
    }
    else{
      right = midIdx - 1;
    }
  }

return -1;

}

int binarySearchDuplicates(const vector<int> &a, int x){
  int initialIdx = binary_search(a,x);
  int previousIdx = initialIdx - 1;
  int firstIdx = -1;

  if (initialIdx != -1){
    while (a[previousIdx] == x){
      previousIdx--;
    }
    firstIdx = previousIdx + 1;
  }

  return firstIdx;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binarySearchDuplicates(a, b[i]) << ' ';
  }
}
