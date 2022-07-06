class Solution {
public:
    int fib(int n) {
        int fibonacci[40];
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        fibonacci[2] = 1;
        for(int i = 3; i <= n; i++){
            fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
        }
        return fibonacci[n];
    }
};