#include <iostream>

int main(){
    int long long a = 0;
    std::cin >> a;
    std::cout << (a / 10 * (a / 10 + 1) * 100) + 25;
    return 0;
}
