#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    char s1[10010],s2[10010];
    cin>>s1>>s2;
    int a[26]={0};
    for(int i=0;i<strlen(s1);i++)
        a[s1[i]-'a']++;
    for(int i=0;i<strlen(s2);i++)
        a[s2[i]-'a']--;
    long long int ans = 0;
    for(int i=0;i<26;i++)
        ans += abs(a[i]);
    cout<<ans<<endl;
    return 0;
}
