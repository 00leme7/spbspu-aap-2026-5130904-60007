#include <iostream>
#include <new>

namespace baskakov
{
  char* replaceSymbol(char* dest, const char* src, char oldChar, char newChar) noexcept
  {
    if (dest == nullptr || src == nullptr) {
      return dest;
    }

    char* target = dest;
    while (*src != '\0') {
      if (*src == oldChar) {
        *target = newChar;
      } else {
        *target = *src;
      }
      ++src;
      ++target;
    }
    *target = '\0';

    return dest;
  }

  size_t getLength(const char* str) noexcept
  {
    size_t length = 0;
    while (str != nullptr && str[length] != '\0') {
      ++length;
    }
    return length;
  }

  char* readLine(std::istream& in)
  {
    size_t capacity = 16;
    size_t size = 0;
    char* buffer = new char[capacity];

    char ch = '\0';
    while (in.get(ch)) {
      if (ch == '\n') {
        break;
      }

      if (size + 1 >= capacity) {
        size_t newCapacity = capacity * 2;
        char* newBuffer = new char[newCapacity];

        for (size_t i = 0; i < size; ++i) {
          newBuffer[i] = buffer[i];
        }

        delete[] buffer;
        buffer = newBuffer;
        capacity = newCapacity;
      }

      buffer[size++] = ch;
    }

    buffer[size] = '\0';
    return buffer;
  }
}

int main()
{
  const char targetChar = 'c';
  const char replacementChar = 'b';

  char* inputStr = nullptr;
  char* resultStr = nullptr;

  try {
    inputStr = baskakov::readLine(std::cin);

    size_t length = baskakov::getLength(inputStr);
    resultStr = new char[length + 1];

    baskakov::replaceSymbol(resultStr, inputStr, targetChar, replacementChar);

    std::cout << resultStr << '\n';

    delete[] inputStr;
    delete[] resultStr;
    return 0;
  } catch (const std::bad_alloc&) {
    delete[] inputStr;
    delete[] resultStr;
    std::cerr << "Error: Unable to allocate dynamic memory\n";
    return 1;
  }
}