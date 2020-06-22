#include <iostream>
using namespace std;
template<typename T, size_t n>

void print_array(T const(& arr)[n])
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    int foo[5];
    int baz[5] = { 10, 20, 30 };
    int ping[5] = {};
    int pong[5] = { 16, 2, 77, 40, 12071 };
    int zap[] = { 10, 20, 30 };
    int boo[] { 10, 20, 30 };
    int input[] { 1, 2, 3, 4, 5 };
    string bar[5] { "a", "b", "c", "d", "e" };

    print_array(foo); // 498562656 32548 498603936 32548 498583976
    print_array(baz); // 10 20 30 0 0
    print_array(ping); // 0 0 0 0 0
    print_array(pong); // 16 2 77 40 12071
    print_array(zap); // 10 20 30
    print_array(boo); // 10 20 30
    print_array(input); // 1 2 3 4 5
    print_array(bar); // a b c d e

    return 0;
}
