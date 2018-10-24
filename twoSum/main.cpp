//
//  main.cpp
//  twoSum
//
//  Created by 黄启明 on 2018/10/17.
//  Copyright © 2018 Himin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int>twoSum(vector<int> &nums, int target) {
        map<int,int> mapping;
        vector<int> result;
        int len = int(nums.size());
        for (int i = 0; i < len; i++) {
            mapping[nums[i]] = i;
        }
        for (int j = 0; j < len; j++) {
            int searched = target - nums[j];
            if (mapping.find(searched) != mapping.end() && j != nums[searched]) {
                result.push_back(j);
                result.push_back(mapping[searched]);
                break;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> test{1,3,4,5,6};
    Solution solution;
    vector<int> res = solution.twoSum(test, 7);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] <<" ";
    }
    
    cout << endl;
    
    return 0;
}
