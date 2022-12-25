# Searching Algorithms, Intro.

---

*Note: Aspects of this project could be improved marginally. For starters, there's plenty of memory leaks, since I didn't bother writing destructors. In the future, I may end up using C++ smart pointers. Another thing I immediately noticed was the lack of error checking. While I could format things properly for the user (for instance, if they wanted to use the `doesPathExist` function, but provided me with lowercase letters for the nodes, I could just use an equivalent `.upper()` function); however, I decided that, since this project isn't going to anyone, I could just leave it and stick to the fundamentals of the algorithms at hand.*

---

As is common among all searching algorithms, you must have: a key/value to search for, and a container to search through.

This repository describes algorithms for vectors (or arrays), trees, and graphs.

## Array/Vector Algos.

There are two primary searching algorithms for arrays/vectors:

### Linear Search

The linear search algorithm takes a vector (or array or list, equivalently) and searches through it sequentially/chronologically; that is, from `index = 0` to `index = size of container - 1`.

For example,
```
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
key = 7

The linear searching algorithm starts at index = 0, or value = 1.
Since 1 != key, we keep searching...
2 -> 3 -> 4 -> 5 ... -> 7
Since 7 = key, our program terminates with a sucess.
If the key was not found, we'd search all the way to value = 10,
at which point the algorithm terminates with a failure; that is,
the key was not in the array.
```

The scenario where the key is not in the array is the worst case scenario. Alternatively, you may consider the scenario where our key is the last value in the list.<br>In this case, we must search through every item in the list. If the list is of some arbitrary size `n`, then our worst case scenario becomes `O(n)`.

### Binary Search

Binary search requires a sorted array to work properly. 

As we'll see, the time complexity for this algorithm performs better than linear search, so, oftentimes, it may be better to sort a vector first *before* searching through it.<br>You may want to sort first or, at the very least, maintain a sorted list, if your list has a large size `n`.

---

The steps for binary search are:
1. Get the midpoint of the array.
2. If the value at the midpoint of the array is our key, terminate.
3. If our key is less than the value at the midpoint, consider the "new" vector: `[0, m - 1]`, where `m` equals the midpoint of the array.
4. Else, our key must be greater than the value at the midpoint, so, consider: `[m + 1, n - 1]`.
5. Repeat steps 1-5 until key is found, or key isn't in array.

For example,

```
arr = [1, 2, 3, 4, 5, 10, 16, 17, 18, 19, 20]
size(arr) = 11
key = 4

The midpoint of the current array is: size(arr) / 2.
size(arr)/ 2 = 11/2 = 5, by integer math.
So, arr[5] = 10.
Since key < 10, we consider: [0, 4].

The new midpoint is: ((4 - 0) + 1) / 2 = 5/2 = 2.
So, arr[2] = 3.
Since arr[2] != key and key > 3, we consider: [3, 4].

The new midpoint is: ((4 - 3) + 1) / 2 = 2/2 = 1.
So, arr[1] = 5.
Since arr[1] != key and key < 5, we consider [3].

The new midpoint is: ((n - 1) + 1) / 2 = 1/2 = 0.
So, arr[0] = 4.
Since key = arr[0], our program terminates successfully.
If this wasn't our key, our program would've terminated unsuccessfully.
```

You'll notice that at each step, we're reducing the size of our problem in half.<br>Thus, binary search operates in **O(log<sub>2</sub>(n))** time.

---

## Tree/Graph Algos.

