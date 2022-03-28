#include<bits/stdc++.h>
using namespace std;
#define Piton4(in,out) freopen(in,"r",stdin);freopen(out, "w",stdout)
#define all(x) x.begin(),x.end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int> >
#define fi first
#define se second
#define PI 3.14159265359
#define pb push_back
#define fora(i,a) for(auto i:a)
#define fori(i,n) for(int i=0;i<n;i++)
#define int long long
#define mp make_pair
template <typename I> void vcin (int n, vector<I> a) {
	int t;
	fori(i,n){
		cin >> t;
		a.pb(t);
	}
}


template <typename I> void vcout (int n, vector<I> a,int d){ //d=0 - in line, d=1 - in column 
	if(d==0){
		fori(i,n){
			cout << a[i]<<" ";
		}
		cout <<endl;
	}
	else{
		fori(i,n){
			cout << a[i]<<endl;
		}
	}
}


void no(){
	cout << "NO"<<endl;
}


void yes(){
	cout << "YES"<<endl;
}


//number theory
template <typename I>I _gcd (I a, I b) {
	return !b ? abs(a) : _gcd(b, a % b);
}
int signf(int a){
	return (a!=0)? abs(a)/a : 0;
}


int sigma(int a){
	int k=0;
	for(int i=1;i<=a;i++){
		if(a%i==0){
			k+=i;
		}
	}
	return k;
}


int tau(int a){
	int k=0;
	for(int i=1;i<=a;i++){
		if(a%i==0){
			k++;
		}
	}
	return k;
}

bool PowerOfTwo(int &Value)
{
	int InitValue = 1;
	while (InitValue < Value){
		InitValue *= 2;
	}
	if (InitValue == Value)
		return true;
	return false;
}
bool PowerOfValue(int &Value,int &Value2)
{
	int InitValue = 1;
	while (InitValue < Value){
		InitValue *= Value2;
	}
	if (InitValue == Value)
		return true;
	return false;
}
bool prost(int n){
	for (int i=2;i<=sqrt(n);i++){
		if (n%i==0){
			return false;
		}
	}
	return true;
}
int colcif(int n){
	int i=0;
	int k=n;
	while(k>0){
		k=k/10;
		i++;
	}
	return i;
}
void eratosfen(int n,vector<bool> prime){
	prime[0] = prime[1] = false;
	for (int i=2; i<=n; ++i){
		if (prime[i]){
			if (i * 1ll * i <= n){
				for (int j=i*i; j<=n; j+=i){
					prime[j] = false;
				}	
			}		
		}	
	}
}

//segtree
int mex(int a,int b){
	if(min(a,b)!=0){
		return min(a,b)-1;
	}
	if(abs(a-b)!=1){
		return 1;
	}
	return 2;
}
template <typename I> segfunctree(I a,I b){
	return mex(a,b);
}


struct segtree{
	vector<int> tree;
	int size;
	
	void init(int n){
		size=1;
		while(size<n){
			size=size*2;
		}
		tree.assign(2*size-1,0);
	}
	void sethelp(int i,int v,int x,int rx,int lx){
		if(rx-lx==1){
			tree[x]=v;
			return;
		}
		int m=(rx-lx)/2;
		if(i<m){
			sethelp(i,v,2*x+1,lx,m);
		}
		else{
			sethelp(i,v,2*x+2,m,rx);
		}
		tree[x]=segfunctree(tree[2*x+1],tree[2*x+2]);
	}
	void set(int i,int v){
		sethelp(i,v,0,0,size);
	}
	int segfunctreefullhelp(int l,int r,int x,int lx,int rx){
		if(l>=lx || lx>=r){
			return 0;
		}
		if(lx>=l and rx<=r){
			return tree[x];
		}
		int m=(lx+rx)/2;
		int s1=segfunctreefullhelp(l,r,2*x+1,lx,m);
		int s2=segfunctreefullhelp(l,r,2*x+1,m,rx);
		return segfunctree(s1,s2);
	}
	int segfunctreefull(int l,int r){
		return segfunctreefullhelp(l,r,0,0,size);
	}
};
string sist(int n, int sis, string k){
	if(n<0){
		return sist(abs(n),sis,"-");
	}
	if(n==0){
		return k;
	}
	char help='0'+n%sis;
	return sist(n/sis,sis,help+k);
}
class Drob
{
public:
	int x, y;
    Drob(){};
    Drob(int a, int b)
    {
        x = a;
        y = b;
    }
    
    
    Drob flip(){
        return Drob(y,x);
    }
    
    
    Drob operator+(Drob c)
    {
        Drob d1 = Drob(x * c.y, y * c.y);
        Drob d2 = Drob(c.x *y, c.y *y);
        
        return Drob(d1.x + d2.x, d1.y);
    }
    
    
    Drob operator-(Drob c)
    {
        Drob d1 = Drob(x * c.y, y * c.y);
        Drob d2 = Drob(c.x * y, c.y * y);
 
        return Drob(d1.x - d2.x, d1.y);
    }
    
    
    Drob operator*(Drob c)
    {
        return Drob(x * c.x, y * c.y);
	}
	
	
	Drob sokr(){
		return Drob(x/_gcd(x,y),y/_gcd(x,y));
	}
	
	
	Drob power(int n){
		return Drob(pow(x,n),pow(y,n));
	}
	
	
	Drob per(int n){
		return Drob(n,1);
	}
	Drob operator^(Drob c){
		return Drob(x+c.x,y+c.y);//medianta
	}
};
vector <int> used;
//grafs
void dfs(int v, vector<vector<int> > graf){
	used[v]=1;
	for(int i=0;i<(graf[v].size());i++){
		if(used[graf[v][i]]==0){
			dfs(graf[v][i],graf);
		}
	}
}
const int INF = 10e18;
//binpoisk
int binpoisklefthelp(vector<int> &a, int l, int r, int key){
	if(r-l>1){
		int m;m=l+(r-l)/2;
		if(a[m]>=key){
			return binpoisklefthelp(a, l, m, key);
		}
		if(a[m]<key){
			return binpoisklefthelp(a, m, r, key);
		}
	}
	else{
		//if(l!=key){
	//		return -1;
		//}
		return l;
	}
}
int lbin(vector<int> &a,int key){
	return binpoisklefthelp(a,-1,a.size(),key);
}


int binpoiskrighthelp(vector<int> &a, int l, int r, int key){
	if(r-l>1){
		int m;m=l+(r-l)/2;
		if(a[m]>key){
			return binpoiskrighthelp(a, l, m, key);
		}
		if(a[m]<=key){
			return binpoiskrighthelp(a, m, r, key);
		}
	}
	else{
		//if(r!=key){
		//	return -1;
		//}
		return r;
	}
}
int rbin(vector<int> &a,int key){
	return binpoiskrighthelp(a,-1,a.size(),key);
}
signed main() {
	std::ios_base::sync_with_stdio(0); std::cout.tie(0); std::cin.tie(0);
	//vector<bool> prime (n+1, true);eratosfen(n,prime);
	//cout << setprecision(10);
	//freopen("tree.in", "r", stdin);
	//freopen("rt.txt", "w", stdout);
	int t;cin >> t;while(t--){
		
	}
	return 0; 
}
