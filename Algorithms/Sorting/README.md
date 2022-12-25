# Sorting, Intro.

There's a good sum of sorting algorithms out there, and, luckily for us, only a small amount of potentially new terminology that we must learn. Let's dive into that head-on first:

---

## Terminology:

### In-place Algorithms:

An in-place algorithm is one where an input data structure is altered with constant additional memory.

For example, if you were given a sorted array in descending order, but you wish to sort it in ascending order, an **out**-of-place algorithm would take that array, and return an entirely different array in reversed order. An **in**-place algorithm takes that array and manipulates it such that the same array is now in the reverse order. 

Those implementations might look something like:
```c++
void inPlace(std::vector<int>& vecToSort) {
    int origSize = vecToSort.size();
    for (int index = origSize - 1; index >= 0; index--)
        vecToSort.push_back(vecToSort[index]);
    vecToSort.erase(vecToSort.begin(), vecToSort.begin() + origSize);
}

std::vector<int> outPlace(std::vector<int> vecToSort) {
    std::vector<int> retVec;
    for (int index = vecToSort.size() - 1; index >= 0; index--) {
        retVec.push_back(vecToSort[index]);
    }
    
    return retVec;
}

int main(void) {
    // vec = {5, 4, 3, 2, 1}
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    
    // After this line is executed, newVec = {1,2,3,4,5}, but
    // vec still = {5,4,3,2,1}
    std::vector<int> newVec = outPlace(vec);
    
    // After this line is executed, vec = {1,2,3,4,5}
    inPlace(vec);
}
```

### Stable Algorithms:

An algorithm is stable if unsorted items with similar attributes keep their order in the sorted version.

For example, if we wish to sort the names in:
```
Frankie
Cameron
Axel
Francis
Gabriela
Harry
Braxton
Cielo
```

...by **first letter only**, a **stable** algorithm would sort them like:

```
Axel
Braxton
Cielo
Frankie
Francis
Gabriela
Harry
```
You'll note that, while `Francis` should come before `Frankie`, since `Frankie` showed up earlier in the list than `Francis` did, the stable algorithm maintains the order.

In an **unstable** algorithm, the sorted list might look something like:
```
Axel
Braxton
Cielo
Francis
Frankie
Gabriela
Harry
```

Note the word: "might". The unstable algorithm **might** sort like this, depending on your algorithm implementation. A better definition of stable vs. unstable is that **stable** algorithms can **guarantee** items will remain in their original order, while **unstable** algorithms **can't guarantee** the order will be preserved. So, it's entirely possible an unstable sorting algorithm will produce the same output as a stable one, and it's also entirely possible it will not produce the same output as a stable one.

