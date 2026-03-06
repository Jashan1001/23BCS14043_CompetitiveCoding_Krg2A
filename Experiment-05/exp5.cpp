#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1e9+9;
const ll base = 31;
const int N = 600005;

ll p[N];

ll getHash(string &s){
    ll h = 0;
    for(int i=0;i<s.size();i++)
        h = (h + (s[i]-'a'+1)*p[i])%mod;
    return h;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    p[0]=1;
    for(int i=1;i<N;i++) p[i]=(p[i-1]*base)%mod;

    unordered_set<ll> st;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st.insert(getHash(s));
    }

    while(m--){
        string s;
        cin>>s;

        ll h = getHash(s);
        bool ok = false;

        for(int i=0;i<s.size() && !ok;i++){
            ll old = s[i]-'a'+1;

            for(char c='a';c<='c';c++){
                if(c==s[i]) continue;

                ll nw = c-'a'+1;

                ll nh = h;
                nh = (nh - old*p[i]%mod + mod)%mod;
                nh = (nh + nw*p[i])%mod;

                if(st.count(nh)){
                    ok = true;
                    break;
                }
            }
        }

        cout<<(ok?"YES\n":"NO\n");
    }
}