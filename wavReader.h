/*
 * wavReader.h
 *
 *  Created on: Nov 19, 2015
 *      Author: root
 */

#ifndef WAVREADER_H_
#define WAVREADER_H_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<short> wavReader(const char* fileName, int & sampleRate);

#endif /* WAVREADER_H_ */
