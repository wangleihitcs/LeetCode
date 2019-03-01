//
//  2replacspace.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/2/28.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n^2)，空间复杂度O(1)，
    //注意: 字符串str有足够多内存保证替换后可以表示
    void replaceSpace(char* str, int length) {
        int i = 0;
        while(str[i] != '\0') {
            if(str[i] == ' ') {
                length += 2;
                for(int j = length - 1; j >= i+3; j--) {
                    str[j] = str[j-2];
                }
                str[i] = '%';
                str[i+1] = '2';
                str[i+2] = '0';
            } else {
                i++;
            }
        }
    }
    
    //方法二、计算空格数量，时间复杂度O(n)，空间复杂度O(1)
    void replaceSpace2(char* str, int length) {
        if(str == nullptr || length <= 0) return;
        int spaceNum = 0;
        for(int i = 0; i < length; i++) {
            if(str[i] == ' ') spaceNum++;
        }
        int newLength = length + 2 * spaceNum;
        if(newLength == length) return;
        int left = length-1, right = newLength-1;
        
        while(left != -1) {
            if(str[left] != ' ') {
                str[right--] = str[left--];
            } else {
                str[right--] = '0';
                str[right--] = '2';
                str[right--] = '%';
                left--;
            }
        }
    }
    
};

int main() {
    char str[101] = "we are happy";
    Solution s;
//    s.replaceSpace(str, 12);
    s.replaceSpace2(str, 12);
    cout << str << endl;
}
