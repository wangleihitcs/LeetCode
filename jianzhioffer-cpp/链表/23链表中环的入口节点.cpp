//
//  23entryNodeOfLoop.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/4.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //方法一、暴力枚举，借助一个指针数组，时间复杂度O(n^2)，空间复杂度O(n)
    //因为是单向链表，存在环必须是最后一个节点指向前面的节点，则该节点为环入口节点
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        
        vector<ListNode*> v;
        ListNode* p = pHead;
        v.push_back(p);
        while(p ->next != NULL) {
            v.push_back(p);
            p = p ->next;
            if(isExsit(v, p)) {
                return p;
            }
        }
        
        return NULL;
    }
    bool isExsit(vector<ListNode*>& v, ListNode* node) {//时间复杂度O(n)
        for(int i = 0; i < v.size(); i++) {
            if(node == v[i]) return true;
        }
        return false;
    }
    
    //方法二、双指针
    ListNode* EntryNodeOfLoop2(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        return NULL;
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
//    h6 ->next = h1;

    Solution s;
    if(s.EntryNodeOfLoop(h1) == NULL) {
        cout << "No Loop" << endl;
    } else {
        cout << s.EntryNodeOfLoop(h1) ->val << endl;
    }
}
