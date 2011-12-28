const int INF=1e+9;
//{{{ bsearch lower_bound for monotone increasing
template<class T>
int lower_bound(int a, int b, const T &t, T *v){
	if(a>b)return -INF;
	const int l=a,r=b;
	assert(l<=r);
	if(v[a]>=t)return a;
	if(v[b]<t)return -INF;
	while(b-a>1){
		int c=(a+b)/2;
		if(t<=v[c])b=c;
		else a=c;
	}
	assert(b==l or (t<=v[b] and v[b-1]<t));
	return b;
}
//}}}
//{{{ bsearch upper_bound for monotone increasing
template<class T>
int upper_bound(int a, int b, const T &t, T *v){
	if(a>b)return -INF;
	const int l=a,r=b;
	assert(l<=r);
	if(v[a]>t)return a;
	if(v[b]<=t)return -INF;
	while(b-a>1){
		int c=(a+b)/2;
		if(t<v[c])b=c;
		else a=c;
	}
	assert(b==l or (t<v[b] and v[b-1]<=t));
	return b;
}
//}}}

