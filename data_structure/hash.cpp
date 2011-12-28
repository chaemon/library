//{{{ Hash
const int H=1000000;
template<typename Key,typename Val>
struct Hash{
	char *used;
	Key *key;Val *val;
	typedef pair<bool,int> PBI;
	Hash(){
		used=new char[H];key=new Key[H];val=new Val[H];
		memset(used,0,sizeof(used));
	}
	void clear(){
		memset(used,0,sizeof(used));
	}
	int hash_func(const Key &k){
		return k%H;
	}
	PBI find(const Key &k){
		int h=hash_func(k);
		for(;;h++,h=(h==H)?0:h){
			if(not used[h])return MP(false,h);
			if(key[h]==k)return MP(true,h);
		}
	}
	void insert(const Key &k,const Val &v){
		int h=find(k).second;
		used[h]=1;key[h]=k;val[h]=v;
	}
	Val &get(const Key &k){
		PBI f=find(k);
		if(!f.first)assert(false);
		return val[f.second];
	}
};
//}}}
