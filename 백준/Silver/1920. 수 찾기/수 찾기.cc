#include <iostream>
#include <vector>
#include <algorithm>  // For sort() and binary_search()

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> nArray(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nArray[i];
    }

    std::cin >> m;
    std::vector<int> mArray(m);
    for (int i = 0; i < m; i++) {
        std::cin >> mArray[i];
    }

    std::sort(nArray.begin(), nArray.end());
    
    for (int i = 0; i < m; i++) {
        mArray[i] = std::binary_search(nArray.begin(), nArray.end(), mArray[i]) ? 1 : 0;
    }

    for (int val : mArray) {
        std::cout << val << '\n';
    }

    return 0;
}
