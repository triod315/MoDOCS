#include <stdio.h>

/// Зсув масиву на один елемент вліво
/// \param array - масив, який буде модифіковано
/// \param size - розмір масиву
void arrayShiftLeft(int array[], int size) {
    int i, temp = *array;
    for (i = 0, size--; i < size; i++)
        *(array+i) = *(array+i+1);
    *(array+size) = temp;
}

/// Вивід масиву в консоль
/// \param array - масиву для виводу
/// \param N - розмір масиву
void printArray(int array[],int N) {
    for (int i = 0; i < N; i++)
        printf("%d ", *(array+i));
}

int main() {
    //розмір вхідного самиву
    int N;

    //зчитування розміру масиву
    scanf("%d",&N);

    int arr[N];

    //зчитування елементів масиву
    for (int i = 0; i < N; i++) {
        scanf("%d",arr+i);
    }

    //вивід масиву перед перетворенням
    printf("Before\n");
    printArray(arr, N);

    //перевірка кожного елементу на рівність 0, якщо вірний то робимо зсув првої частини масиву вліво на 1 елемент
    for (int i = 0; i < N; i++)
        if (*(arr+i)==0)
            arrayShiftLeft(arr+i, N-i);

    //вивід перетвореного масиву
    printf("Result\n");
    printArray(arr, N);

    return 0;
}
