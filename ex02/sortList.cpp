#include "PmergeMe.hpp"
// const int K = 5;

// Insertion sort function for a given range of list elements
void insertionSortList(std::list<int>& A, int p, int q) {
    for (int i = p; i < q; i++) {
        // Get the value at index (i+1)
        int tempVal = *std::next(A.begin(), i + 1);
        int j = i + 1;
        // Shift elements to the right to make space for the current element
        while (j > p && *std::next(A.begin(), j - 1) > tempVal) {
            *std::next(A.begin(), j) = *std::next(A.begin(), j - 1);
            j--;
        }
        // Insert the current element at its correct position
        *std::next(A.begin(), j) = tempVal;
    }
}

// Merge two sorted sublists
void mergeList(std::list<int>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::list<int> LA, RA;
    // Copy elements from the left sublist to LA
    for (int i = 0; i < n1; i++) {
        LA.push_back(*std::next(A.begin(), p + i));
    }
    // Copy elements from the right sublist to RA
    for (int i = 0; i < n2; i++) {
        RA.push_back(*std::next(A.begin(), q + 1 + i));
    }
    int RIDX = 0;
    int LIDX = 0;
    // Merge LA and RA into A
    for (int i = p; i <= r; i++) {
        if (RIDX == n2) {
            *std::next(A.begin(), i) = LA.front();
            LA.pop_front();
            LIDX++;
        } else if (LIDX == n1) {
            *std::next(A.begin(), i) = RA.front();
            RA.pop_front();
            RIDX++;
        } else if (RA.front() > LA.front()) {
            *std::next(A.begin(), i) = LA.front();
            LA.pop_front();
            LIDX++;
        } else {
            *std::next(A.begin(), i) = RA.front();
            RA.pop_front();
            RIDX++;
        }
    }
}

// Recursive function to merge and sort the list
void mergeInsertList(std::list<int>& A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        mergeInsertList(A, p, q);
        mergeInsertList(A, q + 1, r);
        mergeList(A, p, q, r);
    } else { // If list size is smaller than or equal to K, use insertion sort
        insertionSortList(A, p, r);
    }
}


// int main() {
//     std::list<int> A;
//     A.push_back(3);
//     A.push_back(5);
//     A.push_back(9);
//     A.push_back(7);
//     A.push_back(4);
//     // A.push_back(3);
//     int n = A.size();
// 	mergeInsertList(A, 0 , n-1);
// 	// insertionSortLst(A, 0, K);
// 	// mergeLst(A, 0, K, A.size()-1);
// 	for (std::list<int>::iterator it = A.begin(); it != A.end(); ++it)
// 	std::cout << *it << " ";
// 	std::cout << std::endl;
// 	return 0;
// }

