typedef double rnum;
const rnum EPS=1e-8;
const rnum INF=1e+8;
//{{{ Ternary Search
rnum largestCoveringCircle(rnum (*f)(rnum)){
	rnum left=-INF,right=INF;
	while(right-left>EPS){
//				cout<<left<<" "<<right<<endl;
		rnum leftThird=left+(right-left)*0.45;
		rnum rightThird=left+(right-left)*0.55;

		rnum rLeft=f(leftThird,ternaryY(leftThird));
		rnum rRight=f(rightThird,ternaryY(rightThird));
//		cout<<rLeft<<" "<<rRight<<endl;

		if(rLeft>rRight)
			left=leftThird;
		else
			right=rightThird;
	}
	rnum x=(left+right)*0.5;
	return x;
}
//}}}
//{{{ Golden Section Search

const rnum phi=(1+sqrt(5))/2;
const rnum resphi=(rnum)2-phi;

rnum goldenSectionSearch(rnum (*f)(rnum)){
	rnum a=-INF,b=INF, c=(phi*a+b)/(phi+1.0);
	rnum fb=f(b);
	for(;;){
		if(abs(c-a)<EPS*(abs(b)+abs(c)))break;
		rnum x;
		if(c-b>b-a)x=b+resphi*(c-b);
		else x=b-resphi*(b-a);
//		cout<<a<<" "<<b<<" "<<c<<" "<<x<<endl;
		rnum fx=f(x);
		if(fx<fb){
			if(c-b>b-a)a=b,b=x;
			else c=b,b=x;
			fb=fx;
		}else{
			if(c-b>b-a)c=x;
			else a=x;
		}
	}
	return (a+c)/2;
}
//}}}
