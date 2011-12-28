//{{{ factorial and combination
const int M=1000010;
//const int mod=1000003;
const int mod=-1;

Int fact(Int n){
	static bool lookup=false;
	static Int f[M];
	if(!lookup){
		Int s=1;
		REP(i,M){
			f[i]=s;
			s*=(i+1);if(mod>0)s%=mod;
		}
		lookup=true;
	}
	return f[n];
}
//{{{ combnation using factorial
Int comb(Int n,Int k){
	if(n<0 or k<0 or n<k)return 0;
	Int ans=1;
	ans*=fact(n);
	if(mod>0)ans%=mod;
	ans*=invMod(fact(k),mod);
	if(mod>0)ans%=mod;
	ans*=invMod(fact(n-k),mod);
	if(mod>0)ans%=mod;
	return ans;
}
//}}}

//}}}
