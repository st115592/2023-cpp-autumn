#include <iostream>

int main()
{
    int k = 0;
    int c = 0;
    std::cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int a = i;
        int b = 0;
        for(a; a > 0; a = a / 10)
        {
            b = b * 10 + (a % 10);
        }
        if (b == i)
        {
            c += 1;
        }
    }
    std::cout << c;

    return 0;
}
