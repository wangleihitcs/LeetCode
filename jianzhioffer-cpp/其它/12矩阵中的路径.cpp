//
//  12hasPath.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/2.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、回溯法，3ms，456k
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        if(matrix == NULL || rows <= 0 || cols <= 0 || str == NULL) return false;
        
        bool* visited = new bool[rows * cols];
        for(int i = 0; i < rows*cols; i++) {
            visited[i] = false;
        }
        int index = 0;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(hasPathCore(matrix, rows, cols, str, i, j, visited, index)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    bool hasPathCore(char* matrix, int rows, int cols, char* str, int i, int j, bool* visited, int& index) {
        if(str[index] == '\0') return true;
       
        bool has_path = false;
        if(i >= 0 && i < rows && j >= 0 && j < cols && matrix[i*cols+j] == str[index] && !visited[i*cols+j]) {
            index++;
            visited[i*cols+j] = true;
            
            has_path = hasPathCore(matrix, rows, cols, str, i-1, j, visited, index) || hasPathCore(matrix, rows, cols, str, i, j-1, visited, index) || hasPathCore(matrix, rows, cols, str, i+1, j, visited, index) || hasPathCore(matrix, rows, cols, str, i, j+1, visited, index);
            if(!has_path) {
                index--;
                visited[i*cols+j] = false;
            }
        }
        
        return has_path;
    }
};

int main() {
    char matrix[101] = "abcesfcsadee";
    char str[101] = "bcced";
    
    Solution s;
    cout << s.hasPath(matrix, 3, 4, str) << endl;
}
