//
//  55balancedBinaryTree.cpp
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
    //方法一、暴力解法，时间复杂度O(nlogn)
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL) return true;
        
        int left_depth = TreeDepth(pRoot ->left);
        int right_depth = TreeDepth(pRoot ->right);
        
        int dif = left_depth - right_depth;
        if(dif > 1 || dif < -1) return false;
        
        return IsBalanced_Solution(pRoot ->left) && IsBalanced_Solution(pRoot ->right);
        
    }
    int TreeDepth(TreeNode* pRoot) {
        if(pRoot == NULL) return 0;
        int left_depth = TreeDepth(pRoot ->left);
        int right_depth = TreeDepth(pRoot ->right);
        int max = (left_depth > right_depth) ? left_depth : right_depth;
        return max + 1;
    }
    
    //方法二、只遍历一次节点，后序遍历，借助一个值记录深度，改进方法一
    bool IsBalanced_Solution2(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced(pRoot, &depth);
    }
    bool IsBalanced(TreeNode* pRoot, int* depth) {
        if(pRoot == NULL) {
            *depth = 0;
            return true;
        }
        int left_depth, right_depth;
        if(IsBalanced(pRoot ->left, &left_depth)
           && IsBalanced(pRoot ->right, &right_depth)) {
            int dif = left_depth - right_depth;
            if(dif >= -1 && dif <= 1) {
                *depth = 1 + (left_depth > right_depth ? left_depth : right_depth);
                return true;
            }
        }
        return false;
    }
    
};
