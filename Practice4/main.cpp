#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void clear_arr(T arr[], const int length, T num);

template <typename T>
void print_arr(T arr[], const int length);

void fill_arr(int arr[], const int length,int first,int last);

int index_sum(int arr1[], int arr2[], const int length1, const int length2, int index) {
	if (index >= length1 || index >= length2) {
		std::cout << "ERROR!!!\n\n";
		return 0;
	}
	else
		return arr1[index] + arr2[index];
}

int compare_pare(int arr[], const int length, int num1, int num2);

void prime_range(int num1, int num2);
void prime_range(int num1);

template <typename T>
void permute_arr(T arr[], const int length);

int main() {
	setlocale(LC_ALL, "Russian");
	int n,m;

	// Задача 1. Шаблонная функция Обнуляет все элементы равные ключевому значению

	const int size = 5;
	int arr[size];

	std::cout << "Задача 1.\nИсходный массив:\n";
	fill_arr(arr, size,0,10);
	print_arr(arr, size);
	std::cout << "Введите число -> ";
	std::cin >> n;
	clear_arr(arr, size, n);
	std::cout << "Полученный массив:\n";
	print_arr(arr, size);
	std::cout << "\n\n";

	// Задача 2. Сумма двух элементов массива с одинаковым индексом

	const int size1 = 5;
	const int size2 = 6;
	int arr1[size1];
	int arr2[size2];

	std::cout << "Задача 2.\nИсходные массивы:\n";
	std::cout << "arr1 = ";
	fill_arr(arr1, size1, 0, 10);
	print_arr(arr1, size1);
	std::cout << "\narr2 = ";
	fill_arr(arr2, size2, 0, 10);
	print_arr(arr2, size2);
	std::cout << std::endl;

	std::cout << "Введите индекс массивов -> ";
	std::cin >> n;

	std::cout << "Сумма элементов массива под индексом " << n << " = " 
		<< index_sum(arr1, arr2, size1, size2, n) << "\n\n";

	// Задача 3. Функция возвращает индекс массива двух подряд идущих чисел
	std::cout << "Задача 3.\n";
	const int size3 = 10;
	int arr3[size3]{};
	fill_arr(arr3, size3, 0, 26);
	std::cout << "Исходный массив: ";
	print_arr(arr3, size3);
	std::cout << "Введите два числа -> ";
	std::cin >> n >> m;
	std::cout << "Индекс подряд двух чисел " << compare_pare(arr3, size3, n, m) << "\n\n";

	// Задча 4. Перегруженная функция
	std::cout << "Задача 4.\n";
	std::cout << "Простые числа в диапазоне от 10 до 100: ";
	prime_range(10, 100);
	std::cout << std::endl;

	std::cout << "Простые чисела от 1 до 10: ";
	prime_range(10);

	std::cout << "\n\n";

	// Задача 5. Шаблонная функция перестановка половинок массива
	const int size5 = 7;
	int arr5[size5];

	std::cout << "Задача 5.\nИсходный массив:\n";
	fill_arr(arr5, size5, 0, 15);
	print_arr(arr5, size5);

	permute_arr(arr5, size5);

	std::cout << "Итоговый массив:\n";
	print_arr(arr5, size5);


	return 0;
}

template<typename T>
void clear_arr(T arr[], const int length, T num){
	for (int i = 0; i < length; i++) {
		if (arr[i] == num)
			arr[i] = 0;
	}
}

template<typename T>
void print_arr(T arr[], const int length){
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

template<typename T>
void permute_arr(T arr[], const int length){
	for (int i = 0; i < length / 2; i++)
		if (length % 2  == 0)
			std::swap(arr[i], arr[length / 2 + i]);
		else
			std::swap(arr[i], arr[length / 2 + i + 1]);

}

void fill_arr(int arr[], const int length, int first, int last){
	srand(time(NULL));

	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (last - first) + first;
	}

}

int compare_pare(int arr[], const int length, int num1, int num2){
	for (int i = 0; i < length; i++) {
		if (arr[i] == num1)
			if (arr[i + 1] == num2)
				return i;
	}
	return -1;
}

void prime_range(int num1, int num2){
	for (int i = num1; i <= num2; i++) {
		int count = 0;
		for (int j = 2; j < i; j++)
			if (i % j == 0)
				count++;
		if (count == 0)
			std::cout << i << " ";
	}

}

void prime_range(int num1){
	int count = 0;
	for (int i = 1; i <= num1; i++) {
		for (int j = 1; j <= i; j++)
			if (i % j == 0)
				count++;
		if (count <= 2) {
			std::cout << i << " ";
			count = 0;
		}			
		else
			count = 0;
	}
}
