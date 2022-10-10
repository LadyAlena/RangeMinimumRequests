#include <iostream>
#include "alg1/RangeMinimumRequests1.h"
#include "alg2/RangeMinimumRequests2.h"
#include "alg3/RangeMinimumRequests3.h"

int main(int argc, char** argv) {

#ifdef _WIN32
	system("chcp 65001");
	system("Cls");
#endif

	int arr[] = {1, 5, 2, 4, 6, 1, 3, 5, 7}; // 1 test
	// int arr[] = {0, 4, 2, 5, 66, 4, 25}; // 2 test
	int size = sizeof(arr) / sizeof(int);

	int index1 = 0;
	int index2 = 0;

	// Ввод границ интервала
	do {

		int count = 0;

		std::cout << "Введите интервал поиска минимума..." << std::endl;

		std::cout << "Левая граница: ";
		std::cin >> index1;

		std::cout << "Правая граница: ";
		std::cin >> index2;

		system("Cls");

		if (index1 < 0 || index2 < 0) {
			std::cout << "Индексы массива не могут быть меньше нуля" << std::endl;
			count++;
		}
		if (index1 >= size || index2 >= size) {
			std::cout << "Индексы массива не могут быть больше размера самого массива" << std::endl;
			count++;
		}
		if (index1 > index2) {
			std::cout << "Левая граница интервала не может быть больше парвой границы интервала" << std::endl;
			count++;
		}

		if (!bool(count)) {
			break;
		}


	} while (true);

	std::cout << "Левая граница: " << index1 << std::endl;
	std::cout << "Правая граница: " << index2 << std::endl;



	std::cout << "Алгоритм 1. Асимптотика по времени O(n); доппамять O(1)." << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	alg1::RangeMinimumRequests range_min_req_1(arr, size);

	std::cout << "В интервале от " << index1 << " до " << index2 << " минимум равен " << range_min_req_1.getMin(index1, index2) << std::endl;
	std::cout << std::endl;



	std::cout << "Алгоритм 2. Асимптотика по времени: препроцессинг O(n^3), запрос О(1); доппамять: O(n^2)." << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	alg2::RangeMinimumRequests range_min_req_2(arr, size);

	std::cout << "В интервале от " << index1 << " до " << index2 << " минимум равен " << range_min_req_2.getMin(index1, index2) << std::endl;
	std::cout << std::endl;



	std::cout << "Алгоритм 3. Асимптотика по времени: препроцессинг O(n), запрос О(sqrt(n)); доппамять: O(sqrt(n))." << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	alg3::RangeMinimumRequests range_min_req_3(arr, size);
	
	std::cout << "В интервале от " << index1 << " до " << index2 << " минимум равен " << range_min_req_3.getMin(index1, index2) << std::endl;
	std::cout << std::endl;

	return 0;
}