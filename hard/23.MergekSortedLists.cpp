//
//  23.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/9/28.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    //方法一: O([mn]^2), 纯暴力，借助一个数组，排序，再构造链表，最简单的方法，但是time limit
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        //1. get all element to v, O(mn)
        vector<ListNode*>::iterator it;
        for(it = lists.begin(); it != lists.end(); it++) {
            ListNode* p = *(it);
            while(p != NULL) {
                v.push_back(p ->val);
                p = p ->next;
            }
        }
        //2. sort v, O([mn]^2)
        for(int i = 0; i < v.size()-1; i++) {
            for(int j = i+1; j < v.size(); j++) {
                if(v[j] < v[i]) {
                    int temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
        //3. make new link, O(mn)
        ListNode* result = new ListNode(v[0]);
        ListNode* p = result;
        for(int i = 1; i < v.size(); i++) {
            ListNode* temp = new ListNode(v[i]);
            p ->next = temp;
            p = p ->next;
        }
        
        return result;
    }
    
    //方法二: O([m*mn], 借助一个数组，再遍历链表时排序，time limit, 如果me很大，很耗时
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        //0.这个判断输入是否空
        if(lists.size() == 0) return 0;
        int input_flag = 0;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                input_flag = 1;
                break;
            }
        }
        if(input_flag == 0) return 0;
        
        //1.借助一个数组终止循环, O(m)
        vector<int> flag;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] == NULL) {
                flag.push_back(0);
            } else {
                flag.push_back(1);
            }
        }
        
        //2.逐个找出最小值，放入数组v, O(m*mn)
        vector<int> v;
        while(!isAllZero(flag)) {
            int min = 2^31-1;
            int index = 0;
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] == NULL) {
                    flag[i] = 0;
                }
                if(flag[i] == 1 && lists[i] ->val < min) {
                    min = lists[i] ->val;
                    index = i;
                }
            }
            v.push_back(min);
//            cout << min << " ";
            if(lists[index] != NULL)
                lists[index] = lists[index] ->next;
        }
        
        //3.遍历数组v，构建链表, O(mn)
        ListNode* result = new ListNode(v[0]);
        cout << v[0] << " ";
        ListNode* p = result;
        for(int i = 1; i < v.size()-1; i++) {
            cout << v[i] << " ";
            ListNode* temp = new ListNode(v[i]);
            p ->next = temp;
            p = p ->next;
        }
        cout << endl;
        
        return result;
    }
    bool isAllZero(vector<int> v) {
        bool all_zero = true;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == 1) {
                all_zero = false;
                break;
            }
        }
        return all_zero;
    }
    
    //方法二改: O(mn), 遍历链表时排序
    ListNode* mergeKLists3(vector<ListNode*>& lists) {
        //0.这个判断输入是否空
        if(lists.size() == 0) return 0;
        int input_flag = 0;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                input_flag = 1;
                break;
            }
        }
        if(input_flag == 0) return 0;
        
        bool flag = true;
        ListNode* p = new ListNode(-1);
        ListNode* result = p;
        //逐个找出最小值，O(mn)
        while(flag) {
            int min = 100000;
            int index = 0;
            flag = false;
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] != NULL) {
                    flag = true;
                }
                if(lists[i] != NULL && lists[i] ->val < min) {
                    min = lists[i] ->val;
                    index = i;
                }
            }
            if(min != 100000) {
                ListNode* temp = new ListNode(min);
                p ->next = temp;
                p = p ->next;
//                cout << min << " ";
                if(lists[index] != NULL)
                    lists[index] = lists[index] ->next;
            }
        }
        result = result ->next;
        while(result != NULL) {
            cout << result ->val << " ";
            result = result ->next;
        }
        cout << endl;
        return result;
    }
    
};

int main() {
    ListNode* list1 = new ListNode(1);
    ListNode* l11 = new ListNode(4);
    ListNode* l12 = new ListNode(5);
    list1 ->next = l11;
    l11 ->next = l12;
    
    ListNode* list2 = new ListNode(1);
    ListNode* l21 = new ListNode(3);
    ListNode* l22 = new ListNode(4);
    list2 ->next = l21;
    l21 ->next = l22;
    
    ListNode* list3 = new ListNode(2);
    ListNode* l31 = new ListNode(6);
    list3 ->next = l31;
    
    vector<ListNode*> lists = {list1, list2, list3};
    Solution so;
    so.mergeKLists3(lists);
    
}
