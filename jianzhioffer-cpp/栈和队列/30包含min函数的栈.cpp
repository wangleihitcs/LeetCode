//
//  30minStack.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/13.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        if(stack1.empty()) {
            stack1.push(value);
            stack2.push(value);
        } else {
            stack1.push(value);
            if(value < stack2.top()) {
                stack2.push(value);
            } else {
                stack2.push(stack2.top());
            }
        }
    }
    void pop() {
        if(!stack1.empty()) {
            stack1.pop();
            stack2.pop();
        }
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(1);
    cout << s.min() << endl;
    
}

