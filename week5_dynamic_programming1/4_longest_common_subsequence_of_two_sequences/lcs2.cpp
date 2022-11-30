#include <bits/stdc++.h>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {

  int n = a.size();
  int m = b.size();

  vector<vector<int>> dTable(n+1,vector<int>(m+1));

  for (size_t i = 0 ; i <= n ; i++){
    dTable[i][0] = 0;
  }

  for (size_t j = 0 ; j <= m ; j++){
    dTable[0][j] = 0;
  }

  for (size_t i = 1 ; i <= n ; i++){
    for (size_t j = 1 ; j <= m ; j++){
      if (a[i-1] == b [j-1]){
        dTable[i][j] = 1 + dTable[i-1][j-1];
      }
      else{
        dTable[i][j] = max(dTable[i-1][j],dTable[i][j-1]);
      }
    }
  }

  /*
  for (size_t i = 0 ; i <= n ; i++){
    for (size_t j = 0 ; j <= m ; j++){
      cout << dTable[i][j] << " ";
    }
    cout << endl;
  }
  */

  return dTable[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
