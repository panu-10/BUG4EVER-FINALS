#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        if(s.size()==1) cout<<'0'<<endl;
        if(s.size()==2) cout<<'16'<<endl;
        
        int num=(s[n-1]-'0')*100+(s[n-2]-'0')*10+(s[n-3]-'0');
        if(num%8==0){
            cout<<s<<endl;
            continue;
        }
         num=(s[n-1]-'0')*100+(s[n-2]-'0')*10;
         for(int i=1;i<=9;i++){
            num+=i;
            if(num%8==0){
                s[n-1]=i;
                cout<<s<<endl;
            }
         }
    }
    return 0;
}