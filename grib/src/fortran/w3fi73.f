C    *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
C    ** Copyright UCAR (c) 1992 - 2010 
C    ** University Corporation for Atmospheric Research(UCAR) 
C    ** National Center for Atmospheric Research(NCAR) 
C    ** Research Applications Laboratory(RAL) 
C    ** P.O.Box 3000, Boulder, Colorado, 80307-3000, USA 
C    ** 2010/10/7 23:12:29 
C    *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
      SUBROUTINE W3FI73 (IBFLAG,IBMAP,IBLEN,BMS,LENBMS,IER)
C$$$  SUBPROGRAM DOCUMENTATION BLOCK
C                .      .    .                                       .
C SUBPROGRAM:  W3FI73        CONSTRUCT GRIB BIT MAP SECTION (BMS)
C   PRGMMR: FARLEY           ORG: NMC421      DATE:92-11-16
C
C ABSTRACT: THIS SUBROUTINE CONSTRUCTS A GRIB BIT MAP SECTION.
C
C PROGRAM HISTORY LOG:
C   92-07-01  M. FARLEY      ORIGINAL AUTHOR
C   94-02-14  CAVANAUGH      RECODED
C
C USAGE:    CALL W3FI73 (IBFLAG, IBMAP, IBLEN, BMS, LENBMS, IER)
C   INPUT ARGUMENT LIST:
C     IBFLAG      - 0, IF BIT MAP SUPPLIED BY USER
C                 - #, NUMBER OF PREDEFINED CENTER BIT MAP
C     IBMAP       - INTEGER ARRAY CONTAINING USER BIT MAP
C     IBLEN       - LENGTH OF BIT MAP
C
C   OUTPUT ARGUMENT LIST:
C     BMS       - COMPLETED GRIB BIT MAP SECTION
C     LENBMS    - LENGTH OF BIT MAP SECTION
C     IER       - 0 NORMAL EXIT, 8 = IBMAP VALUES ARE ALL ZERO
C
C ATTRIBUTES:
C   LANGUAGE: IBM370 VS FORTRAN 77, CRAY CFT77 FORTRAN
C   MACHINE:  HDS, CRAY C916-128, CRAY Y-MP8/864, CRAY Y-MP EL2/256
C
C$$$
C
      INTEGER       IBMAP(*)
      INTEGER       LENBMS
      INTEGER       IBLEN
      INTEGER       IBFLAG
C
      CHARACTER*1   BMS   (*)
C
      SAVE
C
      IER   = 0
C
C
      IZ  = 0
      DO 20 I = 1, IBLEN
          IF (IBMAP(I).EQ.0) IZ  = IZ + 1
   20 CONTINUE
      IF (IZ.EQ.IBLEN) THEN
C
C                         AT THIS POINT ALL BIT MAP POSITIONS ARE ZERO
C
              IER = 8
              RETURN
      END IF
C
C                          BIT MAP IS A COMBINATION OF ONES AND ZEROS
C                          OR      BIT MAP ALL ONES
C
C                     CONSTRUCT BIT MAP FIELD OF BIT MAP SECTION
C
      CALL SBYTESC (BMS,IBMAP,48,1,0,IBLEN)
C
      IF (MOD(IBLEN,16).NE.0) THEN
          NLEFT  = 16 - MOD(IBLEN,16)
      ELSE
          NLEFT  = 0
      END IF
C
      NUM  = 6 + (IBLEN+NLEFT) / 8
C
C
C                          CONSTRUCT BMS FROM COLLECTED DATA
C
C                          SIZE INTO FIRST THREE BYTES
      CALL SBYTEC (BMS,NUM,0,24)
C                          NUMBER OF FILL BITS INTO BYTE 4
      CALL SBYTEC (BMS,NLEFT,24,8)
C                          OCTET 5-6 TO CONTAIN INFO FROM IBFLAG
      CALL SBYTEC (BMS,IBFLAG,32,16)
C
C                          BIT MAP MAY BE ALL ONES OR A COMBINATION
C                          OF ONES AND ZEROS
C
C                          ACTUAL BITS OF BIT MAP PLACED ALL READY
C
C                          INSTALL FILL POSITIONS IF NEEDED
      IF (NLEFT.NE.0) THEN
          NLEFT  = 16 - NLEFT
C                          ZERO FILL POSITIONS
          CALL SBYTEC (BMS,0,IBLEN+48,NLEFT)
      END IF
C
C     STORE NUM IN LENBMS  (LENGTH OF BMS SECTION)
C
      LENBMS = NUM
C     PRINT *,'W3FI73 - BMS LEN =',NUM,LENBMS
C
      RETURN
      END
