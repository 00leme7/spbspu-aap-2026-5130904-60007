// JUST A SAMPLE: average of numbers

#include <iostream>
// explicitely <cstdef> for std::size_t
#include <cstddef>

// define because MS VS return code is 4 byte
// while *nix is 1 byte
// compiler makes cast
#define ERROR_NOT_ENOUGH_DATA 2

int main()
{
// no spaces inside {}
  int a {0};
  int sum {0};
  std::size_t count {0};

// correct while loop

  while ((std::cin >> a) && (a != 0))
  {
    ++count;
    sum += a;
  }

// end of while due to
// 1. input error, e.g not an integer
// 2. zero entered end of the sequence

// check cin state after reading (1. above)
  if (!std::cin)
  {
    std::cerr << "Incorrect input" << '\n';
    return 1;
  }

// here we are when zero is read (2. above)
// so final calculation
  if (count == 0)
  {
    std::cerr << "Not enough data" << '\n';
    return ERROR_NOT_ENOUGH_DATA;
  }

  std::cout << (sum / static_cast<double>(count))<< '\n';
  return 0;
}
