#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 999999999

struct pie {
    int va, vb, ind, own;
    pie() {}
    pie(int va, int vb, int ind, int own) {
        this->va=va; this->vb=vb; this->ind=ind; this->own=own;
    }
};
bool comp(pie i, pie j) {return i.vb<j.vb;}

int n, d, dist[100000][2];
pie b[100000], e[100000];

int b_search(int val, pie arr[]) {
    int lo=0, hi=n-1;
    while(lo<hi) {
        int mid=(lo+hi)/2+1;
        if(arr[mid].vb>val) hi=mid-1;
        else lo=mid;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    if(fopen("piepie.in", "r")) {
        freopen("piepie.in", "r", stdin);
        freopen("piepie.out", "w", stdout);
    }
    cin>>n>>d;
    queue<pie> q;
    for(int i=0; i<n; i++) {
        dist[i][0]=INF;
        cin>>b[i].va>>b[i].vb;
        b[i].ind=i;
        b[i].own=0;
        if(b[i].vb==0) {
            q.push(b[i]);
            dist[i][0]=1;
        }
    }
    for(int i=0; i<n; i++) {
        dist[i][1]=INF;
        cin>>e[i].vb>>e[i].va;
        e[i].ind=i;
        e[i].own=1;
        if(e[i].vb==0) {
            q.push(e[i]);
            dist[i][1]=1;
        }
    }
    sort(b, b+n, comp);
    sort(e, e+n, comp);
    while(!q.empty()) {
        pie curr=q.front();
        q.pop();
        int start=b_search(curr.va, curr.own==0 ? e:b);
        //cout<<curr.va<<" "<<curr.vb<<" "<<curr.ind<<" "<<curr.own<<" "<<start<<endl;
        for(int i=start; i>=0; i--) {
            pie loc=curr.own==0 ? e[i]:b[i];
            if(loc.vb<curr.va-d) break;
            if(dist[loc.ind][loc.own]==INF) {
                q.push(loc);
                dist[loc.ind][loc.own]=dist[curr.ind][curr.own]+1;
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout<<(dist[i][0]==INF ? -1:dist[i][0])<<"\n";
    }
}

