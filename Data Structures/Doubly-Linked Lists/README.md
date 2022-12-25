# Doubly-Linked Lists, Intro.:

---

*Note: These functions don't include error checks. For instance, `deleteNode(int32_t index)` does not check whether a node at this location exists.*

---

There really isn't much I learned about doubly-linked lists that I didn't already learn/cover in my [intro to singly-linked list's repository.](https://github.com/plclauss/__INTROLinkedLists)
<br><br>

If anything, there were just more pointers to consider. With that requires an awareness of how changing one pointer affects the others. For instance, the `reverseList()` function is really all about swapping a node's two pointers, and we all know what happens in a computer's memory when you try to swap the values of two variables.
<br>
For clarity, this is a pretty elementary topic. If you have something like:
```asm
//...
int a = 7;
int b = 26;
//...
```
...and you wish to swap the values of `a` and `b`, then you must allocate additional memory to temporarily hold one of the variables' contents, so that it's not accidentally overwritten when being assigned with the *other variables'* value. You'll need to save one of the variables' contents to effectively swap the two variables' values.
<br>
I'm not going to dive too much into this topic, though. This is generally the first thing you learn when it comes to memory inside a computer, and, if you've made it all the way to doubly-linked list's without having a firm grasp on memory, then, well... I am thoroughly impressed.
<br><br>
Anyway, the same sort of concept applies to doubly-linked list's. The only difference is that we're working with pointers to `Node`'s, not `int`'s. Often, you'll need to keep track of a `Node`, or two, to effectively follow through with an operation.

---

I will say, though, really quickly:
<br>
There are a short number of pros and cons, that I'm aware of, between singly- and doubly-linked list's. Here's an extremely brief list of those:
<br>
* Singly-Linked Lists:
  * Pros:
    1. Less memory
    2. Fast insertion and deletion
  * Cons:
    1. Not backwards-traversable.
    2. Slow search
* Doubly-Linked Lists:
  * Pros:
    1. Traversable in both directions
    2. Fast insertion and deletion
    3. Fast search (technically better than singly-linked lists, `O(N/2)`)
  * Cons:
    1. More memory

---

Happy Coding! :)
