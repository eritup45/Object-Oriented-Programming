#include <iostream>  
using namespace std;  
//用星號“ * ”畫矩形
int main(){
    int m, n;  //橫的是列，m = 每列有m個*，n = 有幾列
    while(cin >> m >> n){  
        if(m == 0 || n == 0){  //m或n有一個是零，那就沒答案
            cout << "no answer" << endl;  
        }  
        else{  
            for(int i = 1;i <= n;i++){   //第一個for迴圈是控制有幾列 => n
                for(int j = 1;j <= m;j++){  //每列有幾個* => m
                    cout << "*" ;  
                }  
                cout << endl;  
            }  
        }  
    }  
    return 0;  
}  