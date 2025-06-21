# 🧠 LeetCode Practice by Chandra Shekhar Pandey

Welcome to my LeetCode practice repository! This is where I consistently solve coding problems to improve my **Data Structures & Algorithms (DSA)** and **problem-solving skills**, mainly using **C++**.
## 🧠 Competitive Programming Profiles

- 🔗 [**LeetCode**](https://leetcode.com/shekharpandey10) – Solving data structures & algorithm problems regularly  
- 🔗 [**CodeChef**](https://www.codechef.com/users/shekharpandey10) – Participating in rated contests & practicing advanced problems
---

## 🚀 About This Repository

This repo contains my personal solutions to selected problems from [LeetCode](https://leetcode.com/), organized by:

- 🔢 **Problem number**
- 🏷️ **Topic (if applicable)**
- 🧠 **Approach / strategy**
- ✅ **Tested and working solutions**

> Most solutions are in **C++**, written for clarity and efficiency.

---

## 📁 Folder Structure

Leetcode/
│
├── Arrays/
│ ├── two_sum.cpp
│ └── ...
├── Strings/
│ ├── valid_palindrome.cpp
│ └── ...
├── DynamicProgramming/
│ ├── house_robber.cpp
│ └── ...
├── Trees/
│ ├── inorder_traversal.cpp
│ └── ...
├── Graphs/
│ ├── bfs.cpp
│ └── ...
└── README.md


Each file is named after the problem it's solving and includes inline comments for clarity.

---

## 📌 Goals

- 📈 Improve consistency in problem-solving
- ⚡ Build strong foundations in DSA
- 🎯 Prepare for coding interviews and contests

---

## 🛠️ Technologies Used

- Language: **C++**
- Platform: [LeetCode](https://leetcode.com/)
- Editor: VS Code / Sublime Text

---

## 📚 Sample Problem Format

```cpp
// 🔢 Problem: Two Sum
// 🏷️ Tag: Array, HashMap
// ✅ Status: Accepted
// 🔗 Link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (map.count(diff)) {
                return {map[diff], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
