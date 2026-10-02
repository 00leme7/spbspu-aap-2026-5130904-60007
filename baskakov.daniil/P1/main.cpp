#include <iostream>
#include <cstddef>

namespace baskakov {
  struct Result {
    int value;
    int status;
  };

  Result count_local_min()
  {
    int prev = 0;
    int curr = 0;
    int next = 0;
    std::size_t total = 0;
    int cnt = 0;

    while (std::cin >> next && next != 0) {
      ++total;
      if (total >= 3) {
        if (curr < next && curr < prev) {
          ++cnt;
        }
      }
      prev = curr;
      curr = next;
    }

    if (!std::cin) {
      return {0, 1};
    }

    if (total == 0) {
      return {0, 2};
    }

    return {cnt, 0};
  }
}

int main()
{
  baskakov::Result res = baskakov::count_local_min();

  if (res.status == 1) {
    std::cerr << "Invalid input\n";
    return 1;
  }

  if (res.status == 2) {
    std::cerr << "No data\n";
    return 2;
  }

  std::cout << res.value << "\n";
  return 0;
}
