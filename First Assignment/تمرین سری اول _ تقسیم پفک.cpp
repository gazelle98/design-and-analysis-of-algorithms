#include <iostream>
#include <string>

using namespace std;

int main(){
    long long m, s;
    cin >> s >> m;
    string no = "impossible";
    long long q, b, count;
    count = 0;
    while(m>1 && s>1){
        if(s>m){
            q = s / m;
            b = s % m;
            if(b==0){
                cout << no;
                return 0;
            }
            s = b;
            count += q;
        }
        else if(s<m){
            q = m / s;
            b = m % s;
            if(b==0){
                cout << no;
                return 0;
            }
            m = b;
            count += q;
        }
        else{
            cout << no;
            return 0;
        }
    }
    if(m==1){
        cout << count + s - 1;
    }
    else if(s==1){
        cout << count + m - 1;
    }
}