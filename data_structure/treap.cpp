//{{{ Treap
template<class Key,class Value=char>
struct Treap{
	static const int M=400010;
	typedef int Result;
	struct node {
		Key key;Value val;
		int p;
		bool cached;Result cache;
		node *child[2]; // LEFKey = child[0], RIGHKey = child[1]
		node(const Key &key, const Value &val) : key(key), val(val),
		p(rand()), cached(0) { child[0] = child[1] = 0; }
		node(){}
	} *root, v[M];
	int v_num;

	void init(){root=NULL;v_num=0;}
	Treap(){init();}
	typedef node* pointer;
	pointer get_new(const Key &key,const Value &val){
		//		return new node(key,val);
		v[v_num]=node(key,val);
		return &(v[v_num++]);
	}

	unsigned int size(){ return eval(root); }
	pointer rotate(pointer t, int b) {
		pointer s = t->child[1-b]; t->child[1-b] = s->child[b]; s->child[b] = t;
		s->cached = t->cached = false;
		return s;
	}
	pointer find(const Key key){return find(root,key);}
	pointer find(pointer t, const Key &key) {
		return !t || key == t->key ? t : find(t->child[key<t->key], key);
	}
	void insert(const Key &key,const Value &val=-1) { root = insert(root, key, val); }
	pointer insert(pointer t, const Key &key, const Value &val) {
		if (!t) return get_new(key, val);
		else if (key == t->key){ t->val=val;return t;}
		int b = !(key < t->key);
		t->child[b] = insert(t->child[b], key, val);
		if (t->p > t->child[b]->p) t = rotate(t, 1-b);
		t->cached = false;
		return t;
	}
	void erase(const Key &key) { root = erase(root, key); }
	pointer erase(pointer t, const Key &key) {
		if (!t) return NULL;
		if (key == t->key) {
			if (!t->child[0] && !t->child[1]) return NULL;
			else if (!t->child[0]) t = rotate(t, 0);
			else if (!t->child[1]) t = rotate(t, 1);
			else t = rotate(t, t->child[0]->p<t->child[1]->p);
			t = erase(t, key);
		} else {
			int b = !(key < t->key);
			t->child[b] = erase(t->child[b], key);
		}
		t->cached = false;
		return t;
	}
	Key beg_key(pointer t){
		if(!t->child[0])return t->key;
		else return beg_key(t->child[0]);
	}

	Result eval(pointer t) {
		if (!t) return 0;
		if (!t->cached)
			t->cache = eval(t->child[0]) + eval(t->child[1]) + 1; // CHANGE IKey FLEXIBLE
		t->cached = true;
		return t->cache;
	}
	pointer nth(int k) { return nth(root, k); }
	pointer nth(pointer t, int n) { // NTH ELEMENT
		int l = eval(t->child[0]);
		if (n < l) return nth(t->child[0], n);
		if (n > l) return nth(t->child[1], n-l-1);
		return t;
	}
};
//}}}
