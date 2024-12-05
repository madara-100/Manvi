#include <stdio.h>
#include <string.h>

void swap(char str1[], char str2[]) {
    char temp[50];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int partition(char arr[][50], int low, int high) {
    char pivot[50];
    strcpy(pivot, arr[high]); // Last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // Compare strings lexicographically
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(char arr[][50], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int n;
    printf("How much names want to store tell me the number : ");
    scanf("%d", &n);
    printf("\n");

    char names[n][50];
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        gets(names[i]);
        size_t newline_index = strcspn(names[i], "\n"); // removing new line character.
        names[i][newline_index] = '\0'; 
    }

    // Sorting the names using Quick Sort
    quickSort(names, 0, n - 1);

    // Display the sorted names
    printf("\nSorted names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}





