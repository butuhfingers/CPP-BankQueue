#include <iostream>
#include "LinkedList.cpp"

int main(int argc, char const *argv[])
{
    LinkedList<std::string> list;
    list.add("Hello");
    list.add("Another message");
    list.add("Third message!");
    std::cout << list[2] << std::endl;
    return 0;
}