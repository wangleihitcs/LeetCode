//
//  8getNextNode.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/1.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    //方法一、递归，按照前序遍历顺序返回下一个节点
    TreeLinkNode* getNextNode(TreeLinkNode* pNode) {
        if(pNode == NULL) return NULL;
        if(pNode ->left != NULL) return pNode ->left;
        if(pNode ->right != NULL) return pNode ->right;
        
        TreeLinkNode* parent = pNode ->next;
        if(parent ->right != NULL && parent ->right != pNode) {
            return parent ->right;
        }
        if(parent ->right != NULL && parent ->right == pNode){
            parent ->right = NULL;
            return getNextNode(parent);
        }
        if(parent ->right == NULL && parent ->left == pNode) {
            parent ->left = NULL;
            return getNextNode(parent);
        }
        return NULL;
    }
    
    //方法一、递归，按照中序遍历顺序返回下一个节点，3ms，460k
    TreeLinkNode* getNextNode2(TreeLinkNode* pNode) {
        if(pNode == NULL) return NULL;
        
        //1.如果本节点有右子树，则中序遍历下个节点为右子树最左节点
        if(pNode ->right != NULL) {
            TreeLinkNode* p = pNode ->right;
            while(p != NULL && p ->left != NULL) {
                p = p ->left;
            }
            return p;
        };
        
        //2.如果本节点没有右子树，但是其父节点存在且本节点为父节点的左子树，则返回父节点
        TreeLinkNode* parent = pNode ->next;
        if(parent != NULL && parent ->left == pNode) {
            return parent;
        }
        
        //3.如果本节点没有右子树，父节点存在且本节点为父节点的右子树，
        //则遍历父节点直至找到父节点是父父节点的左子树
        if(parent != NULL && parent ->right == pNode) {
            TreeLinkNode* currentParent = parent;
            TreeLinkNode* p = parent;
            while(p != NULL && p ->next != NULL) {
                if(p ->next ->left == currentParent) {
                    return p ->next;
                } else {
                    p = p ->next;
                    currentParent = p;
                }
            }
        }
        
        return NULL;
    }
    
};

int main() {
    TreeLinkNode* h1 = new TreeLinkNode(1);
    TreeLinkNode* h2 = new TreeLinkNode(2);
    TreeLinkNode* h3 = new TreeLinkNode(3);
    h1 ->left = h2;
    h1 ->right = h3;
    h2 ->next = h1;
    h3 ->next = h1;
    TreeLinkNode* h4 = new TreeLinkNode(4);
    h2 ->right = h4;
    h4 ->next = h2;
    TreeLinkNode* h7 = new TreeLinkNode(7);
    h4 ->right = h7;
    h7 ->next = h4;
    TreeLinkNode* h5 = new TreeLinkNode(5);
    h3 ->left = h5;
    h5 ->next = h3;
    
    Solution s;
//    s.preDisplay(h1);
//    TreeLinkNode* nextNode = s.getNextNode(h7);
    TreeLinkNode* nextNode = s.getNextNode2(h3);
    if(nextNode != NULL) {
        cout << nextNode ->val << endl;
    } else {
        cout << "mmp" << endl;
    }
}
