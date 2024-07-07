#include <iostream>
#include <vector>

int countNegatives(std::vector<std::vector<int>>& grid) {
    int m = grid.size();    // Number of rows
    int n = grid[0].size(); // Number of columns

    int count = 0; // Variable to keep track of the count of negative numbers
    int r = 0;     // Start from the first row
    int c = n - 1; // Start from the last column

    while (r < m && c >= 0) {
        if (grid[r][c] < 0) {
            // If the current element is negative, all elements to its left in the row will also be negative
            count += (m - r);
            c--; // Move to the previous column
        } else {
            // If the current element is non-negative, move to the next row
            r++;
        }
    }

    return count;
}

int main() {
    std::vector<std::vector<int>> grid1 = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    std::vector<std::vector<int>> grid2 = {
        {3, 2},
        {1, 0}
    };

    std::cout << "Example 1 Output: " << countNegatives(grid1) << std::endl; // Output: 8
    std::cout << "Example 2 Output: " << countNegatives(grid2) << std::endl; // Output: 0

    return 0;
}
