#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>
#include <new>

namespace semenov {
  char* readLine(size_t* length)
  {
    const size_t initialLength = 10;
    size_t len = initialLength;
    size_t size = 0;
    char* buffer1 = new char[len];

    char c = 0;
    try {
      while (std::cin.get(c) && c != '\n') {
        if (size >= len - 1) {
          if (len > std::numeric_limits< size_t >::max() / 2) {
            throw std::bad_alloc();
          }
          len *= 2;
          char* newBuffer = new char[len];
          std::copy(buffer1, buffer1 + size, newBuffer);
          delete[] buffer1;
          buffer1 = newBuffer;
        }
        buffer1[size++] = c;
      }
    } catch (...) {
      delete[] buffer1;
      throw;
    }
    buffer1[size] = '\0';
    *length = size;
    return buffer1;
  }

  char* fetchlitters(const char* line1, const char* line2, char* result) noexcept
  {
    int amount = 0;
    bool found = false;
    for (size_t i = 0; line1[i] != '\0'; ++i) {
      char c = static_cast< char >(std::tolower(static_cast< unsigned char >(line1[i])));
      if (c < 'a' || c > 'z') {
        continue;
      }
      found = false;
      for (int x = 0; x < amount; ++x) {
        if (result[x] == c) {
          found = true;
          break;
        }
      }
      if (!found) {
        result[amount++] = c;
      }
    }
    for (size_t j = 0; line2[j] != '\0'; ++j) {
      char c = static_cast< char >(std::tolower(static_cast< unsigned char >(line2[j])));
      if (c < 'a' || c > 'z') {
        continue;
      }
      found = false;
      for (int x = 0; x < amount; ++x) {
        if (result[x] == c) {
          found = true;
          break;
        }
      }
      if (!found) {
        result[amount++] = c;
      }
    }
    std::sort(result, result + amount);
    result[amount] = '\0';
    return result;
  }
}

int main()
{
  size_t length1 = 0;
  char* line1 = nullptr;
  const char* line2 = "def ghk";
  char result[28] = {};

  try {
    line1 = semenov::readLine(&length1);
    std::cout << semenov::fetchlitters(line1, line2, result) << "\n";
  } catch (const std::bad_alloc&) {
    delete[] line1;
    std::cerr << "Not enough memory\n";
    return 1;
  }
  delete[] line1;
  return 0;
}
