//{{{ Memo DP
int res[M][M];
int calc(int i,int j){
	//{{{ lookup
	static bool lookup=0;
	if(!lookup){
		memset(res,-1,sizeof(res));
		lookup=true;
	}
	//}}}
	if(res[i][j]>=0)return res[i][j];
	int ret;
	
	
	return ret=0;//dummy
}

//}}}
