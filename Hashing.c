#include <stdio.h>
#include <stdlib.h>

void insert(int array[], int size, int value) {
    int index = value % size;
    array[index] = value;
}

void display(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("Index %d: %d\n", i, array[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    int* hashTable = (int*)malloc(size * sizeof(int));
    if (hashTable == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize hash table with zeros
    for (int i = 0; i < size; ++i) {
        hashTable[i] = 0;
    }

    int value;
    printf("Enter values to insert into the hash table (-1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        insert(hashTable, size, value);
    }

    display(hashTable, size);

    // Free dynamically allocated memory
    free(hashTable);

    return 0;
}
