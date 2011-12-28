//{{{ SegmentTree range-range
template<class T>
struct SegmentTree{
	int N,n;
	vector<T> data,datb;
	SegmentTree(int n):n(n){
		int m=n;
		N=2;
		while(m>0){
			N<<=1;m>>=1;
		}
		N--;
		data.assign(N,0);datb.assign(N,0);
	}
	void add(int a,int b,T x,int k,int l,int r){
//		cout<<"add: "<<a<<" "<<b<<" "<<k<<" "<<l<<" "<<r<<endl;
		assert(k<N);
		if(a<=l and r<=b)data[k]+=x;
		else if(l<b and a<r){
			datb[k]=datb[k]+x*(min(b,r)-max(a,l));
			add(a,b,x,k*2+1,l,(l+r)/2);
			add(a,b,x,k*2+2,(l+r)/2,r);
		}
	}
	void add(int a, int b, T x){
		add(a,b,x,0,0,n);
	}
	T sum(int a, int b, int k, int l, int r){
//		cout<<"sum: "<<a<<" "<<b<<" "<<k<<" "<<l<<" "<<r<<endl;
		assert(k<N);
		if(b<=l or r<=a)return 0;
		else if(a<=l and r<=b)
			return data[k]*(r-l)+datb[k];
		else{
			T res=data[k]*(min(b,r)-max(a,l));
			res+=sum(a,b,k*2+1,l,(l+r)/2);
			res+=sum(a,b,k*2+2,(l+r)/2,r);
			return res;
		}
	}
	T sum(int a, int b){
		return sum(a,b,0,0,n);
	}
};
//}}}
