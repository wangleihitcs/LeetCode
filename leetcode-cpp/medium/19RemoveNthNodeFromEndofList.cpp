//
//  19RemoveNthNodeFromEndofList.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/1.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n)，空间复杂度O(1)，4ms，8.5MB
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* p1_par = NULL;
        while(n--) {
            p2 = p2 ->next;
        }
        while(p2 != NULL) {
            p1_par = p1;
            p1 = p1 ->next;
            p2 = p2 ->next;
        }
        if(p1 == head) return head ->next;
        if(p1 != NULL)
            p1_par ->next = p1 ->next;
        return head;
    }
};

int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    p1 ->next = p2;
    p2 ->next = p3;
    p3 ->next = p4;
    p4 ->next = p5;
    
    Solution s;
    ListNode* res = s.removeNthFromEnd(p1, 1);
    while(res != NULL) {
        cout << res ->val << " ";
        res = res ->next;
    }
    cout << endl;
}
