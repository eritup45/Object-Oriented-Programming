#include <iostream>  
#include<iomanip>  
using namespace std;  
//英哩轉公里
int main(){  
    int mi;  
    double km;  
    cin >> mi;  
    km = mi * 1.6;  
    cout << fixed << setprecision(1) << (double)km << endl;  
    return 0;  
}  