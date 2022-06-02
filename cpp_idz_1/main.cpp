#include "LinkedArray.h"
int main()
{
    DinamicArrayIntNumber arr(4, 4);
    std::cin >> arr;
    std::cout << arr << std::endl;
    arr.pushBack(1);
    std::cout << arr << std::endl;
    arr.popBack();
    std::cout << arr << std::endl;
    std::cout << arr.capacity() << std::endl;
    arr.resize(6);
    arr.pushBack(4);
    arr.pushBack(5);
    arr.pushBack(6);
    std::cout << arr << std::endl;

    DinamicArrayIntNumber arr1(3, 0);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    std::cout << arr1 << std::endl;
    arr1.createReserveSize(3);
    std::cout << arr1.capacity() << std::endl;
    arr1.pushBack(4);
    arr1.pushBack(5);
    arr1.pushBack(6);
    std::cout << arr1 << std::endl;
    DinamicArrayIntNumber arr3 = arr1 + arr;
    std::cout << arr3 << std::endl;
    DinamicArrayIntNumber arr4(8, 0);
    arr4[0] = 1;
    arr4[1] = 2;
    arr4[2] = 3;
    arr4[3] = 10;
    arr4[4] = 0;
    arr4[5] = 0;
    arr4[6] = 0;
    arr4[7] = 1;
    DinamicArrayIntNumber arr5(8, 0);
    arr5[0] = 1;
    arr5[1] = 2;
    arr5[2] = 3;
    arr5[3] = 10;
    arr5[4] = 0;
    arr5[5] = 0;
    arr5[6] = 0;
    arr5[7] = 1;
    std::cout << (arr4 >= arr5) << std::endl;
    std::cout << (arr4 > arr5) << std::endl;
    DinamicArrayIntNumber din(DinamicArrayIntNumber(1, 2));
    arr4 = DinamicArrayIntNumber(1, 2);
    arr4[0] = 3;
    din[0] = 4;
    std::cout << arr4 << std::endl;
    std::cout << din << std::endl;
}
