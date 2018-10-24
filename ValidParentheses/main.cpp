//
//  main.cpp
//  ValidParentheses
//
//  Created by 黄启明 on 2018/10/19.
//  Copyright © 2018 Himin. All rights reserved.
//

/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 An input string is valid if:
 
 Open brackets must be closed by the same type of brackets.
 Open brackets must be closed in the correct order.
 Note that an empty string is also considered valid.
 
 Example 1:
 
 Input: "()"
 Output: true
 Example 2:
 
 Input: "()[]{}"
 Output: true
 Example 3:
 
 Input: "(]"
 Output: false
 Example 4:
 
 Input: "([)]"
 Output: false
 Example 5:
 
 Input: "{[]}"
 Output: true
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0) { return true; }
        vector<char> stack;
        map<char, char> mapping{{'(',')'},{'{','}'},{'[',']'}};
        stack.push_back(s[0]);
        for (int i = 1; i < s.length(); i++) {
            if (mapping[stack.back()] == s[i]) {
                stack.pop_back();
            } else {
                stack.push_back(s[i]);
            }
        }
        
        return stack.empty();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << Solution().isValid("}{(({}))") << endl;
    return 0;
}
