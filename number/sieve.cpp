const int N=1e+6;
int primes[N];
//{{{ eratosthenes
void sieve_of_eratosthenes(int n) {
	for (int i = 2; i < n; ++i)
		primes[i] = i;
	for (int i = 2; i*i < n; ++i)
		if (primes[i]==i)
			for (int j = i*i; j < n; j+=i)
				primes[j] = i;
}
//}}}
