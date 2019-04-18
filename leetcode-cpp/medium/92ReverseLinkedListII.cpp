//
//  92ReverseLinkedListII.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/17.
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
    //方法一、借助数组，时间复杂度O(n)，空间复杂度O(n)
    
    //方法二、逆转链表，时间复杂度O(n)，空间复杂度O(1)，8ms，8.5MB
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL) return head;
        ListNode* cur = head, * pre = NULL;
        while(m > 1) {
            pre = cur;
            cur = cur ->next;
            m--;
            n--;
        }
        ListNode* con = pre, * tail = cur;
        ListNode* third = NULL;
        while(n > 0) {
            third = cur ->next;
            cur ->next = pre;
            pre = cur;
            cur = third;
            n--;
        }
        if(con != NULL) {
            con ->next = pre;
        } else {
            head = pre;
        }
        tail ->next = cur;
        return head;
    }
};

int main() {
    
}
