#include <iostream>
#include <vector>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

vector<int> fibonacci_fastDigits(int n) {
    // write your code here
    vector<int> fibonacci(n,0);

    for (size_t idx = 0; idx <= n ; idx++){
        if (idx <= 1){
            fibonacci[idx] = idx;
        }
        else{
            fibonacci[idx] = (fibonacci[idx-1] + fibonacci[idx-2]) % 10;
        }
    }

    return fibonacci;
}

int lastDigit(int n){
    vector<int> fibonacci = fibonacci_fastDigits(60);

    return fibonacci[n % 60];
}

int main() {
    int n;
    std::cin >> n;
    int c = lastDigit(n);
    std::cout << c << '\n';
    }
