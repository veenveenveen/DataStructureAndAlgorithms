//
//  main.cpp
//  MergeTwoSortedLists
//
//  Created by 黄启明 on 2018/10/19.
//  Copyright © 2018 Himin. All rights reserved.
//

/*
 Merge Two Sorted Lists
 DescriptionHintsSubmissionsDiscussSolution
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 
 Example:
 
 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        ListNode *resList = new ListNode(0);
        ListNode *currNode = resList;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                currNode->next = l2;
                break;
            }
            if (l2 == NULL) {
                currNode->next = l1;
                break;
            }
            if (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    currNode->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    currNode->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
                currNode = currNode->next;
            }
        }
        
        return resList->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);
    
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);
    l2->next->next->next = new ListNode(7);
    
    ListNode *l = Solution().mergeTwoLists(l1, l2);
    
    while (l != NULL) {
        cout << l->val << "->";
        l = l->next;
    }
    
    std::cout << endl;
    
    return 0;
}
