#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> optimal_weight(int W, const vector<int> &w) {

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
 
  return valueTable;
}

vector<int> selectedItems(vector<vector<int>> valueTable, vector<int> w, int W){

  int totalWeight = W;
  int totalItems = w.size();

  int currentValue = valueTable[totalWeight][totalItems];

  vector<int> selectedVector;

  int itemIdx = totalItems;
  int weightIdx = totalWeight;

  for (size_t iN = 0 ; iN <= totalWeight ; iN++){
    for (size_t iM = 0 ; iM <= totalItems ; iM++){
      cout << valueTable[iN][iM] << " ";
    }
    cout << endl;
  }

  while (currentValue != 0){
    if (weightIdx >= w[itemIdx-1]){
      if (valueTable[weightIdx-w[itemIdx-1]][itemIdx-1] == currentValue){
        itemIdx--;
        weightIdx -= itemIdx;
      }
      else if ((valueTable[weightIdx][itemIdx-1] == currentValue) && (valueTable[weightIdx-w[itemIdx-1]][itemIdx-1] != currentValue) ){
        // Be careful of running two times
        itemIdx--;
      }
      else if (max(valueTable[weightIdx-w[itemIdx-1]][itemIdx-1],valueTable[weightIdx][itemIdx-1]) < currentValue){
        if (valueTable[weightIdx-w[itemIdx-1]][itemIdx-1] == max(valueTable[weightIdx-w[itemIdx-1]][itemIdx-1],valueTable[weightIdx][itemIdx-1])){
          currentValue = valueTable[weightIdx-w[itemIdx-1]][itemIdx-1];
          itemIdx--;
          weightIdx -= w[itemIdx-1];
        }
        else{
          selectedVector.push_back(itemIdx);
          currentValue = valueTable[weightIdx][itemIdx-1];
          itemIdx--;
        }
      }
    }
    else{
      itemIdx--;
    }
    
    cout << "Current Value: " << currentValue << endl;
    cout << "Current Item: " << w[itemIdx-1] << endl;

  }

  return selectedVector;

}

int main(){
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  vector<vector<int>> valueTable = optimal_weight(W,w);

  cout << "Total Value: " << valueTable[W][w.size()] << endl;

  vector<int> selected = selectedItems(valueTable,w,W); 

  cout << "The selected items are" << endl;
  for (size_t i = 0 ; i < selected.size() ; i++){
    cout << selected[i] << " " ; 
  }

}

int partition3(vector<int> &A) {
  //write your code here
  int sizeA = A.size();

  // Calculate total value
  int totalValue = 0;
  for (size_t i = 0; i < sizeA ; i++){
    totalValue += A[i];
  }

  // Check if total value is divisible
  if (totalValue % 3 != 0){
    return 0;
  }

  int pirateValue = totalValue/3;
  
  // If total value is divisible, start process


  return 0;
}

/*
int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
*/