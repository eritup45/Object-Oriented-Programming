#include <iostream>
using namespace std;

int main(){
    long long sum = 0;
    int arr[6];
    for (int i = 0; i < 6; i++)
        cin >> arr[i];
    for (int j = 0; j < 6; j++)
        sum += arr[j] * arr[j] * arr[j];
    cout << sum << endl;
    return 0;
}
