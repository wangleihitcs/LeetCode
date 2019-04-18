//
//  82RemoveDuplicatesfromSortedListII.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/11.
//  Copyright © 2019 wanglei. All rights reserved.
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
    //方法一、借助额外空间，时间复杂度O(n)，空间复杂度O(n)，16ms，9.2MB
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        if(head ->next == NULL) return head;
        ListNode* res = new ListNode(-1);
        ListNode* p = res;
        
        ListNode* pre = head;
        ListNode* cur = head ->next;
        if(pre ->val != cur ->val) {
            ListNode* temp = new ListNode(pre ->val);
            p ->next = temp;
            p = p ->next;
        }
        while(cur ->next != NULL) {
            if(pre ->val != cur ->val && cur ->val != cur ->next ->val) {
                ListNode* temp = new ListNode(cur ->val);
                p ->next = temp;
                p = p ->next;
            }
            pre = cur;
            cur = cur ->next;
        }
        if(pre ->val != cur ->val) {
            ListNode* temp = new ListNode(cur ->val);
            p ->next = temp;
            p = p ->next;
        }
        return res ->next;
    }
    
    //方法二、原地，时间复杂度O(n)，空间复杂度O(1)，8ms，9MB
    ListNode* deleteDuplicates2(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* res = new ListNode((long long)head->val-1), *ptr = res, *pre = res;
        while(head != NULL) {
            if(pre->val != head->val && (head->next == NULL || head->next->val != head->val )) {
                ptr ->next = head;
                ptr = ptr->next;
            }
            pre = head;
            head = head ->next;
        }
        ptr ->next = NULL;
        return res ->next;
    }
};
