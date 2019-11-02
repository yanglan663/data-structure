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
