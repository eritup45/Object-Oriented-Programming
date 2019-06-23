#include <iostream>
using namespace std;
//¥­¡B¶|¦~§P©w
int main() {
    int year;
    while(cin >> year){
        if(year%4==0){
            if(year % 100 != 0 || year % 400 == 0){
                cout << "Bissextile Year" << endl;
            }
            else{
                cout << "Common Year" << endl;
            }
        }
        else{
            cout << "Common Year" << endl;
        }
    }
    return 0;
}
