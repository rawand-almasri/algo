#include <iostream>
#include <chrono>
#include <functional>

using namespace std;

// Iterative factorial function
long long iterative_factorial(int n)
{
    long long f = 1;
    for (int i = 1; i <= n; ++i)
    {
        f *= i;
    }
    return f;
}

// Recursive factorial function
long long recursive_factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * recursive_factorial(n - 1);
}

// Function to measure execution time
double measure_time(std::function<long long(int)> func, int n)
{
    auto start = chrono::high_resolution_clock::now();
    func(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::micro> duration = end - start;
    return duration.count();
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }


    double iterative_time = measure_time(iterative_factorial, n);
    long long iterative_result = iterative_factorial(n);

    double recursive_time = measure_time(recursive_factorial, n);
    long long recursive_result = recursive_factorial(n);


    cout << "Factorial of " << n << " (Iterative): " << iterative_result << endl;
    cout << "Iterative Time: " << iterative_time << " microseconds" << endl;

    cout << "Factorial of " << n << " (Recursive): " << recursive_result << endl;
    cout << "Recursive Time: " << recursive_time << " microseconds" << endl;



    return 0;
}
