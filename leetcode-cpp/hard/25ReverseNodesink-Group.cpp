//
//  25ReverseNodesink-Group.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/30.
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
    //方法一、时间复杂度O(n)，空间复杂度O(1)，20ms，9.8MB
    //-1 -> 1 -> 2 -> 3 -> 4 -> 5
    // |    |    |    |
    //pre  cur  nex  tmp
    
    //-1 -> 2 -> 1 -> 3 -> 4 -> 5
    // |         |    |    |
    //pre       cur  nex  tmp
    
    //-1 -> 3 -> 2 -> 1 -> 4 -> 5
    // |              |    |    |
    //pre            cur  nex  tmp
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) return head;
        int num = 0;
        ListNode *preheader = new ListNode(-1);
        preheader->next = head;
        ListNode *cur = preheader, *nex, *tmp, *pre = preheader;
        while(cur = cur ->next)
            num++;
        
        while(num >= k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;i++) {
                tmp= nex->next;
                nex->next = pre->next;
                pre->next = nex;
                cur->next = tmp;
                nex = tmp;
            }
            pre = cur;
            num -= k;
        }
        return preheader->next;
    }
};

int main() {
    
}
