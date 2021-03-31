/*
 1. You are given two 32 bit numbers, N and M, and two bit positions, I and J. Write a method to insert M into N such that M starts at bit J
    and ends at bit I. You can assume that bits J through I have enough space to fit all of M. That is if M = 10011, you can assume that
    there are at least 5 bits between J and I. You would not, for example, have J=3 and I=2, because M could not fully fir between bit 3
    and bit 2.
    EXAMPLE
    Input: N=10000000000, M=10011, I=2, J=6
    Output: N=10001001100

 2. There is a building of 100 floors. If an egg drops from Nth floor or above, it will break. If it's dropped from any floor below, it
    will not break. You're given two eggs. Find N, while minimizing the number of drops for the worst case. Please find the answer and
    implement code which simulate your answer.

 3. Write recursive function to multiply two positive integers without using the * operator (or / operator). You can use addition,
    subtraction, and bit shifting, but you should minimize the number of those operations.

 4. Write a function that adds two numbers. You should not use + or arithmetic operators.

 5. Write a method to count the number of 2s between 0 and n.
*/

#include <stdio.h>

int test_1(int N, int M, int I, int J)
{
    int output;
    int insertedNumber = (M << I) | (N & ~(0xFFFFFFFF << I));

    output = insertedNumber | (insertedNumber & N);

    return output;
}

int test_2(int* building)
{
    int index = 50;

    while (index <= 100)
    {
        if (building[index] > 0)
        {
            break;
        }
        else
        {
            index += 1;
        }
    }

    if (index == 50)
    {
        index = 0;

        for (int i = 0; i <= index; i++)
        {
            if (building[index] > 0)
            {
                break;
            }
        }
    }

    return;
}

int main()
{
    // test_1
    int N, M, I, J;
    scanf("%d %d %d %d", &N, &M, &I, &J);
    printf("Test_1 output: ");
    printf("%d\n", test_1(N, M, I, J);


    // test_2
    int building[100];
    int floorLimit = (rand() % 100) + 1;

    printf("Lowest floor that will break the egg is %d\n", floorLimit);

    memset(building, 0, floorLimit);
    memset(&building[floorLimit], 1, (100 - floorLimit));

    printf("Floor search result: %d\n", test_2(building));

    return 0;
}