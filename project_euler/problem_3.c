// The prime factors of  are  and .

// What is the largest prime factor of the number 600851475143
//
#include <stdio.h>
#include <math.h>


// algorithm trial-division is
//     input: Integer n to be factored
//     output: List F of prime factors of n

//     arr ← set of all primes ≤ sqrt(n)
//     factors ← empty list of factors

//     for each prime p in arr do
//         while n mod p is 0
//             Add factor p to list F
//             n ← n/p

//     if F is empty    (Original n is prime?)
//         Add factor n to list F

void print_primes(double max, long long int n)
{
	long long int arr[100000] = {0};
	long long int factors[100000] = {0};
	int idx = 0;

	for (long long int i = 2; i < max; i++) {
		int is_divisible = 0;
		for (long long int j = 2; j < i; j++) {
			if (i % j == 0) {
				is_divisible = 1;
				break;
			}
		}
		if (is_divisible == 0) {
			arr[idx++] = i;
		}
		is_divisible = 0;
	}

	long long int f_idx = 0;
	for (int i = 0; i < idx; i++) {
		while (n% arr[i] == 0) {
			n = n/ arr[i];
			factors[f_idx++] = arr[i];
			// printf("new n\n");
			// printf("n = %lld\n", n);
		}
		// printf("%lld\n", arr[i]);
	}

	for (int i = 0; i < f_idx; i++) {
		printf("%lld\n", factors[i]);
	}
}

void trial_division(long long int n)
{
	double max = sqrt(n);
	print_primes(max, n);
}


int main(void)
{
	long long int n = 600851475143;
	trial_division(n);

	return 0;
}
