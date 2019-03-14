//
//  38permutation.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/14.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.size() <= 0) return {};
        vector<string> res;
        PermutationCore(str, res, 0);
        sort(res.begin(), res.end());
        return res;
    }
    void PermutationCore(string str, vector<string>& res, int index) {
        if(index == str.size()-1) {
            res.push_back(str);
        } else {
            for(int i = index; i < str.size(); i++) {
                if(i != index && str[i] == str[index]) continue;
                char temp = str[index];
                str[index] = str[i];
                str[i] = temp;
                
                PermutationCore(str, res, index+1);
                
                temp = str[index];
                str[index] = str[i];
                str[i] = temp;
            }
        }
    }
};

int main() {
    char a[101] = "abca";
    Solution s;
    vector<string> res = s.Permutation(a);
    
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}
