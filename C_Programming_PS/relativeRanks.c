#include <stdio.h>
#include <stdlib.h>

/*
-- Description:
- You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

Example 1:
Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

Example 2:
Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

LeetCode: https://leetcode.com/problems/relative-ranks/description/

Solution:
# Approach
- We define a struct Athlete to store both the score and the original index of an athlete.

- The compareAthletes function is used for qsort to sort athletes in descending order of score.

- The findRelativeRanks function:

    - Allocates memory for an Athlete array to store athlete information.
    - Creates Athlete objects with score and original index.
    - Sorts the athletes array in descending order using qsort and the compareAthletes function.
    - Allocates memory for a result array to store rank strings.
Iterates

*/

// Structure to store athlete information (score and original index)
typedef struct
{
    int score;
    int original_index;
} Athlete;

// Comparison function for qsort (sorts in descending order of score)
int compareAthletes(const void *a, const void *b)
{
    const Athlete *athlete1 = (const Athlete *)a;
    const Athlete *athlete2 = (const Athlete *)b;
    return athlete2->score - athlete1->score;
}

char **findRelativeRanks(int *score, int scoreSize, int *returnSize)
{
    *returnSize = scoreSize;

    // Allocate memory for athletes array
    Athlete *athletes = (Athlete *)malloc(scoreSize * sizeof(Athlete));
    if (athletes == NULL)
    {
        return NULL; // Handle memory allocation failure
    }

    // Create athlete objects with score and original index
    for (int i = 0; i < scoreSize; i++)
    {
        athletes[i].score = score[i];
        athletes[i].original_index = i;
    }

    // Sort athletes in descending order of score
    qsort(athletes, scoreSize, sizeof(Athlete), compareAthletes);

    // Allocate memory for result array
    char **result = (char **)malloc(scoreSize * sizeof(char *));
    if (result == NULL)
    {
        free(athletes); // Free memory before returning NULL
        return NULL;
    }

    int rank = 1;
    for (int i = 0; i < scoreSize; i++)
    {
        int original_index = athletes[i].original_index;

        // Assign rank strings for special cases (1st, 2nd, 3rd)
        if (rank == 1)
        {
            result[original_index] = "Gold Medal";
        }
        else if (rank == 2)
        {
            result[original_index] = "Silver Medal";
        }
        else if (rank == 3)
        {
            result[original_index] = "Bronze Medal";
        }
        else
        {
            // Convert rank to string for other positions
            int len = snprintf(NULL, 0, "%d", rank);
            result[original_index] = (char *)malloc((len + 1) * sizeof(char));
            if (result[original_index] == NULL)
            {
                // Handle memory allocation failure within the loop
                for (int j = 0; j < i; j++)
                {
                    free(result[j]);
                }
                free(athletes);
                free(result);
                return NULL;
            }
            sprintf(result[original_index], "%d", rank);
        }

        // Handle athletes with the same score (assign the same rank)
        if (i > 0 && athletes[i].score == athletes[i - 1].score)
        {
            continue;
        }

        rank++;
    }

    // Free memory used for athletes array
    free(athletes);

    return result;
}

// Another Solution:
/*
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    int i, j, count = 1;
    char* firstRank[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    char** res = (char**)malloc((scoreSize + 1) * sizeof(char*));

    // for(i = 0; i < scoreSize; i++){
    //     if(i < 3){
    //         res[i] = (char*)malloc(sizeof(char)*15);
    //     }else{
    //         res[i] = (char*)malloc(sizeof(char)*2);
    //     }
    // }
    // qsort(score, scoreSize, sizeof(int), cmp);

    for(i = 0; i < scoreSize; i++){
        for(j = 0; j < scoreSize; j++){
            if(score[j] > score[i]){
                count++;
            }
        }
        //printf("%d\n", i);
        if(count > 3){
            res[i] = (char*)malloc(sizeof(char)*6);
            sprintf(res[i], "%d", count);
            //printf("%s\n", res[i]);
        }else {
            res[i] = (char*)malloc(sizeof(char)*15);
            res[i] = firstRank[count-1];
            //printf("%s\n", res[i]);
        }
        count = 1;
    }

    *returnSize = scoreSize;
    return res;
}
*/

int main()
{
    int score[] = {5, 4, 3, 2, 1};
    int n = sizeof(score) / sizeof(score[0]);

    int returnSize;
    char **ranks = findRelativeRanks(score, n, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%s ", ranks[i]);
    }
    printf("\n");

    // Free memory allocated for each rank string (result array)
    for (int i = 0; i < returnSize; i++)
    {
        free(ranks[i]);
    }
    free(ranks);

    return 0;
}
