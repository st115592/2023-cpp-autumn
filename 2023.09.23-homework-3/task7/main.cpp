#include <iostream>

int main()
{
    int n = 0;
    int k = 1;
    int i = 0;
    std::cin >> n;
    while(n > k)
    {
        k *= 2;
        i++;
    }
    std::cout << i;
    return 0;
}
