#ifndef UTILS_H
#define UTILS_H

// ARRAY FUNCTIONS

void printArray(int *array, int size);
void randomArray(int *array, int size, int min, int max);
void bubbleSort(int *array, int size);
int findMax(int *array, int size);
int findMin(int *array, int size);
void reverseArray(int *array, int size);
int getSumOfArray(int *array, int size);
double getAvarageOfArray(int *array, int size);
int arrayContains(int *array, int size, int num);
void arrayReplace(int *array, int size, int val1, int val2);

// MATRIX FUNCTIONS

int **allocateMatrix(int rows, int columns);
void randomMatrix(int **matrix, int rows, int columns, int min, int max);
void printMatrix(int **matrix, int rows, int columns);
void freeMatrix(int **matrix, int rows);

// STRING FUNCTIONS

void toUpperCase(char *string);
void toLowerCase(char *string);
int countOccurrences(char *string, char c);
int stringLenght(char *string);
void stringReplace(char *string, char c1, char c2);
int stringContains(char *string, char c);
int stringStartsWith(char *string, char *startString);
int stringEndsWith(char *string, char *endString);
char *stringTrim(char *string);
void capitalize(char *string);
void reverseString(char *string);
int isStringEmpty(char *string);
int isStringPalindrome(char *string);

// GENERAL UTILITY FUNCTIONS

void swapInt(int *a, int *b);
void swapChar(char *c1, char *c2);
int randomNumber(int min, int max);

// FILE FUNCTIONS

void writeStringToFile(const char *filename, char *string);
void writeIntToFile(const char *filename, int num);
void writeDoubleToFile(const char *filename, double num);
void writeCharToFile(const char *filename, char c);
void writeIntArrayToFile(const char *filename, int *array, int size);
void writeMatrixToFile(const char *filename, int **matrix, int rows, int columns);

// ARRAY LIST

typedef struct ListNode ListNode;

typedef struct LinkedList LinkedList;

struct ListNode
{
    void *value;
    ListNode *next;
};

struct LinkedList
{
    ListNode *first;
};

int linkedList_getElement(LinkedList *list, int index, void **value);
int linkedList_append(LinkedList *list, void *value);
// int arrayList_print(LinkedList *list);
int linkedList_create(LinkedList **list);
int linkedList_getSize(LinkedList *list);
int linkedList_destroy(LinkedList *list);

#endif
