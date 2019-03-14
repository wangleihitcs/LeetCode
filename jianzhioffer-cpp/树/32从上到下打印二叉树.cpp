//
//  32printFromTopToBottom.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/14.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一、队列，层序遍历
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            res.push_back(node ->val);
            q.pop();
            if(node ->left != NULL) q.push(node ->left);
            if(node ->right != NULL) q.push(node ->right);
        }
        
        return res;
    }
};
