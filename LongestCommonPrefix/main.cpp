//
//  main.cpp
//  LongestCommonPrefix
//
//  Created by 黄启明 on 2018/10/19.
//  Copyright © 2018 Himin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) { return ""; }
        string res = strs[0];
        for (int i = 1; i < int(strs.size()); i++) {
            if (strs[i][0] != res[0]) {
                return "";
            }
            while (strs[i].find(res) != 0) {
                cout << strs[i].find(res) << endl;
                res = string(res,0,res.length()-1);
                if (res.empty()) {
                    return "";
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    vector<string> strs;
    strs.push_back("asd");
    strs.push_back("aasd");
    strs.push_back("add");
    strs.push_back("aaasd");
    
    std::cout << "longestCommonPrefix = " + solution.longestCommonPrefix(strs) + "\n";
    return 0;
}
