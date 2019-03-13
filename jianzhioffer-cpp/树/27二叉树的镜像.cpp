//
//  27mirrorTree.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/13.
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
    //方法一、递归，时间复杂度O(n)，空间复杂度O(1)
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return;
        if(pRoot ->left == NULL && pRoot ->right == NULL) return;
        TreeNode* temp = pRoot ->left;
        pRoot ->left = pRoot ->right;
        pRoot ->right = temp;
        if(pRoot ->left != NULL)
            Mirror(pRoot ->left);
        if(pRoot ->right != NULL)
            Mirror(pRoot ->right);
    }
};

int main() {
    
}
