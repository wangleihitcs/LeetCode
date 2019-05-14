//
//  206ReverseLinkedList.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/12.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <stdio.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    //方法一、原地做，时间复杂度O(n)，空间复杂度O(1)，4ms，9.4MB
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* pre = NULL, *cur = head;
        while(cur != NULL) {
            ListNode* temp = cur ->next;
            cur ->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    
    //方法二、递归，时间复杂度O(n)，空间复杂度O(n)，4ms，9.4MB
    ListNode* reverseList2(ListNode* head) {
        if(head == NULL || head ->next == NULL) return head;
        ListNode* p = reverseList2(head ->next);
        head ->next ->next = head;
        head ->next = NULL;
        return p;
    }
};


