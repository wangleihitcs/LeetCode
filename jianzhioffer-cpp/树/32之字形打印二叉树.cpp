//
//  32pringZigZag.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/15.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <queue>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(pRoot);
        int nextLevel = 0;
        int toBePrinted = 1;
        bool isLeftToRight = true;
        
        vector<int> item;
        while(!q.empty()) {
            TreeNode* node = q.front();
            item.push_back(node ->val);
            if(node ->left != NULL) {
                q.push(node ->left);
                nextLevel++;
            }
            if(node ->right != NULL) {
                q.push(node ->right);
                nextLevel++;
            }
            q.pop();
            toBePrinted--;
            if(toBePrinted == 0) {
                if(isLeftToRight == false) {
                    reverse(item.begin(), item.end());
                }
                isLeftToRight = !isLeftToRight;
                res.push_back(item);
                item.clear();
                toBePrinted = nextLevel;
                nextLevel = 0;
            }
        }
        
        return res;
    }
};

int main() {
    
}
