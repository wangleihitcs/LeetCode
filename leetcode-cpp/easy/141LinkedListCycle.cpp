//
//  141LinkedListCycle.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/3.
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
    //方法一、哈希，时间复杂度O(n)，空间复杂度O(n)，36ms，16.3MB
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        while (head != NULL) {
            if(s.count(head) == 1) {
                return true;
            }
            s.insert(head);
            head = head ->next;
        }
        return false;
    }
    
    //方法二、快慢双指针，时间复杂度O(n)，空间复杂度O(1)，28ms，9.8MB
    bool hasCycle2(ListNode *head) {
        ListNode* slow, * fast;
        slow = fast = head;
        while(fast && fast ->next) {
            fast = fast ->next ->next;
            slow = slow ->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};



