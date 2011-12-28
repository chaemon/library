const rn EPS=1e-10L,INF=1e+18;
//{{{ Ternary Search
//smallest value of convex function
rn ternarySearch(rn (*f)(rn),rn left=-INF,rn right=INF){
	while(right-left>EPS){
//				cout<<left<<" "<<right<<endl;
		rn leftThird=left+(right-left)*0.45;
		rn rightThird=left+(right-left)*0.55;

		rn rLeft=f(leftThird);
		rn rRight=f(rightThird);
//		cout<<rLeft<<" "<<rRight<<endl;
		if(rLeft>rRight)
			left=leftThird;
		else
			right=rightThird;
	}
	rn x=(left+right)*0.5;
	return x;
}
//}}}
