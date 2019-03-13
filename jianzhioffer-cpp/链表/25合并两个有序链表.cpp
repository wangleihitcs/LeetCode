//
//  25mergeSortedList.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/11.
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
    //方法一、暴力法，借助一个链表，时间复杂度O(m+n)，空间复杂度O(mn)
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* res = new ListNode(-1);
        ListNode* p = res;
        
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        
        while(p1 != NULL && p2 != NULL) {
            if(p1 ->val < p2 ->val) {
                ListNode* temp = new ListNode(p1 ->val);
                p ->next = temp;
                p = p ->next;
                p1 = p1 ->next;
            } else {
                ListNode* temp = new ListNode(p2 ->val);
                p ->next = temp;
                p = p ->next;
                p2 = p2 ->next;
            }
        }
        while(p1 != NULL) {
            ListNode* temp = new ListNode(p1 ->val);
            p ->next = temp;
            p = p ->next;
            p1 = p1 ->next;
        }
        while(p2 != NULL) {
            ListNode* temp = new ListNode(p2 ->val);
            p ->next = temp;
            p = p ->next;
            p2 = p2 ->next;
        }
        
        return res ->next;
    }
    
    //方法一、直接解，借助一个链表，时间复杂度O(m+n)，空间复杂度O(1)
    //前提是两个链表没有公共部分
    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2) {
        ListNode* res = new ListNode(-1);
        ListNode* p = res;
        
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        
        while(p1 != NULL && p2 != NULL) {
            if(p1 ->val < p2 ->val) {
                p ->next = p1;
                p = p ->next;
                p1 = p1 ->next;
            } else {
                p ->next = p2;
                p = p ->next;
                p2 = p2 ->next;
            }
        }
        while(p1 != NULL) {
            p ->next = p1;
            p = p ->next;
            p1 = p1 ->next;
        }
        while(p2 != NULL) {
            p ->next = p2;
            p = p ->next;
            p2 = p2 ->next;
        }
        
        return res ->next;
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
    
    ListNode* h11 = new ListNode(-1);
    h11 ->next = h2;
    
    Solution s;
    ListNode* res = s.Merge2(h1, h11);
    while(res != NULL) {
        cout << res ->val << " ";
        res = res ->next;
    }
    cout << endl;
}
