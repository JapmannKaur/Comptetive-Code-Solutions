#include <bits/stdc++.h> 
#define MOD 1000000007LL
#define SIZE 100000009
#define MAXX 100000009
#define LL long long
#define ULL unsigned long long
#define ABS(x) ((x)<0?-(x):(x))
#define SQR(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define REP(i,n) for(__typeof(n) i=0;i<(n);i++)
#define FOR(i,a,b) for(__typeof(b) i=(a);i<(b);++i)
#define FORE(i,a,b) for(__typeof(b) i=(a);i<=(b);++i)
#define FORD(i,a,b,d) for(__typeof(b) i=(a);i<(b);i+=(d))
#define FORR(i,n,e) for(__typeof(n) i=(n);i>=(e);--i)
#define FORRD(i,n,e,d) for(__typeof(n) i=(n);i>=(e);i-=(d))
#define REP_IT(it,m) for(it=m.begin();it!=m.end();it++)
#define FORI(it,s) for(__typeof((s).begin()) (it)=(s).begin();(it)!=(s).end();(it)++)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(a,b) memset(a,b,sizeof(a))
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define PB push_back
#define MP make_pair
#define XX first
#define YY second
#define TEST int T;cin>>T;FORE(t,1,T)
using namespace std;
double _st;
const int maxx = 10000007;
LL ft[maxx],N;
#define ll long long
#define LSOne(S) (S & (-S))
ll query(int b) {
        ll sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
}
 
// Point update: Adds v to the value at position k in the array
void update(int k, int v) {
        for (; k <= N; k += LSOne(k)) ft[k] += v;
}
 
// Range update: Adds v to each element in [i...j] in the array
void range_update(int i, int j, int v)  {
        update(i, v);
        update(j + 1, -v);
}
void solve()
{ 
  FILL(ft,0);
  int M,a,b,k;
  cin>>N>>M;
  REP(i,M)
    {
      cin>>a>>b>>k;
      range_update(a, b, k);
    }
  LL ans = -1;
  REP(i,N)
    {
      ans = max(ans,query(i+1));
    }
  cout << ans << endl;
}
void pre()
{
  solve();
}
void end(){
#ifdef dexter
  fprintf(stdout,"\nTIME: %.3lf sec\n",(double)(clock()-_st)/(CLOCKS_PER_SEC));
#endif
}
int main()
{
#ifdef dexter
  freopen("/home/dexter/Desktop/Dropbox/ZONE/inout/input.txt","r",stdin);
  freopen("/home/dexter/Desktop/Dropbox/ZONE/inout/output.txt","w",stdout);
  _st = clock();
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  end();
  return 0;
}
