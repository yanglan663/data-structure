05-07代码
#### 约瑟夫
```python
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def create_list(nums):
    first = Node(0)
    p = first
    for i in nums:
        node = Node(i)
        p.next = node
        p = p.next
    p.next = first.next
    return first.next

def find_child(head,steps):
    if head is None:
        return 
    counts = 1
    pre = None
    cur = head
    while cur.next != cur:
        if counts == steps:
            pre.next = cur.next
            cur = cur.next
            counts = 1
        pre = cur 
        cur = cur.next
        counts+=1
    return cur.val

if __name__ == "__main__":
    nums = [i for i in range(1,10)]
    head = create_list(nums)
    child = find_child(head, 2)
    print(child)
```
#### LRU 缓存淘汰算法
思路：
> 1. 如果此数据之前已经被缓存在链表中了，我们遍历得到这个数据对应的结点，并将其从原来的位置删除，然后再插入到链表的头部。
> 2. 如果此数据没有在缓存链表中，又可以分为两种情况：
> 如果此时缓存未满，则将此结点直接插入到链表的头部；
> 如果此时缓存已满，则链表尾结点删除，将新的数据结点插入链表的头部。

```python
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def exists(head,node):
    pre = head
    while pre.next:
        if pre.next.val == node:
            break
        pre = pre.next
    if pre.next == None:
        return None
    return pre

def lru(nums,n):
    if nums is None or len(nums) < n:
        return nums
    head = Node(-1)
    count = 0 
    for i in nums:
        pre = exists(head,i)
        if pre != None:
            pre.next = pre.next.next
            count-=1
        else:
            if count == n:
                p = head
                while p.next.next:
                    p = p.next
                p.next = None
                count -= 1
        newcode = Node(i)
        newcode.next = head.next
        head.next = newcode
        count += 1
    return head

if __name__ == "__main__":
    nums=[2,1,43,62,12,2,4,3,2,5,3,1,6,2]
    head = lru(nums, 5)
    while head.next:
        print(head.next.val)
        head = head.next
```
