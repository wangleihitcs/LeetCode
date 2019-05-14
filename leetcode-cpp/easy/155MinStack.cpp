//
//  155MinStack.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/4.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

//方法一、双栈，时间复杂度O(n)，空间复杂度O(n)，36ms，16.9MB
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(s1.empty()) {
            s2.push(x);
        } else {
            if(s2.top() > x) {
                s2.push(x);
            } else {
                s2.push(s2.top());
            }
        }
        s1.push(x);
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};
