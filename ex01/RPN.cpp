#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input expression provided." << std::endl;
        return 1;
    }

    std::stack<int> numbers; // stack to store numbers

    // convert input expression string to a stringstream
    std::istringstream ss(argv[1]);

    std::string token;
    while (ss >> token) { // loop through all input tokens
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (numbers.size() < 2) { // not enough operands
                std::cerr << "Error: Insufficient operands for " << token << " operator." << std::endl;
                return 1;
            }
            int n2 = numbers.top(); numbers.pop();
            int n1 = numbers.top(); numbers.pop();
            int result;
            if (token == "+")
                result = n1 + n2;
            else if (token == "-")
                result = n1 - n2;
            else if (token == "*")
                result = n1 * n2;
            else if (token == "/") {
                if (n2 == 0) { // division by zero
                    std::cerr << "Error: Division by zero." << std::endl;
                    return 1;
                }
                result = n1 / n2;
            }
            numbers.push(result);
        }
        else { // token is a number
            int num = atoi(token.c_str()); // convert string to int
            numbers.push(num);
        }
    }

    if (numbers.size() != 1) { // final stack size should be 1
        std::cerr << "Error: Invalid input expression." << std::endl;
        return 1;
    }
    
    std::cout << numbers.top() << std::endl; // output final result
    return 0;
}
