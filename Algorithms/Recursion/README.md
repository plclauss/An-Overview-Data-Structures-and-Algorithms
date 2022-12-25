# Recursion, Intro.

## Recursive function, definition:

By definition, a ***recursive*** function is a function which calls itself. <br>
By contrast, an ***iterative*** function uses some tool (some form of loop) to repeat some instruction again and again, rather than calling itself.

### A quick example:

The following code simply prints "Hello" to the screen 5 times.
No spaces, no new lines; nothing fancy. Just prints: *HelloHelloHelloHelloHello*.
```c++
// Recursive
void printHello(int32_t numOfTimes) {
    if (numOfTimes == 0)
        return;
    std::cout << "Hello";
    return printHello(numOfTime - 1);
}
```
```c++
// Iterative
void printHello(int32_t numOfTimes) {
    while (numOfTimes != 0) {
        std::cout << "Hello";
        numOfTimes--;
    }
}
```

Both implementations accomplish the exact same thing. In fact, this is an effective theorem in the world of computer science: <br>
***Every iterative algorithm can be written recursively, and every recursive algorithm can be written iteratively.***

However, the performance of the two implementations may not always be the same, and it's up to the engineer to choose the best approach, provided their circumstances. <br>
Oftentimes, however, there are certain problems that inherently have recursive solutions. And there are certain data structures, like trees, where recursion is an effective necessity, since writing code for trees recursively is a lot easier than writing code for trees iteratively. <br>

It's a give and take, just like most other things in programming.

## Stack Overflow:

Ah, yes. The website we've all inevitably clicked on, with, likely, millions of queries and answers surrounding the world of computer science. <br>

Oh, not the website? That's just where the website got its name? Oh, ok. <br>

Well, if you're not familiar: Stack overflow occurs when a program attempts to use more stack memory than the computer has. While I'm unsure if the website got its name from recursion, it wouldn't come as a surprise, since, when writing recursive functions, it's incredibly easy to run into stack overflow issues. <br>

### Let's look at another example:

```c++
void recurse(int32_t n) {
    std::cout << n << std::endl;
    recurse(n + 1);
}
```

What does the function do if we set n to, say, 1 (*i.e.*, `n=1`)? <br>
What number will the function print up to? <br>

If the first question was easy to answer, but the second one wasn't, that's intentional. Unless you study data sciences, knew the capabilities of your respective computer's hardware, or are just really good at guessing, there's no way of knowing the answer to the second question. <br>

Eventually, the program will crash as a result of stack overflow. If you'll recall, the stack is responsible for tracking many things, including method activation records, that is, function calls, their parameters, and perhaps some metadata about the function. So, every function call will be placed on the stack. <br>
If we never pop from the stack, that is, return from any function, we'll continuously push to the stack, and since memory is ***not*** finite, we'll eventually run out, and the program will crash. This is stack overflow. <br>
***Note: Some applications have checks in place (like a maximum call stack size) to prevent the program from crashing. In this case, once the maximum call stack size has been reached, the program is terminated.***

To prevent stack overflow, you need a base case. Generally, there are two things you can do to help you write an effective recursive function:
1. Create a base case. Something that, on a subsequent function call, terminates the infinite loop, so that stack overflow does not occur.
   1. One such example exists above, where the if-statement checks if `numOfTries` has hit 0. If it has, just return. Otherwise, the algorithm hasn't been executed until completion, so we have the green light to keep going. (***Note that, when a function call has been returned, unless it's within a return statement, the program will pick up on the line AFTER the recursive function call.)***
2. Make the problem smaller and smaller with every function call. 
   1. A good example of this is the recursive implementation of finding the factorial of a given number, n. Notice that, if n is, say, 5 (`n=5`), then:
      1. `5! = 5 * 4 * 3 * 2 * 1 = 5 * 4! = 5 * 4 * 3! = ...`
      2. Thus, finding the factorial of a number amounts to multiplying that number to the factorial of that number minus one. 

---

This might not make sense at first, but start with simpler things, like factorials, Fibonacci numbers, and even tree traversals!<br>

When it comes to recursion, it's best to just take your hands off the keyboard, and draw a diagram. Work through the logic by hand; break the problems down into smaller ones. The answer usually comes naturally. And if you're stuck, just visit our good 'ole website; just don't steal code, unless you'll never learn anything.

Happy Coding! :saxophone:
