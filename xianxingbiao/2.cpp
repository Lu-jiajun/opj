//
// Created by lu on 23-5-3.
//
#include <iostream>
#include <map>
using namespace std;

int n = 0;
map<int, int> coeffient;
int main() {
    cin >> n;
    while(n--){
        coeffient.clear();
        for(int i = 0; i < 2; ++i){
            while(1){
                int tmp1 = 0, tmp2 = 0;
                cin >> tmp1 >> tmp2;
                if(tmp2 < 0)
                    break;
                coeffient[tmp2] += tmp1;
            }
        }
        map<int, int>::iterator i = coeffient.end();
        for(; i != coeffient.begin(); --i){
            if(i -> second != 0)
                cout << "[ " << i->second << " " << i->first << " ] ";
        }
        if(i -> second != 0)
            cout << "[ " << i->second << " " << i->first << " ]";
        cout << endl;
    }
    return 0;
}