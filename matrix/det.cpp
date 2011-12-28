//{{{ det tr rank
// O( n^3 )
const nm eps = 1e-8;
nm det(matrix A) {
	const int n = A.size();
	nm D = 1;
	for (int i = 0; i < n; ++i) {
		int pivot = i;
		for (int j = i+1; j < n; ++j)
			if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
		swap(A[pivot], A[i]);
		D *= A[i][i] * (i != pivot ? -1 : 1);
		if (abs(A[i][i]) < eps) break;
		for(int j = i+1; j < n; ++j)
			for(int k = n-1; k >= i; --k)
				A[j][k] -= A[i][k] * A[j][i] / A[i][i];
	}
	return D;
}
// O(n)
nm tr(const matrix &A) {
	nm ans = 0;
	for (int i = 0; i < A.size(); ++i)
		ans += A[i][i];
	return ans;
}
// O( n^3 ).
int rank(matrix A) {
	const int n = A.size(), m = A[0].size();
	int r = 0;
	for (int i = 0; r < n && i < m; ++i) {
		int pivot = r;
		for (int j = r+1; j < n; ++j)
			if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
		swap(A[pivot], A[r]);
		if (abs(A[r][i]) < eps) continue;
		for (int k = m-1; k >= i; --k)
			A[r][k] /= A[r][i];
		for(int j = r+1; j < n; ++j)
			for(int k = i; k < m; ++k)
				A[j][k] -= A[r][k] * A[j][i];
		++r;
	}
	return r;
}
//}}}
