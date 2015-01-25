// Funktionerna till inlämningsuppgift 2 2010, med anropsexempel i main

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

namespace Course
{
	namespace ExeciseComplexity
	{

		// Finds the largest value in the array "a" of length "length"
		double find_max_in_array(double a[], int length) {
			double max = a[0];
			for (int i = 1; i < length; ++i) {
				if (a[i] > max) {
					max = a[i];
				}
			}
			return max;
		}

		// Reverses the string "s" in place
		void reverse_string(char* s) {
			int n = strlen(s);
			for (int i = 0; i < n / 2; ++i) {
				char temp = s[i];
				s[i] = s[n - i - 1];
				s[n - i - 1] = temp;
			}
		}

		// Reverses the string "s" in place, but there is a bug
		void incorrect_reverse_string(char* s) {
			int n = strlen(s);
			for (int i = 0; i < n; ++i) {
				char temp = s[i];
				s[i] = s[n - i - 1];
				s[n - i - 1] = temp;
			}
		}

		// Compares two arrays of length "length" and returns 1 if they are equal
		double arrays_are_equal(double a[], double b[], int length) {
			for (int i = 0; i < length; ++i) {
				if (a[i] != b[i]) {
					return 0;
				}
			}
			return 1;
		}

		// Returns the sum of how many times each needle occurs in the haystack,
		// both arrays of length "length"
		int find_number_of_matches(int needles[], int haystack[], int length) {
			int nr_matches = 0;
			for (int n = 0; n < length; ++n) {
				for (int h = 0; h < length; ++h) {
					if (needles[n] == haystack[h]) {
						++nr_matches;
					}
				}
			}
			return nr_matches;
		}

		// Sorts the array "a" of length "length" in ascending order using selection sort
		void sort_array(double a[], int length) {
			for (int sorted = 0; sorted < length - 1; ++sorted) {
				int smallest_in_rest = sorted;
				for (int in_rest = sorted + 1; in_rest < length; ++in_rest) {
					if (a[in_rest] < a[smallest_in_rest]) {
						smallest_in_rest = in_rest;
					}
				}
				double temp = a[sorted];
				a[sorted] = a[smallest_in_rest];
				a[smallest_in_rest] = temp;
			}
		}

		// Returns 1 if the array "a" of length "length" is sorted in ascending order
		int is_array_sorted(double a[], int length) {
			for (int i = 0; i < length - 1; ++i)
				if (a[i] > a[i + 1])
					return 0;
			return 1;
		}

		// Returns 1 if the array "a" of length "length" is sorted in ascending order
		int is_array_sorted_2(double a[], int length) {
			double *copy = (double *) malloc(length * sizeof(double));
			memcpy(copy, a, length * sizeof(double));
			sort_array(copy, length);
			int result = arrays_are_equal(a, copy, length);
			free(copy);
			return result;
		}

		// Sorts the array "a" of length "length" in random order
		void shuffle_array(double a[], int length) {
			for (int randomized = 0; randomized < length; ++randomized) {
				// Select a random position in the rest of the array
				int selected = randomized + rand() % (length - randomized);
				// Swap the current position with the random position
				double oldvalue = a[randomized];
				a[randomized] = a[selected];
				a[selected] = oldvalue;
			}
		}

		// Sorts the array "a" of length "length" in ascending order using bogosort
		void bogosort_array(double a[], int length) {
			do
			shuffle_array(a, length);
			while (! is_array_sorted(a, length));
		}
	}
}

