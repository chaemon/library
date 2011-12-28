//{{{ manhattan distance
template<class T>
T manh(const pair<T,T> &p, const pair<T,T> &q){
	return abs(p.first-q.first)+abs(p.second-q.second);
}

template<class T>
T manh_diag(const pair<T,T> &p, const pair<T,T> &q){
	return max(abs(p.first-q.first),abs(p.second-q.second));
}

template<class T>
T euclid(const pair<T,T> &p, const pair<T,T> &q){
	return sqrt((p.first-q.first)*(p.first-q.first)+(p.second-q.second)*(p.second-q.second));
}

//}}}
