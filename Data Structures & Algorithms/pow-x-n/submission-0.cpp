class Solution {
public:
    double myPow(double x, int n) {

        if(n < 0){
            return (double) 1 / myPow(x , abs(n));
        }
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }

        return x * myPow(x , n - 1);
    }
};
