#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    
    int cr,lr,nr;
    nr=0;
    cr=0;

    vector<int> stn(stops.size()+2,0);
    stn[0]=0;
    for(int i=1;i<=stops.size();i++)
        stn[i] = stops[i-1];

    stn[stn.size()-1]=dist;

    int n=stops.size();

    while(cr<=n)
    {
        lr=cr;
        while(cr<=n && stn[cr+1]-stn[lr]<=tank)
            cr++;
        if(cr==lr)
            return -1;
        if(cr<=n)
            nr++;
    }
    return nr;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
