#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

int calculateSum(const std::vector<std::string>& operations) {
    std::stack<int> accountStack;

    for (const std::string& op : operations) {
        if (op == "+") {
           
            if (accountStack.size() < 2) {
                std::cerr << "Error: Insufficient operands for '+' operation." << std::endl;
                return 0;
            }
            int operand2 = accountStack.top();
            accountStack.pop();
            int operand1 = accountStack.top();
            accountStack.pop();
            accountStack.push(operand1 + operand2);
        }
        else if (op == "д") {
           
            if (accountStack.empty()) {
                std::cerr << "Error: Insufficient operand for 'д' operation." << std::endl;
                return 0;
            }
            int operand = accountStack.top();
            accountStack.pop();
            accountStack.push(operand * 2);
        }
        else if (op == "с") {
            
            if (!accountStack.empty()) {
                accountStack.pop();
            }
            else {
                std::cerr << "Error: No operand to cancel." << std::endl;
                return 0;
            }
        }
        else {
           
            int value;
            std::istringstream(op) >> value;
            if (value >= -333 && value <= 333) {
                accountStack.push(value);
            }
            else {
                std::cerr << "Error: Operand out of range [-333, 333]." << std::endl;
                return 0;
            }
        }
    }

   
    int sum = 0;
    while (!accountStack.empty()) {
        sum += accountStack.top();
        accountStack.pop();
    }

    return sum;
}

int main() {
    std::string input;
    std::cout << "Enter control commands separated by spaces: ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::vector<std::string> operations;
    std::string token;

    
    while (iss >> token) {
        operations.push_back(token);
    }

    
    int result = calculateSum(operations);
    if (result != 0) {
        std::cout << "Total sum: " << result << std::endl;
    }

    return 0;
}
