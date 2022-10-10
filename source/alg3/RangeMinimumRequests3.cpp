#include "RangeMinimumRequests3.h"
#include <cmath>

alg3::RangeMinimumRequests::RangeMinimumRequests(int* arr, int size)
{

	this->arr = arr;
	this->size = size;

	sqrt_size = (int)round(sqrt(size));

	left = 0;
	right = 0;

	memory = new int[sqrt_size] {};

	min = 0;

	processArr();

}

alg3::RangeMinimumRequests::~RangeMinimumRequests()
{
	delete[] memory;
}

int alg3::RangeMinimumRequests::getMin(const int left_, const int right_) {

	this->left = left_;
	this->right = right_;

	min = arr[left];

	int left_up = int(left / sqrt_size);
	int right_down = int(right / sqrt_size);

	int number_of_blocks = right_down - left_up + 1; //количество рассматриваемых блоков

	// поиск блоков, находящихся не на концах интервала с последующем использованием предподсчета
	if ((left == left_up * sqrt_size) && (right == (right_down + 1) * sqrt_size - 1) && (number_of_blocks > 1)) {
		for (int block = left_up + 1; block < right_down; ++block) {
			if (min > memory[block]) { min = memory[block]; }
		}
	}


	if (number_of_blocks != 1) { // поиск минимума на краях интервала
		for (int i = left; i < (left_up + 1) * sqrt_size; ++i) {
			if (min > arr[i]) { min = arr[i]; }
		}
		for (int i = right_down * sqrt_size; i < right; ++i) {
			if (min > arr[i]) { min = arr[i]; }
		}
	}
	else { // поиск минимума на интервале, расположенном в одном блоке
		for (int i = left; i < right; ++i) {
			if (min > arr[i]) { min = arr[i]; }
		}
	}

	return min;
}

void alg3::RangeMinimumRequests::processArr() {

	int left_ = 0;
	int right_ = 0;

	int step = 0;

	for (left_ = 0; left_ < size; left_ += sqrt_size) {

		min = arr[left_];

		for (right_ = left_ + 1; (right_ < left_ + sqrt_size) && (size - left_ != 1); ++right_) {

			if (min > arr[right_]) { min = arr[right_]; }

		}

		memory[step] = min;

		step++;

	}
}