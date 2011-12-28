//{{{ intersection of two circles
pair<P, P> cc_cross(const C& c1, const C& c2) {
	rn d = abs(c1.p - c2.p);
	rn rc = (d*d + c1.r*c1.r - c2.r*c2.r) / (2*d);
	rn rs = sqrt(c1.r*c1.r - rc*rc);
	P diff = (c2.p - c1.p) / d;
	return make_pair(c1.p + diff * P(rc, rs), c1.p + diff * P(rc, -rs));
}
//}}}
//{{{ cc_intersects
bool cc_intersects(const C& c1, const C& c2){
	rn d = abs(c1.p - c2.p);
	if(c1.r+c2.r <= d + EPS)return false;
	else return true;
}
//}}}
//{{{ intersection area of two circles
rn cc_area(const C& c1, const C& c2) {
	rn d = abs(c1.p - c2.p);
	if (c1.r + c2.r <= d + EPS) {
		return 0L;
	} else if (d <= abs(c1.r - c2.r) + EPS) {
		rn r = (c1.r < c2.r) ? c1.r : c2.r;
		return r * r * PI;
	} else {
		rn rc = (d*d + c1.r*c1.r - c2.r*c2.r) / (2*d);
		rn theta = acos(rc / c1.r);
		rn phi = acos((d - rc) / c2.r);
		return c1.r*c1.r*theta + c2.r*c2.r*phi - d*c1.r*sin(theta);
	}
}
//}}}
