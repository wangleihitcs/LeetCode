//
//  61RotateList.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/7.
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
    //方法一、暴力，时间复杂度O(n)，空间复杂度O(1)，8ms，9MB
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* p = head;
        int num = 1;
        while(p ->next != NULL) {
            num++;
            p = p ->next;
        }
        k = k % num;
        ListNode* s = head;
        ListNode* s_k = head;
        while(k >= 1) {
            s_k = s_k ->next;
            k--;
        }
        while(s_k ->next!= NULL) {
            s = s ->next;
            s_k = s_k ->next;
        }
        s_k ->next = head;
        head = s ->next;
        s ->next = NULL;
        return head;
    }
};

int main() {
    ListNode* h1 = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(3);
    ListNode* h4 = new ListNode(4);
    ListNode* h5 = new ListNode(5);
    h1 ->next = h2;
    h2 ->next = h3;
    h3 ->next = h4;
    h4 ->next = h5;
    
    Solution s;
    ListNode* res = s.rotateRight(h1, 5);
    while(res != NULL) {
        cout << res ->val << " ";
        res = res ->next;
    }
    cout << endl;
}
