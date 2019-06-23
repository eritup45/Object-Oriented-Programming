#include <iostream>  
using namespace std;  
//輸出 1*1、2*2、...、N*N之結果
int main() {  
    int num;  
    while(cin >> num){  
        for(int i = 1; i <= num;i++){  
            cout << i << "*" << i << "=" << i*i << endl;  
        }  
    }  
    return 0;  
}  