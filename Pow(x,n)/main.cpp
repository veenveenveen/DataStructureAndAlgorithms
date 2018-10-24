//
//  main.cpp
//  Pow(x,n)
//
//  Created by 黄启明 on 2018/10/17.
//  Copyright © 2018 Himin. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    double fun(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double half = fun(x, n/2);
        if (n&1) {
            return x*half*half;
        } else {
            return half*half;
        }
    }
    
    double myPow(double x, int n) {
        double res = fun(x, n);
        return n > 0 ? res : 1/res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;
    std::cout << solution.myPow(-0.00001, -10) << endl;
    
    cout << pow(-0.00001, -10) << endl;
    return 0;
}
