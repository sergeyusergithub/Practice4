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

	// ������ 1. ��������� ������� �������� ��� �������� ������ ��������� ��������

	const int size = 5;
	int arr[size];

	std::cout << "������ 1.\n�������� ������:\n";
	fill_arr(arr, size,0,10);
	print_arr(arr, size);
	std::cout << "������� ����� -> ";
	std::cin >> n;
	clear_arr(arr, size, n);
	std::cout << "���������� ������:\n";
	print_arr(arr, size);
	std::cout << "\n\n";

	// ������ 2. ����� ���� ��������� ������� � ���������� ��������

	const int size1 = 5;
	const int size2 = 6;
	int arr1[size1];
	int arr2[size2];

	std::cout << "������ 2.\n�������� �������:\n";
	std::cout << "arr1 = ";
	fill_arr(arr1, size1, 0, 10);
	print_arr(arr1, size1);
	std::cout << "\narr2 = ";
	fill_arr(arr2, size2, 0, 10);
	print_arr(arr2, size2);
	std::cout << std::endl;

	std::cout << "������� ������ �������� -> ";
	std::cin >> n;

	std::cout << "����� ��������� ������� ��� �������� " << n << " = " 
		<< index_sum(arr1, arr2, size1, size2, n) << "\n\n";

	// ������ 3. ������� ���������� ������ ������� ���� ������ ������ �����
	std::cout << "������ 3.\n";
	const int size3 = 10;
	int arr3[size3]{};
	fill_arr(arr3, size3, 0, 26);
	std::cout << "�������� ������: ";
	print_arr(arr3, size3);
	std::cout << "������� ��� ����� -> ";
	std::cin >> n >> m;
	std::cout << "������ ������ ���� ����� " << compare_pare(arr3, size3, n, m) << "\n\n";

	// ����� 4. ������������� �������
	std::cout << "������ 4.\n";
	std::cout << "������� ����� � ��������� �� 10 �� 100: ";
	prime_range(10, 100);
	std::cout << std::endl;

	std::cout << "������� ������ �� 1 �� 10: ";
	prime_range(10);

	std::cout << "\n\n";

	// ������ 5. ��������� ������� ������������ ��������� �������
	const int size5 = 7;
	int arr5[size5];

	std::cout << "������ 5.\n�������� ������:\n";
	fill_arr(arr5, size5, 0, 15);
	print_arr(arr5, size5);

	permute_arr(arr5, size5);

	std::cout << "�������� ������:\n";
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
