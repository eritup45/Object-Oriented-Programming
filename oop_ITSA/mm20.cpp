#include <iostream>  
#include <math.h>  
using namespace std;  
//十進位轉十六進位 
int main() {  
    int num_10, num_16;  
    while(cin >> num_10){  
        if(num_10 < 16){  
            switch(num_10){   
                case 15:   
                    cout << "F" << endl;  
                    break;  
                case 14:   
                    cout << "E" << endl;   
                    break;   
                case 13:   
                    cout << "D" << endl;   
                    break;   
                case 12:   
                    cout << "C" << endl;   
                    break;   
                case 11:   
                    cout << "B" << endl;   
                    break;  
                  case 10:   
                    cout << "A" << endl;  
                    break;  
                case 9:   
                    cout << "9" << endl;   
                    break;   
                case 8:   
                    cout << "8" << endl;   
                    break;   
                case 7:   
                    cout << "7" << endl;   
                    break;   
                case 6:   
                    cout << "6" << endl;   
                    break;  
                  case 5:   
                    cout << "5" << endl;   
                    break;   
                case 4:   
                    cout << "4" << endl;   
                    break;   
                case 3:   
                    cout << "3" << endl;   
                    break;   
                case 2:   
                    cout << "2" << endl;   
                    break;  
                  case 1:   
                    cout << "1" << endl;   
                    break;  
                default:   
                     cout << "0" << endl;   
            }   
        }  
        else if(num_10 >= 16 && num_10 < 256){  
            switch((int)floor(num_10/16)){   
                case 15:   
                    cout << "F";  
                    break;  
                case 14:   
                    cout << "E";   
                    break;   
                case 13:   
                    cout << "D";   
                    break;   
                case 12:   
                    cout << "C";   
                    break;   
                case 11:   
                    cout << "B";   
                    break;  
                  case 10:   
                    cout << "A";  
                    break;  
                case 9:   
                    cout << "9";   
                    break;   
                case 8:   
                    cout << "8";   
                    break;   
                case 7:   
                    cout << "7";   
                    break;   
                case 6:   
                    cout << "6";   
                    break;  
                  case 5:   
                    cout << "5";   
                    break;   
                case 4:   
                    cout << "4";   
                    break;   
                case 3:   
                    cout << "3";   
                    break;   
                case 2:   
                    cout << "2";   
                    break;  
                  case 1:   
                    cout << "1";   
                    break;  
                default:   
                     cout << "0";   
            }  
              
            switch(num_10%16){   
                case 15:   
                    cout << "F" << endl;  
                    break;  
                case 14:   
                    cout << "E" << endl;   
                    break;   
                case 13:   
                    cout << "D" << endl;   
                    break;   
                case 12:   
                    cout << "C" << endl;   
                    break;   
                case 11:   
                    cout << "B" << endl;   
                    break;  
                  case 10:   
                    cout << "A" << endl;  
                    break;  
                case 9:   
                    cout << "9" << endl;   
                    break;   
                case 8:   
                    cout << "8" << endl;   
                    break;   
                case 7:   
                    cout << "7" << endl;   
                    break;   
                case 6:   
                    cout << "6" << endl;   
                    break;  
                  case 5:   
                    cout << "5" << endl;   
                    break;   
                case 4:   
                    cout << "4" << endl;   
                    break;   
                case 3:   
                    cout << "3" << endl;   
                    break;   
                case 2:   
                    cout << "2" << endl;   
                    break;  
                  case 1:   
                    cout << "1" << endl;   
                    break;  
                default:   
                     cout << "0" << endl;   
            }  
        }  
    }  
    return 0;  
} 