#include <iostream>

using namespace std;

int tday[21];
int pday[21];
int ans= -1000;
int n;

void go(int sum, int day){
    if(day ==n+1){
        if(ans < sum) ans= sum;
        return ;
    }
    if(day>n+1) return;


    go(sum+pday[day],day+tday[day]);
    go(sum,day+1);
    
}

int main(){
    // cin>>n;
    for(int i=1; i<=n; i++){
        cin>>tday[i]>>pday[i];
    }
    go(0,1);
    cout<<ans;
    return 0;
}