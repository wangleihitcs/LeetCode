//
//  36convertBST.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/14.
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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* lastNode = NULL;
        ConvertCore(pRootOfTree, &lastNode);
        
        TreeNode* firstNode = lastNode;
        while(firstNode != NULL && firstNode ->left != NULL) {
            firstNode = firstNode ->left;
        }
        return firstNode;
    }
    void ConvertCore(TreeNode* root, TreeNode** lastNode) {
        if(root == NULL) return;
        
        ConvertCore(root ->left, lastNode);
        
        root ->left = *lastNode;
        if(*lastNode != NULL) (*lastNode) ->right = root;
        *lastNode = root;
        
        ConvertCore(root ->right, lastNode);
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
    h5 ->right = h6;
    
    Solution s;
    TreeNode* res = s.Convert(h4);
    while(res != NULL) {
        cout << res ->val << " ";
        res = res ->right;
    }
    cout << endl;
}
