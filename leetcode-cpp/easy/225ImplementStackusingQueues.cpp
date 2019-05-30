//
//  225ImplementStackusingQueues.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/30.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

//4ms, 8.9MB
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for(int i = 0; i < q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q;
};
