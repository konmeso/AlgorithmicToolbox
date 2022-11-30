#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    long long n = numbers.size();

    long long max1 = 0;
    long long idxMax = 0;

    long long max2 = 0;

    for (long long first = 0; first < n; ++first) {
        if (numbers[first] > max1){
            max1 = numbers[first];
            idxMax = first;
        }
    }

    for (long long second = 0; second < n; ++second){
        if ((second != idxMax) && (numbers[second] > max2)){
            max2 = numbers[second];
        }
    }

    return max1*max2;
}

/*
void stressTest(){
    while(true){
        long long n = rand() % 9 + 1;
        std::vector<long long> s(n);

        for (long long i = 0; i < n; i++){
            long long insertedNumber = rand() % 100 + 1;
            s.push_back(insertedNumber);
        }

        if (MaxPairwiseProduct(s) != MaxPairwiseProductSlow(s)){
            cout << "Different Outcome! | Fast: " << MaxPairwiseProduct(s) << " Slow: " << MaxPairwiseProductSlow(s) << endl;
            break; 
        }
        else{
            cout << "Ok!";
        }
    }
}
*/

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}