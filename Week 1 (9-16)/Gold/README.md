# POTW Gold 9.16.19
Analysis by Aaron Truong

Initially, it may seem like a greedy solution is viable. However, when considering the case ...a, b... where a > b, it is not immediately obvious whether it is more efficient to lower a and necessary preceding values or increase b and necessary subsequent values.

Thus, the solution is dynamic programming. Let a be the array of interest and dp(i, j) be the minimum cost to make a[0]...a[i] nondecreasing such that a[i] <= j.

It follows that dp(i, j) = min(dp(i, j - 1), dp(i - 1, j) + |j - a[i]|) with the solution being dp(n-1, a_max).

This runs in O(nm), where m is the range of the array. However, this can be optimized to O(n^2) by noting that every element always takes on an existing element in the array after an optimal change. Thus, instead of looping through the entire range, we can simply sort the array in ascending order (denoted by a_s) and iterate j through this new array.

It now follows that dp(i, j) = min(dp(i, j - 1), dp(i - 1, j) + |a_s[j] - a[i]|) with the solution being dp(n - 1, n - 1).
