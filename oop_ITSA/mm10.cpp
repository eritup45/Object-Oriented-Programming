#include <iostream>  
#include<iomanip>  
using namespace std;  
//攝氏溫度轉華式溫度
int main() {  
    double C, F;  
    while(cin >> C){  
        F = (9*C)/5+32;  
        cout << fixed << setprecision(1) << F << endl;  
    }  
    return 0;  
}  