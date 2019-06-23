#include<iostream>  
#include<iomanip>  
#include <math.h>  
using namespace std;  
//計算時間的組合   
int main() {  
    int T, days, hrs, mins, secs;  
    while(cin >> T){  //秒數的整數值
        days = floor(T / 86400);  
        hrs = floor((T % 86400)/3600);  
        mins = floor((T % 86400 % 3600)/60);  
        secs = T % 86400 % 3600 % 60;  
   
        cout << days << " days" << endl;  
        cout << hrs << " hours" << endl;  
        cout << mins << " minutes" << endl;  
        cout << secs << " seconds" << endl;  
    }  
    return 0;  
}  