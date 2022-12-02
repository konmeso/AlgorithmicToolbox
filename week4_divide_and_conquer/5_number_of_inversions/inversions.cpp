#include <bits/stdc++.h>

using namespace std;
/*
vector<int> merge(vector<int> b, vector<int> c){
  vector<int> d;

  while (!b.empty() && !c.empty()){
    int bElem = b[0];
    int cElem = c[0];

    if (bElem <= cElem){
      d.push_back(bElem);
      b.erase(b.begin());
    }
    else{
      d.push_back(cElem);
      c.erase(c.begin());
    }

  }
}
*/

vector<int> mergeSort(vector<int> a, int left, int right){
  
  int vectorSize = a.size();

  if (vectorSize == 1){
    return a;
  }

  vector<int> d;
  int mid;


  if (left < right){
    mid = floor((left+right)/2);

    vector<int> b = mergeSort(a,left,mid);
    vector<int> c = mergeSort(a,mid+1,right);

    // Merge algorithm
    long long invCounter = 0;
    int prevMerge = 0;
    int curMerge;

    while (!b.empty() && !c.empty()){
      int bElem = b[0];
      int cElem = c[0];

      if (bElem <= cElem){
        cout << bElem << " ";
        d.push_back(bElem);
        b.erase(b.begin());
        curMerge = 0;
      }
      else{
        cout << cElem << " "; 
        d.push_back(cElem);
        c.erase(c.begin());
        curMerge = 1;
      }

      if ((prevMerge != curMerge) && (d.end()[-1] != d.end()[-2])){
        invCounter++;
        prevMerge = curMerge;
      }
      
      cout << endl;
    }
  }


  // End of merge algorithm

  for (size_t i = 0 ; i < d.size() ; i++){
    cout << d[i] << " " << endl;
  }

  return d;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  // Initialize number of inversions
  long long number_of_inversions = 0;


  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  mergeSort(a,0,a.size()-1);
  //std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
