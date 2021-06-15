
#include <iostream>
#include <vector>

float calcMean(std::vector<int> & numbers, std::vector<float> & probs, int number) {
    float value{};
    for (int i = 0; i < number; i++) {
        value += (numbers[i] * probs[i]);
    }
    return value;
}

void expectedMeanDisRand() {
    std::cout << "How many numbers? ";
    int number;
    std::cin >> number;
    std::vector<int> numbers(number);
    std::vector<float> probs(number);
    for (int i = 0; i < number; i++) {
        std::cin >> numbers[i];
    }
    for (int i = 0; i < number; i++) {
        std::cin >> probs[i];
    }
    std::cout << "\nThe expected mean is:\n";
    float value = calcMean(numbers, probs, number);
    std::cout << value << '\n';
}

void discreteVariance() {
    std::cout << "How many numbers? ";
    int number;
    std::cin >> number;
    std::vector<int> numbers(number);
    std::vector<float> probs(number);
    for (int i = 0; i < number; i++) {
        std::cin >> numbers[i];
    }
    for (int i = 0; i < number; i++) {
        std::cin >> probs[i];
    }
    std::cout << "\nThe expected variance is:\n";
    float value{};
    float mean = calcMean(numbers, probs, number);
    for (int i = 0; i < number; i++) {
        value += static_cast<float>(std::pow((numbers[i] - mean), 2) * probs[i]);
    }
    std::cout << value << '\n';
}

int main()
{
    int n;
    float p;
    std::cin >> n >> p;
    float value = std::sqrt((p * (1 - p)) / n);
    std::cout << value;
}


