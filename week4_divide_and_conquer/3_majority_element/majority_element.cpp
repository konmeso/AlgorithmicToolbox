#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

long long binary_search(const vector<long long> &a, long long x) {
  long long left = 0, right = (long long) a.size(); 
  long long midIdx;

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

int get_majority_element(vector<long long> &a) {

  long long sizeA = a.size();
  vector<long long> uniqueArr;
  vector<long long> scores;
  long long idx;

  uniqueArr.push_back(a[0]);
  scores.push_back(1);

  for (size_t ii = 1; ii < sizeA ; ii++){
    idx = binary_search(uniqueArr,a[ii]);
    if (idx == -1){
      uniqueArr.push_back(a[ii]);
      scores.push_back(1);
    }
    else{
      scores[idx]++;
    }
  }

  int max = *max_element(scores.begin(),scores.end());

  if (max > sizeA/2){
    return 1;
  }
  else{
    return 0;
  }

}

int get_majority_element(vector<long long> &a, long long left, long long right){

  if (left==right){
    return a[left];
  }

  long long mid = floor((left+right)/2);


}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a) << '\n';
}
