#include <iostream>
using namespace std;
void showMess(int n){
    if (n>0){
        cout << "line " << endl;
        showMess(n-1);
    }
}

int main(){
    showMess(5);
//     int *numbers = new int[5];
//     for (int i=0;i<=4;i++)
//         *(numbers + i) = i;
//         cout << numbers[2] << endl;
//
//         int number = 22;
// int *var = &number;
// cout << number << "22" << endl;
//
// enum Tree {OAK,MAPLE,PINE};
// cout << (OAK < PINE) << " 22 " << endl;


}
