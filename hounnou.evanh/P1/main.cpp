#include <iostream>

namespace hounnou {
  int processSequence() {
    int prev1 = 0;
    int prev2 = 0;
    int current = 0;
    int count = 0;
    int totalCount = 0;

    if (!(std::cin >> prev1)) {
      std::cerr << "Incorrect input" << '\n';
      return 1;
    }
    if (prev1 == 0) {
      std::cerr << "Not enough data" << '\n';
      return 2;
    }
    totalCount = 1;

    if (!(std::cin >> prev2)) {
      std::cerr << "Incorrect input" << '\n';
      return 1;
    }
    if (prev2 == 0) {
      std::cerr << "Not enough data" << '\n';
      return 2;
    }
    totalCount = 2;

    while (std::cin >> current && current != 0) {
      ++totalCount;
      if (current == prev1 + prev2) {
        ++count;
      }
      prev1 = prev2;
      prev2 = current;
    }

    if (!std::cin) {
      std::cerr << "Incorrect input" << '\n';
      return 1;
    }

    if (totalCount < 3) {
      std::cerr << "Not enough data" << '\n';
      return 2;
    }

    std::cout << count << '\n';
    return 0;
  }
}

int main() {
  return hounnou::processSequence();
}