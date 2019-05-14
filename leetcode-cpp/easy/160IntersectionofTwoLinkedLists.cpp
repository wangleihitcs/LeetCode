//
//  160IntersectionofTwoLinkedLists.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/7.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //方法一、暴力，时间复杂度O(mn)，空间复杂度O(1)，800ms，16.7MB
    //A、B一个一个节点比较
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA, *pb;
        while(pa != NULL) {
            pb = headB;
            while(pb != NULL) {
                if(pa == pb) return pa;
                pb = pb ->next;
            }
            pa = pa ->next;
        }
        return NULL;
    }
    
    //方法二、哈希的思想，时间复杂度O(m+n)，空间复杂度O(m)或O(n)，68ms，20.1MB
    //借助一个数组
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA, *pb = headB;
        set<ListNode*> s;
        while(pa != NULL) {
            s.insert(pa);
            pa = pa ->next;
        }
        while(pb != NULL) {
            if(s.count(pb) != 0) {
                return pb;
            } else {
                pb = pb ->next;
            }
        }
        return NULL;
    }
    
    //方法三、双指针，时间复杂度O(m+n)，空间复杂度O(1)，52ms，16.9MB
    //因为没有环
    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA, *pb = headB;
        while(pa != pb) {
            pa = (pa != NULL) ? pa ->next : headB;
            pb = (pb != NULL) ? pb ->next : headA;
        }
        return pa;
    }
};
