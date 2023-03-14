#include "PmergeMe.hpp"

// const int K = 5;

void insertionSortVec(std::vector<int>& A, int p, int q) {
    for (int i = p; i < q; i++) {
        int tempVal = A[i + 1];
        int j = i + 1;
        while (j > p && A[j - 1] > tempVal) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tempVal;
    }
    // for (int i = p; i <= q; i++) {
    //     std::cout << A[i] << " ";
    // }
    // std::cout << std::endl;
}

void mergeVec(std::vector<int>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> LA(n1), RA(n2);
    for (int i = 0; i < n1; i++) {
        LA[i] = A[p + i];
    }
    for (int i = 0; i < n2; i++) {
        RA[i] = A[q + 1 + i];
    }
    int RIDX = 0;
    int LIDX = 0;
    for (int i = p; i <= r; i++) {
        if (RIDX == n2) {
            A[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            A[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            A[i] = LA[LIDX];
            LIDX++;
        } else {
            A[i] = RA[RIDX];
            RIDX++;
        }
    }
}

void mergeInsertVec(std::vector<int>& A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        mergeInsertVec(A, p, q);
        mergeInsertVec(A, q + 1, r);
        mergeVec(A, p, q, r);
    } else {
        insertionSortVec(A, p, r);
    }
}

// int main() {
//     std::vector<int> A;
//     A.push_back(5);
//     A.push_back(3);
//     A.push_back(9);
//     A.push_back(2);
//     A.push_back(8);
//     A.push_back(7);
//     A.push_back(1);
//     A.push_back(4);
//     A.push_back(6);
//     int n = A.size();
//     mergeInsertVec(A, 0, n - 1);
//     for (int i = 0; i < n; i++) {
//         std::cout << A[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }

