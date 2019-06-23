#include <iostream>  
using namespace std;  
//判斷座標是否在正方形的範圍內 100*100
int main() {  
    int x, y;  
    while(cin >> x >> y){  
        if(0 <= x && x <=100 && 0 <= y && y <=100){  
            cout << "inside" << endl;  
        }  
        else{  
            cout << "outside" << endl;  
        }  
    }  
    return 0;  
}  