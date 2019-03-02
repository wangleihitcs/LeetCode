//
//  13robotMoveRange.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/2.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        if(threshold < 0 || rows <= 0 || cols <= 0) return 0;
        
        bool* visited = new bool[rows * cols];
        for(int i = 0; i < rows * cols; i++)
            visited[i] = false;
            
        int count =  movingCountCore(threshold, rows, cols, 0, 0, visited);
        
        return count;
    }
    int movingCountCore(int threshold, int rows, int cols, int i, int j, bool* visited) {
        int count = 0;
        if(check(threshold, rows, cols, i, j, visited)) {
            visited[i*cols+j] = true;
            count = 1 + movingCountCore(threshold, rows, cols, i, j-1, visited) + movingCountCore(threshold, rows, cols, i-1, j, visited) + movingCountCore(threshold, rows, cols, i, j+1, visited) + movingCountCore(threshold, rows, cols, i+1, j, visited);
        }
        return count;
    }
    bool check(int threshold, int rows, int cols, int i, int j, bool* visited) {
        if(i >= 0 && i < rows && j >= 0 && j < cols && getDigitSum(i) + getDigitSum(j) <= threshold && !visited[i*cols+j])
            return true;
        return false;
    }
    int getDigitSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
};

int main() {
    Solution s;
    cout << s.movingCount(100, 2, 2) << endl;
}
