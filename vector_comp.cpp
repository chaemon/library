//{{{ compare for vector
template<class T>
bool operator<(const vector<T> &v,const vector<T> &w){
	if(v.size()!=w.size())return v.size()<w.size();
	REP(i,v.size()){
		if(v[i]!=w[i])return v[i]<w[i];
	}
	return false;
}
//}}}
