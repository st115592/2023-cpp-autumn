#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    std::cin >> a;
    for(a; a > 0; a = a / 10)
    {
        b = b * 10 + (a % 10);
    }
    std::cout << b;

    return 0;
}
