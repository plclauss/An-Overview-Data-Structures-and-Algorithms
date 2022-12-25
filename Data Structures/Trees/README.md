# Trees, C++ Introduction

---

At their bases, trees have the same building blocks as linked lists. So, there really wasn't much to learn here; rather, some specific design implementations. The question, in this case, is:

## Why use a tree, and not a linked list?

---

### Speed:

For starters, some operations are faster, although this depends on how your trees and linked lists are constructed. For instance, if you have a basic binary tree and a basic linked list, searching for the tree takes `O(log(number of nodes)` times, while searching in the linked list takes `O(number of nodes)` time. The same is true for insertions, and sometimes deletion.

However, if you implemented your linked list in such a way where the location of the last node in the list is always known, then your insertion time would be constant, beating the insertion time for the tree. Or, if you had an unbalanced tree, and each future insertion is greater than the previous node, then your tree essentially becomes a linked list.

In general, though, lookup, insertion, and deletion take `O(log(number of nodes)` time for a tree.

### Ordering:

Unlike with linked lists, there's some form of ordering to the data inserted into a tree. That is, again, if you design it that way. There are a number of different types of trees, each with their own use case and benefits. 

Of the most common are Binary Search Trees (BSTs), where each node has up to two children and each node's children are positioned to the left or to the right based on the parent and child nodes' values (left, if the child node's value is less than the parents; right, otherwise).

There's also tries, which store character data, and are good for things like searching and replacing words in a body of text, or even autocomplete.

There are plenty, though. (The Wikipedia is overwhelming!)

---

Besides that, as long as you, as a developer, understand *how* you wish to construct your tree, you'll know how the operations for inserting, searching, deleting, etc. should work. From there, you just have to construct it, which, in the end, isn't terribly difficult, especially since trees are relatively nice with their recursion!
