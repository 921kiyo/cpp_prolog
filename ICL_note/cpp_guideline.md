https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md


# Google C++ Style Guide
https://google.github.io/styleguide/cppguide.html

- Avoid using forward declarations where possible.


## Functions

### Parameter Ordering

When defining a function, parameter order is: inputs, then outputs.

### Reference Arguments

All parameters passed by reference must be labeled const

### Use of const

Declare methods to be const whenever possible. Accessors should almost always be const.

### Integer Types

C++ does not specify the sizes of its integer types. Typically people assume that short is 16 bits, int is 32 bits and long long is 64 bits.

<stdint.h> defines types like int16_t, uint32_t, int64_t, etc. You should always use those in preference to short, unsigned long long and the like, when you need a guarantee on the size of an integer. Of the C integer types, only int should be used.

You should assume that an int is at least 32 bits, but don't assume that it has more than 32 bits. If you need a 64-bit integer type, use int64_t or uint64_t.

### File Names

Filenames should be all loswercase and can include underscores or dashes: my_userful_class.cc

### Type Names

Type names start with a capital letter and have a capital letter for each new word: MyExcitingClass

### Variable Names

Variable names and data members are all lowercase, with underscores between words: a_local_variable

Data members of classes additionally have trailing underscores: a_class_data_member_

### Namespace Names

Namespace names are all lower-case.

### Comment Style

// is much more common than /* */

### Class Comments

The class comment should provide the reader with enough information to know how and when to use the class, as well as any additional considerations necessary. In general, these comments do not describe how the function performs its task. Instead, that should be left to comments in the function definition.

You could put a small example code snippet. 

### Function declarations

Almost every function declaration should have comments immediately preceding it that describe what the function does and how to use it.

These comments should be descriptive ("Opens the file") rather than imperative ("Open the file").

- What the inputs and outputs are.
 -For class member functions: whether the object remembers reference arguments beyond the duration of the method call, and whether it will free them or not.
- If the function allocates memory that the caller must free.
- Whether any of the arguments can be a null pointer.
- If there are any performance implications of how a function is used.
- If the function is re-entrant. What are its synchronization assumptions?

### Function Definision 

You might describe any coding tricks you use, give an overview of the steps you go through, or explain why you chose to implement the function in the way you di. 

### Global Variables

All global variables should have a comment describing what they are used for, and why it needs to be global

### TODO Comments

TODOs should include the string TODO in all caps, followed by the name, e-mail address, bug ID, or other identifier of the person or issue with the best context about the problem referenced by the TODO.

## Formatting

### Line Length

Each line of text should be at most 80 characters long.

An #include statement with a long path may exceed 80 columns.


### Non-ASCII Characters

Non-ASCII Characters should be rare, and must use UTF-8 formatting.

### Spaces vs. Tabs

Use only spaces, and indent 2 spaces at a time.
You should set your editor to emit spaces when you hit the tab key.

### Conditionals

In all cases you must have a space between if and the open parenthesis. 
In general, curly braces are not required for single-line statements. 

### Loops and Switch Statements

If not conditional on an enumerated value, switch statements should always have a default case.
If the default case should never excecute, simply assert
```
default:{
    assert(false);
}
```


### Pointer and Reference Expressions

```
x = *p;
p = &x;
x = r.y;
x = r->y;
```

There are no spaces around the period or arrow when accessing a member.
Pointer operators have no space after the * or &.


### Class Format

```
class MyClass : public OtherClass {
 public:      // Note the 1 space indent!
  MyClass();  // Regular 2 space indent.
  explicit MyClass(int var);
  ~MyClass() {}

  void SomeFunction();
  void SomeFunctionThatDoesNothing() {
  }

  void set_some_var(int var) { some_var_ = var; }
  int some_var() const { return some_var_; }

 private:
  bool SomeInternalFunction();

  int some_var_;
  int some_other_var_;
};
```


