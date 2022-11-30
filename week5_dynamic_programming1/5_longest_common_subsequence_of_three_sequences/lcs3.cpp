#include <bits/stdc++.h>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {

  int n = a.size();
  int m = b.size();
  int k = c.size();

  vector<vector<vector<int>>> dTable(n+1,vector<vector<int>>(m+1,vector<int>(k+1)));

  // Initialize first rows
  for (size_t i = 0 ; i <= n ; i++){
    dTable[i][0][0] = 0;
  }

  for (size_t j = 0 ; j <= m ; j++){
    dTable[0][j][0] = 0;
  }

  for (size_t l = 0 ; l <= k ; l++){
    dTable[0][0][l] = 0;
  }

  for (size_t i = 1 ; i <= n ; i++){
    for (size_t j = 1 ; j <= m ; j++){
      for (size_t l = 1 ; l <= k ; l++){
        if ((a[i-1] == b [j-1]) && (a[i-1] == c[l-1])){
          dTable[i][j][l] = 1 + dTable[i-1][j-1][l-1];
        }
        else{
          dTable[i][j][l] = max({dTable[i-1][j][l],dTable[i][j-1][l],dTable[i][j][l-1],dTable[i-1][j-1][l],dTable[i-1][j][l-1],dTable[i][j-1][l-1]});
        }
      }
    }
  }

  return dTable[n][m][k];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
