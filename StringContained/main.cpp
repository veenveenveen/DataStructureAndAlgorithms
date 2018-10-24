//
//  main.cpp
//  StringContained
//
//  Created by 黄启明 on 2018/10/19.
//  Copyright © 2018 Himin. All rights reserved.
//

/*
 Implement strStr().
 
 Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 
 Example 1:
 
 Input: haystack = "hello", needle = "ll"
 Output: 2
 Example 2:
 
 Input: haystack = "aaaaa", needle = "bba"
 Output: -1
 Clarification:
 
 What should we return when needle is an empty string? This is a great question to ask during an interview.
 
 For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */

#include <iostream>

using namespace std;

class Solution {
public:
    
    // O((n-m)*m)
    bool isContained(string str, string cmp) {
        
        int n = int(str.length());
        int len = int(cmp.length());
        if (n < len) { return false; }
        if (len == 0) { return true; }
        
        for (int i = 0; i < n-len+1; i++) {
            if (str[i] == cmp[0]) {
                for (int j = 0; j < len; j++) {
                    if (str[i+j] != cmp[j]) { break; }
                    if (j == len-1) { return true; }
                }
            }
        }
        
        return false;
    }
    
    int strStr(string haystack, string needle) {
        int n = int(haystack.length());
        int len = int(needle.length());
        if (len > n) {
            return -1;
        }
        if (len == 0) {
            return 0;
        }
        for (int i = 0; i < n - len + 1; i++) {
            if (needle[0] == haystack[i]) {
                for (int j = 0; j < len; j++) {
                    if (needle[j] != haystack[i+j]) {
                        break;
                    }
                    if (j == len - 1) {
                        return i;
                    }
                }
            }
        }
        
        return -1;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << Solution().isContained("asdfassdadasdasdasdasdasdasdasdasdasasadasdasdasdasdas", "ass") << endl;
    
    std::cout << Solution().strStr("a", "a") << endl;

    return 0;
}
