//
//  24SwapNodesinPairs.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/2.
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
    //方法一、暴力，时间复杂度O(n)，空间复杂度O(1)，4ms，8.6MB
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = new ListNode(-1);
        res ->next = head;
        ListNode* par = res;
        while(head && head ->next) {
            ListNode* temp = head ->next ->next;
            par ->next = head ->next;
            head ->next ->next = head;
            head ->next = temp;
            par = head;
            head = temp;
        }
        return res ->next;
    }
};

int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    ListNode* p6 = new ListNode(6);
    p1 ->next = p2;
    p2 ->next = p3;
    p3 ->next = p4;
    p4 ->next = p5;
    p5 ->next = p6;
    
    Solution s;
    ListNode* res = s.swapPairs(p1);
    while(res != NULL) {
        cout << res ->val << " ";
        res = res ->next;
    }
    cout << endl;
}
