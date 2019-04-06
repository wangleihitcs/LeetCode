//
//  56MergeIntervals.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/5.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    //方法一、先排序，时间复杂度O(nlogn)，空间复杂度O(n)，not in-place，12ms，9.7MB
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
        
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(res.back().end < intervals[i].start) res.push_back(intervals[i]);
            else
                res.back().end = max(res.back().end, intervals[i].end);
        }
        return res;
    }
};

int main() {
    Interval iv1 = Interval(1, 3);
    Interval iv2 = Interval(2, 6);
    Interval iv3 = Interval(8, 10);
    Interval iv4 = Interval(15, 18);
    vector<Interval> nums = {iv2, iv1, iv3, iv4};
    Solution s;
    vector<Interval> res = s.merge(nums);
    for(Interval iv : res) {
        cout << iv.start << " " << iv.end << endl;
    }
}
