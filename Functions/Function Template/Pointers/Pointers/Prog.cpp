// Pointers : Introduction and principles.
// & : Address operator.
// * : indirection (or dereferencing) operator.
// Using * and & together only returns the address. &*VarPoint = &Var
//													 *&VarPoint = &Var

// Educational Comment:
// This sample demonstrates basic raw pointer mechanics with variables on the stack.
// For pointers that own dynamically allocated memory (i.e., memory allocated with `new`),
// modern C++ strongly prefers using smart pointers like `std::unique_ptr` or `std::shared_ptr`.
// Smart pointers automatically manage the lifetime of the allocated memory, helping to
// prevent common issues such as memory leaks and dangling pointers by clearly defining ownership.

#include <iostream> // For std::cin, std::cout
#include <format>   // For std::format

int main()
{
    int Var = 5;
    int *VarPoint; // It is said that VarPoint is of type ' int * ' which stores an address.
    
    VarPoint = &Var;  // & unary operator returns the address of the variable.
//  In General the statement :  VarPoint = Var;  is an error.
//  Because VarPoint is of type ' int * ' but Var is of type ' int ' and these are not convertable to each other.
    
    std::cout << std::format("The VALUE which is pointed by VarPoint is : {}\n", *VarPoint);
//  * unary operator returns the value of an address. See the difference in these 2 statements.
    std::cout << std::format("The ADDRESS which is pointed by VarPoint is : {}\n", static_cast<void*>(VarPoint));
    std::cout << std::format("The address of VarPoint itself is : {}\n\n", static_cast<void*>(&VarPoint));

    std::cout << "Enter a new value for VarPoint : ";
    std::cin >> *VarPoint;
    std::cout << std::format("The value of Var has become : {}\n", Var);

    return 0;
}
