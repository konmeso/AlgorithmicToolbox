//#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using std::vector;
using std::swap;
using namespace::std;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<long long> &a, long long l, long long r, long long &beginCounter, long long &endCounter){
  long long x = a[l];
  beginCounter = l;
  endCounter = r;

  /*
  cout << endl;
  cout << "Pivot point: " << x << endl;
  // Print input vectors
  cout << "Input Vector" << endl;
  for (size_t i = l; i <= r; ++i) {
    std::cout << a[i] << ' ';
  }
  cout << endl;
  */

  for (long long i = beginCounter + 1; i <= endCounter; i++){
    if (a[i] < x){
      swap(a[i],a[beginCounter]);
      beginCounter++;
    }
    else if (a[i]>x){
      swap(a[i],a[endCounter]);
      endCounter--;
      i--;
    }
  }
  
  //a.insert(a.begin()+s.last+1,a[l]);
  //a.erase(a.begin()+l);

  // Print sorted vectors
  
  /*
  cout << "Sorted Vector" << endl;
  for (size_t i = l; i <= r; ++i) {
    std::cout << a[i] << ' ';
  }
  cout << endl;
  */
  // cout << "Lower Value: " << s.first << endl;
  // cout << "Greater Value: " << s.last << endl;
  
}

void randomized_quick_sort(vector<long long> &a, long long l, long long r) {
  
  // Since this function is a void, if l >= r return the initial one element vector
  if (l >= r) {
    return;
  }

  // Get random index
  long long k = l + rand() % (r - l + 1);

  // Bring random index in front in order to iterate through the vector
  swap(a[l], a[k]);

  long long beginCounter, endCounter;

  partition3(a, l, r, beginCounter, endCounter);
  randomized_quick_sort(a, l, --beginCounter);
  randomized_quick_sort(a, ++endCounter, r);
}

void stressTest(){

  long long counter = 1;

  while(true){
    long long n = rand() % 100000;
    vector<long long> a;

    for (size_t i=0; i < n; i++){
      long long elment = rand() % 10000000;
      a.push_back(elment);
    }

    cout << endl;

    cout << "--- Test Number: " << counter << endl;
    counter++;

    cout << "Generated A" << endl;
    for (size_t i = 0; i < a.size(); ++i) {
          std::cout << a[i] << ' ';
    }

    cout << endl;

    cout << "Generated B" << endl;
    
    vector<long long> b = a;

    for (size_t i = 0; i < b.size(); ++i) {
          std::cout << b[i] << ' ';
    }

    sort(b.begin(),b.end());

    randomized_quick_sort(a,0,a.size()-1);

    cout << endl;
    cout << "Sorted A" << endl;

    for (size_t i = 0; i < a.size(); ++i) {
          std::cout << a[i] << ' ';
    }

    cout << endl;
    cout << "Sorted B" << endl;

    for (size_t i = 0; i < b.size(); ++i) {
          std::cout << b[i] << ' ';
    }

    assert(a==b);

  }
}

/*
int main(){
  stressTest();
}
*/


int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}

