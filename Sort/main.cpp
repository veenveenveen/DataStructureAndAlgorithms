//
//  main.cpp
//  Sort
//
//  Created by 黄启明 on 2018/10/23.
//  Copyright © 2018 Himin. All rights reserved.
//

/*
  排序
  插入排序、选择排序、冒泡排序、梳排序
  快速排序、希尔排序、基数排序、桶排序、归并排序、计数排序
 */

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
    // 插入排序
    void insertionSort(vector<int> &nums) {
        for (int i = 1,j; i < nums.size(); i++) {
            int tmp = nums[i];
            for (j = i; j > 0 && tmp < nums[j-1]; j--) {
                nums[j] = nums[j-1];
            }
            nums[j] = tmp;
        }
    }
    
    // 选择排序
    void selectionSort(vector<int> &nums) {
        int n = int(nums.size());
        for (int i = 0; i < n-1; i++) {
            int p = i;
            for (int j = i+1; j < n; j++) {
                if (nums[j] < nums[p]) {
                    p = j;
                }
            }
            if (i != p) {
                swap(nums[i], nums[p]);
            }
        }
    }
    
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
    
    // 希尔排序
    void shellSort(vector<int> &nums) {
        int step = 3;// 设定步长
        int h = 1;
        while (h*step < nums.size()) {
            h = h * step + 1;
        }
        while (h >= 1) {
            for (int i = 1; i < nums.size(); i++) {
                for (int j = i; j-h >= 0 && nums[j-h] > nums[j] ; j = j-h) {
                    swap(nums[j-h], nums[j]);
                }
            }
            h = h / step;
        }
    }
    
    // 快速排序
    int partition(vector<int> &nums, int low, int high) {
        int key = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= key) {
                high--;
            }
            nums[low] = nums[high];
            while (low < high && nums[low] <= key) {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = key;
        return low;
    }
    void quickSort(vector<int> &nums, int low, int high) {
        if (low < high) {
            int tmp = partition(nums, low, high);
            cout << "tmp == " << tmp << endl;
            quickSort(nums, low, tmp-1);
            quickSort(nums, tmp+1, high);
        }
    }
    
    // 归并排序
    void mergeTwo(vector<int> &nums, int first, int mid, int last) {
        vector<int> tmp(last-first+1);
        int i = first, j = mid+1, k = 0;
        while (i <= mid && j <= last ) {
            if (nums[i] < nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= last) {
            tmp[k++] = nums[j++];
        }
        i = first;
        k = 0;
        while (k < tmp.size()) {
            nums[i++] = tmp[k++];
        }
    }
    void mergeSort(vector<int> &nums, int first, int last) {
        if (first < last) {
            int mid = first+(last-first)/2;
            mergeSort(nums, first, mid);
            mergeSort(nums, mid+1, last);
            mergeTwo(nums, first, mid, last);
        }
    }
    
    int Add(int num1, int num2) {
        int sum=0;
        int a=0;
        do {
            sum=num1^num2;  //不进位的结果
            a=(num1&num2)<<1;  //只进位的结果
            num1=sum;
            num2=a;
        } while(num2!=0);
        return num1;
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
//    Solution().insertionSort(nums);
//    Solution().selectionSort(nums);
//    Solution().bubbleSort(nums);
//    Solution().shellSort(nums);
//    Solution().quickSort(nums, 0, int(nums.size())-1);
    Solution().mergeSort(nums, 0, int(nums.size())-1);
    

    printVector("sort", nums);
    
    cout << "sum = " << Solution().Add(43, 30) << endl;
    
    return 0;
}
