//{{{ breadth first search
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int M=22,INF=1e+9;
char c[M][M];
int m,n;
#define inner(x,y) (0<=(x) and (x)<m and 0<=(y) and (y)<n)

bool vis[M][M];

void bfs(int x,int y){
	memset(vis,false,sizeof(vis));
	queue<pii> q;
	q.push(MP(x,y));
	while(!q.empty()){
		pii f=q.front();q.pop();
		int x=f.first,y=f.second;
		if(vis[x][y])continue;
		vis[x][y]=true;
		REP(i,4){
			int x2=x+dir[i][0],y2=y+dir[i][1];
			if(!inner(x2,y2))continue;
			q.push(MP(x2,y2));
		}
	}
}
//}}}
