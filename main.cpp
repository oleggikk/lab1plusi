#include <iostream>

void printArray(int arr[], int size_of_array)
{
    for (int i = 0; i < size_of_array; i++)
    {
        std::cout << arr[i] << " "; // выводим массив в одну строку для проверки
    }
    std::cout << std::endl;
}

void insertionSort(int arr[], int size_of_array)
{
    unsigned int start_time = clock(); // начальное время

    int key;
    int j;
    for (int i = 1; i < size_of_array; i++)
    {
        key = arr[i]; // каждый раз получаем новыое значение ключевого значения
        j = i - 1;
        while (j >= 0 && arr[j] > key) // перемещаем элементы массива, которые меньше ключевого значения (key) на одну позицию назад (от их текущей позиции)
        {
            arr[j + 1] = arr[j]; // смещаем элемент
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    std::cout << "Time intention sort takes " << search_time << " to sort " << size_of_array << " items"  << std::endl;
    printArray(arr, size_of_array);
}

void bubbleSort(int arr[], int size_of_array)
{

    unsigned int start_time = clock(); // начальное время

    int i, j; // объявим переменный цикла
    for (i = 0; i < size_of_array - 1; i++)
        for (j = 0; j < size_of_array - i - 1; j++) // сравниваем с каждым элементом и меняем местами, если тот что справа меньше
            if (arr[j] > arr[j + 1]) // если больше -> меняем местами
                std::swap(arr[j], arr[j + 1]);

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

    std::cout << "Time bubble sort takes " << search_time << " to sort " << size_of_array << " items"  << std::endl;
    printArray(arr, size_of_array);
}

void selectionSort(int arr[], int size_of_array)
{
    unsigned int start_time = clock(); // начальное время

    int min_index; // выделяем память под индекс минимального элемента
    for (int i = 0; i <= size_of_array - 1; i++)
    {
        min_index = i; // каждый вход во внешний цикл обновляем индекс на итый
        for (int j = i + 1; j <= size_of_array - 1; j++) // начинаем с итый + 1, тк min_index уже указывает на итый элемент и в случае, если он будет минимальным сделает свап итого на итый
        {
            if (arr[min_index] > arr[j]) // если находится меньший элемент - кушаем его индекс
            {
                min_index = j; // кушаем индекс
            }
        }
        std::swap(arr[min_index], arr[i]); // меняем местами
    }

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    std::cout << "Time selection sort takes " << search_time << " to sort " << size_of_array << " items"  << std::endl;
    printArray(arr, size_of_array);
}



int main()
{

    int array[11] = { 2, 71, 8, 1, -5, 6, 5, -100, 1000, 55, -106}; // объявляем массив
    int size_of_array= sizeof(array) / sizeof(array[1]); // вычисляем размер массива
    bubbleSort(array, size_of_array);    // вызовы функций различных сортировок
    selectionSort(array, size_of_array); // вызовы функций различных сортировок
    insertionSort(array, size_of_array); // вызовы функций различных сортировок


}