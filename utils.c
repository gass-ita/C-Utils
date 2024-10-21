#include "utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Prints an array of integers of size `size`
void printArray(int *array, int size)
{
    printf("\n[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(",\t");
    }
    printf("]\n");
}

// Fills an array with random numbers between `min` and `max`
void randomArray(int *array, int size, int min, int max)
{
    for (int i = 0; i < size; i++)
        array[i] = randomNumber(min, max);
}

// Sorts an array of integers using Bubble Sort
void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
                swapInt(&array[j], &array[j + 1]);
}

// Finds the index of the maximum element in the array
int findMax(int *array, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
        if (array[i] > array[max])
            max = i;
    return max;
}

// Finds the index of the minimum element in the array
int findMin(int *array, int size)
{
    int min = 0;
    for (int i = 0; i < size; i++)
        if (array[i] < array[min])
            min = i;
    return min;
}

// Writes the contents of an array to a file
void writeArrayToFile(const char *filename, int *array, int size)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "[");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d", array[i]);
        if (i < size - 1)
            fprintf(file, ",\t");
    }
    fprintf(file, "]\n");
    fclose(file);
}

// Reverses the order of an array
void reverseArray(int *array, int size)
{
    for (int i = 0; i < size / 2; i++)
        swapInt(&array[i], &array[size - i - 1]);
}

// Returns the sum of the elements in an array
int getSumOfArray(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];
    return sum;
}

// Returns the average of the elements in an array
double getAvarageOfArray(int *array, int size)
{
    return (double)getSumOfArray(array, size) / size;
}

// Finds the distinct elements in an array
int *getDistinctArray(int *array, int size);

// Checks if an element exists in the array
int arrayContains(int *array, int size, int num)
{
    for (int i = 0; i < size; i++)
        if (array[i] == num)
            return 1;
    return 0;
}

// Replaces `val1` with `val2` in the array
void arrayReplace(int *array, int size, int val1, int val2)
{
    for (int i = 0; i < size; i++)
        if (array[i] == val1)
            array[i] = val2;
}

// Dynamically allocates a matrix with dimensions `rows` x `columns`
int **allocateMatrix(int rows, int columns)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(columns * sizeof(int));
    return matrix;
}

// Fills a matrix with random numbers between `min` and `max`
void randomMatrix(int **matrix, int rows, int columns, int min, int max)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = randomNumber(min, max);
}

// Prints a matrix
void printMatrix(int **matrix, int rows, int columns)
{
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Frees the memory allocated for a matrix
void freeMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

// Converts a string to uppercase
void toUpperCase(char *string)
{
    if (string == NULL)
        return;
    int size = strlen(string);
    for (int i = 0; i < size; i++)
        string[i] = toupper((unsigned char)string[i]);
}

// Converts a string to lowercase
void toLowerCase(char *string)
{
    if (string == NULL)
        return;
    int size = strlen(string);
    for (int i = 0; i < size; i++)
        string[i] = tolower((unsigned char)string[i]);
}

// Counts the occurrences of a character in a string
int countOccurrences(char *string, char c)
{
    int count = 0;
    int size = strlen(string);
    for (int i = 0; i < size; i++)
        if (string[i] == c)
            count++;
    return count;
}

// Returns the length of a string
int stringLenght(char *string)
{
    return strlen(string);
}

// Replaces `c1` with `c2` in a string
void stringReplace(char *string, char c1, char c2)
{
    if (string == NULL)
        return;
    int size = strlen(string);
    for (int i = 0; i < size; i++)
        if (string[i] == c1)
            string[i] = c2;
}

// Checks if a character exists in a string
int stringContains(char *string, char c)
{
    if (string == NULL)
        return 0;
    int size = strlen(string);
    for (int i = 0; i < size; i++)
        if (string[i] == c)
            return 1;
    return 0;
}

// Checks if a string starts with another string
int stringStartsWith(char *string, char *startString)
{
    int startStringSize = strlen(startString);
    int stringSize = strlen(string);
    if (startStringSize > stringSize)
        return 0;
    for (int i = 0; i < startStringSize; i++)
        if (string[i] != startString[i])
            return 0;
    return 1;
}

// Checks if a string ends with another string
int stringEndsWith(char *string, char *endString)
{
    int endStringSize = strlen(endString);
    int stringSize = strlen(string);
    if (endStringSize > stringSize)
        return 0;
    for (int i = stringSize - endStringSize; i < stringSize; i++)
        if (string[i] != endString[i])
            return 0;
    return 1;
}

// Removes leading and trailing spaces from a string
char *stringTrim(char *string)
{
    char *end;
    while (isspace((unsigned char)*string))
        string++;
    if (*string == 0)
        return string;
    end = string + strlen(string) - 1;
    while (end > string && isspace((unsigned char)*end))
        end--;
    *(end + 1) = '\0';
    return string;
}

// Capitalizes the first letter of a string and lowercases the others
void capitalize(char *string)
{
    if (string == NULL || *string == '\0')
        return;
    if (islower(string[0]))
        string[0] = toupper(string[0]);
    for (int i = 1; string[i] != '\0'; i++)
        if (isupper(string[i]))
            string[i] = tolower(string[i]);
}

// Reverses a string
void reverseString(char *string)
{
    int start = 0;
    int end = strlen(string) - 1;
    while (start < end)
    {
        swapChar(&string[start], &string[end]);
        start++;
        end--;
    }
}

// Checks if a string is empty
int isStringEmpty(char *string)
{
    return (string == NULL || string[0] == '\0');
}

// Checks if a string is a palindrome
int isStringPalindrome(char *string)
{
    int size = strlen(string);
    for (int i = 0; i < size / 2; i++)
        if (string[i] != string[size - i - 1])
            return 0;
    return 1;
}

// Swaps two integers
void swapInt(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Swaps two characters
void swapChar(char *c1, char *c2)
{
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

// Generates a random number between `min` and `max`
int randomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Swap double function
void swapDouble(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Swap float function
void swapFloat(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Write a string to a file
void writeStringToFile(const char *filename, char *string)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "%s\n", string);
    fclose(file);
}

// Write an integer to a file
void writeIntToFile(const char *filename, int num)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "%d\n", num);
    fclose(file);
}

// Write a double to a file
void writeDoubleToFile(const char *filename, double num)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "%lf\n", num);
    fclose(file);
}

