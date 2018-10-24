//
//  main.cpp
//  ReverseInteger
//
//  Created by 黄启明 on 2018/10/18.
//  Copyright © 2018 Himin. All rights reserved.
//
/*
 Given a 32-bit signed integer, reverse digits of an integer.
 
 Example 1:
 
 Input: 123
 Output: 321
 Example 2:
 
 Input: -123
 Output: -321
 Example 3:
 
 Input: 120
 Output: 21
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        
        int res = 0;
        
        while (x != 0) {
            int tmp = x%10;
            if (res > INT_MAX/10 || (res == INT_MAX/10 && tmp > 7)) { return 0; } // 判断是否会溢出
            if (res < INT_MIN/10 || (res == INT_MIN/10 && tmp < -8)) { return 0; }
            res = res * 10 + tmp;
            x = x/10;
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;
    int res = solution.reverse(-2147483412);
    std::cout << res << endl;
    return 0;
}
