//
//  main.cpp
//  CountAndSay
//
//  Created by 黄启明 on 2018/10/22.
//  Copyright © 2018 Himin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) { return ""; }
        string res = "1";
        for (int i = 1; i < n; i++) {
            string cur = "";
            for (int j = 0; j < res.length(); j++) {
                int count = 1;
                while (j+1 < res.length() && res[j+1] == res[j]) {
                    count++;
                    j++;
                }
                cur += to_string(count) + res[j];
            }
            res = cur;
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << Solution().countAndSay(10) << endl;
    return 0;
}
