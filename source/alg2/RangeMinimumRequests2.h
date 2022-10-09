#pragma once

//Алгоритм 2 (с препроцессингом). Асимптотика по времени: препроцессинг O(n^3), запрос О(1); доппамять: O(n^2).

namespace alg2 {
	class RangeMinimumRequests {

	public:

		RangeMinimumRequests(int* arr, const int size);
		~RangeMinimumRequests();

		int getMin(const int left_, const int right_);

	private:
		int* arr;
		int size;

		int left;
		int right;

		int** memory;

		int min;

		void processArr();

	};
}