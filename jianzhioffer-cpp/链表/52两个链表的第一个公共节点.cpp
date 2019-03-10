//
//  52findFirstCommonNode.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/10.
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
    //方法一、精巧解法，时间复杂度O(m+n)，空间复杂度O(1)
    //求两个链表公共节点，则两链表必须从尾巴至公共节点相等
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL) return NULL;
        int m = getListLength(pHead1);
        int n = getListLength(pHead2);
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        if(m == n && p1 == p2) return p1;
        if(m == n && p1 != p2) return NULL;
        else if(m > n) {
            int l = m - n;
            while(l > 0) {
                p1 = p1 ->next;
                l--;
            }
            while(p1 != p2) {
                p1 = p1 ->next;
                p2 = p2 ->next;
            }
        } else {
            int l = n - m;
            while(l > 0) {
                p2 = p2 ->next;
                l--;
            }
            while(p1 != p2) {
                p1 = p1 ->next;
                p2 = p2 ->next;
            }
        }
        return p1;
    }
    int getListLength(ListNode* pHead) {
        int length = 0;
        ListNode* p = pHead;
        while(p != NULL) {
            length++;
            p = p ->next;
        }
        return length;
    }
};

int main() {
    ListNode* h1 = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    h1 ->next = h2;
    ListNode* h3 = new ListNode(3);
    h2 ->next = h3;
    ListNode* h4 = new ListNode(4);
    h3 ->next = h4;
    ListNode* h5 = new ListNode(5);
    h4 ->next = h5;
    ListNode* h6 = new ListNode(6);
    h5 ->next = h6;
    
    Solution s0;
    ListNode* x = s0.FindFirstCommonNode(h1, h1);
    cout << x ->val << endl;
}
