#include <iostream>  
using namespace std;  
//1~N之間的總和  
int main() {  
    int N, sum;  //1~N，總和
    while(cin >> N){  
        for(int i = 1;i <= N;i++){  //計算總和  
            sum = sum + i;  
        }  
        for(int j = 1;j <= N;j++){  //輸出格式要求
            if(j == 1){  
                cout << "1";  
            }  
            else{  
                cout << " + " << j;  
            }  
        }  
        cout << " = " << sum << endl;  
        sum=0;  
    }  
    return 0;  
}  