inline function?

    When the program executes the function call instruction the CPU stores the memory address of the instruction following 
 the function call, copies the arguments of the function on the stack and finally transfers control to the specified function. The CPU then executes the function code, stores the function return value in a predefined memory location/register and returns
control to the calling function. This can become an overhead if the execution time of the function is less than the switching time from the caller function to called function (callee). For functions that are large and/or perform complex tasks, the overhead of the function call is usually insignificant compared to the amount of time the function takes to run. However, for small, commonly-used functions, the time needed to make the function call is often a lot more than the time needed to actually execute the function's code. This overhead occurs for small functions because of execution time of small function is less than the switching time.

    Inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the inline function gets inserted or substituted at the point of inline function call. This substitution is performed by the compiler at compile time. Inline function may increase efficiency if it is small.

    Inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining. Compiler may not perform inlining in such circumstances.
    1. Function contains loop
    2. Function contains static variables
    3. Function is recursive
    4. Function return type is other than void, and the return statement doesn't exist in function body.
    5. Function contains switch or goto statement

Advantages:
    1. Function call overhead doesn't occur
    2. Saves the overhead of push/pop variables on the stack when function is called
    3. Saves overhead of a return call from a function
    4. When you inline a function, you may enable compiler to perform context specific optimization on the body of function.
       Such optimizations are not possible for normal function calls. Other optimizations can be obtained by considering the flows
       of calling context and the called context.
    5. Inline function may be useful (if it is small) for embedded systems because inline can yield less code than the function call preamble and return

Disadvantages:
    1. Too many inline functions then the size of the binary executable will be large, because of the duplication of same code.
    2. Reduce instruction cache hit rate, thus reducing the speed of instruction fetch from that of cache memory to that of primary memory.

    It is only useful to make the function inline if the time spent during a function call is more compared to the function body execution time.




Macro

    When the preprocessor comes accross any occurrences of SUM(first, last) in the code, then that text will be replaced by (first + last). When would one want to use a macro? Usually when what you're substituting for is very simple, and does not justify the overhead of a function call. Remember that function calls do incur overhead.


Inline function vs macro:

    Inline functions, are parsed by the compiler directly instead of the preprocessor. Inline functions look very similar to regular functions. 

    The difference between an inline function and a regular function is that wherever the compiler finds a call to an inline function, it writes a copy of the compiled function definition.

    The fact that macros use text replacement creates the potential for bugs. Suppose we have the following code:

 #define DOUBLE(X) X*X

 int y = 3;
 int j = DOUBLE(++y);



    Another problem with macros occurs with binding. Suppose we have a macro with two statements, and then we try to use that macro with an if statement. If we decide not to use the curly brackets with out if statement, then we will have something that looks like this

    Debugging macros is difficult. This is because the proprocessor does the textual replacement for macros, but that textual replacement is not visible in the source code itself. Because of this, it's generally considered a good idea to use inline functions over macros.