// Write a character to a file
void writeCharToFile(const char *filename, char c)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "%c\n", c);
    fclose(file);
}

// Write an integer array to a file
void writeIntArrayToFile(const char *filename, int *array, int size)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "[");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d", array[i]);
        if (i < size - 1)
            fprintf(file, ",\t");
    }
    fprintf(file, "]\n");
    fclose(file);
}

// Write a double array to a file
void writeMatrixToFile(const char *filename, int **matrix, int rows, int columns)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            fprintf(file, "%d,\t", matrix[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
}

// Write a linked list to a file
void writeListToFile(const char *filename, Node *head)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }
    Node *current = head;
    while (current != NULL)
    {
        fprintf(file, "%d -> ", current->data);
        current = current->next;
    }
    fprintf(file, "NULL\n");
    fclose(file);
}

// Write a binary tree to a file
void writeTreeToFile(const char *filename, TreeNode *root)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }
    printTreeInOrder(root);
    fclose(file);
}

// Linked List functions

int arrayList_getElement(LinkedList *list, int index, void **value)
{
    if (list == NULL)
        return 1;

    ListNode *node = list->first;

    if (node == NULL)
        return 1;

    for (int i = 0; i < index; i++)
    {
        if (node->next == NULL)
            return 1;
        node = node->next;
    }

    *value = node->value;
    return 0;
}

int arrayList_append(LinkedList *list, void *value)
{
    ListNode *new_node = malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = NULL;

    if (list->first == NULL)
    {
        list->first = new_node;
        return 0;
    }

    ListNode *last = list->first;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return 0;
}

int arrayList_create(LinkedList **list)
{
    LinkedList *new_list = malloc(sizeof(LinkedList));
    if (new_list == NULL) // Always check if malloc fails
        return -1;
    new_list->first = NULL;
    *list = new_list; // Dereference to update the caller's pointer
    return 0;
}

/* int arrayList_print(LinkedList *list)
{
    if (list == NULL)
        return 1;
    ListNode *item = list->first;

    printf("[");
    while (item->next != NULL)
    {
        printf("%d, ", item->value);
        item = item->next;
    }
    printf("%d", item->value);

    printf("]");
    return 0;
} */

int arrayList_getSize(LinkedList *list)
{
    if (list == NULL)
        return -1;
    ListNode *item = list->first;
    int size = 0;

    while (item != NULL)
    {
        size++;
        item = item->next;
    }

    return size;
}
