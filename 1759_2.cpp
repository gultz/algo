#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check(string password){
    int ja =0;
    int mo =0;

    for(char a : password){
        if(a =='a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
            mo+=1;
        }else{
            ja+=1;
        }
    }
    return mo>=1 && ja>=2;
}

void go(int n, vector<char> &alpha, string password, int i){
    if(password.length()==n){
        if(check(password)){
            cout<<password<<'\n';
        }
        return ;
    }
    if(i==alpha.size()) return;
    go(n,alpha,password+alpha[i],i+1);
    go(n,alpha,password,i+1);

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<char> a(m);
    for(int i=0; i<m; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    go(n,a,"",0);
    return 0;
}