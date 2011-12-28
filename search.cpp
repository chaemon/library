//{{{ search, need EPS and rnum
rnum find_root(rnum a, rnum b, rnum f(rnum)) {
	rnum fa = f(a), fb = f(b);
//	cout<<fa<<" "<<fb<<endl;
	while (b - a > EPS) {
		rnum c = (b + a) / 2.0;
		rnum fc = f(c);
		if (fa*fc > 0) { a = c; fa = fc; }
		else { b = c; fb = fc; }
	}
	return a;
}
rnum find_max(rnum a, rnum b, rnum f(rnum)) {
	const rnum r = 2 / (3 + sqrt(5));
	rnum c = a + r * (b - a), d = b - r * (b - a);
	rnum fc = f(c), fd = f(d);
	while (d - c > EPS) {
		if (fc < fd) { // '<': maximum, '>': minimum
			a = c; c = d; d = b - r * (b - a);
			fc = fd; fd = f(d);
		} else {
			b = d; d = c; c = a + r * (b - a);
			fd = fc; fc = f(c);
		}
	}
	return c;
}
//}}}
