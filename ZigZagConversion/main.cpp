//
//  main.cpp
//  ZigZagConversion
//
//  Created by 黄启明 on 2018/10/18.
//  Copyright © 2018 Himin. All rights reserved.
//

/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 */

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int rows = min(numRows, int(s.length()));
        vector<string> strArr(rows);
        int curRow = 0;
        bool goingDown = false;
        for (char c : s) {
            strArr[curRow] += c;
            if (curRow == 0 || curRow == numRows-1) {
                goingDown = ! goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }
        
        string resStr;
        for (string str : strArr) {
            resStr += str;
        }
        
        return resStr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution solution;
    std::cout << solution.convert("PAYPALISHIRING", 4) << endl;
    return 0;
}
