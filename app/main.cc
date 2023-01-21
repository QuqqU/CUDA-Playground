#include <mylib/lucky7/lucky7.h>
#include <mylib/shape.h>

int main() {
    shape::Rectangle rect(10, 30);

    rect.Print();

    int a = lucky7::lucky7();

    return 0;
}