Stable and unstable algorithms have a bit more depth to them, but this is the foundation. If you'd like to read more, I'd check out how radix sort works, and also [this SO post](https://stackoverflow.com/questions/1517793/what-is-stability-in-sorting-algorithms-and-why-is-it-important).

---

## Now, let's talk about complexity analysis:

### Bubble Sort:

Bubble sort works in that the largest numbers are "bubbled" up to the top, or back of, an array, like a fizzy soda. It's implemented by taking each individual number, checking to see if it's larger than the number next to it, and if it is, swap the two numbers.

This algorithm is O(n<sup>2</sup>), since it requires each number to be checked against the rest of them. 

### Selection Sort:

Selection sort works by finding the smallest number in the array, and placing at the next available spot in the front of the array. It's sort of like an inverse bubble sort. You're basically searching for the smallest number in the array, placing it at the beginning, then searching for the next smallest, and so on.

This algorithm is also O(n<sup>2</sup>), since you're searching for the smallest number in the array for every location in the array.

***The above two algorithms aren't all that useful, apart from teaching purposes.***

### Insertion Sort:

To describe insertion sort effectively, imagine that the array you are sorting is broken into two parts: (1) the portion of the array that is already sorted, and (2) the portion of the array that has not been sorted yet.

Insertion sort works as follows:
1. With some index, *i*, between `0` and the `size of the array - 1`, start with the index *i - 1*, and traverse backwards towards 0. This is the sorted part of the array.
2. If the values at index *i* is less than the value at *i - 1*, swap the values. Go to index *i - 1 - 1*.
3. Repeat previous step until the value which was originally at location *i* is in it's required position in the sorted half of the array. 

As you might imagine, this algorithm is also O(n<sup>2</sup>), since for every value in the array, we must iterate through the sorted portion of the array to find where it fits in. **However**, it performs particularly well for nearly sorted arrays, because it will skip the inner loop more often, since values are already where they are supposed to be.

So, while still O(n<sup>2</sup>)--particularly bad performance--it's a viable option for nearly sorted containers. 

---

### Merge Sort:

Merge sort is a divide and conquer algorithm. Here's how it works:
1. Starting with some array of size `n`, divide it in two pieces: `[0, n/2)` and `[n/2, n)`.
2. Recursively repeat the previous step until you're left with arrays of size `n = 1`. 
3. Once returned, merge the two arrays into one sorted array.
4. Repeat previous step until you achieve a fully sorted array.

This algorithm is particularly complex if you're not comfortable with recursion; I'd recommend looking at either my implementation or any number of the other ones available online.

This algorithm is O(n*log<sub>2</sub>(n)). This is because we're dividing the problem in half each function call, but we must also sort every subarray, which requires us to iterate through at most `n` elements. This is by far the most efficient algorithm we've come across, and it's well-known in the industry. An extremely useful and common algorithm to have in your back pocket.

### Quick Sort:

If merge sort sorts containers by sorting their broken-down pieces first, quick sort sorts containers by sorting its larger array first, then breaking it down into smaller pieces. The merge part of merge sort is *sort of* useless, depending on your implementation. Let's take a look:
1. In quick sort, you must choose an index. Any index. There are good choices and there are bad choices, but we'll dive into that later. For now, you'll take whatever value is at that index, and compare it to the rest of the values in the array. Ensure that every value which is **less** than the value at your chosen index is to the **left** of that value, and that every value which is **greater** than the value at your chosen index is to the **right** of that value. These values to the left and right of the chosen value do **NOT** need to be sorted; they just need to be either to the left or to the right of the chosen value.
2. After the previous step, the value at the index you chose will be in the position it should be in the sorted container once finished sorting. Don't touch it. Now, say your chosen value is now at some index `k`. You'll want to split the array into arrays: `[0, k)` and `(k, n)`.
3. Repeat the last two steps.

This is also a recursive algorithm. Let's dive into the time complexity:
- Now, this algorithm's worst case performance is O(n<sup>2</sup>). Average performance is nlog<sub>2</sub>(n). This is dependent on your index choice, which we denote your "pivot". 
- You want your pivot choice to be as random as possible; limit deterministic choices. Looking at a bare-bones example:
  - Say you're given an array `[5, 4, 3, 2, 1]`, and that your pivot is the first element in the array every time.
  - Your new arrays will look like: `{Base: [4, 3, 2, 1, 5], Broken: [4, 3, 2, 1]}, {Base: [3, 2, 1, 4], Broken: [3, 2, 1]}, ...`.
  - You'll notice that the problem is never being split in two. At this point, you're either bubbling up the largest to the top (bubble sort) or finding the minimum and bringing it to the front (selection sort).
- Now, let's look at the same example with a different pivot choice:
  - You may either do entirely random choices, or a median of three (MOT). I'll explain MOT, since it's less obvious:
  - Say you're given an array `[5, 4, 3, 2, 1]`. The size of the array is `n = 5`. The middle of the array is index `i = 2`. Our three candidates are therefore: `5, 3, 1`. Sorted, they are `1, 3, 5`. The median of this list is `3`, so this is our pivot.
  - Our subsequent arrays are: `{Base: [5, 4, 3, 2, 1], Broken: [2, 1], [5, 4]}, {Base: [2, 1], [5, 4]; Broken: [2], [5]`. 
  - In two steps (the same amount of steps we wrote in the first example), we've already sorted the entire array.

***Note: It's entirely possible that, even using MOT or random pivots, your pivot choices could still be the minimum/maximum value in an array, resulting in a n<sup>2</sup> runtime. It's just that this is a lot less likely to happen using MOT or random pivots. I'm assuming that it occurs less enough such that the average time complexity ends up being nlog<sub>2</sub>(n); at least, that's what the [Big O cheat sheet](https://www.bigocheatsheet.com/) says.***

So, quick sort is still a good, viable option, and is a useful and good algorithm to have in your back pocket. Why? Depending on your implementation (if not in-place), quick sort uses less memory than merge sort. A lot less memory, in fact; this is actually one of the drawbacks of merge sort, unless you're sorting externally. 

---

Phew, been at this café for a while now. I need another :coffee:; it's cold in here.
