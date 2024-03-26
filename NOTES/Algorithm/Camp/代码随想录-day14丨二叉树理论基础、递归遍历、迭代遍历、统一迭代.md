

# 二叉树理论基础

> 文档讲解：[代码随想录](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html)
>
> 视频讲解：[链接](https://www.bilibili.com/video/BV1Hy4y1t7ij/?vd_source=eef63af53fcfefb768e9bb2742f4f697)
>



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





--------------



# 递归遍历

> 文档讲解：[代码随想录](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html)
>
> 视频讲解：[链接](https://www.bilibili.com/video/BV1Xg41167Lz)



[144.二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)



```java
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        preorder(root, result);
        return result;
    }

    private void preorder(TreeNode root, List<Integer> result) {
        if (root==null) {
            return ;
        }

        result.add(root.val);
        preorder(root.left, result);
        preorder(root.right, result);
    }

}
```





[145.二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)



```java
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        postorder(root, result);
        return result;
    }

    private void postorder(TreeNode root, List<Integer> result) {
        if (root == null) {
            return;
        }

        postorder(root.left, result);
        postorder(root.right, result);
        result.add(root.val);
    }
}
```



[94.二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)



```java
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        inorder(root, result);
        return result;
    }

    private void inorder(TreeNode root,List<Integer> result){
        if (root == null) {
            return;
        }

        inorder(root.left, result);
        result.add(root.val);
        inorder(root.right, result);
    }
}
```



------------





# 迭代遍历

> 文档讲解：[代码随想录](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html)
>
> 视频讲解：
>
> [链接](https://www.bilibili.com/video/BV15f4y1W7i2)
>
> [链接](https://www.bilibili.com/video/BV1Zf4y1a77g)



* [144.二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

前序遍历顺序：中-左-右，入栈顺序：中-右-左

```java
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        if (root == null) {
            return result;
        }
        Stack<TreeNode> stack = new Stack<>();
        // 中
        stack.push(root);
        //前序遍历顺序：中-左-右，入栈顺序：中-右-左
        while (!stack.isEmpty()) {
            // 弹出
            TreeNode node = stack.pop();
            result.add(node.val);
            // 右
            if (node.right != null) {
                stack.push(node.right);
            }
            // 左
            if (node.left != null) {
                stack.push(node.left);
            }
        }
        return result;
    }

}
```



* [94.二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

中序遍历顺序: 左-中-右 入栈顺序： 左-右

```java
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        if (root == null) {
            return result;
        }

        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
		
        while (cur != null || !stack.isEmpty()) {
            if (cur!=null) {
                stack.push(cur);
                // 左
                cur = cur.left;
            }else{
                // 弹出
                cur = stack.pop();
                result.add(cur.val);
                // 右
                cur = cur.right;
            }
        }
        return result;
    }
}
```



* [145.二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

后序遍历顺序 左-右-中 入栈顺序：中-左-右 出栈顺序：中-右-左， 最后翻转结果

```java
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        if (root == null) {
            return result;
        }
        Stack<TreeNode> stack = new Stack<>();
        // 中
        stack.push(root);

        while (!stack.isEmpty()) {
            // 弹出
            TreeNode node = stack.pop();
            result.add(node.val);
            // 左
            if (node.left != null) {
                stack.push(node.left);
            }
            // 右
            if (node.right != null) {
                stack.push(node.right);
            }
        }
        Collections.reverse(result);
        return result;
    }
}
```



------------







# 统一迭代

> 文档讲解：[代码随想录](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%BB%9F%E4%B8%80%E8%BF%AD%E4%BB%A3%E6%B3%95.html)
>







------------



