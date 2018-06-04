/******************************************************************************
Copyright 2015, Intel Corporation All Rights Reserved.

The source code, information and material("Material") contained herein is owned
by Intel Corporation or its suppliers or licensors, and title to such Material
remains with Intel Corporation or its suppliers or licensors. The Material
contains proprietary information of Intel or its suppliers and licensors.The
Material is protected by worldwide copyright laws and treaty provisions. No
part of the Material may be used, copied, reproduced, modified, published,
uploaded, posted, transmitted, distributed or disclosed in any way without
Intel's prior express written permission. No license under any patent,
copyright or other intellectual property rights in the Material is granted to
or conferred upon you, either expressly, by implication, inducement, estoppel
or otherwise. Any license under such intellectual property rights must be
express and approved by Intel in writing.

Unless otherwise agreed by Intel in writing, you may not remove or alter this
notice or any other notice embedded in Materials by Intel or Intel's suppliers
or licensors in any way.
******************************************************************************/

//
// http://en.wikipedia.org/wiki/Algorithms_for_calculating_variance
// This code implments a method for determining Std Dev from streaming data.
// Based on Donald Knuth's Art of Computer Programming vol 2, 3rd edition, 
// page 232
//
// The basic algorithm follows (to show what the variable names represent)
// X is the current data item
// Mc is the running Mean (Mean current), Mc-1 is the mean for the previous 
// item, Sc is the running Sum of Squares of Differences (Sum current), 
// Sc-1 is the sum for the previous item, c is the count or current item.
// Init M1 = X1 and S1 = 0 during the first pass and on reset
// Data is added to the cumulating values using this formula
// Mc = Mc-1 + (Xc - (Mc-1))/c
// Sc = Sc-1 + (Xc - (Mc-1))*(Xc - Mc)
// for 2<= c <= n the cth estimate of variance is s*2 = Sc/(c-1)
//

#include "math.h"
#include "streaming_stats.hh"

#include <iostream>

using namespace std;

StreamingStats::StreamingStats(unsigned int windowSize) : ss_Mean(0), ss_PrevMean(0), ss_Sum(0), ss_Data(NULL)
{
	if (windowSize > 0)
		ss_Size = windowSize;
	ss_Data = new double[ss_Size];
	 
	return;
}

// This is the only public routine, it returns the count of the # of items used
// to determine the current values in the object.
//
int StreamingStats::DataCount()
{
	return count;			// return the number of accumulated data items
}

int StreamingStats::DataReset()
{
//	ss_PrevMean = ss_Mean = 0.0;	// clear all data
//	ss_PrevSum = 0.0;
	count = 0;
	index = 0;
	return 0;				// start empty, no elements 
}

// this routine adds new data to the streaming stats totals
// returns the # of items added to the data set
int StreamingStats::NewData(double x)
{
	ss_PrevMean = ss_Mean;
	if (count >= ss_Size) { // We're rolling the window
		// The oldest data point is the next point in a circular array
		index++;
		if (index >= ss_Size)
			index = 0;
    double oldest = ss_Data[index];

    ss_Mean = ss_PrevMean + (x - oldest) / ss_Size;
    
		ss_Sum = ss_Sum - (oldest - ss_PrevMean) * (oldest - ss_Mean) + (x - ss_PrevMean) * (x - ss_Mean);
	}
	else { // We're still filling the window
		count++;
		
		if (count == 1) // initialize with the first data item only
		{
			ss_PrevMean = ss_Mean = x;
			ss_Sum = 0.0;
		}
		else // we are adding a data item, follow the formula
		{
			ss_Mean = ss_PrevMean + (x - ss_PrevMean) / count;
			ss_Sum = ss_Sum + (x - ss_PrevMean)*(x - ss_Mean);
		}
		index = count - 1;
	}

	// Store new data point - overwriting oldest in circular array
	ss_Data[index] = x;

	return count;
}

// if the count is positive, return the new mean
double StreamingStats::Mean()
{
	return (count > 0) ? ss_Mean : 0.0;
}

// if the count is 2 or more, return a variance, otherwise zero
double StreamingStats::Variance()
{
	return ((count > 1) ? ss_Sum / (count - 1) : 0.0);
}

// calc the StdDev based using sqrt of the variance (standard method)
double StreamingStats::StandardDeviation()
{
	return sqrt(Variance());
}

int main(int argc, char** argv) {
  StreamingStats s(5);
  double x = 0;
  while (cin >> x) {
    s.NewData(x);
    cout << "mean=" << s.Mean() << ", stddev=" << s.StandardDeviation() << endl;
  }
  return 0;
}