//
//  41数据流中的中位数.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/19.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //时间复杂度O(n)
    void Insert(int num) {
        vector<int> :: iterator it;
        for(it = ves.begin(); it != ves.end(); it++) {
            if(num < *(it)) {
                ves.insert(it, num);
                return;
            }
        }
        ves.push_back(num);
    }
    
    double GetMedian() {
        double res;
        if(ves.size() <= 0) return res;
        if(ves.size() % 2 == 0) {
            res = (ves[ves.size()/2] + ves[ves.size()/2 - 1] ) / 2.0;
        } else {
            res = ves[ves.size()/2] + 0.0;
        }
        return res;
    }
private:
    vector<int> ves;
};

int main() {
    Solution s;
    s.Insert(5);
    cout << s.GetMedian() << endl;
    s.Insert(2);
    cout << s.GetMedian() << endl;
    s.Insert(3);
    cout << s.GetMedian() << endl;
    s.Insert(4);
    cout << s.GetMedian() << endl;
    s.Insert(1);
    cout << s.GetMedian() << endl;
    s.Insert(6);
    cout << s.GetMedian() << endl;
    s.Insert(7);
    cout << s.GetMedian() << endl;
    s.Insert(0);
    cout << s.GetMedian() << endl;
    s.Insert(8);
    cout << s.GetMedian() << endl;
    
}

