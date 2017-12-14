#pragma once

template<typename T>
T max_function(T i, T j){
    return(i>j) ? i:j;
}

template<typename T>
T mid_function(T i, T j){
    return (i+j)/2;
}

template<typename T>
std::vector <T> vector_function(int i){
    std::vector<T> v;
    for(int k = 0; k < i; k++){
        v.push_back(rand() % 100);
    }
    return std::move(v);
}

template<typename T>
T sum_of_elements(std::vector<T> v){
    T sum = v[0];
    for(int i = 1; i < v.size(); i++){
        sum +=v[i];
    }
    return sum;
}

template<typename T>
T vector_in_range(T i, T j, std::vector<T> v){
    std::vector<T> v2;
    for(int k = 0; k < v.size(); k++)
    {
        if(v[k] > i && v[k] < j){
            v2.push_back(v[i]);
        }
    }
    for(int k = 0; k < v2.size(); k++){
        std::cout<< v2[k];
    }
    std::cout<<std::endl;
}

template<typename T>
T sort_vector(std::vector<T> v){

    for(int k = 0; k < v.size(); k++){
        std::cout<< v[k];
    }
    std::cout<<std::endl;

    for (int n = 0; n < 10; n++)
    {
        T b = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                b = v[i];
                v[i] = v[i + 1];
                v[i + 1] = b;
            }
        }
        if (b == 0)
        {
            break;
        }
    }

    for(int k = 0; k < v.size(); k++){
        std::cout<< v[k];
    }
    std::cout<<std::endl;
}