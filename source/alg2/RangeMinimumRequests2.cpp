#include "RangeMinimumRequests2.h"

alg2::RangeMinimumRequests::RangeMinimumRequests(int* arr, const int size) {
	this->arr = arr;
	this->size = size;

	left = 0;
	right = 0;

	memory = new int* [size];
	for (int i = 0; i < size; ++i) {
		memory[i] = new int[size] {};
	}

	min = 0;

	processArr();

}

alg2::RangeMinimumRequests::~RangeMinimumRequests() {

	for (int i = 0; i < size; ++i) {
		delete[] memory[i];
	}

	delete[] memory;
}

int alg2::RangeMinimumRequests::getMin(const int left_, const int right_) {

	this->left = left_;
	this->right = right_;

	return memory[left][right];

}

void alg2::RangeMinimumRequests::processArr() {

	int left_ = 0;
	int right_ = 0;

	for (left_ = 0; left_ < size; ++left_) {

		min = arr[left_];

		for (right_ = left_ + 1; right_ < size; ++right_) {

			for (int i = left_; i < right_; ++i) {
				if (min > arr[i]) { min = arr[i]; }
			}

			memory[left_][right_] = min;

		}

	}
}