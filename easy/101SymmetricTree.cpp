//
//  101SymmetricTree.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/11/26.
//  Copyright © 2018 wanglei. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetricTwoTree(root ->left, root ->right);
    }
    bool isSymmetricTwoTree(TreeNode* tree1, TreeNode* tree2) {
        if(tree1 == NULL && tree2 == NULL) {
            return true;
        }
        if(tree1 == NULL || tree2 == NULL) {
            return false;
        }
        if(tree1 ->val != tree2 ->val) {
            return false;
        }
        return isSymmetricTwoTree(tree1 ->left, tree2 ->right)
                && isSymmetricTwoTree(tree1 ->right, tree2 ->left);
    }
    
};

int main() {
    TreeNode * p = new TreeNode(1);
    TreeNode * p1 = new TreeNode(2);
    TreeNode * p2 = new TreeNode(3);
    p ->left = p1;
    p ->right = p2;
    
    Solution so;
    cout << so.isSymmetric(p) << endl;
}
