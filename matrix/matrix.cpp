//{{{ Matrix
typedef int nm;
typedef vector<nm> array;
typedef vector<array> matrix;

nm add(const nm &x,const nm &y){return (x+y)%mod;}
nm mul(const nm &x,const nm &y){return x*y%mod;}

// O( n )
matrix identity(int n) {
	matrix A(n, array(n));
	for (int i = 0; i < n; ++i) A[i][i] = 1;
	return A;
}
// O( n )
nm inner_product(const array &a, const array &b) {
	nm ans = 0;
	for (int i = 0; i < a.size(); ++i)
		ans = add(ans,mul(a[i],b[i]));
	return ans;
}
// O( n^2 )
array mul(const matrix &A, const array &x) {
	array y(A.size());
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < A[0].size(); ++j)
			y[i] = add(y[i], mul(A[i][j],x[j]));
	return y;
}
// O( n^3 )
matrix mul(const matrix &A, const matrix &B) {
	matrix C(A.size(), array(B[0].size()));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j)
			for (int k = 0; k < A[i].size(); ++k)
				C[i][j] =add(C[i][j],mul(A[i][k],B[k][j]));
	return C;
}
// O( n^3 log e )
matrix pow(const matrix &A, int e) {
	return e == 0 ? identity(A.size())  :
		e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
//}}}
