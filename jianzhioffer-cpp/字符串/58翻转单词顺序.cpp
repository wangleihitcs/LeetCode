//
//  58reverseSentence.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/18.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、借助反转字符串，时间复杂度O(n)，空间复杂度O(k)
    string ReverseSentence(string str) {
        if(str.size() <= 0) return str;
        
        string res = "";
        string word = "";
        for(int i = str.size()-1; i >= 0; i--) {
            if(str[i] == ' ') {
                reverse(word, 0, word.size()-1);
                res = res + word + " ";
                word = "";
            } else {
                word += str[i];
            }
        }
        reverse(word, 0, word.size()-1);
        res += word;
        return res;
    }
    
    void reverse(string& str, int left, int right) {
        while(left < right) {
            char ch = str[left];
            str[left] = str[right];
            str[right] = ch;
            left++;
            right--;
        }
    }
};

int main() {
    Solution s;
    string str = "I am a student.";
    cout << str << endl;
    cout << s.ReverseSentence(str) << endl;
    
    return 0;
}
