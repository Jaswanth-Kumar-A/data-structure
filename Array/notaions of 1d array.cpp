#include <stdio.h>

void rightRotate(int arr[], int length, int n) {
    for (int i = 0; i < n; i++) {
        int j, last;
        last = arr[length - 1];

        for (j = length - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = last;
    }
}

void leftRotate(int arr[], int length, int n) {
    for (int i = 0; i < n; i++) {
        int j, first;
        first = arr[0];

        for (j = 0; j < length - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[length - 1] = first;
    }
}

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int arr[length];
    printf("Enter the array elements:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    int n;
    printf("Enter the number of rotations: ");
    scanf("%d", &n);

    int choice;
    printf("Choose rotation direction (1 for right, 2 for left): ");
    scanf("%d", &choice);

    printf("Original array: \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    switch (choice) {
        case 1:
            rightRotate(arr, length, n);
            printf("\nArray after right rotation: \n");
            break;
        case 2:
            leftRotate(arr, length, n);
            printf("\nArray after left rotation: \n");
            break;
        default:
            printf("\nInvalid choice\n");
            return 1;
    }

    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
