#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int start, end;
    std::cin >> start >> end;
    
    std::vector<bool> boolArr(end + 1, true);
    boolArr[0] = boolArr[1] = false;  // 0 and 1 are not prime numbers

    int limit = std::sqrt(end);
    for (int i = 2; i <= limit; i++) {
        if (boolArr[i]) {
            for (int j = i * i; j <= end; j += i) {
                boolArr[j] = false;
            }
        }
    }

    for (int i = start; i <= end; i++) {
        if (boolArr[i]) {
            std::cout << i << '\n';
        }
    }

    return 0;
}
