#include <iostream>  
using namespace std;  
//比較數字大小  
   
int main() {  
    int a, b, c;  
    while(cin >> a >> b >> c){  
        if(a > b){  
            if(b > c){ //a > b > c  
                cout << a << ">" << b << ">" << c << endl;  
            }  
            else{  
                if(a > c){ //a > c > b  
                    cout << a << ">" << c << ">" << b << endl;  
                }  
                else{ //c > a > b  
                    cout << c << ">" << a << ">" << b << endl;  
                }  
            }  
        }  
        else{ //b > a  
            if(a > c){ //b > a > c    
                cout << b << ">" << a << ">" << c << endl;  
            }  
            else{ //b, c > a  
                if(b > c){ //b > c > a  
                    cout << b << ">" << c << ">" << a << endl;      
                }  
                else{ //c > b > a  
                    cout << c << ">" << b << ">" << a << endl;  
                }  
            }  
        }  
    }  
    return 0;  
}  