//
//  94BinaryTreeInorderTraversal.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/20.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一、递归，时间复杂度O(n)，空间复杂度O(n)，4ms，9.4MB
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversalCore(res, root);
        return res;
    }
    void inorderTraversalCore(vector<int>& res, TreeNode* root) {
        if(root == NULL) return;
        inorderTraversalCore(res, root ->left);
        res.push_back(root ->val);
        inorderTraversalCore(res, root ->right);
    }
    
    //方法二、非递归，时间复杂度O(n)，空间复杂度O(n)，4ms，9.1MB
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur != NULL || !s.empty()) {
            while(cur != NULL) {
                s.push(cur);
                cur = cur ->left;
            }
            cur = s.top();
            s.pop();
            res.push_back(cur ->val);
            cur = cur ->right;
        }
        return res;
    }
};

int main() {
    
}
