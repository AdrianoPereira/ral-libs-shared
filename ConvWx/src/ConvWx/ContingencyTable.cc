// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// � University Corporation for Atmospheric Research (UCAR) 2009-2010. 
// All rights reserved.  The Government's right to use this data and/or 
// software (the "Work") is restricted, per the terms of Cooperative 
// Agreement (ATM (AGS)-0753581 10/1/08) between UCAR and the National 
// Science Foundation, to a "nonexclusive, nontransferable, irrevocable, 
// royalty-free license to exercise or have exercised for or on behalf of 
// the U.S. throughout the world all the exclusive rights provided by 
// copyrights.  Such license, however, does not include the right to sell 
// copies or phonorecords of the copyrighted works to the public."   The 
// Work is provided "AS IS" and without warranty of any kind.  UCAR 
// EXPRESSLY DISCLAIMS ALL OTHER WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
// ANY IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
// PURPOSE.  
//  
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
#include <toolsa/copyright.h>
/**
 * @file ContingencyTable.cc
 */

#include <cstring>
#include <ConvWx/ContingencyTable.hh>

using std::string;

//----------------------------------------------------------------
string ContingencyTable::descriptor(const ContingencyTable::Type_t type)
{
  string ret;
  switch (type)
  {
  case ContingencyTable::MISSING_VALUE:
    ret = "MISSING_VALUE";
    break;
  case ContingencyTable::NONE:
    ret = "NONE";
    break;
  case ContingencyTable::FALSEP:
    ret = "FALSEP";
    break;
  case ContingencyTable::MISS:
    ret = "MISS";
    break;
  case ContingencyTable::HIT:
    ret = "HIT";
    break;
  case ContingencyTable::UNKNOWN:
    ret = "UNKNOWN";
    break;
  default:
    ret = "UNKNOWN";
    break;
  }
  return ret;
}

