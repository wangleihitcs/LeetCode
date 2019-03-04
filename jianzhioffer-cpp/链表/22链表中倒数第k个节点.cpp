//
//  22findKthToTail.cpp
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
    //方法一、借助一个指针数组，时间复杂度O(n)，空间复杂度O(n)
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k == 0) return NULL;
        
        vector<ListNode*> v;
        ListNode* p = pListHead;
        while(p != NULL) {
            v.push_back(p);
            p = p ->next;
        }
        if(k > v.size()) return NULL;
        else {
            return v[v.size()-k];
        }
            
        return NULL;
    }
    
    //方法二、双指针
    ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k == 0) return NULL;
        
        ListNode* right = pListHead;
        ListNode* left = NULL;
        for(int i = 1; i <= k-1; i++) {
            if(right ->next != NULL) {
                right = right ->next;
            } else {
                return NULL;
            }
        }
        left = pListHead;
        while (right ->next != NULL) {
            right = right ->next;
            left = left ->next;
        }
        
        return left;
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
    
    cout << s.FindKthToTail(h1, 5) ->val << endl;
    
}
