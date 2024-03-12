/*
-- Desription:
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:
Input: grid = [[1]]
Output: 4

LeetCode: https://leetcode.com/problems/island-perimeter/description/

-- Solution:o find the perimeter of the island represented by the grid, you can iterate over each cell in the grid and check its surroundings to determine the number of sides of the island that are exposed to water.

-- Time And Space Complexities:
The time complexity of this solution is O(M×N), where
M is the number of rows and N is the number of columns in the grid. The space complexity is O(1) because we are using a constant amount of extra space regardless of the input size.
*/

#include "stdio.h"

int islandPerimeter(int **grid, int gridSize, int *gridColSize)
{
    int perimeter = 0;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < *gridColSize; j++)
        {
            if (grid[i][j] == 1)
            {
                perimeter += 4; // Assuming the cell is surrounded by water

                // Check left cell
                if (j > 0 && grid[i][j - 1] == 1)
                {
                    perimeter -= 2; // Subtract 2 if the left cell is land
                }

                // Check top cell
                if (i > 0 && grid[i - 1][j] == 1)
                {
                    perimeter -= 2; // Subtract 2 if the top cell is land
                }
            }
        }
    }

    return perimeter;
}

int main()
{
    int grid[4][4] = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int gridSize = 4;
    int gridColSize = 4;

    // Convert 2D array to pointer-to-pointer
    int *gridPtr[gridSize];
    for (int i = 0; i < gridSize; i++)
    {
        gridPtr[i] = grid[i];
    }

    int perimeter = islandPerimeter(gridPtr, gridSize, &gridColSize);

    printf("Perimeter = %d\n", perimeter);

    return 0;
}
