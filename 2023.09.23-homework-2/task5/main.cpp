#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    if(n == 1 || n % 100 == 1 || (n % 10 == 1 && n % 100 != 11)) {
        std::cout << n << " " << "bochka";
    }
    else if( n % 100 > 11 && n % 100 < 15) {
        std::cout << n << " " << "bochek";
    }
    else if((n >1 && n < 5) || (n % 10 > 1 && n % 10 < 5)) {
        std::cout << n << " " << "bochki";
    }
    else {
        std::cout << n << " " << "bochek";
    }

    return 0;
}
