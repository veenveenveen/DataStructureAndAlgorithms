//
//  main.cpp
//  SearchInsetPosition
//
//  Created by 黄启明 on 2018/10/22.
//  Copyright © 2018 Himin. All rights reserved.
//

/*
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 
 You may assume no duplicates in the array.
 
 Example 1:
 
 Input: [1,3,5,6], 5
 Output: 2
 Example 2:
 
 Input: [1,3,5,6], 2
 Output: 1
 Example 3:
 
 Input: [1,3,5,6], 7
 Output: 4
 Example 4:
 
 Input: [1,3,5,6], 0
 Output: 0
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int low = 0, high = int(nums.size())-1;
        int mid = 0;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (target < nums[mid]) {
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return high + 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums{1,2,5,7,9};
    std::cout << Solution().searchInsert(nums, 4) << endl;
    return 0;
}
