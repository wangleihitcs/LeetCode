# LeetCode and 剑指offer
- [LeetCode](#LeetCode)
- [剑指offer](#剑指offer)

## LeetCode
### Easy(easy)
* [1. Two Sum](https://leetcode.com/problems/two-sum/)
* [167. Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

* [28. Implement strStr()](https://leetcode.com/problems/implement-strstr/description/)
* [35. Search Insert Position](https://leetcode.com/problems/search-insert-position/description/)
* [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/)
* [58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/description/)
* [66. Plus One](https://leetcode.com/problems/plus-one/description/)
* [67. Add Binary](https://leetcode.com/problems/add-binary/description/)
* [69. Sqrt(x)](https://leetcode.com/problems/sqrtx/description/)
* [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)
	* 动态规划，找规律
* [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)
	* 链表的删除、遍历
* [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/)
* [100. Same Tree](https://leetcode.com/problems/same-tree/description/)
* [101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
* [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
* [107. Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
* [108. Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
* [110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)
* [111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
* [112. Path Sum](https://leetcode.com/problems/path-sum/)
* [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)
* [119. Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)
* [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
* [169. Majority Element](https://leetcode.com/problems/majority-element/)
* [189. Rotate Array](https://leetcode.com/problems/rotate-array/)
* [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
* [219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)


### Medium(medium)
* [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
* [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/)
	* 方法一、递归求解，暴力求解O(n^3-4)
	* 方法二、从中心点展开，O(n^2)
	* 方法三、动态回归, O(n^2)
* [6. ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/description/)
* [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/description/)
* [12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/description/)

* [15. 3Sum](https://leetcode.com/problems/3sum/description/)
* [16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/)
* [18. 4Sum](https://leetcode.com/problems/4sum/)

* [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
* [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

* [39. Combination Sum](https://leetcode.com/problems/combination-sum/)
* [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

* [48. Rotate Image](https://leetcode.com/problems/rotate-image/)

### Hard(hard)
* [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)
* [23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/)
	* 方法一、逐层遍历，O(kN)
	* 方法二、优先队列，O(Nlog(k)）

## 剑指offer
### 字符串
* 5.替换空格
	- 思路是先统计空格数目

### 链表
* 6.从尾到头打印链表
	- 递归、栈

### 树
* 7.重建二叉树
	- 先找根节点，再找左子树的前序和中序集合，递归构建左子树；接着找右子树的前序和中序集合，递归构建右子树
* 8.二叉树的下一个节点
	- 理解中序遍历即可

### 栈和队列
* 9.用两个栈实现队列

