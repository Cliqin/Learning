# Set

```java
Set<Integer> record = new HashSet<>();
```



# Map

```java
Map<Integer, Integer> map = new HashMap<>();
```





# List

```java
List<List<Integer>> result = new ArrayList<>();
```



# int[]

```java
int[] result = new int[5];
int[] result = new int[]{1,2,3,4,5};
```



# StringBuilder

```java
StringBuilder sb = new StringBuilder();
```







# Stack

```java
Stack<Integer> stack = new Stack<>();
```



# Queue

```java
 Queue<Integer> queue = new LinkedList<>();
```



# Deque

```java
Deque<Character> deque = new LinkedList<>();
Deque<Integer> deque = new LinkedList<>();
```



# ArrayDeque

```java
ArrayDeque<Integer> deque = new ArrayDeque<>();
```



# PriorityQueue

```java
// 在优先队列中存储二元组(num, cnt),cnt表示元素值num在数组中的出现次数
// 出现次数按从队头到队尾的顺序是从大到小排,出现次数最多的在队头(相当于大顶堆)
// 大顶堆
PriorityQueue<int[]> pq1 = new PriorityQueue<>((pair1, pair2) -> pair2[1] - pair1[1]);

// 在优先队列中存储二元组(num, cnt),cnt表示元素值num在数组中的出现次数
// 出现次数按从队头到队尾的顺序是从小到大排,出现次数最低的在队头(相当于小顶堆)
// 小顶堆
PriorityQueue<int[]> pq2 = new PriorityQueue<>((pair1, pair2) -> pair1[1] - pair2[1]);

Map<Integer, Integer> map = new HashMap<>();
for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
    pq.add(new int[] { entry.getKey(), entry.getValue() });
}
```





# 二叉树定义

### Java：

```java
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
```

### Python：

```python
class TreeNode:
    def __init__(self, val, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right
```









