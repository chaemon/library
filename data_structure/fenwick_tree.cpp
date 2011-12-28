//{{{ Fenwick Tree
template <class T>
struct fenwick_tree {
	vector<T> x;
	fenwick_tree(int n) : x(n, 0) { }
	T sum(int p, int q) {
		if (p == 0) {
			T S = 0;
			for (int j=q ; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
			return S;
		} else return sum(0, q) - sum(0, p-1);
	}
	void add(int p, T a) {
		for (int k=p ; k < x.size(); k |= k+1) x[k] += a;
	}
};
//}}}
//{{{ Fenwick Tree type2
template <class T>
struct fenwick_tree {
	vector<T> x;
	fenwick_tree(int n) : x(n, 0) { }
	void add(int p, int q, T a) {
		if (p == 0) {
			for (int j=q; j >= 0; j = (j & (j + 1)) - 1) x[j] += a;
		} else {
			add(0,q,a);add(0,p-1,-a);
		}
	}
	T get(int p) {
		T ret = 0;
		for (int k=p; k < x.size(); k |= k+1) ret += x[k];
		return ret;
	}
};
//}}}
//{{{ Fenwick Tree type2 2D
/*
template <class T>
struct fenwick_tree {
	vector<vector<T> > x;
	fenwick_tree(int n) : x(n, vector<T>(n,0)) { }
	void add(int i0, int i1, int j0,int j1,T a) {
		if (i0 == 0 and i1 == 0) {
			int J0=j0,J1=j1;
			for (j0=J0; j0 >= 0; j0 = (j0 & (j0 + 1)) - 1)
				for (j1=J1; j1 >= 0; j1 = (j1 & (j1 + 1)) - 1) x[j0][j1] += a;
		} else {
			add(0,0,j0,j1,a);
			add(0,0,i0-1,j1,-a);
			add(0,0,j0,i1-1,-a);
			add(0,0,i0-1,i1-1,a);
		}
	}
	T get(int k0,int k1) {
		T ret = 0;
		const int K0=k0,K1=k1;
		for(k0=K0; k0<x.size();k0 |= (k0+1))
			for (k1=K1; k1 < x.size(); k1 |= (k1+1)) ret += x[k0][k1];
		return ret;
	}
*/
};
//}}}
