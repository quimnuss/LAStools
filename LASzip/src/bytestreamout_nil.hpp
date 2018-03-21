/*
===============================================================================

  FILE:  bytestreamout_.hpilp
  
  CONTENTS:
      
    Class for a black hole that only counts the bytes.

  PROGRAMMERS:

    martin.isenburg@rapidlasso.com  -  http://rapidlasso.com

  COPYRIGHT:

    (c) 2007-2012, martin isenburg, rapidlasso - fast tools to catch reality

    This is free software; you can redistribute and/or modify it under the
    terms of the GNU Lesser General Licence as published by the Free Software
    Foundation. See the COPYING file for more information.

    This software is distributed WITHOUT ANY WARRANTY and without even the
    implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  
  CHANGE HISTORY:
  
     1 October 2011 -- added 64 bit file support in MSVC 6.0 at McCafe at Hbf Linz
    10 January 2011 -- licensing change for LGPL release and liblas integration
    12 December 2010 -- created from ByteStreamOutFile after Howard got pushy (-;
  
===============================================================================
*/
#ifndef BYTE_STREAM_OUT_NIL_H
#define BYTE_STREAM_OUT_NIL_H

#include "bytestreamout.hpp"

#include <stdio.h>

class ByteStreamOutNil : public ByteStreamOut
{
public:
  ByteStreamOutNil();
/* write a single byte                                       */
  LAStools::BOOL putByte(U8 byte);
/* write an array of bytes                                   */
  LAStools::BOOL putBytes(const U8* bytes, U32 num_bytes);
/* write 16 bit low-endian field                             */
  LAStools::BOOL put16bitsLE(const U8* bytes);
/* write 32 bit low-endian field                             */
  LAStools::BOOL put32bitsLE(const U8* bytes);
/* write 64 bit low-endian field                             */
  LAStools::BOOL put64bitsLE(const U8* bytes);
/* write 16 bit big-endian field                             */
  LAStools::BOOL put16bitsBE(const U8* bytes);
/* write 32 bit big-endian field                             */
  LAStools::BOOL put32bitsBE(const U8* bytes);
/* write 64 bit big-endian field                             */
  LAStools::BOOL put64bitsBE(const U8* bytes);
/* is the stream seekable (e.g. standard out is not)         */
  LAStools::BOOL isSeekable() const;
/* get current position of stream                            */
  I64 tell() const;
/* seek to this position in the stream                       */
  LAStools::BOOL seek(const I64 position);
/* seek to the end of the file                               */
  LAStools::BOOL seekEnd();
/* destructor                                                */
  ~ByteStreamOutNil(){};
private:
  I64 num_bytes;
};

inline ByteStreamOutNil::ByteStreamOutNil()
{
  num_bytes = 0;
}

inline LAStools::BOOL ByteStreamOutNil::putByte(U8 byte)
{
  num_bytes++;
  return TRUE;
}

inline LAStools::BOOL ByteStreamOutNil::putBytes(const U8* bytes, U32 num_bytes)
{
  this->num_bytes += num_bytes;
  return TRUE;
}

inline LAStools::BOOL ByteStreamOutNil::put16bitsLE(const U8* bytes)
{
  return putBytes(bytes, 2);
}

inline LAStools::BOOL ByteStreamOutNil::put32bitsLE(const U8* bytes)
{
  return putBytes(bytes, 4);
}

inline LAStools::BOOL ByteStreamOutNil::put64bitsLE(const U8* bytes)
{
  return putBytes(bytes, 8);
}

inline LAStools::BOOL ByteStreamOutNil::put16bitsBE(const U8* bytes)
{
  return putBytes(bytes, 2);
}

inline LAStools::BOOL ByteStreamOutNil::put32bitsBE(const U8* bytes)
{
  return putBytes(bytes, 4);
}

inline LAStools::BOOL ByteStreamOutNil::put64bitsBE(const U8* bytes)
{
  return putBytes(bytes, 8);
}

inline LAStools::BOOL ByteStreamOutNil::isSeekable() const
{
  return TRUE;
}

inline I64 ByteStreamOutNil::tell() const
{
  return num_bytes;
}

inline LAStools::BOOL ByteStreamOutNil::seek(I64 position)
{
  return TRUE;
}

inline LAStools::BOOL ByteStreamOutNil::seekEnd()
{
  return TRUE;
}

#endif
