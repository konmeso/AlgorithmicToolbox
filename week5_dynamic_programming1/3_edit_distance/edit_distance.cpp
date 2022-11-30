#include <bits/stdc++.h>

using namespace std;

int edit_distance(const string &str1, const string &str2) {

  int iLength = str1.length(); 
  int jLength = str2.length();

  // Declare 2D array on the heap dynamically
  int** d = new int*[iLength + 1];

  for (size_t idx = 0; idx <= iLength ; idx++){
    d[idx] = new int[jLength + 1];
  }

  // Initialize first column
  for (size_t i = 0; i <= iLength ; i++){
    d[i][0] = i;
  }

  // Initialize first row
  for (size_t j = 0 ; j <= jLength ; j++){
    d[0][j] = j;
  }
  
  // Process started
  for (size_t i = 1 ; i <= iLength ; i++){

    for (size_t j = 1 ; j <= jLength ; j++){

      int insertion = 1 + d[i][j-1];
      int deletion = 1 + d[i-1][j];
      int replacement = 1 + d[i-1][j-1];
      int match = d[i-1][j-1];

      if (str1[i-1] == str2[j-1]){
        d[i][j] = min({insertion,deletion,match});
      }
      else{
        d[i][j] = min({insertion,deletion,replacement});
      }
    }
  }

  return d[iLength][jLength];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
