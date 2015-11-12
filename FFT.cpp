#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
typedef complex<double> dcomp; 

dcomp * fft(dcomp A[], int m, dcomp omegaN) {
	static dcomp * F;
    F = (dcomp *)malloc(m * sizeof(dcomp));

	static dcomp * Aeven;
    Aeven = (dcomp *)malloc((m/2) * sizeof(dcomp));

	static dcomp * Aodd;
    Aodd = (dcomp *)malloc((m/2) * sizeof(dcomp));

	static dcomp * Feven;
    Feven = (dcomp *)malloc(m * sizeof(dcomp));
	
	static dcomp * Fodd;
    Fodd = (dcomp *)malloc(m * sizeof(dcomp));

	int j = 0;
	// cout << endl << "Aeven: " << endl;
	for (int i = 0 ; i < m ; i = i + 2) {
        Aeven[j] = A[i];
		// cout << Aeven[j] << " ";
        j++ ;
    }
    j = 0 ;
    // cout << endl << "Aodd: " << endl;
    for (int k = 1 ; k < m ; k = k + 2) {
        Aodd[j] = A[k];
        // cout << Aodd[j] << " ";
        j++ ;
    }
    if (m==1) {
    	return &A[0];
    }
    else {
        Feven = fft(Aeven, m/2, pow(omegaN,2));
        Fodd = fft(Aodd, m/2, pow(omegaN,2));

        dcomp omega = 1 ;
        for (int p = 0 ; p < m/2 ; ++p) {
            F[p] = Feven[p] + omega*Fodd[p] ;
            F[p+(m/2)] = Feven[p] - omega*Fodd[p] ;
            omega = omega * omegaN;
        }
        return F;
    }
    
}