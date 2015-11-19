/*
 * FFT.h
 *
 *  Created on: Nov 19, 2015
 *      Author: root
 */

#ifndef FFT_H_
#define FFT_H_

#include <cmath>
#include <complex>
#include <vector>

using namespace std;
typedef complex<double> dcomp;

vector<dcomp> fft(vector<dcomp> &A, int m, dcomp omegaN);

#endif /* FFT_H_ */
