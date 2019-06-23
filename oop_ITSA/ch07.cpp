#include <iostream>  
#include<iomanip>  
using namespace std;  
  
int main() {  
    //標準體重計算  
    //男生1＝(身高－80 )*0.7  
    //女生2＝(身高－70)*0.6  
    int h,gender;  
    double w;  
    while(cin >> h >> gender){  
        switch(gender){  
            case 1:  
                w = (h - 80)*0.7;  
                cout << fixed << setprecision(1) << w << endl;  
                break;  
            case 2:  
                w = (h - 70)*0.6;  
                cout << fixed << setprecision(1) << w << endl;  
                break;  
        }  
    }  
    return 0;  
}  