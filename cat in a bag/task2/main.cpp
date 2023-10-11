#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    if(n >= 0)
    {
        for(int i = 0; i <= n; ++i)
        {
            std::cout << i << " ";
        }
    }
    if(n < 0)
    {
        for(int i = 0; i >= n; --i)
        {
            std::cout << i << " ";
        }
    }

    return 0;
}
