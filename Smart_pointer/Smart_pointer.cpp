
#include <iostream>
#include "uniq_ptr.h"
#include "Shared_ptr.h"

using namespace std;
class Test {
public:
    int number;
    Test() = default;
    ~Test() = default;
    Test(int number)
    {
        this->number = number;
    }
    int GetNumber()
    {
        return number;
    }
};
int main() {
    /*Share_pointer <Test> p1(new Test);
    Share_pointer <Test> p2(p1);
    Share_pointer <Test> p3;
    p3 = p1;
        cout << "Hello, world!\n";
    cout << p1.get_counter() << endl;
    p1.~Share_pointer();
    cout << p1.get_counter() << endl;*/
    uniq_ptr<Test> up(new Test(7));
    uniq_ptr<Test> i = up.reales();
    i.Swap(up.get());
    return 0;

}

