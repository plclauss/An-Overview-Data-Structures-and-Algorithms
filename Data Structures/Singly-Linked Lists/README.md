# Linked Lists, Introduction:

---

*The structure with this one will be less rigid. I've tinkered with linked lists in the past, so there wasn't really a new concept that I had to learn. Not to say I didn't learn a lot, because I did. And I mean a LOT...*

---

## My First Attempt:

---

Initially, I tried to get fancy with linked lists: "I'm going to create *two* classes; one for the Nodes in the linked list, and one for the linked list itself."
<br>
Boy, oh boy, was that a mistake. I no longer have those bits of code, but let's analyze:
<br><br>

I had something similar to this:
```asm
class Node {
public:
    Node();
    Node(int value);
    
    ~Node();
    Node(const Node& originalNode);
    Node& operator=(const Node& originalNode);
    
    int getValue();
    void setValue();
    Node& getAddressOfNextNode();
    void setAddress();
private:
    int value;
    Node* next;
};
```
We'll break this into chunks.

---

`public:`
<br>

`Node()` and `Node(int value)`:
<br>

These are both constructors. They're typical in any class. Whenever you want to create another instance of this class, you invoke one of the class' constructors, depending on how much information you wish to specify for the instance you're creating at that time.
<br>

For instance, the first constructor `Node()` is the default constructor. If no additional information is passed in, the Node's value will be set to 0, and the Node's next pointer will be set to `nullptr`. 
<br>

**Note:** *I do **not** believe these values are implicitly set to 0 and null. You must explicitly write these yourself in any method you wish (There are several).*
<br><br>

The next block of functions are generally referred to as the "Rule of Three". If you want to explicitly define one of these functions, it's generally good practice to explicitly define the others, as well. We'll look at these in order:
<br>

**The Destructor:** 
<br>

Upon creating new instances of this class, you're likely using the keyword `new`, which allocates memory on the heap. You must give this memory back to the computer. Well, I suppose you don't *have* to, but you'll have memory leaks, and you'll be limiting your computer's capabilities in doing so. This is where the destructor comes into play:
<br>

The destructor's job is to free any memory the user may have allocated. If this isn't done, you will have memory leaks. To free memory that's been allocated on the heap with `new`, you must use the `delete` keyword. Specifically, use `delete` on the same name of the variable you initialized `new` with.
<br>

***If you choose not to write this function, C++ will define one for you implicitly.***
<br><br>

**The Copy Constructor:**
<br>

The copy constructor is called when a previously-initialized instance of that class has been passed into a function. In short, this is to prevent memory leaks/errors when your program terminates. The copy constructor will--can you guess? That's right! Create a copy of the instance of the class you passed in.
<br><br>

**The Copy Assignment Operator:**
<br>

The copy assignment operator is called when reassigning the contents of a previously-initialized instance of a class with *another* instance of the same class.
<br><br>

**Note:** There's a notable key difference between the copy constructor and the copy assignment operator, since both cam technically assign an instance of the same class with pertinent data:
<br>

The ***copy constructor*** assigns previously **uninitialized** instances of a class with the data of an initialized instance of that same class. THe ***copy assignment operator*** ***replaces*** the data of one instance of a class with the contents of another instance of that same class.
<br><br>

The final block of functions is extraneous, custom-written, and petty. I figured it best that the user not accidentally mess up their structure, so I made sure they couldn't blindly access the data of a specific instance, without calling a function first.
<br>
This is stupid because they could still alter the data as they please, but oh well. Let's move on.

---

The question is: ***Why was this implementation a bad idea?***
<br>

Really, it's just tedious and unnecessary. I put so much more work on the user. Instead of the user simply creating a list, and giving them the ability to add directly to it whatever they wanted, they must both create the list AND all the nodes they want in the list, prior to inserting them.
<br>

Furthermore, the extraneous functions at the end are not necessary. These can be accomplished, just as before, using one class for the linked list. Not to mention these functions only alter the status of up to two nodes at one time. Not very effective for a linked list.
<br>
Thus, we're probably better off with just a simple:
```asm
typdef struct Node {
    int data;
    Node* next;
}Node;
```

---

The current implementation of the linked list class compared to the previous one is relatively unchanged; *i.e.*, there aren't any mistakes worth pointing out.

## Classes:

---

We've generally covered most of what I know about C++ classes, already, but here are a few short, extra points:
<br>

1. I generally keep most of the functions public and all the data private. The functions I *don't* keep public are those that might change the private data themselves, or ones that aren't really applicable to the user. These functions are private, and just like the data, they're only accessible/usable through public functions.
2. Whenever a function is called, the instance the function is called from is implicitly passed into the function, under the keyword `this`. Therefore, any member function/data of the class is accessible through the arrow operator `->`.
   1. *Note:* Whenever you're dereferencing a pointer to access its member data, you may use the shorthand arrow operator, instead of combining the dereference operator with the dot notation.
   
## Smart Pointers in C++:

---

I did not experiment with these in this project, but I did learn about them, because when I asked about my original code to some peers, they asked me why I wasn't just using smart pointers.
<br>

Smart pointers are a sort of safeguard. They ensure an object is deleted (*i.e.*, the memory is given back to the computer), when the object is no longer in use (*i.e.*, whenever it exits the scope of the function it's contained in). This way, you don't have to worry about destructors; you'll know the smart pointer will handle it.
<br>

There are two types of smart pointers, though:
1. Unique Pointers
   1. Only one copy of the object exists, and it will be deleted when it reaches the end of its scope.
2. Shared Pointers
   1. "...a reference counting smart pointer that can be used to store and pass a reference beyond the scope of a function.", pulled directly from the CPP reference [website about smart pointers.](https://en.cppreference.com/book/intro/smart_pointers)

Choose whichever best suits your application.

---

That's it for today!
