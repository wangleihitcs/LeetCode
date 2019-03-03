//
//  18deleteNode.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/3.
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
    //在O(1)时间内删除指定节点
    void deleteNode(ListNode* head, ListNode* node) {
        if(head == NULL || node == NULL) return;
//        if(head ->next == NULL) head = NULL;
        //1.待删除节点不是尾节点
        if(node ->next != NULL) {
            node ->val = node ->next ->val;
            node ->next = node ->next ->next;
        } else {//2.带删除节点是尾节点
            ListNode *p = head;
            while (p != NULL) {
                if(p ->next == node) {
                    break;
                }
                p = p ->next;
            }
            p ->next = NULL;
        }
        
    }
    
    //删除所有具有重复元素的节点
    //如1-1-2-3-4-5-5 ==》2-3-4
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        if(pHead ->next == NULL) return pHead;
        
        ListNode* newHead = new ListNode(-1);
        ListNode* pNew = newHead;
        
        ListNode* left = pHead;
        ListNode* right = pHead;
        while(right != NULL) {
            if(right ->next != NULL && right ->val == right ->next ->val) {
                right = right ->next;
            } else if(right == left && left != NULL) {
                ListNode* temp = new ListNode(left ->val);
                pNew ->next = temp;
                pNew = pNew ->next;
                
                left = right ->next;
                right = right ->next;
            } else {
                left = right ->next;
                right = right ->next;
            }
            
        }
        
        return newHead ->next;
    }
};

int main() {
    Solution s;
    
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

    ListNode* res = s.deleteDuplication(h1);
    while(res != NULL) {
        cout << res ->val << " ";
        res = res ->next;
    }
    cout << endl;
    
    s.deleteNode(h1, h6);
    ListNode* p = h1;
    while(p != NULL) {
        cout << p ->val << " ";
        p = p ->next;
    }
    cout << endl;
}
