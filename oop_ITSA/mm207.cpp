#include <iostream>  
using namespace std;  
//求數字和
//將數字 0~51 表示為樸克牌的 52 張牌，其中 0~12 表示為黑桃（ Spade ）的 1 至 13 、 
//13~25 表示為紅心（ Heart ）的 1 至 13 、 
//26~38 表示為方塊（ Diamond ）的 1 至 13 、 
//39~51 表示為梅花（ Club ）的 1 至 13 。
//從檔案讀入五筆 0~51 的數字，求出這五個數字所代表的樸克牌點數和。
int main(){  
    int num, sum = 0;  
    for(int i = 0;i < 5;i++){  
        cin >> num;  
        sum = sum + ((num+1)%13);  
    }  
    cout << sum << endl;  
    return 0;  
}  