//
//  50firstNotRepeatingChar2.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/19.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    //Insert one char from stringstream
    void Insert(char ch) {
        str += ch;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        char ch;
        if(str == "") return '#';
        int index = FirstNotRepeatingChar(str);
        if(index != -1) {
            ch = str[index];
        } else {
            ch = '#';
        }
        return ch;
    }
    int FirstNotRepeatingChar(string str) {
        map<char, int> m1;  //store index
        map<char, int> m2;  //store count
        for(int i = 0; i < str.size(); i++) {
            if(m1.find(str[i]) == m1.end()) {
                m1.insert(pair<char, int>(str[i], i));
                m2.insert(pair<char, int>(str[i], 1));
            } else {
                m2[str[i]] += 1;
            }
        }
        
        map<char, int>::iterator it;
        int min = str.size();
        for(it = m2.begin(); it != m2.end(); it++) {
            if(it ->second == 1 && m1[it ->first] < min) {
                min = m1[it ->first];
            }
        }
        if(min >= 0 && min < str.size()) return min;
        return -1;
    }
private:
    string str;
};

int main() {
    Solution s;
    s.Insert('g');
    cout << s.FirstAppearingOnce() << " ";
    s.Insert('o');
    cout << s.FirstAppearingOnce() << " ";
    s.Insert('o');
    cout << s.FirstAppearingOnce() << " ";
    s.Insert('g');
    cout << s.FirstAppearingOnce() << " ";
    s.Insert('l');
    cout << s.FirstAppearingOnce() << " ";
    s.Insert('e');
    cout << s.FirstAppearingOnce() << " ";
    
    cout << endl;
}
