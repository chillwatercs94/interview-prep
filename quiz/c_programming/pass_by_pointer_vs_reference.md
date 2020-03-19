passing by pointer vs reference

In C++, we can pass parameters to a function either by pointers or by reference. In both the cases, we get the same result.
So the following question is inevitable; when is one preferred over the other? What are the reasons we use one over the other?


References are generally implemented using pointers. A reference is same object, just with a different name and reference must refer to an object. Since references can't be NULL, they are safer to use.
    1. A pointer can be re-assigned while reference cannot, and must be assigned at initialization only
    2. Pointer can be assigned NULL directly, whereas reference cannot
    3. Pointers can interate over an array, we can use ++to go to the next item that a pointer is pointing to.
    4. A pointer is a variable that holds a memory address. A reference has the same memory address as the item it references.
    5. A pointer to a class/struct uses -> to access it's members whereas a reference uses a . (dot operator)
    6. A pointer needs to be dereferenced with * to access the memory location it points to, whereas a reference can be used directly.

