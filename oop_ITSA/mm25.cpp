#include <iostream>  
using namespace std;  
//計算正整數被3整除之數值之總和
//輸入一正整數N，可計算出1到N之間可被3整除的數值之總和
int main() {  
    int num;  
    int sum = 0;  
    while(cin >> num){  
        for(int i = 1;i <= num;i++){  
            if(i % 3 == 0){  
                sum = sum + i;  
            }  
        }  
        cout << sum << endl;  
        sum = 0;  
    }  
    return 0;  
}  