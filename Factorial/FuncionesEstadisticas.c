int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; ++i)	{
		result *= i;
	}
	return result;
}

int combinacion(int n, int p) {
	return factorial(n) / (factorial(p) * factorial( n - p));
}