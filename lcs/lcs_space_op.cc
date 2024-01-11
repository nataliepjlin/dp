#include <iostream>
using namespace std;
#define LEN 1001
int main(){
    int a[LEN] = {0}, b[LEN] = {0};
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.length(), l2 = s2.length();
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s1[i - 1] == s2[j - 1])
                b[j] = a[j - 1] + 1;
            else b[j] = max(b[j - 1], a[j]);
        }

        for(int j = 1; j <= l2; j++){
            a[j] = b[j];
            cout << a[j] << " ";
        }
        cout << endl;

    }
}