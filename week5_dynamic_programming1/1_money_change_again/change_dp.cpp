#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int get_change(int m) {
  //write your code here

  // Initialize Table | Infinity = m + 1
  vector<int> minCoins;
  vector<int> coins{1,3,4};
  int numOfCoins;

  // Base Case
  minCoins.push_back(0);

  for (int money = 1; money <= m; money++){
    minCoins.push_back(m+1);
    for (int coin_i = 0; coin_i < coins.size() ; coin_i++){
      if (money >= coins[coin_i]){
        numOfCoins = minCoins[money - coins[coin_i]] + 1;
        if (numOfCoins < minCoins[money]){
          minCoins[money] = numOfCoins;
        }
      }
    }
  }

  /*
  for (size_t ii = 0; ii < minCoins.size(); ii++){
    cout << "Minimum Number of Coins for " << ii << " is " << minCoins[ii] << endl;
  }
  */
  //cout << "Minimum Number of Coins: " << minCoins[m] << endl;

  return minCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
