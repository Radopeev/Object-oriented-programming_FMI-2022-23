#include "sort.hpp"


int main()
{
    int arr[5] = { 1,-1,-2,4,5 };
    sort(arr, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i]<<" ";
    }
    std::cout << std::endl;
    char arr2[6] = "opwal";
    sort(arr2, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";
    }
}