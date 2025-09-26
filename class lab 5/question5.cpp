#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }
    int temp= (n % 10) + sumDigits(n / 10);
    return temp;
}

int nestedSum(int n) {
    int sum = sumDigits(n);
    if (sum / 10 == 0) {
        return sum;
    }
    return nestedSum(sum);
}

int main() {
    cout << "Enter your number: ";
    int n;
    cin >> n;
    int result = nestedSum(n);
    cout << "The final single-digit sum is: " << result << endl;
    return 0;
}