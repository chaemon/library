typedef int nm;

pair<nm,nm> nmersection(const pair<nm,nm> &r,const pair<nm,nm> &s){
	if(r.second<=s.first or s.second<=r.first)return make_pair(0,0);
	else{
		return make_pair(max(r.first,s.first),min(r.second,s.second));
	}
}

