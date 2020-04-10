#include <stdio.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k, n1 = m - l + 1, n2 = r - m, L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void main()
{
    int arr_size, i;
    printf("Enter the number of Elements:");
    scanf("%d", &arr_size);
    int arr[arr_size];
    printf("Enter the Elements:\n");
    for (i = 0; i < arr_size; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, arr_size - 1);
    printf("\nSorted array is \n");
    for (i = 0; i < arr_size; i++)
        printf("%d\t", arr[i]);
}
