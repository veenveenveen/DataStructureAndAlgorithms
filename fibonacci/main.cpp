//
//  main.cpp
//  fibonacci
//
//  Created by 黄启明 on 2018/10/17.
//  Copyright © 2018 Himin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// 返回数组
vector<uint64_t> fibonaccis(int n) {
    if (n <= 0) {
        vector<uint64_t> fibs{0};
        return fibs;
    }
    vector<uint64_t> fibs(n,1);
    if (n == 1 || n == 2) { return fibs; }
    for (int i = 2; i < n; i++) {
        fibs[i] = fibs[i-2] + fibs[i-1];
    }
    return fibs;
}

// 返回第n个数
int fibonacci(int n) {
    if (n <= 0) { return 0; }
    if (n == 1 || n == 2) { return 1; }
    int f1 = 1;
    int f2 = 1;
    for (int i = 3; i <= n; i++) {
        int temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
    return f2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << fibonacci(47) << std::endl; // uint
    std::cout << fibonacci(46) << std::endl;
    
    int n = 94;
    vector<uint64_t> fibs = fibonaccis(n);
    
    for (int i = 0; i < n; i++) {
        cout << fibs[i] << " ";
    }
    
    cout << endl;
    cout << UINT8_MAX;
    return 0;
}
