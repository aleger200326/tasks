#include <iostream>

int main()
{
	int rows, cols;
	do { std::cout << "Rows: "; std::cin >> rows; } while (rows < 1);
	do { std::cout << "Columns: "; std::cin >> cols; } while (cols < 1);

	int** M;
	// Ð’Ñ‹Ð´ÐµÐ»ÐµÐ½Ð¸Ðµ Ð¿Ð°Ð¼ÑÑ‚Ð¸
	M = new int*[rows];
	for (int i = 0; i < rows; ++i)
		M[i] = new int[cols];

	// Ð—Ð°Ð¿Ð¾Ð»Ð½Ð¸Ñ‚ÑŒ Ð¼Ð°ÑÑÐ¸Ð²
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			M[i][j] = rand();

	int* widths = new int[cols];
	for (int j = 0; j < cols; ++j) {
		widths[j] = 0;
		for (int i = 0; i < rows; ++i) {
			// Ð²Ñ‹Ñ‡Ð¸ÑÐ»Ð¸Ñ‚ÑŒ ÐºÐ¾Ð»Ð¸Ñ‡ÐµÑÑ‚Ð²Ð¾ Ñ†Ð¸Ñ„Ñ€ Ð² Ñ‡Ð¸ÑÐ»Ðµ
			int digits_count = 0;
			int n = M[i][j];
			do {
				++digits_count;
				n /= 10;
			} while (n>0);

			// ÐµÑÐ»Ð¸ Ñ†Ð¸Ñ„Ñ€ Ð±Ð¾Ð»ÑŒÑˆÐµ Ñ‡ÐµÐ¼ Ð² widths[j] Ð¸Ð·Ð¼ÐµÐ½Ð¸Ñ‚ÑŒ widths[j]
			if (widths[j] < digits_count)
				widths[j] = digits_count;
		}
	}

	// Ð’Ñ‹Ð²ÐµÑÑ‚Ð¸ Ð½Ð° ÑÐºÑ€Ð°Ð½
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {

			// Ð²Ñ‹Ñ‡Ð¸ÑÐ»Ð¸Ñ‚ÑŒ ÐºÐ¾Ð»Ð¸Ñ‡ÐµÑÑ‚Ð²Ð¾ Ñ†Ð¸Ñ„Ñ€ Ð² Ñ‡Ð¸ÑÐ»Ðµ
			int digits_count = 0;
			int n = M[i][j];
			do {
				++digits_count;
				n /= 10;
			} while (n > 0);
			
			for (int space = digits_count; space < widths[j]; ++space)
				std::cout << ' ';

			std::cout << M[i][j];
			
			std::cout << ' '; // Ð¿Ñ€Ð¾Ð±ÐµÐ» Ð¼ÐµÐ¶Ð´Ñƒ ÑÑ‚Ð¾Ð»Ð±Ñ†Ð°Ð¼Ð¸
		}
		std::cout << std::endl;
	}

	// ÐžÑÐ²Ð¾Ð±Ð¾Ð¶Ð´ÐµÐ½Ð¸Ðµ Ð¿Ð°Ð¼ÑÑ‚Ð¸
	for (int i = 0; i < rows; ++i)
		delete[] M[i];
	delete[] M;
	delete[] widths;
	return 0;
}
