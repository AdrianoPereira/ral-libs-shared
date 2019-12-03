/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR (c) 1990 - 2016                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/*************************************************************************
 * trig.c - math utilities library
 *
 * Mike Dixon RAP NCAR Boulder CO USA
 *
 * Nov 2008
 *
 ***************************************************************************/

#include <rapmath/trig.h>

/***********************************************
 * compute sin and cos together for efficiency
 */

void rap_sincos(double radians, double *sinVal, double *cosVal)
  
{
  
  double cosv, sinv, interval;

  /* compute cosine */

  cosv = cos(radians);
  *cosVal = cosv;

  /* compute sine magnitude */

  sinv = sqrt(1.0 - cosv * cosv);

  /* set sine sign from location relative to PI */

  interval = floor(radians / M_PI);
  if (fabs(fmod(interval, 2.0)) == 0) {
    *sinVal = sinv;
  } else {
    *sinVal = -1.0 * sinv;
  }

}

/**************************************************
 * compute atan2, setting result to 0 allowing for
 * floating point underflow
 */

double rap_atan2(double y, double x)
  
{
   
  if ((fabs(y - 0.0) < 1.0e-9) && (fabs(x - 0.0) < 1.0e-9)) {
    return 0;
  }

  return atan2(y, x);

}
