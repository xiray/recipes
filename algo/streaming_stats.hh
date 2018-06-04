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
// This code implements a method for determining Std Dev from streaming data.
// Based on Donald Knuth's Art of Computer Programming vol 2, 3rd edition, 
// page 232
//
// The basic algorithm follows (to show what the variable names represent)
// X is the current data item
// Mc is the running Mean (Mean current), Mc-1 is the mean for the previous 
// item, Sc is the running Sum (Sum current), Sc-1 is the sum for the previous 
// item, c is the count or current item
// init M1 = X1 and S1 = 0 during the first pass and on reset
// Data is added to the cumulating values using this formula
// Mc = Mc-1 + (Xc - (Mc-1))/c
// Sc = Sc-1 + (Xc - (Mc-1))*(Xc - Mc)
// for 2<= c <= n the cth estimate of variance is s*2 = Sc/(c-1)
//


#include "math.h"

class StreamingStats {

private:
	unsigned int count = 0;
	unsigned int index = 0;
	double ss_Mean, ss_PrevMean, ss_Sum;
	double* ss_Data;
	unsigned int ss_Size = 1;
	// Internal functions defined here

	StreamingStats(const StreamingStats&);

public:
	explicit StreamingStats(unsigned int windowSize);     // Constructor, defines window size
	~StreamingStats(void) { delete [] ss_Data; };	// destructor for data
	int		DataCount();			// return # items are in this data set
	int		DataReset();			// reset the data to empty state
	int		NewData(double x);		// add a data item
	double	Mean();				// return Mean of the current data
	double	Variance();				// return Variance of the current data
	double	StandardDeviation();		// return Std Deviation of the current data

};
