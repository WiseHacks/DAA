# Assignment 4


**Team Members**
|   Enrollment No.  |   Name   |
|   --------------  |   ----   |
|    IIT2019063  |   DIVYESH RANA |
|    IIT2019064  |   AKASH DEEP | 
|    IIT2019065  |   GOPAL PEDADA |

**Group No-**"21"

**Faculty Name-**"DR. MOHAMMED JAVED"

**Mentor Name-** "Md. Meraz"

---
## Problem Statement
Implement Strassen’s matrix algorithm using divide and
conquer.

---
## How to use code
```
#Download project
git clone https://github.com/WiseHacks/DAA
```
Project Initialize
```
cd daa
#create assignment-4 folder
mkdir assignment_04

#go to assignment-4
cd assignment_04
```

Run the code
```
gcc code.c
./a.out
```
**Test case**
```
Test Case-1
Input:
4
1 1 1 1 
2 2 2 2
3 3 3 3
4 4 4 4
1 1 1 1 
2 2 2 2 
3 3 3 3 
4 4 4 4 

Out:
10 10 10 10 
20 20 20 20 
30 30 30 30 
40 40 40 40 

#--------------------------#
Test Case-2
Input:
2
1 2
3 4
1 0
0 1

Out:
1 2 
3 4 

```
---

### Theory

Strassen’s Algorithm named after Volker Strassen is used to compute multiplication of two matrices, it is the improvement in divide and conquer approach which has time complexity O(n^3). 

---

### ANALYSIS

**Time Complexity**
|   Approach  |   Time complexity   |
|   --------------  |   ----   |
|    1  | O(n^3) |
|    2  | O(n^(log7)) |

**Time Complexity**

Space complexity of the algorithm is O(n^2).

---

### References

https://en.wikipedia.org/wiki/Strassen_algorithm
