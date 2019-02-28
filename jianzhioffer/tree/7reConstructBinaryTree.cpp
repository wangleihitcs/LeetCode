//
//  7reConstructBinaryTree.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/2/28.
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
    //方法一、递归，时间复杂度O(n)，5ms，608k
    //先找出根节点，找出左子树节点和右子树节点
    TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin) {
        //1. Find root node、left tree nodes、right tree nodes
        if(pre.size() == 0 || vin.size() == 0) return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        
        //2. left tree
        vector<int> leftTreePre, leftTreeVin;
        int rootIndex = 0;
        for(rootIndex = 0; rootIndex < vin.size(); rootIndex++) {
            if(vin[rootIndex] == pre[0]) break;
            else {
                leftTreeVin.push_back(vin[rootIndex]);
            }
        }
        for(int i = 1; i <= rootIndex; i++) {
            leftTreePre.push_back(pre[i]);
        }
        TreeNode* leftTree = reConstructBinaryTree(leftTreePre, leftTreeVin);
        root ->left = leftTree;
        
        //3. right tree
        vector<int> rightTreePre, rightTreeVin;
        for(int i = rootIndex + 1; i < pre.size(); i++) {
            rightTreePre.push_back(pre[i]);
        }
        for(int i = rootIndex + 1; i < vin.size(); i++) {
            rightTreeVin.push_back(vin[i]);
        }
        TreeNode* rightTree = reConstructBinaryTree(rightTreePre, rightTreeVin);
        root ->right = rightTree;
        
        return root;
    }
    
    
    //前序遍历
    void preDisplay(TreeNode* root) {
        if(root != NULL) {
            cout << root ->val << " ";
            preDisplay(root ->left);
            preDisplay(root ->right);
        }
    }
    //中序遍历
    void vinDisplay(TreeNode* root) {
        if(root != NULL) {
            vinDisplay(root ->left);
            cout << root ->val << " ";
            vinDisplay(root ->right);
        }
    }
};

int main() {
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};
    Solution s;
    TreeNode* root = s.reConstructBinaryTree(pre, vin);

    s.preDisplay(root);
    cout << endl;
    s.vinDisplay(root);
    cout << endl;
}
