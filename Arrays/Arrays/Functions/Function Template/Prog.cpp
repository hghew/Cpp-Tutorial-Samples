// Function Template
// Syntax:   template <class UserTypeName>
///			 Type0/UserTypeName FunctionName (Type1/UserTypeName Var1 , ...);
// When the template function name is called in the program, then the compiler substitutes the 
///		TypeName  for a proper type.
// To define more than one type parameter follow this syntax: template <class Type1 , class Type2 , ...>
// Note that it is necessary to place  class  before EACH type.
// Every type parameter in the template definition MUST appear in the function's parameter list
///		at least once.

#include <iostream>
#include <concepts>  // For C++20 concepts
#include <format>    // For std::format
#include <string>    // For std::string, std::getline
#include <vector>    // For parsing helper
#include <sstream>   // For std::stringstream in parsing helper
#include <stdexcept> // For error handling (though not strictly used by stoi/stod in this simplified version)

// Define the Comparable concept
template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>; // Check if less-than operator is supported
};

// Function template declaration using the Comparable concept
template <Comparable MyType>
MyType maximum(MyType Var1, MyType Var2, MyType Var3);

// Helper function to parse three values from a string
template <typename T>
bool parse_three_values(const std::string& line, T& val1, T& val2, T& val3) {
    std::stringstream ss(line);
    // Attempt to read three values directly
    if (ss >> val1 && ss >> val2 && ss >> val3) {
        // Check if there's any non-whitespace stuff left
        std::string remaining;
        if (std::getline(ss, remaining)) {
            if (remaining.find_first_not_of(" \t\n\v\f\r") != std::string::npos) {
                return false; // Extra non-whitespace characters found
            }
        }
        return true; // Successfully parsed three values and no extra tokens
    }
    return false; // Failed to parse three values
}

// Specialization for char to handle single characters correctly from a string
template <>
bool parse_three_values<char>(const std::string& line, char& val1, char& val2, char& val3) {
    std::vector<char> chars;
    for (char c : line) {
        if (!isspace(static_cast<unsigned char>(c))) {
            chars.push_back(c);
        }
    }

    std::stringstream ss(line);
    if (ss >> val1 && ss >> val2 && ss >> val3) {
        std::string remaining;
        if (std::getline(ss, remaining)) {
            if (remaining.find_first_not_of(" \t\n\v\f\r") != std::string::npos) {
                 if (chars.size() == 3) { // Fallback for "abc" if "a b c" with extra chars
                    val1 = chars[0];
                    val2 = chars[1];
                    val3 = chars[2];
                    return true;
                 }
                return false; 
            }
        }
        return true;
    }
    if (chars.size() == 3) { // Fallback for "abc"
        val1 = chars[0];
        val2 = chars[1];
        val3 = chars[2];
        return true;
    }
    return false;
}

int main()
{
    std::string line;

    // Integer input
    int int1, int2, int3;
    std::cout << "Enter 3 integers : ";
    std::getline(std::cin, line);
    if (parse_three_values(line, int1, int2, int3)) {
        std::cout << std::format("The MAX is : {}\n\n", maximum(int1, int2, int3));
    } else {
        std::cerr << "Invalid input for integers. Please enter three integers separated by spaces.\n\n";
    }

    // Double input
    double d1, d2, d3;
    std::cout << "Enter 3 doubles : ";
    std::getline(std::cin, line);
    if (parse_three_values(line, d1, d2, d3)) {
        std::cout << std::format("The MAX is : {}\n\n", maximum(d1, d2, d3));
    } else {
        std::cerr << "Invalid input for doubles. Please enter three doubles separated by spaces.\n\n";
    }

    // Character input
    char char1, char2, char3;
    std::cout << "Enter 3 characters : ";
    std::getline(std::cin, line);
    if (parse_three_values(line, char1, char2, char3)) {
        std::cout << std::format("The MAX is : {}\n\n", maximum(char1, char2, char3));
    } else {
        std::cerr << "Invalid input for characters. Please enter three characters.\n\n";
    }

    return 0;
}

// Function template definition using the Comparable concept
// The logic of this function remains the same as the original.
template <Comparable MyType>
MyType maximum(MyType Var1, MyType Var2, MyType Var3)
{
    MyType max = Var1; 
    if (max < Var2)
        max = Var2;
    if (max < Var3)
        max = Var3;
    return max;
}
