//{{{ AVL tree
template <class Key,class Value=char>
struct avl_tree {
	static const int M=400010;
	struct node {//for AVL
		Key key;Value val;
		int size, height;
		node *child[2];
		node(const Key &key,const Value &val=0) : key(key), size(1), height(1), val(val) {
			child[0] = child[1] = 0; }
		node(){}
	} *root,v[M];
	int v_num;
	typedef node* pointer;
	pointer get_new(const Key &key,const Value &val){
		//		return new node(key,val);
		v[v_num]=node(key,val);
		return &(v[v_num++]);
	}
	void init() { root = NULL; v_num=0;}
	avl_tree() { init(); }
	unsigned int size(){
		if(not root)return 0;
		else return root->size;
	}
	pointer find(const Key &key) { return find(root, key); }
	pointer find(pointer t, const Key &key) {
		if (t == NULL) return NULL;
		if (key == t->key) return t;
		else if (key < t->key) return find(t->child[0], key);
		else                   return find(t->child[1], key);
	}
	void insert(const Key &key,const Value &val=0) { root = insert(root, key, val); }
	pointer insert(pointer t, const Key &key,const Value &val) {
//			if (t == NULL) return new node(key,val);
		if (t == NULL) return get_new(key,val);
		if (key==t->key){t->val=val;return t;}
		if (key < t->key) t->child[0] = insert(t->child[0], key,val);
		else if(key>t->key) t->child[1] = insert(t->child[1], key,val);
		t->size += 1;
		return balance(t);
	}
	void erase(const Key &key) { root = erase(root, key); }
	pointer erase(pointer t, const Key &x) {
		if (t == NULL) return NULL;
		if (x == t->key) {
			return move_down(t->child[0], t->child[1]);
		} else {
			if (x < t->key) t->child[0] = erase(t->child[0], x);
			else            t->child[1] = erase(t->child[1], x);
			t->size -= 1;
			return balance(t);
		}
	}
	Key beg_key(pointer t){
		if(!t->child[0])return t->key;
		else return beg_key(t->child[0]);
	}
	pointer move_down(pointer t, pointer rhs) {
		if (t == NULL) return rhs;
		t->child[1] = move_down(t->child[1], rhs);
		return balance(t);
	}
#define sz(t) (t ? t->size : 0)
#define ht(t) (t ? t->height : 0)
	pointer rotate(pointer t, int l, int r) {
		pointer s = t->child[r];
		t->child[r] = s->child[l];
		s->child[l] = balance(t);
		if (t) t->size = sz(t->child[0]) + sz(t->child[1]) + 1;
		if (s) s->size = sz(s->child[0]) + sz(s->child[1]) + 1;
		return balance(s);
	}
	pointer balance(pointer t) {
		for (int i = 0; i < 2; ++i) {
			if (ht(t->child[!i]) - ht(t->child[i]) < -1) {
				if (ht(t->child[i]->child[!i]) - ht(t->child[i]->child[i]) > 0)
					t->child[i] = rotate(t->child[i], i, !i);
				return rotate(t, !i, i);
			}
		}
		if (t) t->height = max(ht(t->child[0]), ht(t->child[1])) + 1;
		if (t) t->size = sz(t->child[0]) + sz(t->child[1]) + 1;
		return t;
	}
	pointer nth(int k) const { return nth(root, k); }
	pointer nth(pointer t, int k) const {
		if (!t) return NULL;
		int m = sz(t->child[0]);
		if (k  < m) return nth(t->child[0], k);
		if (k == m) return t;
		if (k  > m) return nth(t->child[1], k - m - 1);
	}

};
//}}}
