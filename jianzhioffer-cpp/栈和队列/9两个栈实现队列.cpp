
//
//  9twoStacks.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/1.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <stack>
#include <exception>
using namespace std;

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }
    int pop() {
        if(stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty()) cout << "queue is empty" << endl;
        int node = stack2.top();
        stack2.pop();
        return node;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
}
