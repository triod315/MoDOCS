#include <iostream>
// Макрос для зчитування з консолі
#define READ(a) std::cin>>a;
// Макрос для обчислення середнього арифметичного
#define MIDDLE(a, b) (a+b)/2
// Зчитування двовимірного масиву
#define READ_ARRAY(array, N, M)        \
    for (int i = 0; i < N; i++) {      \
        for (int j = 0; j < M; j++) {  \
            std::cin>>array[i][j];     \
        }                              \
    }

int comp_count=0;

/// Пошику елементу в одновимірному масиві методом бінарного пошуку
/// \param array одновимірний масив для пошуку
/// \param size розмір масиву
/// \param value значення лементу який потрібно знайти
/// \return номер знайденого елементу або -1 якщо такий елемент не знайдено
int binarySearch(int array[], int size, int value)
{
    int first = 0,                      // Перший елемент масиву
    last = size - 1,                    // Останній елеемнт масиву
    middle,                             // Центральний елемент
    position = -1;                      // Позиція шкуаного елементу
    while (first <= last)
    {
        middle = MIDDLE(first,last);    // Визначення середнього елементу
        comp_count++;
        if (array[middle] == value)     // Якщо елемент знайдено то повертаємо позицію
        {
            return middle;
        }
        else {
            comp_count++;
            if (array[middle] > value)  // Якщо значення нижче середнього
                last = middle - 1;
            else
                first = middle + 1;     // Якщо значення більше середнього
        }
    }
    return position;
}

int main() {
    int N,M;
    READ(N)
    READ(M)
    int A[N][M];

    int inc=0;
    //READ_ARRAY(A, N, M)

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j]=++inc;
        }
    }

    int X;
    READ(X)
    int resultI, resultJ;
    for (int i = 0; i < N; i++) {
        comp_count++;
        if (A[i][0]<=X && A[i][N-1]>=X) {
            resultJ = binarySearch(A[i], M, X);
            if (resultJ != -1) {
                resultI=i;
                break;
            }
        }
    }

    if (resultJ!=-1)
        std::cout << resultI << " " << resultJ<<std::endl;
    else
        std::cout<<"HI"<<std::endl;

    std::cout<<"Кількість порівнянь: "<<comp_count;

    return 0;
}
