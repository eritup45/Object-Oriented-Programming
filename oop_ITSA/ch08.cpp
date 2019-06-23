#include <iostream>  
using namespace std;  
  
int main() {  
    //計算MVP數值
    int score , rebounds, assists, screenshots, errors;  
    //輸入籃球員的平均得分，籃板，助攻及抄截、失誤
    int mvp;  
    while(cin >> score >> rebounds >> assists >> screenshots >> errors){  //(得分*1＋助攻*2＋籃板*2＋抄截*2)－(失誤*2)
        mvp = (score*1 + assists*2 + rebounds*2 + screenshots*2) - (errors*2);  
        if(mvp>=45){  
            cout << "A" << endl;  
        }  
        else if(35 <= mvp && mvp <= 44){  
            cout << "B" << endl;  
        }  
        else if(25 <= mvp && mvp <= 34){  
            cout << "C" << endl;  
        }  
        else if(mvp < 25){  
            cout << "D" << endl;  
        }  
    }  
    return 0;  
}  