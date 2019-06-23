#include <iostream>  
using namespace std;  
  
int main() {  
    int num;   //ÅÐ”àÆæ”µÅ¼”µ
    while(cin >> num){  
        if(num % 2 == 0){  
            cout << "even" << endl;  
        }  
        else{  
            cout << "odd" << endl;  
        }  
    }  
    return 0;  
}  