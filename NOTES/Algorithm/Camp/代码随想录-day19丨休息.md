# 链表理论基础 

建议：了解一下链接基础，以及链表和数组的区别 

[文章链接](https://programmercarl.com/链表理论基础.html)



```java
public class ListNode {
    // 结点的值
    int val;

    // 下一个结点
    ListNode next;

    // 节点的构造函数(无参)
    public ListNode() {
    }

    // 节点的构造函数(有一个参数)
    public ListNode(int val) {
        this.val = val;
    }

    // 节点的构造函数(有两个参数)
    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
```



---------



# 203.移除链表元素

> 题目：[链接](https://leetcode.cn/problems/remove-linked-list-elements/)
>
> 文档讲解：[代码随想录](https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html)
>
> 视频讲解：[链接](https://www.bilibili.com/video/BV18B4y1s7R9)



思路：

1. 直接使用原来的链表来进行删除操作。
2. 设置一个虚拟头结点在进行删除操作。



![img](https://code-thinking-1253855093.file.myqcloud.com/pics/20210316095619221.png)



```java
class Solution {
    public ListNode removeElements(ListNode head, int val) {

        // 创建一个虚拟节点,为了保证处理头结点与非头结点的逻辑相同
        ListNode dummyHead = new ListNode(0, head);
        ListNode cur = dummyHead;
        while (cur.next != null) {
            if (cur.next.val == val) {
                cur.next = cur.next.next;
            } else {
                cur = cur.next;
            }
        }
        return dummyHead.next;
    }
}
```



--------------



# 707.设计链表

> 题目：[链接](https://leetcode.cn/problems/design-linked-list/)
>
> 文档讲解：[代码随想录](https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html)
>
> 视频讲解：[链接](https://www.bilibili.com/video/BV1FU4y1X7WD)



```java
//单链表
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }
}

class MyLinkedList {
    int size;
    ListNode head;

    public MyLinkedList() {
        size = 0;
        head = new ListNode(0);
    }

    // 获取第index个节点的数值，注意index是从0开始的，第0个节点就是头结点
    public int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode cur = head;
        // 包含一个虚拟头节点，所以查找第 index+1 个节点
        for (int i = 0; i <= index; i++) {
            cur = cur.next;
        }
        return cur.val;

    }

    public void addAtHead(int val) {
        addAtIndex(0, val);
    }

    public void addAtTail(int val) {
        addAtIndex(size, val);
    }

    // 在第 index 个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果 index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果 index 大于链表的长度，则返回空
    public void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index < 0) {
            index = 0;
        }
        
        // 找到要插入节点的前驱
        ListNode pre = head;
        for (int i = 0; i < index; i++) {
            pre = pre.next;
        }

        ListNode toAdd = new ListNode(val);
        toAdd.next = pre.next;
        pre.next = toAdd;
        size++;
    }

    //删除第index个节点
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        size--;
        if (index == 0) {
            head = head.next;
            return;
        }

        ListNode pre = head;
        for (int i = 0; i < index; i++) {
            pre = pre.next;
        }

        pre.next = pre.next.next;
        
    }
}

```







------------



# 206.反转链表

> 题目：[链接](https://leetcode.cn/problems/reverse-linked-list/)
>
> 文档讲解：[代码随想录](https://programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html)
>
> 视频讲解：[链接](https://www.bilibili.com/video/BV1nB4y1i7eL)



思路：改变链表的next指针的指向，直接将链表反转，而不用重新定义一个新的链表



我们拿有示例中的链表来举例，如动画所示：（纠正：动画应该是先移动pre，在移动cur）

![](https://code-thinking.cdn.bcebos.com/gifs/206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.gif)

首先定义一个cur指针，指向头结点，再定义一个pre指针，初始化为null。



双指针法

```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        ListNode tmp;
        
        while (cur != null) {
            tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
}
```



递归法

(从左到右递归)

```java
class Solution {
    private ListNode reverse(ListNode pre, ListNode cur) {
        if (cur == null) {
            return pre;
        }
        ListNode tmp = cur.next;
        cur.next = pre;
        pre = cur;
        cur = tmp;
        return reverse(pre, cur);
    }

    public ListNode reverseList(ListNode head) {
        return reverse(null, head);
    }

}
```





(从右到左递归)

```java
class Solution {
    public ListNode reverseList(ListNode head) {
        // 边缘条件判断
        if (head == null || head.next == null) {
            return head;
        }

        // 递归调用，反转第二个节点开始往后的链表
        // 并获得reversedList的头结点,也就是初始未反转链表的最后一个元素
        ListNode reversedList = reverseList(head.next);

        // 反转 头节点与第二个节点的指向
        // 本质上是将reversedList的最后一个元素的下一位指向head
        head.next.next = head;
        // 此时的 head 节点为尾节点，next 需要指向 NULL
        head.next = null;
        return reversedList;

    }
}
```









![](https://code-thinking-1253855093.file.myqcloud.com/pics/%E6%95%B0%E7%BB%84%E6%80%BB%E7%BB%93.png)









