#include <iostream>  
#include <iomanip>  
#include <cmath>  
using namespace std;  
//計算正方形面積
int main() {  
    double square;  
    while(cin >> square){  
        square = square * square;  
        square = square * 10 + 0.5;  
        square = floor(square);  
        square = square  / 10;  
        cout << fixed << setprecision(1) << square << endl;  
    }  
    return 0;  
}  