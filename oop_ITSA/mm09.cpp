#include <iostream>  
#include<math.h>  
using namespace std;  
//計算 i 次方的值
int main() {  
    int i, result;
    while(cin >> i){  
        result = pow(2, i);  
        if(i > 31){  
            cout << "Value of more than 31" << endl;  
        }  
        else{  
            cout << result << endl;  
        }  
    }  
    return 0;  
}  