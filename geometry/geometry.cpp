//{{{ Geometry Components
#include<complex>
const rn PI=3.141592653589793238462643383279L;
const rn EPS=1e-10,INF=1e+10;

inline int signum(rn x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }

// point
typedef complex<rn> P;
// line
struct L {
	P pos, dir; 
	L(const P &pos,const P &dir):pos(pos),dir(dir){
	}
};
// polygon
typedef vector<P> G;
// circle
struct C { 
	P p; rn r;
	C(const P &p,const rn r):p(p),r(r){}
};
//}}}
