
#include <iostream>

int main() {
	int n = 0;
	int n_o = 0;
	int n_f = 0;
	int n_t = 0;
	int n_tw = 0;
	int n_s = 0;
	std::cin >> n;
	n_s = n / 60;
    n_tw = (n % 60) / 20;
    n_t = (n % 20) / 10;
    n_f = (n % 10) / 5;
    n_o = n % 5;
	if (n_o * 15 >= 70) {
		n_o = 0;
		n_f += 1;
	}
	if (n_o * 15 + n_f * 70 >= 125) {
		n_o = 0;
		n_f = 0;
		n_t += 1;
	}
	if (n_o * 15 + n_f * 70 + n_t * 125 >= 230) {
		n_o = 0;
		n_f = 0;
		n_t = 0;
		n_tw += 1;
	}
	if (n_o * 15 + n_f * 70 + n_t * 125 + n_tw * 230 >= 440) {
		n_o = 0;
		n_f = 0;
		n_t = 0;
		n_tw = 0;
		n_s += 1;
	}
	std::cout << n_o << " " << n_f << " " << n_t << " " << n_tw << " " << n_s;
	return 0;
}
