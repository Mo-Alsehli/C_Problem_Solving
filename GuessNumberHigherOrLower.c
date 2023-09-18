int guess(int num); // This is the provided API function

int guessNumber(int n)
{
    int left = 1;
    int right = n;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int result = guess(mid);

        if (result == 0)
        {
            return mid; // Found the correct number
        }
        else if (result == 1)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Not found (this line is unlikely to be reached)
}
