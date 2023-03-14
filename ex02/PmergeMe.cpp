#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cstdio>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    // Parse input sequence and store in containers
    for (int i = 1; i < argc; i++) {
        try {
            int num = std::atoi(argv[i]);
            if (num <= 0) {
                throw std::invalid_argument("Error: Input sequence must only contain positive integers.");
            }
            vec.push_back(num);
            lst.push_back(num);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }

    // Display unsorted sequence
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Sort with vector and measure time
    std::clock_t start_vec = std::clock();
    std::sort(vec.begin(), vec.end());
    std::clock_t end_vec = std::clock();
    double elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

    // Display sorted sequence with vector
    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Display time taken by vector sort
    std::cout << "Time to process a range of " << vec.size() << " elements with vector sort: " << elapsed_vec << " s" << std::endl;

    // Sort with list and measure time
    std::clock_t start_lst = std::clock();
    lst.sort();
    std::clock_t end_lst = std::clock();
    double elapsed_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC;

    // Display sorted sequence with list
    std::cout << "After: ";
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Display time taken by list sort
    std::cout << "Time to process a range of " << lst.size() << " elements with list sort: " << elapsed_lst << " s" << std::endl;

    return 0;
}
