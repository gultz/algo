#include <iostream>
#include <string>
using namespace std;

void 
go(int a[]){
    a[0] = 10;
}
int main(){

    int a[10] = {1,2,3,4};
    go(a);
    cout<<a[0]<<'\n';

}