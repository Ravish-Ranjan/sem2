#ifndef COUNTSORT_CPP
#define COUNTSORT_CPP

#include <typeinfo>
#include <unordered_map>
#include <vector>
#include "../metric.cpp"

template <typename T>
int getDigitAt(T num, int at, int precision = 2) {
    long long scaled;

    if constexpr (std::is_floating_point_v<T>) {
        long long factor = std::pow(10, precision);
        scaled = std::llround(num * factor);
    } 
    else {
        long long factor = std::pow(10, precision);
        scaled = static_cast<long long>(num) * factor;
    }

    int idx = at + precision;

    if (idx < 0) return 0;

    while (idx--) scaled /= 10;

    return std::llabs(scaled % 10);
}

void countSort(json& data,int key,int at){
    int range = 0;
    if (data[0][key].is_number_integer()){
        range = 10;
    } else if (data[0][key].is_number_float()){
        range = 100;
    } else if (data[0][key].is_string()){
        range = 26;
    }

    std::vector<int> cummFreq(range,0);
    for (auto &elem : data) {
        if (range == 10) {
            int digit = getDigitAt<int>(elem[key].get<int>(), at);
            cummFreq[digit]++;
        }
        else if (range == 100) {
            int digit = getDigitAt<double>(elem[key].get<double>(), at);
            cummFreq[digit]++;
        }
        else if (range == 26) {
            char ch = std::toupper(elem[key].get<std::string>()[at]);
            cummFreq[ch - 'A']++;
        }
    }

    for(int i = 1; i<cummFreq.size(); i++){
        cummFreq[i] += cummFreq[i-1];
    }
    std::cout << "Got cummulative freq" << std::endl;
    json sol(data.size(),nullptr);
    for(int i = data.size()-1; i>=0; i--){
        printJson(data[i]);
        if (range == 10) {
            int digit = getDigitAt<int>(data[i][key].get<int>(), at);
            sol[--cummFreq[digit]] = data[i];
        }
        else if (range == 100) {
            int digit = getDigitAt<double>(data[i][key].get<double>(), at);
            sol[--cummFreq[digit]] = data[i];
        }
        else if (range == 26) {
            char ch = std::toupper(data[i][key].get<std::string>()[at]);
            sol[--cummFreq[ch - 'A']] = data[i];
        }
    }
    data = sol;
}

#endif