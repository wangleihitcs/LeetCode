//
//  24reverseList.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/10.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //方法一、借助栈，时间复杂度O(n)，空间复杂度O(n)
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        stack<ListNode*> s;
        ListNode* p = pHead;
        while(p != NULL) {
            s.push(p);
            p = p ->next;
        }
        ListNode* newHead = s.top();
        s.pop();
        p = newHead;
        while(!s.empty()) {
            p ->next = s.top();
            s.pop();
            p = p ->next;
        }
        p ->next = NULL;
        return newHead;
    }
    
    //方法二、直接解，时间复杂度O(n)，空间复杂度O(1)
    ListNode* ReverseList2(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        if(pHead ->next == NULL) return pHead;
        ListNode* newHead = NULL;
        ListNode* p = pHead;
        ListNode* par = NULL;
        while(p != NULL) {
            ListNode* pNext = p ->next;
            if(p ->next == NULL) newHead = p;
            
            p ->next = par;
            par = p;
            p = pNext;
        }
        return newHead;
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
    
    Solution s;
    ListNode* res = s.ReverseList2(h1);
    
    while(res != NULL) {
        cout << res ->val << " ";
        res = res ->next;
    }
    cout << endl;
}
