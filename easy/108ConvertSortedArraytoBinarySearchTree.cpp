//
//  108ConvertSortedArraytoBinarySearchTree.cpp
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return createBBT(0, nums.size()-1, nums);
    }
    
    TreeNode* createBBT(int left, int right, vector<int>& nums) {
        if(left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root ->left = createBBT(left, mid-1, nums);
        root ->right = createBBT(mid+1, right, nums);
        return root;
    }
};

