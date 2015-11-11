#include <iostream>
#include <fstream>
#include <String>
#include "wavReader.cpp"

using namespace std;

int * FFT(int A[], int m, int omegaN) {

}

// int FFT(int A[], int m, int omegaN) {
//     int Aeven[m/2] ;
//     int Aodd[m/2] ;
//     int Feven[m/2] ;
//     int Fodd[m/2]
//     int j = 0 ;
//     for (int i = 0 ; i < m ; i = i + 2) {
//         Aeven[j] = A[i] ;
//         j++ ;
//     }
//     j = 0 ;
//     for (int k = 1 ; k < m ; k = k + 2) {
//         Aodd[j] = A[k] ;
//         j++ ;
//     }
//     if (m == 1) reutrn A[0] ;
//     else {
//         Feven = FFT(Aeven, m/2, omegaN^2) ;
//         Fodd = FFT(Aodd, m/2, omegaN^2) ;
//         int F[m] ;
//         omega = 1 ;
//         for (int p = 0 ; p < m/2 ; ++p) {
//             F[p] = Feven[p] + omega*Fodd[p] ;
//             F[p+(m/2)] = Feven[p] - omega*Fodd[p] ;
//             omega = omega * omegaN ;
//         }
//     }
//     return F ;
// }