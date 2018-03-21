/*
===============================================================================

  FILE:  laswriter_txt.hpp
  
  CONTENTS:
  
    Writes LIDAR points to ASCII through on-the-fly conversion from LAS.

  PROGRAMMERS:

    martin.isenburg@rapidlasso.com  -  http://rapidlasso.com

  COPYRIGHT:

    (c) 2007-2014, martin isenburg, rapidlasso - fast tools to catch reality

    This is free software; you can redistribute and/or modify it under the
    terms of the GNU Lesser General Licence as published by the Free Software
    Foundation. See the LICENSE.txt file for more information.

    This software is distributed WITHOUT ANY WARRANTY and without even the
    implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  
  CHANGE HISTORY:
  
    10 April 2011 -- created after a sunny weekend of biking to/from Buergel
  
===============================================================================
*/
#ifndef LAS_WRITER_TXT_HPP
#define LAS_WRITER_TXT_HPP

#include "laswriter.hpp"

#include <stdio.h>

class LASwriterTXT : public LASwriter
{
public:

  void set_pts(LAStools::BOOL pts);
  void set_ptx(LAStools::BOOL ptx);
  void set_scale_rgb(F32 scale_rgb);

  LAStools::BOOL refile(FILE* file);

  LAStools::BOOL open(const CHAR* file_name, const LASheader* header, const CHAR* parse_string=0, const CHAR* separator=0);
  LAStools::BOOL open(FILE* file, const LASheader* header, const CHAR* parse_string=0, const CHAR* separator=0);

  LAStools::BOOL write_point(const LASpoint* point);
  LAStools::BOOL chunk() { return FALSE; };

  LAStools::BOOL update_header(const LASheader* header, LAStools::BOOL use_inventory=FALSE, LAStools::BOOL update_extra_bytes=FALSE);
  I64 close(LAStools::BOOL update_npoints=TRUE);

  LASwriterTXT();
  ~LASwriterTXT();

private:
  LAStools::BOOL close_file;
  FILE* file;
  const LASheader* header;
  CHAR* parse_string;
  LAStools::BOOL opts;
  LAStools::BOOL optx;
  F32 scale_rgb;
  CHAR separator_sign;
  CHAR printstring[512];
  I32 attribute_starts[10];
  LAStools::BOOL check_parse_string(const CHAR* parse_string);
  LAStools::BOOL unparse_attribute(const LASpoint* point, I32 index);
};

#endif
