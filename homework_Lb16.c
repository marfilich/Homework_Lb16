#include <stdio.h> //ghj
#include <stdlib.h>
#include <time.h>
#include <locale.h>

double* full_elements_16(double* ptr_array, int size);
int put_elements_16(double* ptr_array, int size);
int find_size_d(int size_a, int size_b, double* ptr_array_a, double* ptr_array_b);
double* even_uneven(double* ptr_array_a, double* ptr_array_b, double* ptr_array_d, int size_a, int size_b, int size_d);

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int size_a, size_b, size_c, size_d;
	size_a = 10 + rand() % 41;
	size_b = 10 + rand() % 41;
	size_c = 10 + rand() % 41;

	double* ptr_array_a = (double*)malloc(size_a * sizeof(double));
	if (ptr_array_a == NULL) {
		printf("Ошибка выделения памяти!\n");
		return NULL;
	}
	ptr_array_a = full_elements_16(ptr_array_a, size_a);
	
	double* ptr_array_b = (double*)malloc(size_b * sizeof(double));
	if (ptr_array_b == NULL) {
		printf("Ошибка выделения памяти!\n");
		return NULL;
	}
	ptr_array_b = full_elements_16(ptr_array_b, size_b);
	
	double* ptr_array_c = (double*)malloc(size_c * sizeof(double));
	if (ptr_array_c == NULL) {
		printf("Ошибка выделения памяти!\n");
		return NULL;
	}
	ptr_array_c = full_elements_16(ptr_array_c, size_c);

	size_d = find_size_d(size_a, size_b, ptr_array_a, ptr_array_b);
	double* ptr_array_d = (double*)malloc(size_d * sizeof(double));
	if (ptr_array_d == NULL) {
		printf("Ошибка выделения памяти!\n");
		return NULL;
	}
	ptr_array_d = even_uneven(ptr_array_a, ptr_array_b, ptr_array_d, size_a, size_b, size_d);
	puts("Массив А");
	put_elements_16(ptr_array_a, size_a);
	puts("Массив B");
	put_elements_16(ptr_array_b, size_b);
	puts("Массив C");
	put_elements_16(ptr_array_c, size_c);
	puts("Массив D");
	put_elements_16(ptr_array_d, size_d);
	
    free(ptr_array_a);
    free(ptr_array_b);
    free(ptr_array_c);
    free(ptr_array_d);
    return 0;
}



double* full_elements_16(double* ptr_array, int size)
{
	for (int i = 0; i < size; i++) {
		ptr_array[i] = -1 + ((double)rand() / RAND_MAX) * (1 - (-1));
	}
	return ptr_array;
}

int put_elements_16(double* ptr_array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("ptr_array[%d] = %.2lf\n", i, ptr_array[i]);
	}
}

int find_size_d(int size_a, int size_b, double* ptr_array_a, double* ptr_array_b)
{
	int size, even = 0, uneven = 0;
	for (int i = 0; i < size_a; i++)
	{
		if (i % 2 == 0) {
			even += 1;
		}
	}
	for (int i = 0; i < size_b; i++)
	{
		if (i % 2 == 1) {
			uneven += 1;
		}
	}
	size = (even < uneven) ? even * 2 : uneven * 2;
	return size;
}

double* even_uneven(double* ptr_array_a, double* ptr_array_b, double* ptr_array_d, int size_a, int size_b, int size_d)
{
	for (int i = 0; i < size_d; i++)
	{
		if (i % 2 == 0)
		{
			ptr_array_d[i] = ptr_array_a[i];
		}
		else {
			ptr_array_d[i] = ptr_array_b[i];
		}
	}
	return ptr_array_d;
}



