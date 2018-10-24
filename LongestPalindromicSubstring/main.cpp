//
//  main.cpp
//  LongestPalindromicSubstring
//
//  Created by 黄启明 on 2018/10/18.
//  Copyright © 2018 Himin. All rights reserved.
//

/*
 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 
 Example 1:
 
 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:
 
 Input: "cbbd"
 Output: "bb"
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = int(s.length()), start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            cout << "len = " << len << endl;
            if (len > end-start+1) {// 是否加1：不加返回asa,加1返回sds
                start = i-(len-1)/2;
                end = i+len/2;
                cout << "start = " << start<< ", end = " << end << ", str = " << string(s,start,end-start+1) << endl;
            }
        }
        
        if (end-start == 0) {
            return "null";
        }
        
        return string(s,start,end-start+1);
    }
private:
    int expandAroundCenter(string s, int left, int right) {
        int l = left, r = right;
        while (l >= 0 && r < int(s.length()) && s[l] == s[r]) {
            l--;
            r++;
        }
        return r-l-1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;
    std::cout << solution.longestPalindrome("vassademasds") << endl;
    return 0;
}
