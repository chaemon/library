//{{{ id set??
template<class T>
struct id_set{
	vector<T> v;
	map<T,int> m;
	int num;
	id_set(){num=0;}
	int size(){return num;}
	int encode(const T &t){
		if(m.find(t)==m.end()){
			insert(t);
		}
		return m[t];
	}
	int operator[](const T &t){
		if(m.find(t)==m.end()){
			insert(t);
		}
		return m[t];
	}
	T decode(int i){
		assert(i<v.size());
		return v[i];
	}
	int insert(const T &t){
		if(m.find(t)!=m.end()){
			return m[t];
		}else{
			m.insert(MP(t,num));
			v.push_back(t);
			num++;
			assert(v.size()==num);
		}
		return num-1;
	}
	bool find(const T &t){
		return m.find(t)!=m.end();
	}
	void sort(){
		std::sort(v.begin(),v.end());
		m.clear();
		REP(i,v.size())m[v[i]]=i;
	}
};
//}}}
