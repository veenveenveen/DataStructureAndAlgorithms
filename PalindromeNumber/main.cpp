//
//  main.cpp
//  PalindromeNumber
//
//  Created by 黄启明 on 2018/10/18.
//  Copyright © 2018 Himin. All rights reserved.
//

/*
 Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 
 Example 1:
 
 Input: 121
 Output: true
 Example 2:
 
 Input: -121
 Output: false
 Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 Example 3:
 
 Input: 10
 Output: false
 Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 */

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x % 10 == 0 && x!=0 )) { return false; }
        
        int revertedNum = 0;
        while (x > revertedNum) {
            revertedNum = revertedNum * 10 + x % 10;
            x = x / 10;
        }
        
        return x == revertedNum || x == revertedNum/10;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution solution;
    
    std::cout << solution.isPalindrome(1221) << std::endl;
//    std::cout << "\n ------------------\n/ Hello David Day! \\\n\\ my Macro Log ~   /\n ------------------\n            \\\n             \\   ^__^\n                 (OO)\__________\n                 (__)\\          )\\/\\\n                     ||_______ _)\n                     ||       W |\n       YYy           ww        ww\n" << std::endl;
    return 0;
}
