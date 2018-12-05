//
//  107BinaryTreeLevelOrderTraversal-II.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/12/5.
//  Copyright © 2018 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法一：暴力搜索
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        vector<vector<int>> result_top_down;
        vector<int> level;
        level.push_back(root ->val);
        result_top_down.push_back(level);
        level.clear();
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* same_level_last = root;
        TreeNode* index = root;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if(front ->left != NULL) {
                q.push(front ->left);
                level.push_back(front ->left ->val);
                index = front ->left;
            }
            if(front ->right != NULL) {
                q.push(front ->right);
                level.push_back(front ->right ->val);
                index = front ->right;
            }
            if(front == same_level_last and !level.empty()) {
                result_top_down.push_back(level);
                level.clear();
                same_level_last = index;
            }
        }
        
        for(int i = result_top_down.size() - 1; i >= 0; i--) {
            result.push_back(result_top_down[i]);
        }
        
        return result;
    }
};

int main() {
    TreeNode * p = new TreeNode(1);
    TreeNode * p1 = new TreeNode(2);
    TreeNode * p2 = new TreeNode(3);
    p ->left = p1;
    p ->right = p2;
    
    Solution so;
    so.levelOrderBottom(p);
}
