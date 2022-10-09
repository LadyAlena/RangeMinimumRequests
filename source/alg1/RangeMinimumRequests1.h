#pragma once

//Алгоритм 1. Асимптотика по времени O(n); доппамять O(1).

namespace alg1 {
	class RangeMinimumRequests {

	public:
		RangeMinimumRequests(int* arr, const int size);

		int getMin(const int left, const int right);

	private:
		int* arr;
		int size;

		int left;
		int right;

		int min;
	};
}

