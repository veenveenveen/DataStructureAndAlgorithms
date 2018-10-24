//
//  main.cpp
//  Sort
//
//  Created by 黄启明 on 2018/10/23.
//  Copyright © 2018 Himin. All rights reserved.
//

/*
  排序
 */

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
    // 冒泡排序
    void bubbleSort(vector<int> &nums) {
        int len = int(nums.size());
        for (int i = 0; i <len-1; i++) {
            bool flag = true;
            for (int j = 0; j < len-i-1; j++) {
                if (nums[j] > nums[j+1]) {
                    flag = false;
                    swap(nums[j], nums[j+1]);
                }
            }
            if (flag) {
                break;
            }
        }
    }
};

void printVector(string name, vector<int> &nums) {
    cout << name + ": ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {

    vector<int> nums{4,6,3,10,12,2,8,1,9};
    Solution().bubbleSort(nums);
    
    printVector("bubble sort", nums);
    return 0;
}
