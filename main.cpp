#include <iostream>

void printArray(int arr[], int size_of_array)
{
    for (int i = 0; i < size_of_array; i++)
    {
        std::cout << arr[i] << " "; // �뢮��� ���ᨢ � ���� ��ப� ��� �஢�ન
    }
    std::cout << std::endl;
}

void insertionSort(int arr[], int size_of_array)
{
    unsigned int start_time = clock(); // ��砫쭮� �६�

    int key;
    int j;
    for (int i = 1; i < size_of_array; i++)
    {
        key = arr[i]; // ����� ࠧ ����砥� ���뮥 ���祭�� ���祢��� ���祭��
        j = i - 1;
        while (j >= 0 && arr[j] > key) // ��६�頥� ������ ���ᨢ�, ����� ����� ���祢��� ���祭�� (key) �� ���� ������ ����� (�� �� ⥪�饩 ����樨)
        {
            arr[j + 1] = arr[j]; // ᬥ頥� �����
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    unsigned int end_time = clock(); // ����筮� �६�
    unsigned int search_time = end_time - start_time; // �᪮��� �६�
    std::cout << "Time intention sort takes " << search_time << " to sort " << size_of_array << " items"  << std::endl;
    // printArray(arr, size_of_array);
}

void bubbleSort(int arr[], int size_of_array)
{

    unsigned int start_time = clock(); // ��砫쭮� �६�

    int i, j; // ���� ��६���� 横��
    for (i = 0; i < size_of_array - 1; i++)
        for (j = 0; j < size_of_array - i - 1; j++) // �ࠢ������ � ����� ����⮬ � ���塞 ���⠬�, �᫨ �� �� �ࠢ� �����
            if (arr[j] > arr[j + 1]) // �᫨ ����� -> ���塞 ���⠬�
                std::swap(arr[j], arr[j + 1]);

    unsigned int end_time = clock(); // ����筮� �६�
    unsigned int search_time = end_time - start_time; // �᪮��� �६�

    std::cout << "Time bubble sort takes " << search_time << " to sort " << size_of_array << " items"  << std::endl;
    //printArray(arr, size_of_array);
}

void selectionSort(int arr[], int size_of_array)
{
    unsigned int start_time = clock(); // ��砫쭮� �६�

    int min_index; // �뤥�塞 ������ ��� ������ �������쭮�� �����
    for (int i = 0; i <= size_of_array - 1; i++)
    {
        min_index = i; // ����� �室 �� ���譨� 横� ������塞 ������ �� ���
        for (int j = i + 1; j <= size_of_array - 1; j++) // ��稭��� � ��� + 1, � min_index 㦥 㪠�뢠�� �� ��� ����� � � ��砥, �᫨ �� �㤥� ��������� ᤥ���� ᢠ� �⮣� �� ���
        {
            if (arr[min_index] > arr[j]) // �᫨ ��室���� ����訩 ����� - ��蠥� ��� ������
            {
                min_index = j; // ��蠥� ������
            }
        }
        std::swap(arr[min_index], arr[i]); // ���塞 ���⠬�
    }

    unsigned int end_time = clock(); // ����筮� �६�
    unsigned int search_time = end_time - start_time; // �᪮��� �६�
    std::cout << "Time selection sort takes " << search_time << " to sort " << size_of_array << " items"  << std::endl;
    //printArray(arr, size_of_array);
}



int main()
{
    std::cout << "Enter size of array: ";
    int size_of_array;
    std::cin >> size_of_array;

    int *array = new int[size_of_array]; // �뤥�塞 ������ ��� ���ᨢ

    srand(time(0)); // ��� stand  time �㭪�� �㤥� �뤠���� ���� � � �� "��砩��" �᫠
    for (int i = 0; i < size_of_array; i++) { // ���������� ���ᨢ�

        array[i] = std::rand(); // ������㥬 ��砩�� �᫠ ��� ���ᨢ�

    }



    //printArray(array, size_of_array);
    //bubbleSort(array, size_of_array);    // �맮�� �㭪権 ࠧ����� ���஢��
    //insertionSort(array, size_of_array); // �맮�� �㭪権 ࠧ����� ���஢��
    selectionSort(array, size_of_array); // �맮�� �㭪権 ࠧ����� ���஢��



    delete [] array; // ���⪠ �����
    return 0;
}