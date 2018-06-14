auto allows us to declare a variable, and let the compiler figure out what the type is (from the static type of the initialiser)

Resource Acquisition is Initialisation (RAII)
    std::unique_ptr
    avoids the need for manual tracking using mechanisms such as Java's AutoCloseable or Net's IDisposable

Resource management
    Locks need to be released.

Most applications will be composed of broadly 2 catgegory
    resource mangement
    implement logic.

Shared Pointer (std::shared_ptr)
    it works by referncing-counting
    We can also have shared pointer for array

Unique pointer

auto pointer (will be removed in c++17)

noexcept functions. These are functions which quarantee never to throw an exception.
Declaring a function as noexcept allows certain optimizations
Most functions are noexcept(false) unless we explicitly state otherwise- the notable exception being destructors.

As an exception propagates up the call stack, we have a process referred to as 'stack unwinding', which destroys any local stack variables as their scope is exited.

In short, avoid throwing exceptions from destructors; it's almost always a bad idea. 

C++ has no direct equivalent of the finally constructed used by Java. This is because it is unnecessary; destructors and RAII are a better solution to the problem.

Rvalue References are references that can only bind to unamed objects, such as temporaries and return values. 
    They are important because they allow us to provide "move semantics", which can provide optimization opportunities.

    They can also be used to provide so-called "move-only" types, which turn out to be useful for single-ownership resources.