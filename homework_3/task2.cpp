//This solution uses https://github.com/GeorgiTerziev02/Object-oriented_programming_FMI/tree/main/Sem.%2009/Solutions/Vector%20(with%20move)
// and https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2012/Templates/Queue/Queue.hpp
#include <iostream>
#include "kPriorityQueue.hpp"


int main()
{
    //Example 
    kPriorityQueue<char> q(4);

    q.push('A', 0);
    q.push('B', 3);
    q.push('C', 2);
    q.push('D', 2);
    q.push('E', 1);


    std::cout << q.peek() << std::endl;; // B
    q.pop();

    std::cout << q.peek()<<std::endl; // C
    q.pop();

    std::cout << q.peek() << std::endl; // D
    q.pop();

    std::cout << q.peek() << std::endl; // E
    q.pop();

    std::cout << q.peek() << std::endl; // A
    q.pop();

}