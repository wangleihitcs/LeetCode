//
//  104MaximumDepthofBinaryTree.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/11/26.
//  Copyright © 2018 wanglei. All rights reserved.
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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left_depth = maxDepth(root ->left);
        int right_depth = maxDepth(root ->right);
        int max_depth = left_depth > right_depth ? left_depth : right_depth;
        return max_depth + 1;
    }
};

int main() {
    TreeNode * p = new TreeNode(1);
    TreeNode * p1 = new TreeNode(2);
    TreeNode * p2 = new TreeNode(3);
    p ->left = p1;
    p ->right = p2;
    
    Solution so;
    cout << so.maxDepth(p) << endl;
}
