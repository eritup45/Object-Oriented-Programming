#include <iostream>  
#include <cmath>  
using namespace std;  
//Armstrong數
//一個三位數的整數，其各位數字之立方和等於該數本身
int main() {  
    int num;
    double Armstrong, a, b, c;  
    while(cin >> num){  
        a = floor(num / 100);  
        b = num / 10 % 10;     
        c = num % 10;          
        Armstrong = pow(a,3)+pow(b,3)+pow(c,3); 
        if(num == Armstrong){  
            cout << "Yes" << endl;  
        }  
        else{  
            cout << "No" << endl;  
        }  
    }  
    return 0;  
}  