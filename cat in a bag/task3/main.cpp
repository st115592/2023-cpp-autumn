#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    int k = 0;
    while (n != 0)
    {
        k += n % 10;
        n /= 10;
    }

    std::cout << k;
    return 0;
}
