//
//  55treeDepth.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/15.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一、深度优先搜索
    int TreeDepth(TreeNode* pRoot) {
        if(pRoot == NULL) return 0;
        int left_depth = TreeDepth(pRoot ->left);
        int right_depth = TreeDepth(pRoot ->right);
        int max = (left_depth > right_depth) ? left_depth : right_depth;
        return max + 1;
    }
};

int main() {
    TreeNode* h4 = new TreeNode(4);
    TreeNode* h3 = new TreeNode(3);
    TreeNode* h1 = new TreeNode(1);
    TreeNode* h2 = new TreeNode(2);
    TreeNode* h5 = new TreeNode(5);
    TreeNode* h6 = new TreeNode(6);
    h4 ->left = h2;
    h4 ->right = h5;
    h2 ->left = h1;
    h2 ->right = h3;
//    h5 ->right = h6;
    
    Solution s;
    cout << s.TreeDepth(h4) << endl;
    
}
