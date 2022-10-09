#include "RangeMinimumRequests1.h"

alg1::RangeMinimumRequests::RangeMinimumRequests(int* arr, const int size)
{
	this->arr = arr;
	this->size = size;

	left = 0;
	right = 0;

	min = 0;
}

int alg1::RangeMinimumRequests::getMin(const int left, const int right)
{

	this->left = left;
	this->right = right;

	min = arr[left];

	for (int i = left; i < right; ++i) {
		if (min > arr[i]) { min = arr[i]; }
	}

	return min;

}