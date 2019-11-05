《08 | 栈：如何实现浏览器的前进和后退功能？》笔记：
### 一、栈的概念
1. 一种“操作受限”的线性表，只支持端操作，先进者后出，后进者先出。
2. 当某个数据集只涉及到一端插入和删除数据，并且满足先进后出，后进先出的特性，我们就应该首选“栈”这种数据结构。
3. 实现：用数组实现（顺序栈），用链表实现（链式栈）

```java
// 基于数组实现的顺序栈
public class ArrayStack {
  private String[] items;  // 数组
  private int count;       // 栈中元素个数
  private int n;           //栈的大小

  // 初始化数组，申请一个大小为n的数组空间
  public ArrayStack(int n) {
    this.items = new String[n];
    this.n = n;
    this.count = 0;
  }

  // 入栈操作
  public boolean push(String item) {
    // 数组空间不够了，直接返回false，入栈失败。
    if (count == n) return false;
    // 将item放到下标为count的位置，并且count加一
    items[count] = item;
    ++count;
    return true;
  }
  
  // 出栈操作
  public String pop() {
    // 栈为空，则直接返回null
    if (count == 0) return null;
    // 返回下标为count-1的数组元素，并且栈中元素个数count减1
    String tmp = items[count-1];
    --count;
    return tmp;
  }
}
```

```python
class Mystack:
    def __init__(self,n):
        self.n = n
        self.count = 0
        self.nums = [None]*n
    
    def enque(self,num):
        if self.count == self.n:
            return False
        self.nums[self.count] = num
        self.count+=1
        return True

    def deque(self):
        if self.count == 0:
            return False
        ret = self.nums[self.count]
        self.count -= 1
        return self.count

```

4.. 动态扩容的顺序栈
支持动态扩容的栈，就要有一个支持动态扩容的数组，栈满后，重新终身一块更大的内存空间。
时间复杂度分析：摊还分析法 O（1）

### 二、栈的应用

1. 函数调用栈
操作系统给每个线程都分配了一个独立的内存空间，这些内存空间被组织成栈这种数据结构，存储临时变量。
**从调用函数进入被调用函数，对于数据来说，变化的是什么呢？是_==作用域==_。所以根本上，只要能保证每进入一个新的函数，都是一个新的作用域就可以。而要实现这个，用栈就非常方便。在进入被调用函数的时候，分配一段栈空间给这个函数的变量，在函数结束的时候，将栈顶复位，正好回到调用函数的作用域内。**

2. 表达式求值

   计算 3+5*8-6 ：
   * 两个栈，stack1 和 stack2 ，分别存储数值和符号，当符号的优先级大于或等于栈顶的符号，就从stack1 中出栈两个数，计算结果再入栈。

3. 括号匹配

