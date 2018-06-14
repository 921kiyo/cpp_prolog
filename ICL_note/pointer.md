typedef does not make any instance


## As part of type declaration
 
int a = 10;
int &x = a;
x is     another name of a;

int a = 10;
cout << &a;
address of 


## In expression

int a = 10;
int* p = &a;
[int *] p : p holds the address of some integer


int a = 10;
cout << *(&a) << endl;
Deferencing operator
content of memory being dereferenced. 

NULL is a special address

Valgrind : tracks all the memory leaks

try catch ... catches any errors if you do not know which kind of error you want to catch.
