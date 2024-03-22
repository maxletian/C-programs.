#include <stdio.h>
#include <stdbool.h>


#define MAX_SIZE 100


int arr[MAX_SIZE];
int size = 0;


void insertElement(int num) {
    if (size < MAX_SIZE) {
        arr[size] = num;
        size++;
    } else {
        printf("Array is full. Cannot insert more elements.\n");
    }
}


void deleteElement(int num) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            found = true;
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            break;
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
}


void searchElement(int num) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            found = true;
            break;
        }
    }
    if (found) {
        printf("Element found in the array.\n");
    } else {
        printf("Element not found in the array.\n");
    }
}


void updateElement(int oldNum, int newNum) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == oldNum) {
            found = true;
            arr[i] = newNum;
            break;
        }
    }
    if (!found) {
        printf("not found.\n");
    }
}


void displayElements() {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void reverseArray() {
  int temp, start = 0, end = size - 1;

  while (start < end) {
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

int main() {
    int choice, num, oldNum, newNum;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("7. reverse\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &num);
                insertElement(num);
                break;
            case 2:
                printf("Enter a number to delete: ");
                scanf("%d", &num);
                deleteElement(num);
                break;
            case 3:
                printf("Enter a number to search: ");
                scanf("%d", &num);
                searchElement(num);
                break;
            case 4:
                printf("Enter the number to update: ");
                scanf("%d", &oldNum);
                printf("Enter the new number: ");
                scanf("%d", &newNum);
                updateElement(oldNum, newNum);
                break;
            case 5:
                displayElements();
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            case 7:
                reverseArray();
                printf("Array reversed.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

  return 0;
}