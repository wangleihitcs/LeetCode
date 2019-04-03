//
//  49GroupAnagrams.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/3.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    //方法一、暴力，时间复杂度O(n*(k^2)*(m^2))，空间复杂度O(n*m)，time limit
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size() == 0) return res;
        res.push_back({strs[0]});
        for(int i = 1; i < strs.size(); i++) {//O(n)
            int flag = 0;
            for(int j = 0; j < res.size(); j++) {//O(k^2)
                if(isGroup2(res[j][0], strs[i])) {//O(m^2)
                    res[j].push_back(strs[i]);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) res.push_back({strs[i]});
        }
        return res;
    }
    bool isGroup(string str1, string str2) {//O(m^2)
        if(str1.size() != str2.size()) return false;
        while(str1 != "") {
            string c = str1.substr(0, 1);
            int index = str2.find(c);
            if(index != string::npos) {
                str1 = str1.substr(1);
                str2 = str2.erase(index, 1);
            } else {
                return false;
            }
        }
        return true;
    }
    bool isGroup2(string str1, string str2) {//O(m)
        if(str1.size() != str2.size()) return false;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for(int i = 0; i < str1.size(); i++) {
            v1[str1[i] - 'a']++;
            v2[str2[i] - 'a']++;
        }
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
    
    //方法二、通过排序分组，时间复杂度O(n*m*logm)，空间复杂度O(n*m)，76ms，19.7MB
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size() == 0) return res;
        map<string, vector<string>> m;
        for(string str : strs) {
            vector<char> chars(str.begin(), str.end());
            sort(chars.begin(), chars.end());
            
            string key = "";
            for(char c : chars) {
                key += c;
            }
            if(m.find(key) != m.end()) {
                m[key].push_back(str);
            } else {
                m[key] = {str};
            }
        }
        for(map<string, vector<string>>::iterator it = m.begin(); it != m.end(); it++) {
            res.push_back(it ->second);
        }
        return res;
    }
    
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> res = s.groupAnagrams2(strs);
    for(vector<string> item : res) {
        for(string str : item) {
            cout << str << " ";
        }
        cout << endl;
    }
}
