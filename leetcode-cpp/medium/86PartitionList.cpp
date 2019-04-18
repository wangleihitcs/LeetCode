//
//  86PartitionList.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/13.
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
    //方法一、借助一个数组，使用双指针进行划分，时间复杂度O(n)，空间复杂度O(n)
    
    //方法二、双指针直接做，时间复杂度O(n)，空间复杂度O(1)
    //注意，这只是完成划分功能，不合题意，题意要求划分后两个部分相对位置不变
    ListNode* partition(ListNode* head, int x) {
        ListNode* find_small = head, * find_big = head;
        while(find_small != NULL && find_small ->val < x) {
            find_small = find_small ->next;
            find_big = find_big ->next;
        }
        while(find_small != NULL && find_big != NULL) {
            while(find_small != NULL && find_small ->val >= x) {
                find_small = find_small ->next;
            }
            while(find_big != NULL && find_big ->val < x) {
                find_big = find_big ->next;
            }
            if(find_small != NULL && find_big != NULL) {
                swap(find_small ->val, find_big ->val);
                find_small = find_small ->next;
                find_big = find_big ->next;
            }
        }
        return head;
    }
    
    //方法二、双链表，时间复杂度O(n)，空间复杂度O(1)，12ms，8.7MB
    //思路很简单，让小于x的节点z和大于等于x的节点分别放置在两个链表中，最后再合一起
    ListNode* partition2(ListNode* head, int x) {
        ListNode* before_head = new ListNode(0);
        ListNode* after_head = new ListNode(0);
        ListNode* before = before_head;
        ListNode* after = after_head;
        while(head != NULL) {
            if(head ->val < x) {
                before ->next = head;
                before = before ->next;
            } else {
                after ->next = head;
                after = after ->next;
            }
            head = head ->next;
        }
        after ->next = NULL;
        before ->next = after_head ->next;
        return before_head ->next;
    }
};

int main() {
    
}