There are also two primary tree/graph vectors...sort of.<br>*(Check out some more advanced algorithms: [Dijkstra's algorithm](https://www.programiz.com/dsa/dijkstra-algorithm) and [Bellman-Ford's algorithm](https://www.programiz.com/dsa/bellman-ford-algorithm).)*

### Depth-First Search (DFS):

**Trees:**

Let's take a binary search tree (BST) for convenience and ease.

The DFS algorithm works as follows:

- Each node of a BST has at most two children. Depending on the form of traversal (inorder, preorder, and postorder), the algorithm changes, but not by much. We'll look at inorder.
- With an inorder traversal, we look at **LEFT_CHILD**, then **PARENT**, then **RIGHT_CHILD**. We repeat this process until we either: **(1)** find what we're looking for, or **(2)** we've searched through the entire tree.

Let's look at an example.
```
Take the following tree:

            10
         5      20
       1   6  15   29
       
For an inorder traversal, we'd write the tree as:
[1, 5, 6, 10, 15, 20, 29].
You'll notice the array is "sorted" from least to largest; that is, this array describes an inorder tree traversal.

How did we get this, though? 
Well, we start at the root--10.
Since 10 has a left child, we traverse to 5.
Since 5 has a left child, we traverse to 1.
Since 1 does not have a left child, and does not have a right child, we can print or store this value.
Our array is now: [1].

We return back to 5.
Since, we've regressed back to 5, we may add it to the vector.
Our array is now: [5].
Since 5 has a right child, we traverse to 6.
Since 6 has no left child, we "return" to 6, and add it to the array.
Since 6 has no right child, we return back to 5.
(Our array is now: [1, 5, 6].)
Since we've already visited/added 5 to the array, we return back to 10 (adding it to the vector).

Since 10 also has a right child, we traverse to 20.
Since 20 has a left child, we traverse to 15.
Since 15 does not have a left child, we "return" to 15, and add it to the list.

Etc., etc., etc.
LEFT, PARENT, RIGHT.
```

### Breadth-First Search (BFS):

**Trees:**

Let's, once again, look at a BST.

The BFS algorithm works as follows:

- Start at the node, and store its children for later analysis.
- If the node isn't the key we're searching for, continue on to the next node that you've stored.
  - Depending on the order you stored the node's children in, you may look at the left child first or the right child first.
- If the node isn't the key we're searching for, store this node's children, and continue to the next node.
- Etc., etc.

There's a hint in there about which data structure to use...<br>Let's take an example:

```
We have the same tree as above.
The tree as a vector, using BFS, would look like:
[10, 5, 20, 1, 6, 15, 29].


Walking through the algorithm...
Say our key = 21.

Starting at the root (10).
Since 10 != key, we store 10's children, 5 and 20.
We can now remove 10 from our consideration, so our data structure now holds: <5, 20>

Now, we're at 5.
Since 5 != key, we store 5's children: <5, 20, 1, 6>
We can now remove 5 from our consideration.

Now, we're at 20.
Since 20 != key, we store 10's children: <20, 1, 6, 15, 29>
We can now remove 20 from our consideration.

Now, we're at 1.
Since 1 != key, we store 1's children. Depending on your goal, you may actually find it beneficial to store a null pointer; oftentimes, though, you'd just check if 1 had non-null children. In which case, you'd add them to the queue.
We can now remove 1 from our consideration: <6, 15, 19>.

Etc., etc., etc.
```

---

**Graphs:**

We started with BST's for ease, but trees and graphs with more than just two children/connections are more applicable.

Really, the shift in our understanding comes from the fact that we must analyze a varying number of children per node, whereas before, we only had to consider two children per node. So, before, we could just say, go left, and then go right.

With varying children per node, the concept of "left" and "right" escapes us, and there's no other concept we can apply to trees/graphs with varying children. "Forward" and "backward" don't really make sense, but even if they did, that's still only four total descriptors.

Instead of attaching meaning to each connection, we return to our end goal. We know we must traverse each node. So, we know that, for each node, we must explore all of its connections. Therefore, for each node, we must maintain some sort of data structure that tracks all other nodes that a node is connected to, such that, when we reach a specific node, we know which node's it is connected to, and we may use some loop to traverse each connection.

*That said, the time complexity of both of these algorithms is **O(V + E)**, where **V** is the number of nodes and **E** is the number of edges.*<br>...For the most part, that is. Sometimes, this depends on your graph implementation, but using adjacency lists perform in this time.<br>I'd recommend looking at why this is. [This Quora post](https://www.quora.com/Why-is-the-complexity-of-DFS-O-V+E) helped me understand.

---

## BONUS!

# Red-Black Trees:

In learning the above algorithms, I figured it was about time I learned about red-black trees, which are a sort of self-balancing tree.

Self-balancing trees are an important topic. One of the benefits of using BST's are their time complexities for searching, inserting, and deleting (**O(log<sub>2</sub>(n))**). Sometimes, however, with non-self-balancing trees, if we keep inserting nodes which have a higher/smaller value than the previous node, then we'll have a tree that looks like:

```
10
    11
        12
            13
                14

or...

            20
         19
      18
   17
16
```

Our tree now looks like a linked list. We've now lost our logarithmic properties. We wish to keep these for efficiency purposes.

Self-balancing trees accomplish this. There are two primary types of self-balancing trees, one which is slightly better than another, but I decided to start with red-black trees as an introduction.<br>If curious, check out [AVL Trees](https://www.programiz.com/dsa/avl-tree).

---

With red-black trees, each node stores an additional 1-bit of information, denoting the color of the node. Can you guess which colors? Yep! Red or Black.<br>I decided to use an enumerated type for two reasons: **(1)** for readability, and **(2)** since a node can take one value at a time--either `RED` or `BLACK`.

This added node property determines whether a tree is balanced based on a number of tree properties:
1. The root node is `BLACK`.
2. Every leaf node is `BLACK`, including null nodes.
3. If a `RED` node has children, it's children are `BLACK`.
4. For each node, the number of `BLACK` nodes FROM this node (that is, not including this node), to each leaf node is the same.
   1. That is, the number of `BLACK` nodes along each path, starting from some arbitrary node, ending at any/all leaf nodes (including null's) are the same.

If a tree violates any of these properties, it must be fixed. You can imagine that, if you already have a valid red-black tree, then the only possible way this tree could ever be in violation of these properties is if you add/remove a node. So, whenever you add/remove a node, you must check to make sure these properties are not violated.

There's a relatively simple algorithm for ensuring a tree is balanced. It involves rotating subtrees of a tree to either: **(1)** bring larger subtrees up, or **(2)** pull smaller subtrees down.<br>
Luckily, there are patterns we look for, denoting which rotations we perform.

---

**Left Triangle Rotation:**

This looks like:
```
    10
  5
    7
```
Imagine that 10 is `BLACK`, 5 is `RED`, and 7 is `RED`.<br>
This is a violation of our 3rd property.

Since 7 is the newest node to the tree, it is the violating node, and since 7 is 5's right node and since 5 is 10's left node, this arrangement forms a triangle. We must rotate the 5,7 subtree in the opposite direction of 7, so our tree will look like:

```
        10
      7
    5
```

This is still a violation, since the absolute value of the difference of the left and right subtree's of node 10 is greater than 1.<br>
You'll notice now the arrangement is:

**Right Line Rotation:**

...where the new violating node is 5. Since the arrangement is: 5 is 7s left child and 7 is 10s left child, this is a right line rotation, since the nodes form a line and since we must rotate in the opposite direction of the violating node.

As this is a line rotation, we must not only rotate, but then recolor the original parent and grandparent nodes (that is, the parent and grandparent of the violating node, PRE-rotation).


Our new tree looks like:

```
    7
  5   10
```

...where 5 is `RED`, 7 is `BLACK`, and 10 is `BLACK`.<br>This is the final, balanced tree.

---

The operations are similar for **Right Triangle Rotation** and **Left Line Rotation**, respectively, only mirrored across the effective "y-axis" of the tree, or mirrored across the root node.

*Note: After each operation (that is, after each rotation), ensure the tree is not still in violation. There's typically a new violating node after a triangle rotation (the old parent node), but not one after a line rotation. In fact, most tend not to think of these "types" of rotation as triangle versus line. If you notice there's a triangle rotation, you can simply perform the corresponding left/right rotation, followed by a right/left rotation, respectively. This is shown in the above example, where we had a left rotation, followed by a right rotation. If we had started with the line formation, we'd just have to do a right rotation; it's the triangle formation which requires two rotations.*

There's a LOT more to this topic, implementation-wise, so I'd recommend checking it out.<br>I personally found helpful the [Programiz site](https://www.programiz.com/dsa/red-black-tree) and [Michael Sambol's](https://www.youtube.com/c/MichaelSambol) short, but extremely detailed algorithm videos.

---

Algos. are tough! :seedling:
