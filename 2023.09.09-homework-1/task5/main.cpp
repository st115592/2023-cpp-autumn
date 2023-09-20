#include <iostream>

int main(){
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    std::cin >> a;
    std::cin >> b;

    c = a * b % 109;

    d = ( c + 109 ) % 109 + 1;

    std::cout << d;
    return 0;
}
