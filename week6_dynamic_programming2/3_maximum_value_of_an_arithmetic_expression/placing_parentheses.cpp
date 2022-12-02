#include <bits/stdc++.h>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
  return 0;
}

vector<long long> MinAndMax(long long i, long long j, vector<vector<vector<long long>>> eTable, string &s){
  long long maxValue = - pow(9,7);
  long long minValue = - maxValue;


  for (long long k = i ; k <= j-1 ; k++){
    
    char opk = s[2*k+1];

    vector<long long> minMax_i_k = eTable[i][k];
    vector<long long> minMax_k_j = eTable[k+1][j];
    
    long long a = eval(minMax_i_k[1],minMax_k_j[1],opk);
    long long b = eval(minMax_i_k[1],minMax_k_j[0],opk);
    long long c = eval(minMax_i_k[0],minMax_k_j[1],opk);
    long long d = eval(minMax_i_k[0],minMax_k_j[0],opk);

    minValue = min({minValue,a,b,c,d});
    maxValue = max({maxValue,a,b,c,d});
  }

  return {minValue,maxValue};
}

long long mainProcess(string &sString){

  vector<int> numbers;

  // Keep all numbers in a vector
  for (size_t i = 1 ; i <= (sString.length()-1)/2 + 1 ; i++){
    int num = stoi(string(1,sString[2*(i-1)]));
    numbers.push_back(num);
  }

  int totalNumbers = numbers.size();
  
  //cout << "Total numbers = " << totalNumbers << endl;

  // Declare eTable
  vector<vector<vector<long long>>> eTable(totalNumbers,vector<vector<long long>>(totalNumbers,vector<long long>(2)));

  //cout << "eTable size = " << eTable.size() << endl;

  // Initialize main diagonal of eTable
  for (size_t i = 0 ; i < totalNumbers ; i++){
    eTable[i][i][0] = numbers[i];
    eTable[i][i][1] = numbers[i];
  }

  // Calculate values for upper diagonals
  for (size_t s = 1 ; s <= totalNumbers - 1 ; s++){
    for (size_t i = 0 ; i < totalNumbers - s ; i++){
      size_t j = i + s;
      vector<long long> minMax = MinAndMax(i,j,eTable,sString);
      eTable[i][j][0] = minMax[0];
      eTable[i][j][1] = minMax[1];
    }
  }

  /*
  for (size_t i = 0 ; i < totalNumbers ; i++){
    for (size_t ii = 0 ; ii < totalNumbers ; ii++){
      cout << "(" << eTable[i][ii][0] << "," << eTable[i][ii][1] << ") " ; 
    }
    cout << endl;
  }
  */

  // Return the M(1,n)
  return eTable[0][totalNumbers-1][1];
}

long long get_maximum_value(const string &exp) {
  //write your code here
  return 0;
}

int main() {
  string s;
  std::cin >> s;
  //cout << stoi(string(1,s[2]));
  cout << mainProcess(s);
  //std::cout << get_maximum_value(s) << '\n';
}
