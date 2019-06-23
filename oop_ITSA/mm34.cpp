#include <iostream>  
using namespace std;  
//�򔵆��
int main(){
    int num;
    while(cin >> num){  
        for(int i = 1;i<=num;i++){  
            if(num % i == 0){  
                if(i == num){  
                    cout << i << endl;
                }  
                else{  
                    cout << i << " " ;
                }  
            }  
        }  
    }  
    return 0;  
}  