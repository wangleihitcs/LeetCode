//
//  26hasSubtree.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/12.
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
    //详细理解题意即可
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        bool res = false;
        if(pRoot1 != NULL && pRoot2 != NULL) {
            if(pRoot1 ->val == pRoot2 ->val) {
                res = isSubTree(pRoot1, pRoot2);
            }
            if(res == false) {
                res = HasSubtree(pRoot1 ->left, pRoot2);
            }
            if(res == false) {
                res = HasSubtree(pRoot1 ->right, pRoot2);
            }
        }
        return res;
    }
    bool isSubTree(TreeNode* p1, TreeNode* p2) {
        if(p2 == NULL) return true;
        if(p1 == NULL) return false;
        if(p1 ->val != p2 ->val) return false;
        return isSubTree(p1 ->left, p2 ->left) && isSubTree(p1 ->right, p2 ->right);
    }
    
};

int main() {
    
}
