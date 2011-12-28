//{{{ Segment Tree
template <class T>
struct segment_tree {
	int n;
	vector<T> x;
	segment_tree(int n_) {
		n=1;
		int logn=0;
		while(n < n_)n*=2,logn++;
		x.assign(n*logn,(T)0);
	}
	void add(int a,int b,T diff,int k,int l,int r){
		if(r<=a or b<=l)return;
		if(a<=l and r<=b)x[k]+=diff;
		else{
			add(a,b,diff,k*2+1,l,(l+r)/2);
			add(a,b,diff,k*2+2,(l+r)/2,r);
		}
	}
	void add(int a,int b,T diff){
		add(a,b,diff,0,0,n);
	}
	T get(int k) {
		k+=n-1;
		T s=(T)0;
		while(1){
			s+=x[k];
			if(k==0)break;
			k=(k-1)/2;
		}
		return s;
	}
};
//}}}

