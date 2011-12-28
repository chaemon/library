
//{{{ inp outp
inline rn inp(const P& a, const P& b) {
	return (conj(a)*b).real();
}

inline rn outp(const P& a, const P& b) {
	return (conj(a)*b).imag();
}
//}}}
//{{{ projection
// $B%Y%/%H%k(Bp$B$r%Y%/%H%k(Bb$B$K<M1F$7$?%Y%/%H%k$r7W;;$9$k(B
inline P proj(const P& p, const P& b) {
	return b*inp(p,b)/norm(b);
}

// $BE@(Bp$B$+$iD>@~(Bl$B$K0z$$$??b@~$NB-$H$J$kE@$r7W;;$9$k(B
inline P perf(const L& l, const P& p) {
	L m(l.pos - p, l.dir);
	return (p + (m.pos - proj(m.pos, m.dir)));
}

// $B@~J,(Bs$B$rD>@~(Bb$B$K<M1F$7$?@~J,$r7W;;$9$k(B
inline L proj(const L& s, const L& b) {
	return (L){perf(b, s.pos), proj(s.dir, b.dir)};
}
//}}}

//{{{ ccw
inline int ccw(const P& p, const P& r, const P& s) {
	P a(r-p), b(s-p);
	int sgn = signum(outp(a, b));
	if (sgn != 0)
		return sgn;
	if (a.real()*b.real() < -EPS || a.imag()*b.imag() < -EPS)
		return -1;
	if (norm(a) < norm(b) - EPS)
		return 1;
	return 0;
}
//}}}
