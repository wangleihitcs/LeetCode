//
//  28symmetricalTree.cpp
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
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        return isSymmetricalCore(pRoot, pRoot);
    }
    bool isSymmetricalCore(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot1 == NULL && pRoot2 == NULL) return true;
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        if(pRoot1 ->val != pRoot2 ->val) return false;
        return isSymmetricalCore(pRoot1 ->left, pRoot2 ->right) && isSymmetricalCore(pRoot1 ->right, pRoot2 ->left);
    }
    
};
