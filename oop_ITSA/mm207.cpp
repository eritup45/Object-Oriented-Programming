#include <iostream>  
using namespace std;  
//�D�Ʀr�M
//�N�Ʀr 0~51 ��ܬ���J�P�� 52 �i�P�A�䤤 0~12 ��ܬ��®�] Spade �^�� 1 �� 13 �B 
//13~25 ��ܬ����ߡ] Heart �^�� 1 �� 13 �B 
//26~38 ��ܬ�����] Diamond �^�� 1 �� 13 �B 
//39~51 ��ܬ�����] Club �^�� 1 �� 13 �C
//�q�ɮ�Ū�J���� 0~51 ���Ʀr�A�D�X�o���ӼƦr�ҥN����J�P�I�ƩM�C
int main(){  
    int num, sum = 0;  
    for(int i = 0;i < 5;i++){  
        cin >> num;  
        sum = sum + ((num+1)%13);  
    }  
    cout << sum << endl;  
    return 0;  
}  