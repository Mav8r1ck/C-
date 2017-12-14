#include <iostream>
#include <vector>
#include "Header.h"











int main() {

    std::cout << max_function(2, 5) << std::endl;
    std::cout << mid_function(9, 8) << std::endl;


    std::vector<int> v1;
    v1 = vector_function<int>(15);
    std::cout << sum_of_elements(v1) << std::endl;

    std::vector<int> v2;
    v2 = vector_function<int>(15);
    vector_in_range(5, 20, v2);

    sort_vector(vector_function<int>(15));


        std::cout << "Hello, World!" << std::endl;
    return 0;
}