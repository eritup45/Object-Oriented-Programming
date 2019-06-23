#include <iostream>  
#include <cmath>  
#include <string.h>  
using namespace std;  
//迴文字串
int main(){
    int n,count;//n是測資數  
    char change;//互換的暫存值  
    cin >> n;  
    string input;  
    for(int j = 0;j < n;j++){  
        cin >> input;  
        count = input.size();//string 長度  
        char result[count]; //存入回文結果  
        strcpy(result, input.c_str());//string to char  
        for(int i = 0;i<floor(count/2);i++){//製造回文
            change = result[i];  
            result[i] = result[count-1-i];  
            result[count-1-i] = change;  
        }  
        for(int i = 0;i<count;i++){//輸出 
            if(i == count-1){  
                cout << result[i] << endl;  
            }  
            else{  
                cout << result[i];  
            }  
        }  
    }  
    return 0;  
}  