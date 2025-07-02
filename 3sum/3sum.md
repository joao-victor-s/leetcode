# 15. 3Sum

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`
- `i != k`
- `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

**Note:** The solution set must not contain duplicate triplets.

---

### Example 1

**Input:**

```
nums = [-1, 0, 1, 2, -1, -4]
```

**Output:**

```
[[-1, -1, 2], [-1, 0, 1]]
```

---

### Example 2

**Input:**

```cpp
nums = [0, 1, 1]
```

**Output:**

```cpp
[]
```

**Explanation:**
The only possible triplet does not sum up to 0.

---

### Example 3

**Input:**

```cpp
nums = [0, 0, 0]
```

**Output:**

```cpp
[[0, 0, 0]]
```

**Explanation:**
The only possible triplet sums up to 0.



