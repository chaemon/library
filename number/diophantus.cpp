//{{{ Diophantus equation: an = b (mod m)
struct no_solution {};
Int divide(Int a, Int b, Int m) {
	Int g = gcd(a, m);
	if (b%g != 0)
		throw no_solution();
	Int x, y;
	extgcd(a, m, x, y);
	assert(a*x+m*y == gcd(a,m));
	Int n = x*b/g;
	Int dn = m/g;
	n -= n/dn*dn;
	if (n < 0)
		n += dn;
	return n;
}
//}}}
