# Stacks and Queues C++, Introduction

---

***Note: I did not complete `main.cpp`; I took a large break in between stacks and queues, so I fast-tracked it, so I could move on to "more intense" data structures, and eventually some algorithms.***

Although at their bases, stacks and queues *really* only have two operations (push and pop), there's a lot of nitty-gritty nuance in them; you really have to marry them if you want to get comfortable with their use cases. Sorta like a learning curve, like when recursion is taught; or like when someone's good at algebra, and bad at geometry, or vice versa.

Start at the base (`std::stack<X>` and `std::queue<X>`) and move up from there, and don't be afraid of new syntax. You'll see "multiset" or "deque" or "pii"; peep around the code a bit, or open up the C++ reference page, and you'll be good. Also, stacks and queues seem so small; don't be afraid of expanding their abilities a bit. You don't always need to store single-item data, like integers or characters. You can store whole strings in a stack if you'd like. 

## Stacks

---

Of everything I've learned about stacks, the most helpful, truthfully, would be to know that there are quite a number of problems that can be solved with stacks; they're just rather tricky, and you might not think of using a stack at first, since it'd make more sense to do it another way. 

However, if you *do* use a stack, it's very likely that you'll be implementing a bunch more if-statements than normal, because you want to take advantage of the constant-time operations (top, push, and pop). You'd seldom want to search through a stack; that ruins the whole point. Thus, you'll find yourself in "theory mode," thinking, "what's the best way I can organize this data so I only have to worry about pushing and popping data, and *maybe* worrying about what's at the top of my stack."

## Queues

---

With queues, it's much of the same. The point is to utilize the constant-time operations. Although, there are seemingly more problems that can be solved with queues, and it's possible this is because the amount of variation with queues.

As far as I know, there's only one type of stack in C++. There are multiple types of queues with huge benefits. For instance, there's a max heap (which falls under the priority queue in C++) and there's a deque, or, double-ended queue, which allows you to dynamically push to the front and back of the queue in constant time. 
