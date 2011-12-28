//{{{ circle and line
rn lp_distance(const L& l, const P& p) {
	return abs(outp(l.dir, p-l.pos) / abs(l.dir));
}

bool cl_intersects(const C& c, const L& l) {
	return lp_distance(l, c.p) <= c.r + EPS;
}

//Circle line cross: order: according to the direction
vector<P> cl_cross(const C& c, const L& l) {
	P h = perf(l, c.p);
	rn d = abs(h - c.p);
	vector<P> res;
	if(d < c.r - EPS){
		P x = (l.dir / abs(l.dir)) * P(sqrt(c.r*c.r - d*d));
		res.push_back(h - x);
		res.push_back(h + x);
	}else if(d < c.r + EPS){
		res.push_back(h);
		res.push_back(h);
	}
	REP(i,res.size()){
		assert(abs(outp(res[i]-l.pos,l.dir))<EPS);
		assert(abs(abs(res[i]-c.p)-c.r)<EPS);
	}
	return res;
}
//}}}
//{{{ sp intersects
bool sp_intersects(const L& s, const P& p) {
	return ( abs(s.pos - p) + abs(s.pos + s.dir - p) - abs(s.dir) < EPS );
}
//}}}
//{{{ polygon area
rn area(G& g) {
	int n = g.size();
	rn s = 0.0;
	for(int i = 0; i < n; i++) {
		int j = (i+1)%n;
		s += outp(g[i], g[j])/2;
	}
	return abs(s);
}
//}}}
//{{{ inner
//circle
bool inner(const C &c,const P &p){//inner or circumference
	return abs(p-c.p)<c.r+EPS;
}
//triangle
bool inner(const vector<P> &v,const P &p){
	if(outp(v[1]-v[0],p-v[0])>-EPS and
			outp(v[2]-v[1],p-v[1])>-EPS and
			outp(v[0]-v[2],p-v[2])>-EPS )return true;
	return false;
}
//}}}
//{{{ area of circleSector
rn circleSector(const C &c, const P &a,const P &b){
	assert(abs(abs(b-c.p)-c.r)<EPS and abs(abs(a-c.p)-c.r)<EPS);
	rn theta=arg((b-c.p)/(a-c.p));
	if(theta<-EPS)theta+=(rn)PI*2;
	else if(theta<EPS)return 0.0;
	rn res=c.r*c.r*theta/2;
	assert(res<c.r*c.r*PI+EPS);
	return res;
}
//}}}
//{{{ area of circle and triangle
rn CT_area(const C &c, vector<P> v){
	if(area(v)<EPS)return 0.0L;
	assert(ccw(v[0],v[1],v[2])==1);
	int s=-1;
	REP(i,3)if(!inner(c,v[i])){s=i;}
	if(s==-1)return area(v);//all inner
	bool in=false;
	vector<pair<P,bool> > poly;//in->out: true, other: false
	for(int i=s;;){
		int j=(i+1==3)?0:i+1;
		L l(v[i],v[j]-v[i]);
		bool inj=inner(c,v[j]);
		if(in){
			poly.push_back(MP(v[i],false));
			if(inj){
				//in->in
			}else{
				//in->out
				vector<P> vp=cl_cross(c,l);
				poly.push_back(MP(vp[1],true));
			}
		}else{
			if(inj){
				//out->in
				vector<P> vp=cl_cross(c,l);
				poly.push_back(MP(vp[0],false));
			}else{
				//out->out
				if(cl_intersects(c,l)){
					//out->in->out
					vector<P> vp=cl_cross(c,l);
					if(sp_intersects(l,vp[0])){
						assert(sp_intersects(l,vp[1]));
						poly.push_back(MP(vp[0],false));poly.push_back(MP(vp[1],true));
					}else assert(!sp_intersects(l,vp[1]));
				}else assert(!inj);
			}
		}
		i=j;in=inj;
		if(i==s)break;
	}
	if(poly.size()==0 and inner(v,c.p))return c.r*c.r*PI;
	rn ans=0.0L;
	for(int i=0;i<poly.size();i++){
		int j=(i+1==poly.size())?0:i+1;
		if(poly[i].second)ans+=circleSector(c,poly[i].first,poly[j].first);
		else ans+=outp(poly[i].first-c.p,poly[j].first-c.p)/2;
	}
	return ans;
}
//}}}
//{{{ contains
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
enum { OUT, ON, IN };
int contains(const G& g, const P& p) {
	bool in = false;
	for (int i = 0; i < g.size(); ++i) {
		P a = curr(g,i) - p, b = next(g,i) - p;
		if (imag(a) > imag(b)) swap(a, b);
		if (imag(a) <= 0 && 0 < imag(b))
			if (outp(a, b) < 0) in = !in;
		if (outp(a, b) == 0 && inp(a, b) <= 0) return ON;
	}
	return in ? IN : OUT;
}
//}}}
