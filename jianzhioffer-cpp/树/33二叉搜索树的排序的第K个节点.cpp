//
//  33KthNode.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/19.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
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
    //方法一、二叉搜索树的中序遍历即按照从小到大顺序
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if(pRoot == NULL || k <= 0) return NULL;
        vector<TreeNode*> res;
        PreDisplay(pRoot, res);
        if(res.size() < k) return NULL;
        return res[k-1];
    }
    void PreDisplay(TreeNode* pRoot, vector<TreeNode*>& res) {
        if(pRoot == NULL) return;
        PreDisplay(pRoot ->left, res);
        res.push_back(pRoot);
        PreDisplay(pRoot ->right, res);
    }
};
