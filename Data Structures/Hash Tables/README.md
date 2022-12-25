# Hash Tables C++, Introduction:

---

## Declaring Hash Tables:
A couple of things to note:
1. Hash tables in C++ are not called hash tables. They are some form of a map or a set.
   1. The closest data structure in C++ to a hash table is the `std::map` data structure. However, the "backing data structure," as it was explained to me, is a balanced tree, so all operations within `std::map` take `O(log(n))`.
      1. The one benefit of `std::map`, obviously, is then your keys are in sorted order, unlike those in a traditional hash table.
   2. The conventional `O(1)` hash table is an `std::unordered_map`. This is the one I'll be using for now.
2. In order to use hash tables, you'll need to write:
`#include <unordered_map`.

To declare a hash map, you must write:<br>
`std::unordered_map<XXX, XXX> NAME;`, where `XXX` are data types, and `NAME` is what you'll be referring to your map as throughout the program. By default, I believe the hash map is empty, though there are specific input parameters you could include upon declaration to change this, along with other things. Check out the documentation [here](https://www.cplusplus.com/reference/unordered_map/unordered_map/).

---

## Inserting and Searching:
As far as this project goes, it was only necessary for me to insert items and search for those items. Specifically, I needed to find the first recurring character in an array of integers. So, I figured I'd store the key as the actual integer within the integer array, and store the index of the integer as the mapped value.
<br>
### Insert:
In order to insert, you must specify the `[key, value]` pair to be inserted into your map. While you could make a pair manually, via the `std::pair` and `std::make_pair` functions, it seemed easier, at least in this application, to use only the `std::make_pair` function, which I believe is smart enough to figure out the data types of the parameters entered. Thus, no need to define a `std::pair` separately.<br>
The proper insertion syntax is:<br>
`NAME.insert(std::make_pair(YYY, YYY))`, where `YYY` are the `[key, value]` pair.
<br>
### Search:
To search for a particular element in your map, you'll need to use the `NAME.find(YYY)` function. Note the following:
1. This function searches through the **KEYS** in your map.
2. This function returns an **ITERATOR** to the location of the key in your map, **IF** it exists. If it does **NOT** exist, it will return `unordered_map::end`.
   1. Thus, to check if a specific `YYY` is in your map, you must check:
`if (NAME.find(YYY) != NAME.end())`.
