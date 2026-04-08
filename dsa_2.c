#include <stdio.h>

int main() {
    int arr[100], n, i, key;
    int low = 0, high, mid, found = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements in sorted order:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key element to be searched: ");
    scanf("%d", &key);

    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            found = 1;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(found) {
        printf("Element found at index %d\n", mid);
    }
    else {
        printf("Element not found\n");
    }

    return 0;
}