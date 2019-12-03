/**
 * @file DistStats.cc
 * @brief Source for DistStats class
 */


#include <cstdio>
#include <ConvWx/DistStats.hh>
#include <ConvWx/ConvWxTime.hh>
using std::vector;
   
DistStats::DistStats(const time_t genTime, const int leadSecs, 
		     const int subgridNum, const vector <int> obsHistTotals, 
		     const vector <int> fcstHistTotals,const int nObsHists,
		     const int nFcstHists)
  : pGenTime(genTime),
    pLeadSecs(leadSecs),
    pSubgridNum(subgridNum),
    pObsHistTotals(obsHistTotals),
    pFcstHistTotals(fcstHistTotals),
    pNObsHists(nObsHists),
    pNFcstHists(nFcstHists)
{
  //
  // Set time variables of data record
  //
  ConvWxTime::expandTime(genTime, pYear, pMonth, pDay, pGenHour, pGenMin, 
			 pGenSecs);
}

DistStats::DistStats(const time_t genTime, const int leadSecs, 
		     const int subgridNum, const vector <float> obsHistStats, 
		     const vector <float> fcstHistStats,const int nObsHists,
		     const int nFcstHists)
  : pGenTime(genTime),
    pLeadSecs(leadSecs),
    pSubgridNum(subgridNum),
    pObsHistStats(obsHistStats),
    pFcstHistStats(fcstHistStats),
    pNObsHists(nObsHists),
    pNFcstHists(nFcstHists)
{
  //
  // Set time variables of data record
  //
  ConvWxTime::expandTime(genTime, pYear, pMonth, pDay, pGenHour, pGenMin, 
			 pGenSecs);
}

DistStats::~DistStats()
{
  //
  // Clear containers of observation and forecast histogram data
  //
  pObsHistTotals.clear();

  pFcstHistTotals.clear();

  pObsHistStats.clear();

  pFcstHistStats.clear();
}
   
