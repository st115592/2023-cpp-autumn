#include <iostream>

int main()
{
    int b = 0;
    std::cin >> b;
    std::cout << ((1 + b) * (abs(b - 1) + 1)) / 2;
    return 0;
}
