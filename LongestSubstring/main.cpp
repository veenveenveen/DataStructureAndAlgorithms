//
//  main.cpp
//  LongestSubstring
//
//  Created by 黄启明 on 2018/10/18.
//  Copyright © 2018 Himin. All rights reserved.
//

// Longest Substring Without Repeating Characters

/*
 Example 1:
 
 Input: "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 Example 2:
 
 Input: "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 Example 3:
 
 Input: "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = int(s.length());
        int res = 0;
        
        string resStr(s,0,1);
        
        map<char,int> mapping;
        
        for (int i = 0, j = 0; j < n; j++) {
            if (mapping.find(s[j]) != mapping.end()) {
                i = max(mapping[s[j]], i);
            }
//            res = max(res, j-i+1);
            cout << "i = " << i << ", j = " << j << ", str = " << string(s,i,j-i+1) << endl;

            if (res < j-i+1) {
                res = j-i+1;
                resStr = string(s,i,j-i+1);
            }
            
            mapping[s[j]] = j+1;
        }
        
        cout << resStr << endl;//打印最大子串
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    string str = "abcabcasdssgsfsgfdgfgsfggfertdfadsfasfbb";
    string str = "pwwkew";
    Solution solution;
    
    cout << solution.lengthOfLongestSubstring(str) << endl;
    
    return 0;
}
