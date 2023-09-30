#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    std::cin >> a;
    std::cin >> b;
    while(a != b)
    {
        if((a > 2 * b) && (a % 2 != 0))
        {
            a -= 1;
            std::cout << -1 << " ";
        }
        else if((a >= 2 * b) && (a % 2 == 0))
        {
            a /= 2;
            std::cout << ":2" << " ";
        }
        else if( a < 2 * b)
        {
            a -= 1;
            std::cout << -1 << " ";
        }
    }
    return 0;
}
