//
//  169MajorityElement.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/2/22.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n^2)，空间复杂度O(1)，time limit
    int majorityElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int count = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(nums[j] == nums[i]) count++;
            }
            if(count > nums.size()/2) return nums[i];
        }
        return 0;
    }
    
    //方法二1、暴力排序，找出中位数，时间复杂度O(n^2)，空间复杂度O(1)，time limit
    int majorityElement1(vector<int>& nums) {
        int temp = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] > nums[j]) {
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums[nums.size()/2];
    }
    //方法二2、优先队列排序，找出中位数，时间复杂度O(nlogn)，空间复杂度O(n)，72ms
    int majorityElement2(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        int i = 0;
        while(i < nums.size()/2) {
            pq.pop();
            i++;
        }
        return pq.top();
    }
    
    //方法三、统计频率，时间复杂度O(n)，空间复杂度O(1)，28ms
    int majorityElement3(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i]) != m.end()) {
                m[nums[i]]++;
            } else {
                m.insert(pair<int, int>(nums[i], 1));
            }
        }
        map<int, int>::iterator it;
        for(it = m.begin(); it != m.end(); it++) {
            if(it ->second > nums.size()/2) return it ->first;
        }
        return 0;
    }
    
    //方法四、Boyer- Moore，时间复杂度O(n)，空间复杂度O(1)，20ms
    int majorityElement4(vector<int>& nums) {
        int count = 0;
        int candidate = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) candidate = nums[i];
            count += (nums[i] == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution so;
    cout << so.majorityElement4(nums) << endl;
}
