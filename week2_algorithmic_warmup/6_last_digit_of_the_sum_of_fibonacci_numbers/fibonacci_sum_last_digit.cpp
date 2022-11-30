#include <iostream>
#include <vector>

using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long fibonacci(long long n ){
    long long pre=0,cur=1;
    n = n %60;
    if(n==0){
        return 0;}
    else if (n == 1){
        return 1;
    }
    else{
    for (long long i =2; i<=n; i++){
        long long temp = (pre+cur)%60;
        pre = cur;
        cur = temp;
        // cout<<pre<<"\n"<<cur<<"\n";
    }
    }
    
    return(cur); 
}

 long long sumSquares(unsigned long long n){
    return fibonacci(n)*fibonacci(n+1);
}

int main() {
    unsigned long long n;
    std::cin >> n;
    std::cout << sumSquares(n) % 10;
}
