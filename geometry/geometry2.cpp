//{{{ geometry components

typedef double rnum;
const rnum EPS = 1e-8;
const rnum INF = 1e12;
typedef complex<rnum> P;
namespace std {
	bool operator < (const P& a, const P& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
rnum cross(const P& a, const P& b) {
	return imag(conj(a)*b);
}
rnum dot(const P& a, const P& b) {
	return real(conj(a)*b);
}

struct L : public vector<P> {
	L(const P &a, const P &b) {
		push_back(a); push_back(b);
	}
};

typedef vector<P> G;

struct C {
	P p; rnum r;
	C(const P &p, rnum r) : p(p), r(r) { }
};

int sign(const rnum &x){
	if(x<-EPS)return -1;
	else if(x>EPS)return 1;
	else return 0;
}

int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)   return +1;       // counter clockwise
	if (cross(b, c) < 0)   return -1;       // clockwise
	if (dot(b, c) < 0)     return +2;       // c--a--b on line
	if (norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;
}
//}}}
