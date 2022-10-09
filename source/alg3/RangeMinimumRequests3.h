#pragma once

//Алгоритм 3. (препроцессинг + sqrt-декомпозиция). Асимптотика по времени: препроцессинг O(n), запрос О(sqrt(n)); доппамять: O(sqrt(n)).

namespace alg3 {
	class RangeMinimumRequests {
	public:
		RangeMinimumRequests(int* arr, int size);
		~RangeMinimumRequests();

		int getMin(const int left_, const int right_);

	private:
		int* arr;
		int size;
		int sqrt_size;

		int left;
		int right;

		int* memory;

		int min;

		void processArr();
	};
}