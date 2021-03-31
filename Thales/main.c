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
#include <stdlib.h>
#include <string.h>
#include <time.h>

int test_1(int N, int M, int I, int J)
{
    int output = (M << I) | (N & ~(0xFFFFFFFF << I)) | (N & ~(0xFFFFFFFF >> (31-J)));

    return output;
}

int test_2(char* building)
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
        for (int i = 0; i <= index; ++i)
        {
            if (building[i] > 0)
            {
                index = i;
                break;
            }
        }
    }

    return (index + 1);
}

int test_3(int input1, int input2)
{
    int output;

    if (input1 < input2)
    {
        test_3(input2, input1);
    }

    if (input2 > 0)
    {
        output = input1 + test_3(input1, input2 - 1);
    }
    else
    {
        output = 0;
    }
    
    return output;
}

int test_4(int input1, int input2)
{
    while (input2 > 0)
    {
        int carry = (input1 & input2) << 1;
        input1 = input1 ^ input2;
        input2 = carry;
    }

    return input1;
}

int test_5(int input)
{
    int count = 0;

    for (int i = 0; i < input; i++)
    {
        int tempVal = i;
        while (tempVal != 0)
        {
            if (tempVal % 10 == 2)
            {
                count++;
            }
            tempVal = tempVal / 10;
        }
    }

    return count;
}

int main()
{
    // test_1
    int N, M, I, J;
    printf("Insert input for test_1: ");
    scanf("%d %d %d %d", &N, &M, &I, &J);
    printf("Test_1 output: ");
    printf("%d\n", test_1(N, M, I, J));


    // test_2
    char building[100];
    int floorLimit;

    srand(time(0));
    floorLimit = (rand() % 100) + 1;

    printf("Lowest floor that will break the egg is %d\n", floorLimit);

    memset(building, 0, (floorLimit - 1));
    memset(&building[(floorLimit - 1)], 1, (100 - (floorLimit - 1)));

    for (int i = 0; i < 100; i++)
    {
        printf("%d ", building[i]);
    }
    printf("\n\n");
    printf("Floor search result: %d\n", test_2(building));


    // test_3
    int t3_input1, t3_input2;
    printf("Insert input for test_3: ");
    scanf("%d %d", &t3_input1, &t3_input2);

    printf("Multiplication result: %d", test_3(t3_input1, t3_input2));


    // test_4
    int t4_input1, t4_input2;
    printf("Insert input for test_4: ");
    scanf("%d %d", &t4_input1, &t4_input2);

    printf("Multiplication result: %d\n", test_4(t4_input1, t4_input2));


    // test_5
    int t5_input;
    printf("Insert input for test_5: ");
    scanf("%d", &t5_input);

    printf("Numer of 2s are: %d\n", test_5(t5_input));

    printf("\n\n");
    system("pause");
    return 0;
}