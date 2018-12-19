//
//  main.cpp
//  ReverseString
//
//  Created by 黄启明 on 2018/10/25.
//  Copyright © 2018 Himin. All rights reserved.
//
/*
 Write a function that takes a string as input and returns the string reversed.
 
 Example 1:
 
 Input: "hello"
 Output: "olleh"
 Example 2:
 
 Input: "A man, a plan, a canal: Panama"
 Output: "amanaP :lanac a ,nalp a ,nam A"
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i = 0, len = int(s.length());
        while (i < len) {
            swap(s[i++], s[(len--)-1]);
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << Solution().reverseString("hello world!") << endl;
    return 0;
}
