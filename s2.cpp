#include <iostream>
#include <string>

// Function to find the minimum number of patches needed to feed all the cows
// and print a configuration that uses the minimum amount of patches needed
// to feed the cows
void feed_cows(int n, int k, std::string breeds)
{
    // Initialize variables to keep track of the number of patches and
    // the current patch type
    int patches = 0;
    char patch = '.';

    // Loop through the cows
    for (int i = 0; i < n; i++)
    {
        // If the current cow's breed is different from the current patch type,
        // or if there is no patch within k positions, plant a new patch
        if (breeds[i] != patch || (i >= k && breeds[i - k] != patch))
        {
            patches++;
            patch = breeds[i];
        }
    }

    // Print the minimum number of patches needed to feed all the cows
    std::cout << patches << std::endl;

    // Reset the patch type
    patch = '.';

    // Loop through the cows again
    for (int i = 0; i < n; i++)
    {
        // If the current cow's breed is different from the current patch type,
        // or if there is no patch within k positions, plant a new patch
        if (breeds[i] != patch || (i >= k && breeds[i - k] != patch))
        {
            patch = breeds[i];
        }

        // Print the patch type for the current position
        std::cout << patch;
    }

    std::cout << std::endl;
}

int main()
{
    // Read in the number of test cases
    int t;
    std::cin >> t;

    // Loop through the test cases
    while (t--)
    {
        // Read in the number of cows and the maximum distance they are willing
        // to move to reach a patch
        int n, k;
        std::cin >> n >> k;

        // Read in the breeds of the cows
        std::string breeds;
        std::cin >> breeds;

        // Find the minimum number of patches needed to feed all the cows
        // and print a configuration that uses the minimum amount of patches
        // needed to feed the cows
        feed_cows(n, k, breeds);
    }

    return 0;
}
