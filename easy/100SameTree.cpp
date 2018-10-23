//
//  100SameTree.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/10/23.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一、O(n), 递归比较
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        }
        if(p == NULL || q == NULL) {
            return false;
        }
        if(p ->val != q ->val) {//比较结点的值
            return false;
        }
        bool isLeftSame = isSameTree(p ->left, q ->left);
        bool isRightSame = isSameTree(p ->right, q ->right);
        if(isLeftSame && isRightSame) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    TreeNode * p = new TreeNode(1);
    TreeNode * p1 = new TreeNode(2);
    TreeNode * p2 = new TreeNode(3);
    p ->left = p1;
    p ->right = p2;
    
    TreeNode * q = new TreeNode(1);
    TreeNode * q1 = new TreeNode(3);
    TreeNode * q2 = new TreeNode(3);
    q ->left = q1;
    q ->right = q2;
    
    Solution s;
    cout << s.isSameTree(p, q) << endl;
}
