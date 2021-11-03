#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    vector<int> vec;
    string str;
    int beforeBit;
    //0 positive 전압 , 1 negative 전압이라고 가정.

    cout<<"enter bitPattern : ";
    getline(cin,str); //bitpattern 한줄로 입력받아 vec에 저장.
      for(int i=0; i<str.size(); i++){
        int temp = str[i]-'0';
        vec.push_back(temp);
    }
    cout<<"enter before bit : ";
    cin>>beforeBit; // beforeBit을 따로 입력받음 different manchester에서 beforebit에 따라 값이변하기때문.
    cout<<"\n==========================================";
    cout<<"\nManchester encoding"<<'\n';
    
    for(int i=0; i<vec.size(); i++){
        if(vec[i] == 0){
            cout<<"01 "; // manchester은 beforebit와 상관없이 인코딩값이 일정하다. 0일때 high to low, 1일때 low to high
        }
        else if(vec[i]==1){
            cout<<"10 ";
        }else{
            cout<<"error"<<'\n';
            return -1;
        }
    }
    cout<<"\n==========================================\n";

    cout<<"Differential Manchester Encoding\n";

    for(int i=0; i<vec.size(); i++){ 
        if(beforeBit == 0){
            if(vec[i]== 0){
                cout<<"10 "; 
                beforeBit = 0; // beforeBit에 의해, 인코딩 값이 변함으로, 연속적인 인코딩을 위해, Beforebit를 저장해준다.
            }
            else if(vec[i] == 1){
                cout<<"01 ";
                beforeBit =1;
            }
            else{
                cout<<"error";
                return -1;
            }
        }
        else if(beforeBit == 1){
            if(vec[i]==0){
                cout<<"01 ";
                beforeBit=1;
            }
            else if (vec[i] == 1){
                cout<<"10 ";
                beforeBit =0;
            }
            else{
                cout<<"error";
                return -1;
            }
        }
        else{
            cout<<"error"<<'\n'; 
            return -1;
        }
    }
    cout<<"\n==========================================\n";

    return 0;
}