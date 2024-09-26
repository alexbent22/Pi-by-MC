#include <iostream> // For input/output operations
#include <vector>   // For using vectors
#include <random>   // For random number generation
#include <cmath>    // For mathematical operations
#include <ctime>    // For measuring execution time

int main() {
    // Start measuring time
    std::clock_t start_time = std::clock();

    // Variables to count points inside the circle and total points in the square
    int circle = 0;
    int square = 0;

    // Vector to store our range of values for length and width
    std::vector<double> length(10000);
    std::vector<double> width(10000);

    // Fill the vectors with values from -1 to 1 (linspace equivalent in C++)
    for (int i = 0; i < 10000; i++) {
        length[i] = -1.0 + (2.0 * i / 9999.0);
        width[i] = -1.0 + (2.0 * i / 9999.0);
    }

    // Initialize random number generator
    std::random_device rd;  // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dis(0, 9999); // Distribution to generate random indices

    // Perform the Monte Carlo simulation
    for (int i = 1; i <= 100; ++i) {
        // Generate random index
        int l_index = dis(gen);
        int w_index = dis(gen);

        // Get random values from the vectors based on generated indices
        double l = length[l_index];
        double w = width[w_index];

        // Check if the point is inside the circle
        if (std::sqrt(l * l + w * w) <= 1.0) {
            circle++;
        }

        // Increment the number of points in the square
        square++;
    }

    // Calculate the approximate value of Pi
    double pi = 4.0 * circle / square;

    // Print the results
    std::cout << "Approximate value of Pi: " << pi << std::endl;

    // Print the time taken
    double duration = (std::clock() - start_time) / (double) CLOCKS_PER_SEC;
    std::cout << "Time taken: " << duration << " seconds" << std::endl;

    return 0;
}