#include <bits/stdc++.h>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {

  int numberOfItems = w.size();

  vector<vector<int>> valueTable(W+1,vector<int>(numberOfItems+1));

  // Initialization of value table
  for (size_t i = 0 ; i <= W ; i++){
    valueTable[i][0] = 0;
  }

  for (size_t j = 0 ; j <= numberOfItems ; j++){
    valueTable[0][j] = 0;
  }

  // Filling the value table
  for (size_t idxW = 1 ; idxW <= W ; idxW++){
    for (size_t i = 1 ; i <= numberOfItems ; i++){
      if (w[i-1] <= idxW){
        valueTable[idxW][i] = max(valueTable[idxW - w[i-1]][i-1] + w[i-1],valueTable[idxW][i-1]);
      }
      else{
        valueTable[idxW][i] = valueTable[idxW][i-1];
      }
    }
  }

  /*
  for (size_t iN = 0 ; iN <= W ; iN++){
    for (size_t iM = 0 ; iM <= numberOfItems ; iM++){
      cout << valueTable[iN][iM] << " ";
    }
    cout << endl;
  }
  */
 
  return valueTable[W][numberOfItems];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
