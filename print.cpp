//{{{ Print functions
// Input/Output
template<class S,class T>
ostream &operator<<(ostream &os, const pair<S,T> &p){
	cout<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &x) {
	os<<"[";
	REP(i,x.size()){
		os<<x[i];
		if(i!=x.size()-1)os<<",";
	}
	os<<"]";
	return os;
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &x) {
	os<<"[";
	FOR(it,x){
		os<<*it;
		if(++it!=x.end())os<<",";
		it--;
	}
	os<<"]";
	return os;
}

template<class S,class T>
ostream &operator<<(ostream &os, const map<S,T> &x) {
	os<<"[";
	FOR(it,x){
		os<<*it;
		if(++it!=x.end())os<<",";
		it--;
	}
	os<<"]";
	return os;
}

void printBit(int b,int k=-1){
	if(k==-1){
		int bb=1,i=0;
		while(bb){
			if(b&bb)k=i;
			bb<<=1;i++;
		}
	}
	REP(ct,k){
		cout<<b%2;
		b>>=1;
	}
	cout<<endl;
}

//}}}
