//
//  6printListFromTailToHead.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/2/28.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n)，空间复杂度O(1)，3ms，504k
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head == NULL) return res;
        
        ListNode* p = head;
        while(p != NULL) {
            res.insert(res.begin(), p ->val);
            p = p ->next;
        }
        return res;
    }
    
    //方法二、使用栈，时间复杂度O(n)，空间复杂度O(1)
    vector<int> printListFromTailToHead2(ListNode* head) {
        vector<int> res;
        if(head == NULL) return res;
        
        stack<ListNode*> st;
        ListNode* p = head;
        while(p != NULL) {
            st.push(p);
            p = p ->next;
        }
        
        while(!st.empty()) {
            res.push_back(st.top() ->val);
            st.pop();
        }
        return res;
    }
    
    //方法三、递归，时间复杂度O(n)，空间复杂度O(1)
    void printListFromTailToHead3(ListNode* head) {
        if(head != NULL) {
            if(head ->next != NULL) {
                printListFromTailToHead3(head ->next);
            }
            cout << head ->val << " ";
        }
    }
};

int main() {
    ListNode* h1 = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    h1 ->next = h2;
    ListNode* h3 = new ListNode(3);
    h2 ->next = h3;
    
    Solution s;
    vector<int> res = s.printListFromTailToHead2(h1);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    s.printListFromTailToHead3(h1);
    cout << endl;
}
