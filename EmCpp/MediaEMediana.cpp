//https://neps.academy/br/exercise/1656

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//por matemática
int main() {
    int A, B;
    cin >> A >> B;
    
    int C, C1, C2, C3 = 0;

    //supondo que z > y > x 
    //(x + y + z)/3 = y
    //3y = x + y + z
    //z = 2y - x
    //x = 2y - z
    //y = (x + z)/2

    //As posições possiveis pra C, sabendo que B > A são:
    // C > B > A; nesse caso C é z
    // B > C > A; nesse caso C é y
    // B > A > C; nesse caso C é x

    C1 = (2*B) - A;
    C2 = (B + A)/2;
    C3 = (2*A) - B;
    
    cout << min({C1,C2,C3}) << endl;
    
    return 0;
}




//Ou por computação
// int main () {

//     int A, B;

//     cin >> A >> B;

//     int C = 0;
//     int D = 0;

//     while (true){
//         vector<int> listap = {A,B,C};
//         vector<int> listan = {A,B,D};
//         float mediap = (A+B+C)/3.0;
//         float median = (A+B+D)/3.0;
//         sort(listap.begin(), listap.end());
//         sort(listan.begin(), listan.end());

//         if(mediap == listap[1]){
//             cout << C << endl;
//             break;
//         }
//         if(median == listan[1]){
//             cout << D << endl;
//             break;
//         }
//         C += 1;
//         D -= 1;

//     }


//     return 0;
// }