void main_exercise_complexity(void) {
	using namespace Course::ExeciseComplexity;

	// find_max_in_array
	double a1[] = { 17.1 };
	double m = find_max_in_array(a1, 1);
	printf("Max = %f\n", m);
	double a2[] = { 17.1, 17.2, 17.3, 17.2, 17.1, 17.1 };
	m = find_max_in_array(a2, 6);
	printf("Max = %f\n", m);

	// reverse_string and incorrect_reverse_string
	char s[] = "Det här är en sträng med elva ord i. Hej hej!";
	printf("Först är s = '%s'\n", s);
	incorrect_reverse_string(s);
	printf("Efter incorrect_reverse_string är s = '%s'\n", s);
	reverse_string(s);
	printf("Efter reverse_string är s = '%s'\n", s);

	double b1[] = { 17.1 };
	int b = arrays_are_equal(a1, b1, 1);
	printf("a1 och b1 är lika: %d\n", b);
	double b2[] = { 17.1, 17.2, 17.3, 17.2, 17.1, 17.1 };
	b = arrays_are_equal(a2, b2, 6);
	printf("a2 och b2 är lika: %d\n", b);
	double b2b[] = { 17.1, 17.2, 17.3, 17.2, 17.1, 17.9 };
	b = arrays_are_equal(a2, b2b, 6);
	printf("a2 och b2b är lika: %d\n", b);

	int n1[] = { 1, 2, 9, 3, 5 };
	int h1[] = { 2, 2, 2, 7, 7 };
	int n = find_number_of_matches(n1, h1, 5);
	printf("Antal matchningar: %d\n", n);
	int n2[] = { 1, 2, 9, 3, 5, 5, 5, 5 };
	int h2[] = { 5, 5, 5, 5, 5, 5, 5, 5 };
	n = find_number_of_matches(n2, h2, 8);
	printf("Antal matchningar: %d\n", n);

	printf("Osorterad b1: %f\n", b1[0]);
	sort_array(b1, 1);
	printf("Sorterad b1: %f\n", b1[0]);
	printf("Osorterad b2: %f %f %f %f %f %f\n", b2[0], b2[1], b2[2], b2[3], b2[4], b2[5]);
	sort_array(b2, 6);
	printf("Sorterad b2: %f %f %f %f %f %f\n", b2[0], b2[1], b2[2], b2[3], b2[4], b2[5]);
	printf("Osorterad b2b: %f %f %f %f %f %f\n", b2b[0], b2b[1], b2b[2], b2b[3], b2b[4], b2b[5]);
	sort_array(b2b, 6);
	printf("Sorterad b2b: %f %f %f %f %f %f\n", b2b[0], b2b[1], b2b[2], b2b[3], b2b[4], b2b[5]);

	double s1[] = { 1, 9.9, 33.3, 33.4 };
	printf("s1 är sorterad: %d\n", is_array_sorted(s1, 4));
	double s2[] = { 1, 9.9, 33.5, 33.4 };
	printf("s2 är sorterad: %d\n", is_array_sorted(s2, 4));
	double s3[] = { 17.26 };
	printf("s3 är sorterad: %d\n", is_array_sorted(s3, 1));
	printf("b1 är sorterad: %d\n", is_array_sorted(b1, 1));
	printf("b2 är sorterad: %d\n", is_array_sorted(b2, 6));
	printf("b2b är sorterad: %d\n", is_array_sorted(b2b, 6));

	printf("s1 är sorterad: %d\n", is_array_sorted_2(s1, 4));
	printf("s2 är sorterad: %d\n", is_array_sorted_2(s2, 4));
	printf("s3 är sorterad: %d\n", is_array_sorted_2(s3, 1));
	printf("b1 är sorterad: %d\n", is_array_sorted_2(b1, 1));
	printf("b2 är sorterad: %d\n", is_array_sorted_2(b2, 6));
	printf("b2b är sorterad: %d\n", is_array_sorted_2(b2b, 6));

	shuffle_array(b1, 1);
	printf("Blandad b1: %f\n", b1[0]);
	shuffle_array(b2, 6);
	printf("Blandad b2: %f %f %f %f %f %f\n", b2[0], b2[1], b2[2], b2[3], b2[4], b2[5]);
	shuffle_array(b2b, 6);
	printf("Blandad b2b: %f %f %f %f %f %f\n", b2b[0], b2b[1], b2b[2], b2b[3], b2b[4], b2b[5]);

	bogosort_array(b1, 1);
	printf("Sorterad b1: %f\n", b1[0]);
	bogosort_array(b2, 6);
	printf("Sorterad b2: %f %f %f %f %f %f\n", b2[0], b2[1], b2[2], b2[3], b2[4], b2[5]);
	bogosort_array(b2b, 6);
	printf("Sorterad b2b: %f %f %f %f %f %f\n", b2b[0], b2b[1], b2b[2], b2b[3], b2b[4], b2b[5]);
}