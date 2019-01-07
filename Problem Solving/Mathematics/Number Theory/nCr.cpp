#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int,int> mii;
typedef long long ll;

#define all(s) (s).begin(), (s).end()
#define FOR(i,a,b) for(int i=(a);i<(b); i++)
#define REP(i,b) FOR(i,0,b)
#define FE(it,set) for(auto it = (set).begin(); it != (set).end(); ++it)
#define pb push_back

int partBalance(int n, int prime) {
	return n == 0 ? 0 : n/prime + partBalance(n/prime, prime);
}
int calcBalance(int n, int r, int prime) {
	return partBalance(n,prime) - partBalance(r, prime) - partBalance(n-r, prime);


}
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

ll mulMod(ll a, ll b, ll mod) {
	return a * b % mod;
}
ll expMod(ll n, ll p, ll mod) {
	assert(p >= 0);
	if(p <= 0) return 1;
	ll part = expMod(n * n % mod, p/2, mod);
	if(p % 2) part = (part * n) % mod;
	return part;
}

int calcInvPow(int mod, int p){
	static mii memo;
	int& prod = memo[mod];
	if(prod) return prod;
	prod = p - 1;
	assert(mod % p == 0);
	mod /= p;

	while(mod > 1) {
		assert(mod % p == 0);
		mod /= p;
		prod *= p;
	}
	prod--;
	return prod;
}

void addRange(vi & v, const int start, const int end, const int delta, const int P) {
	const int N = v.size();
	if(start > end) return;
	if(end == 0) return;
	REP(i,N) {
		const int x = start + i;
		if(x > end)break;

		const int inRange = (end - x) / N + 1;
		v[x % N] += delta * inRange;
	}
	addRange(v, (start + P - 1) / P , end / P, delta, P);

}

int multiplierWithoutPrime(int n, int i, int modulo, int prime) {
	const int P = calcInvPow(modulo, prime);
	int mul = n - i;
	while(mul % prime == 0) {
		mul /= prime;
	}
	int div = i + 1;
	//cout << mul << " / " <<  div << endl;
	while(div % prime == 0) {
		div /= prime;
	}
	//cout << "P=" << P << endl;
	ll invDiv = expMod(div, P, modulo);
	mul = mulMod(mul, invDiv, modulo);
	return mul;
}

int primeNCRMod(int n, int r, int prime) {
	r = min(r, n-r);
	if(r == 0) return 1;
	const int balance = calcBalance(n, r, prime);
	if(balance > 0) {
		return 0;
	}
	vi factorCount(prime);
	addRange(factorCount, 1, r, -1, prime);
	addRange(factorCount, n - r + 1, n, +1, prime);
	//for(int i: factorCount) cout << i << ' ';
	//cout << endl;

	int prod = 1;
	FOR(i,1,prime) {
		int p = factorCount[i];
		if(p == 0) continue;

		int base = i;
		if(p < 0) {
			base = expMod(base, prime - 2, prime);
			p = -p;
		}
		const int part = expMod(base, p, prime);
		//cout << base << " "  << p << " gives " << part << endl;
		prod = mulMod(prod, part, prime);
	}

	return prod;
}
int ncrModNew(int n, int r, int modulo, int prime) {
	//cout << "n="<<n<<" r="<<r<< " mod=" << modulo << endl;
	const int P = calcInvPow(modulo, prime);
	r = min(r, n-r);
	if(r == 0) return 1;
	const int balance = calcBalance(n, r, prime);
	const int factor = expMod(prime, balance, modulo);
	if(factor == 0) {
		return 0;
	}
	vi factorCount(modulo);
	addRange(factorCount, 1, r, -1, prime);
	addRange(factorCount, n - r + 1, n, +1, prime);
	//for(int i: factorCount) cout << i << ' ';
	//cout << endl;

	int prod = factor;
	FOR(i,0,modulo) {
		int p = factorCount[i];
		if(p == 0) continue;
		if(i % prime == 0)continue;

		int base = i;
		if(p < 0) {
			base = expMod(base, P, modulo);

			p = -p;
		}
		//cout << "P=" << P << endl;
		const int part = expMod(base, p, modulo);
		//cout << base << " "  << p << " gives " << part << endl;
		prod = mulMod(prod, part, modulo);
		//cout << "prod = " << prod << endl;
	}

	return prod;

}

int ncrMod(int n, int r, int modulo, int prime) {
	r = min(r, n - r);

	const int balance = calcBalance(n, r, prime);
	//cout << "balance = " << balance << endl;
	const int factor = expMod(prime, balance, modulo);
	if(factor == 0) {
		return 0;
	}
	ll prod = 1;

	for(int i=0;i<r; i++) {
		int mul = multiplierWithoutPrime(n, i, modulo, prime);
		//cout << n <<"," << i << " " << mul << endl;

		prod = mulMod(prod, mul, modulo);
	}
	//cout << "prod was / " << prod << endl;
	//cout << "factor is " << factor << endl;
	prod = mulMod(prod, factor, modulo);

	assert(prod == ncrModNew(n, r, modulo, prime));
	return prod;

}

int crt(int a, int b, int c, int d) {
	//cout << b << " to " << d << endl;
	assert(gcd(b,d) == 1);
	while(a % d != c) {
		a += b;
	}
	return a;
}

int solution(int n, int r) {
	static const vii parts = {pii(27, 3), pii(11,11), pii(13,13), pii(37,37)};
	//142857: 3 3 3 11 13 37
	int sol = 0, mod = 1;
	for(pii part: parts) {
		const int factor = part.first, prime = part.second;
		int partial;
		//cout << "mod " << factor << endl;
		if(factor != prime){
			partial = ncrModNew(n, r, factor, prime);
		} else {
			partial = primeNCRMod(n, r, prime);
		}
		//cout << "done" << endl;

		sol = crt(sol, mod, partial, factor);
		mod *= factor;
		assert(sol < mod);
	}
	return sol;
}
int main() {
	assert(primeNCRMod(10269,886, 11) == 7);
	/*while(true) {
		int a = rand() % 10000, b = rand() % 100;
		a += b;
		cout << a << " b=" << b << endl;
		cout << solution(a, b) << endl;
	}*/
	assert(solution(10269, 886) >= 0);
	assert(solution(5,2) == 10);
	assert(ncrMod(1,1,3,3) == 1);
	assert(ncrMod(2,1,3,3) == 2);
	assert(ncrMod(5,2,3,3) == 1);
	assert(ncrMod(20000,10000,37,37) == 18);
	assert(solution(200000,100000) == 0);
	assert(solution(2,1) == 2);
	assert(solution(9999,0) == 1);
	assert(solution(10,3) == 120);

	int t;
	cin >> t;
	REP(i,t) {
		int n,r;
		cin >> n >> r;
		//cout << n << " " << r << endl;
		cout << solution(n,r) << '\n';

	}

	return 0;
}
