#include<bits/stdc++.h>
#include <sys/stat.h>
#include<fstream>

using namespace std;

const double NMAX = 1e6;
const int ntest = 10;
const int N = 1e6;

uniform_real_distribution<double> dist(0.00000001, NMAX);
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
mt19937_64 RND(seed);

vector<double> gen(){
    vector<double> ans(N);
    for(int i = 0; i < N; ++i)
        ans[i] = dist(RND);
    return ans;
}

int main(){
    // cout << fixed << setprecision(10);
    fstream inp;

    for(int i = 0; i < ntest; ++i){   
        
        string file = "data" + to_string(i) + ".txt";
        file = "data/" + file;

        inp.open(file, ios::out | ios::trunc);
            vector<double> num = gen();
            if(i == 0) sort(num.begin(), num.end());
            else if(i == 1) sort(num.rbegin(), num.rend());
            
            for(double x : num)
                inp << x << "\n";
        inp.close();
    }
    
    return 0;
}