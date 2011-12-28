Int powMod(const Int &x, const Int &k, const Int &m) {
	if (k == 0)     return 1;
	if (k % 2 == 0) return powMod(x*x % m, k/2, m);
	else            return x*powMod(x, k-1, m) % m;
}
Int geometricProgression(Int x,Int k,Int m){
	if(k==0)return 0;
	Int s=geometricProgression(x,k/2,m),t=powMod(x,k/2,m);
	s=s*(t+1)%m;
	if(k%2==1)s=(s*x+1)%=m;
	return s;
}
