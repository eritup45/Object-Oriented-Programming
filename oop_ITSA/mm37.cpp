#include <iostream>  
using namespace std;  
//判斷座標位於何處
int main(){
    int x, y;  
    while(cin >> x >> y){  
        if(x == 0 && y == 0){ //原點
            cout << "Origin" << endl;  
        }  
        else if(x != 0 && y == 0){ //x軸 
            cout << "x-axis" << endl;  
        }  
        else if(x == 0 && y != 0){ //y軸 
            cout << "y-axis" << endl;  
        }  
        else{ //判斷象限 
            if(x > 0 && y > 0){//第一象限  
                cout << "1st Quadrant" << endl;  
            }  
            else if(x < 0 && y > 0){//第二象限
                cout << "2nd Quadrant" << endl;  
            }  
            else if(x < 0&& y < 0){ 
                cout << "3rd Quadrant" << endl;  
            }  
            else{  
                cout << "4th Quadrant" << endl;  
            }  
        }  
    }  
    return 0;  
}  