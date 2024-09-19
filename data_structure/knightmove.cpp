#include <iostream>
#include <cstring>
#include <queue>
// 騎士移動問題 以 QUEUE 進行廣度搜尋
using namespace std;

struct point{
    int x,y;
    int step;
};

int dx[8] = {-2, -2, -1, -1, 1,  1, 2,  2};
int dy[8] = { 1, -1,  2, -2, 2, -2, 1, -1};
#define maxn 100
bool vis[maxn][maxn];
int sx, sy, ex, ey, tx, ty, L;

int bfs(){
    if(sx == ex && sy == ey){
        return 0;
    }
    memset(vis, false, sizeof(vis));
    queue<point> Q;
    point start,node;
    start.x = sx;
    start.y = sy;
    start.step = 0;

    Q.push(start);
    int step,x,y;
    while(!Q.empty()){

        start = Q.front();
         Q.pop();
        x = start.x;
        y = start.y;
        step = start.step;

        for(int i=0; i<8; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx == ex && ty == ey){
                return step+1;
            }
            if(tx >= 0 && tx < L && ty >= 0 && ty < L && !vis[tx][ty]){
                node.x = tx;
                node.y = ty;
                node.step = step+1;
                Q.push(node);
                vis[tx][ty] = true;
            }
        }
    }
    
}

int main(){
    // sx = 0;
    // sy = 0;
    // ex = 7;
    // ey = 0;
    // L=8;
    int ncase=0;
    cin >> ncase;
    for(int nn=0; nn<ncase; nn++){
        cin >> L;
        cin >> sx >> sy;
        cin >> ex >> ey;
        cout << bfs() << '\n';    
    }
    

    return 0L;
}