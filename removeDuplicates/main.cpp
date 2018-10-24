//
//  main.cpp
//  removeDuplicates
//
//  Created by 黄启明 on 2018/10/19.
//  Copyright © 2018 Himin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        int i = 0;
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        for (int a : nums) {
            cout << a << " ";
        }
        
        return i+1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums{1,1,2,2,4,5,6,7,8};
    std::cout << "count = " << Solution().removeDuplicates(nums);
    return 0;
}
