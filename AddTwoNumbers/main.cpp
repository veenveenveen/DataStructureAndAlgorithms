//
//  main.cpp
//  AddTwoNumbers
//
//  Created by 黄启明 on 2018/10/17.
//  Copyright © 2018 Himin. All rights reserved.
//

/*单链表
  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
  Explanation: 342 + 465 = 807.
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode *addTwoSum(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = res;
        int carry = 0;
        
        while (p != NULL || q != NULL) {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            
            if (p != NULL) {
                p = p -> next;
            }
            if (q != NULL) {
                q = q -> next;
            }
        }
        
        if (carry > 0) {
            curr -> next = new ListNode(carry);
        }
        
        return res->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(8);
    l1->next->next = new ListNode(9);
    
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(8);
    l2->next->next = new ListNode(7);
    
    {
        ListNode *p = l1, *q = l2;
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
        
        while (q != NULL) {
            cout << q->val << " ";
            q = q->next;
        }
        cout << endl;
    }
    
    Solution solution;
    ListNode *res = solution.addTwoSum(l1, l2);
    
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    
    cout << endl;
    
    return 0;
}
