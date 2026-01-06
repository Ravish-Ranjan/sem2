#include "input.cpp"
#include "runner.cpp"
#include <iostream>

template <typename T>
void bubbleSort(std::vector<T>& arr){
    for (int i = 0; i < arr.size() -1; i++){
        for (int j = 0; j < arr.size() - i -1; j++){
            if (arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    Input<> inp1(10,"int");
    Input<> inp2(20,"int");
    Input<> inp3(30,"int");
    Input<> inp4(40,"int");
    Input<> inp5(50,"int");
    Input<> inp6(60,"int");
    Input<> inp7(70,"int");
    Input<> inp8(80,"int");
    Input<> inp9(90,"int");
    Input<> inp10(100,"int");
    inp1.genInput();
    inp2.genInput();
    inp3.genInput();
    inp4.genInput();
    inp5.genInput();
    inp6.genInput();
    inp7.genInput();
    inp8.genInput();
    inp9.genInput();
    inp10.genInput();
    std::vector<int> age1 = parse<int>(inp1.input[0]);
    std::vector<int> age2 = parse<int>(inp2.input[0]);
    std::vector<int> age3 = parse<int>(inp3.input[0]);
    std::vector<int> age4 = parse<int>(inp4.input[0]);
    std::vector<int> age5 = parse<int>(inp5.input[0]);
    std::vector<int> age6 = parse<int>(inp6.input[0]);
    std::vector<int> age7 = parse<int>(inp7.input[0]);
    std::vector<int> age8 = parse<int>(inp8.input[0]);
    std::vector<int> age9 = parse<int>(inp9.input[0]);
    std::vector<int> age10 = parse<int>(inp10.input[0]);

    Runner runner1(bubbleSort<int>);
    Runner runner2(bubbleSort<int>);
    Runner runner3(bubbleSort<int>);
    Runner runner4(bubbleSort<int>);
    Runner runner5(bubbleSort<int>);
    Runner runner6(bubbleSort<int>);
    Runner runner7(bubbleSort<int>);
    Runner runner8(bubbleSort<int>);
    Runner runner9(bubbleSort<int>);
    Runner runner10(bubbleSort<int>);

    for (int i = 0; i< 10; i++){
        std::vector<int> age_copy = age1;
        runner1.run(age_copy);
    }
    for (int i = 0; i< 10; i++){
        std::vector<int> age_copy = age2;
        runner2.run(age_copy);
    }
    for (int i = 0; i< 10; i++){
        std::vector<int> age_copy = age3;
        runner3.run(age_copy);
    }
    for (int i = 0; i< 10; i++){
        std::vector<int> age_copy = age4;
        runner4.run(age_copy);
    }
    for (int i = 0; i< 10; i++){
        std::vector<int> age_copy = age5;
        runner5.run(age_copy);
    }
    for (int i = 0; i< 10; i++){
        std::vector<int> age_copy = age6;
        runner6.run(age_copy);
    }
    for (int i = 0; i< 10; i++){
        std::vector<int> age_copy = age7;
        runner7.run(age_copy);
    }
    for (int i = 0; i< 10; i++){
        std::vector<int> age_copy = age8;
        runner8.run(age_copy);
    }
    for (int i = 0; i< 10; i++){
        std::vector<int> age_copy = age9;
        runner9.run(age_copy);
    }
    for (int i = 0; i< 10; i++){
        std::vector<int> age_copy = age10;
        runner10.run(age_copy);
    }

    std::cout << "Avg. Time (age1) : " << runner1.getAvgTime() << "," << runner2.getAvgTime() << "," << runner3.getAvgTime() << "," << runner4.getAvgTime() << "," << runner5.getAvgTime() << "," << runner6.getAvgTime() << "," << runner7.getAvgTime() << "," << runner8.getAvgTime() << "," << runner9.getAvgTime() << "," << runner10.getAvgTime() << std::endl;

    return 0;
}