比如，{[{}]}或 [{()}([])] 等都为合法格式，而{[}()] 或 [({)] 为不合法的格式。

* 用栈来存储左括号，当遇到右括号的时候查看栈顶元素是否匹配，匹配则出栈。遍历结束看栈是否为空。

4. 浏览器的前进个后退

* 比如你顺序查看了 a，b，c 三个页面，我们就依次把 a，b，c 压入栈，这个时候，两个栈的数据就是这个样子：

![](/Users/yanglan/git_rep/pic/stack1.jpg)

* 当你通过浏览器的后退按钮，从页面 c 后退到页面 a 之后，我们就依次把 c 和 b 从栈 X 中弹出，并且依次放入到栈 Y。这个时候，两个栈的数据就是这个样子：

![](/Users/yanglan/git_rep/pic/stack2.jpg)

* 这个时候你又想看页面 b，于是你又点击前进按钮回到 b 页面，我们就把 b 再从栈 Y 中出栈，放入栈 X 中。此时两个栈的数据是这个样子：
![](/Users/yanglan/git_rep/pic/stack3.jpg)

* 这个时候，你通过页面 b 又跳转到新的页面 d 了，页面 c 就无法再通过前进、后退按钮重复查看了，所以需要清空栈 Y。此时两个栈的数据这个样子：
![](/Users/yanglan/git_rep/pic/stack4.jpg)


#####################################################

《08 | 栈：如何实现浏览器的前进和后退功能？》笔记：
### 一、理解队列
1. 队列：一种操作受限的线性表结构，只允许在两端插入和删除，先进先出
2. 队列的实现：数组（顺序队列），链表实现（链式队列）

```java

// 用数组实现的队列
public class ArrayQueue {
  // 数组：items，数组大小：n
  private String[] items;
  private int n = 0;
  // head表示队头下标，tail表示队尾下标
  private int head = 0;
  private int tail = 0;

  // 申请一个大小为capacity的数组
  public ArrayQueue(int capacity) {
    items = new String[capacity];
    n = capacity;
  }
   // 入队操作，将item放入队尾
  public boolean enqueue(String item) {
    // tail == n表示队列末尾没有空间了
    if (tail == n) {
      // tail ==n && head==0，表示整个队列都占满了
      if (head == 0) return false;
      // 数据搬移
      for (int i = head; i < tail; ++i) {
        items[i-head] = items[i];
      }
      // 搬移完之后重新更新head和tail
      tail -= head;
      head = 0;
    }
    
    items[tail] = item;
    ++tail;
    return true;
  }
  // 出队
  public String dequeue() {
    // 如果head == tail 表示队列为空
    if (head == tail) return null;
    // 为了让其他语言的同学看的更加明确，把--操作放到单独一行来写了
    String ret = items[head];
    ++head;
    return ret;
  }
}
```
### 二、几种队列
* 循环队列（关键是判断队满和队空）

队满：当队满时，(tail+1)%n=head。
![](/Users/yanglan/git_rep/pic/队满.jpg)

队空：队列为空的判断条件是 head == tail

实现：

```java

public class CircularQueue {
  // 数组：items，数组大小：n
  private String[] items;
  private int n = 0;
  // head表示队头下标，tail表示队尾下标
  private int head = 0;
  private int tail = 0;

  // 申请一个大小为capacity的数组
  public CircularQueue(int capacity) {
    items = new String[capacity];
    n = capacity;
  }

  // 入队
  public boolean enqueue(String item) {
    // 队列满了
    if ((tail + 1) % n == head) return false;
    items[tail] = item;
    tail = (tail + 1) % n;
    return true;
  }

  // 出队
  public String dequeue() {
    // 如果head == tail 表示队列为空
    if (head == tail) return null;
    String ret = items[head];
    head = (head + 1) % n;
    return ret;
  }
}
```
* 阻塞队列和并发队列

	* 阻塞队列就是在队列的基础上增加了阻塞操作，当队列为空时，禁止取数据；当队列满时，禁止增加数据
	* 并发队列，线程安全的队列，实现最简单的方法就是在dequeue(),enqueue()时枷锁，但是锁粒度大，并发性就低

	
![](/Users/yanglan/git_rep/pic/阻塞队列.jpg)

### 三、解答开篇问题
* 线程池没有空闲线程时，新的任务请求线程资源时，线程池该如何处理？
	* 第一种是非阻塞的处理方式，直接拒绝任务请求；
	* 另一种是阻塞的处理方式，将请求排队，等到有空闲线程时，取出排队的请求继续处理。

	

* 各种处理策略又是如何实现的呢？那如何存储排队的请求呢？
队列有基于链表和基于数组这两种实现方式。

* 这两种实现方式对于排队请求又有什么区别呢？
	* 基于链表的实现方式，可以实现一个支持无限排队的无界队列（unbounded queue），但是可能会导致过多的请求排队等待，请求处理的响应时间过长。所以，针对响应时间比较敏感的系统，基于链表实现的无限排队的线程池是不合适的。
	* 基于数组实现的有界队列（bounded queue），队列的大小有限，所以线程池中排队的请求超过队列大小时，接下来的请求就会被拒绝，这种方式对响应时间敏感的系统来说，就相对更加合理。不过，设置一个合理的队列大小，也是非常有讲究的。队列太大导致等待的请求太多，队列太小会导致无法充分利用系统资源、发挥最大性能。
	
	
	==实际上，对于大部分资源有限的场景，当没有空闲资源时，基本上都可以通过“队列”这种数据结构来实现请求排队。==