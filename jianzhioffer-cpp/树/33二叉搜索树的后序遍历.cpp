//
//  33verifySquenceOfBST.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/14.
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
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0) return false;
        return lastOrderBSTCore(sequence);
    }
    bool lastOrderBSTCore(vector<int> sequence) {
        if(sequence.size() == 0) return true;
        int root = sequence[sequence.size()-1];
        vector<int> left_seq;
        vector<int> right_seq;
        for(int i = 0; i < sequence.size()-1; i++) {
            if(sequence[i] <= root) {
                left_seq.push_back(sequence[i]);
            } else {
                break;
            }
        }
        for(int i = left_seq.size(); i < sequence.size()-1; i++) {
            right_seq.push_back(sequence[i]);
            if(sequence[i] <= root) return false;
        }
        return lastOrderBSTCore(left_seq) && lastOrderBSTCore(right_seq);
    }
};

int main() {
    vector<int> seq = {7,4,6,5};
    Solution s;
    cout << s.VerifySquenceOfBST(seq) << endl;
}
