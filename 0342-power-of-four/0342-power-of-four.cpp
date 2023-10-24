class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) {
            return 0;
        }
        int num=n;
        while(num%4==0) {
            num/=4;
        }
        return num==1;
    }
};