/*
 * Дана програма виконує пошук шуканого елементу Х в двровимірному масиві де елементи впорядковані за неспаданням по
 * рядках та стовпчиках. Пошук виконється алгоритмом бінарного пошуку, а саме спочатку знаходиться рядок, де може
 * знаходитись шуканий елемент, а потім стовпчик.
 */
#include <iostream>
#include <tuple>
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

/// Пошику елементу в одновимірному масиві методом бінарного пошуку
/// \param array одновимірний масив для пошуку
/// \param size розмір масиву
/// \param value значення лементу який потрібно знайти
/// \return номер знайденого елементу або -1 якщо такий елемент не знайдено
int binarySearch(const int array[], int size, int value)
{
    int first = 0,                      // Перший елемент масиву
    last = size - 1,                    // Останній елеемнт масиву
    middle,                             // Центральний елемент
    position = -1;                      // Позиція шкуаного елементу
    while (first <= last)
    {
        middle = MIDDLE(first,last);    // Визначення середнього елементу
        if (array[middle] == value)     // Якщо елемент знайдено то повертаємо позицію
        {
            return middle;
        }
        else {
            if (array[middle] > value)  // Якщо значення нижче середнього
                last = middle - 1;
            else
                first = middle + 1;     // Якщо значення більше середнього
        }
    }
    return position;
}

/// Бінарний пошук в двовимірному впорядкованому масиві
/// \param array вкізівник на двовимірний масив
/// \param N кількість рядків
/// \param M кількість стовпчиків
/// \param value значення, яке шукаєсять
/// \return пара індексів де знайдено елемент, або -1 -1, якщо такий елемент не знайдено
std::tuple<int, int> binarySearch2D(int **array, int N, int M, int value)
{
    int resultI, resultJ;
    int first = 0,                      // Перший елемент масиву
    last = N - 1,                       // Останній елеемнт масиву
    middle;                             // Центральний елемент
    while (first <= last)
    {
        // Визначення середнього елементу
        middle = MIDDLE(first,last);
        // Якщо елемент знайдено то повертаємо позицію
        if (array[middle][0] <= value && array[middle][M-1]>=value)
        {
            resultJ = binarySearch(array[middle], M, value);
            if (resultJ != -1) {
                resultI=middle;
                return std::make_tuple(resultI, resultJ);
            }
        }
        else {
            if (array[middle][0] > value)
                last = middle - 1;
            else
                first = middle + 1;
        }
    }
    return std::make_tuple(-1,-1);
}
int main() {
    // зчитування розмірів масиву
    int N,M;
    READ(N)
    READ(M)
    int *A[N];
    for (int i = 0; i < N; i++) {
        A[i]=new int [N];
    }
    // зчитування самого масиву з консолі або автогенерація масиву (закоментовано)
    READ_ARRAY(A, N, M)
    /*int inc=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j]=++inc;
        }
    }*/
    //зчитування шуканого елементу
    int X;
    READ(X)
    // отримання результату бінарного пошуку
    auto [ resultI, resultJ ] = binarySearch2D(A,N,M,X);
    if (resultJ!=-1)
        std::cout << resultI << " " << resultJ<<std::endl;
    else
        std::cout<<"HI"<<std::endl;
    return 0;
}
