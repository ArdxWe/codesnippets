# 报告

## 要求

- 用 C 实现函数队列调度结构中必须的函数队列代码， 至少包括两个函数， 一个往函数队列的尾部插入函数指针， 一个从函数队列的头部读取第一项， 队列空时返回 NULL 指针
- 在临界区禁止中断
- 增加优先级调度支持

## 文件说明

|        file        |     description                                       |
| ---------------    | ------------                                       |
|        queue.c     | 实现 queue.h 接口，主要包括队列的初始化，增加，删除，销毁，展示 | 
| queue.h            | 接口声明          |
| main.c             | 测试代码          |
| main.out           | 可执行文件        |

## 实现

- 维护最大堆， 优先级作为 key, 获取复杂度 O(n)， 添加复杂度 O(lgn)
- 默认长度为 4(宏 QUEUE_SIZE)， 队列满时动态增长(*2)

```bash
ardxwe@ardxwe ~/github/codesnippets/Embedded Systems$ gcc queue.c main.c -o main.out
ardxwe@ardxwe ~/github/codesnippets/Embedded Systems$ /main.out
p: 1 
p: 18 1 
p: 18 1 8 
p: 56 18 8 1 
p: 79 56 8 1 18 
p: 79 56 65 1 18 8 
e call
p: 99 56 65 1 18 8 
a call
p: 564 56 65 1 18 8 
p: 564 56 65 1 18 8 34 
p: 564 56 65 3 18 8 34 1 
p: 569 564 65 56 18 8 34 1 3 
e call
p: 564 56 65 45 18 8 34 1 3
```

![add(1)](/images/1.jpg)
![add(18)](/images/2.jpg)
![add(8)](/images/3.jpg)
![add(56)](/images/4.jpg)
![add(79)](/images/5.jpg)
![add(65)](/images/6.jpg)
![get()](/images/7.jpg)
![add(99)](/images/8.jpg)
![get()](/images/9.jpg)
![add(564)](/images/10.jpg)
![add(34)](/images/11.jpg)
![add(3)](/images/12.jpg)
![add(569)](/images/13.jpg)
![get()](/images/14.jpg)
![add(15)](/images/15.jpg)






 