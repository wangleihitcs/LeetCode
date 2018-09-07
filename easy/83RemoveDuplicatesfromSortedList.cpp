//
//  83RemoveDuplicatesfromSortedList.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/9/7.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // O(n), accepted
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* newHead = new ListNode(head ->val);
        ListNode* p = newHead;
        while(head ->next != NULL) {
            if(head ->next ->val != p ->val) {
                ListNode* temp = new ListNode(head ->next ->val);
                p ->next = temp;
                p = p ->next;
            }
            head = head ->next;
        }
        return newHead;
    }
    
    void display(ListNode* head) {
        while(head != NULL) {
            cout << head ->val << " ";
            head = head ->next;
        }
        cout << endl;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* body1 = new ListNode(2);
    ListNode* body2 = new ListNode(3);
    ListNode* body3 = new ListNode(4);
    head ->next = body1;
    body1 ->next = body2;
    body2 ->next = body3;
    
    Solution s;
    s.display(head);
    ListNode* result = s.deleteDuplicates(head);
    s.display(result);
    
}
