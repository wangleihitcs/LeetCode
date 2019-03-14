//
//  34findPath.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/14.
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
    //方法一、树的遍历，深度优先搜索
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> path;
        if(root != NULL) {
            DFS(root, expectNumber, res, path);
        }
        return res;
    }
    void DFS(TreeNode* root, int val, vector<vector<int>>& res, vector<int>& path) {
        path.push_back(root ->val);
        if(root ->left == NULL && root ->right == NULL && root ->val == val) {
            res.push_back(path);
        }
        if(root ->left != NULL) {
            DFS(root ->left, val - root ->val, res, path);
        }
        if(root ->right != NULL) {
            DFS(root ->right, val - root ->val, res, path);
        }
        path.pop_back();
    }
};

int main() {
    
}
