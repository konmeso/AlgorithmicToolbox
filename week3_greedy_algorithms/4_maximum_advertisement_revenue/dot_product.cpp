#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

using namespace std;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here

  long long multiplication;

  stable_sort(a.begin(), a.end(), greater<int>());
  stable_sort(b.begin(), b.end(), greater<int>());

  size_t slots = a.size();

  long long result = 0;
  for (size_t i = 0; i < slots; i++) {
    multiplication = ((long long) a[i]) * b[i];
    //cout << "Value a: " << a[i] << "---" << "Value b: " << b[i] << endl;
    result += multiplication;
  }

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
