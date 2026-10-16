#include <iostream>

int main() {
long long p = 0;
long long cur = 0;
long long changes = 0;
bool is_first = true;

while (true) {
	if (!(std::cin >> cur)) {
		std::cerr << "ошибка\n";
		return 1;
	}

	if (cur == 0) {
		break;
	}

	if (is_first) {
		p = cur;
		is_first = false;
	}
	else {
		if ((p > 0 && cur < 0)
			|| (p < 0 && cur > 0)) {
			changes++;
		}
		p = cur;
	}
}

std::cout << changes << "\n";

return 0;
}
