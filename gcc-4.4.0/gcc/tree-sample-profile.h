/* Header file of sample profile in GCC.
   Copyright (C) 2008
   Free Software Foundation, Inc.
   Contributed by Paul Yuan (yingbo.com@gmail.com)
              and Vinodha Ramasamy (vinodha@google.com).

This file is part of GCC.
GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* References:
   [1] "Feedback-directed Optimizations in GCC with Estimated Edge Profiles
        from Hardware Event Sampling", Vinodha Ramasamy, Paul Yuan, Dehao Chen,
        and Robert Hundt; GCC Summit 2008.
*/

#ifndef _SAMPLE_PROFILE_H
#define _SAMPLE_PROFILE_H

#include "input.h"

#define FB_SAMPLE_NIDENT       16
#define FB_SAMPLE_MAJOR_VERSION      1
#define FB_SAMPLE_MINOR_VERSION      1
#define SP_HTAB_INIT_SIZE 2000
#define SP_INLINE_HTAB_INIT_SIZE 2000

/* Organization of sample file is as follows:
   fb_sample_hdr
   pu_hdr 1
   pu_hdr 2
   pu_hdr 3 ...
   inline_hdr 1
   inline_hdr 2 ...
   str_table
   Profile_Data.  */

struct fb_sample_hdr
{
  /* Identifier.  */
  char fb_ident[FB_SAMPLE_NIDENT];

  /* File version.  */
  unsigned int fb_version;

  /* Total number of inline function hdrs.  */
  unsigned int fb_func_inline_hdr_num;

  /* Function header file offset.  */
  unsigned long long fb_func_hdr_offset;

  /* Function header entry size.  */
  unsigned int fb_func_hdr_ent_size;

  /* Number of function header entries.  */
  unsigned int fb_func_hdr_num;

  unsigned long long fb_str_table_offset;
  unsigned long long fb_str_table_size;

  /* File offset for profile data.  */
  unsigned long long fb_profile_offset;
};

/* Header for each function.  */
struct func_sample_hdr
{
  int func_checksum;
  int inline_depth;
  unsigned long long sampling_rate;
  /* Sum of samples including inlined function samples.  */
  unsigned long long total_samples;

  /* Offset into string table.  */
  unsigned long long func_name_index;

  /* Offset into profile section relative to fb_profile_offset.  */
  unsigned long long func_profile_offset;

  /* Offsets into different profile data follows.  */
  unsigned long long func_freq_offset;
  unsigned long long func_num_freq_entries;
  /* Used to hold inline stack if inline_depth > 0.  */
  /* inline_depth number of fb_info_inline_stack entries are stored.  */
  unsigned long long inline_stack_offset;

  /* Offset relative to start of inline hdrs section.  */
  unsigned long long func_inline_hdr_offset;
  unsigned long long func_num_inline_entries;

  /* Used only for inlined routines.  */
  unsigned long long func_parent_hdr_offset;

  /* For future use.  */
  unsigned long long reserved1;
  unsigned long long reserved2;
};

struct fb_info_freq
{
  unsigned long long filename_offset;
  int line_num;
  int discriminator;
  int num_instr;
  float freq;
};

struct fb_info_inline_stack_entry
{
  unsigned long long filename_offset;
  int line_num;
  int reserved;
};

/* Store line number and it's associated count.  */
struct sample_freq_detail
{
  const char *filename;
  const char *func_name;
  int line_num;
  int discriminator;
  int num_instr;
  float freq;
};

struct sample_inline_freq
{
  bool is_first;
  int depth;
  int line_num;
  int discriminator;
  expanded_location *inline_stack;
  const char *func_name;
  const char *filename;
  int num_instr;
  float freq;
};

/* Store profile per feedback data file.  */
struct profile
{
  struct fb_sample_hdr fb_hdr;
  char *str_table;
};

extern void init_sample_profile (void);
extern void end_sample_profile (void);
extern unsigned long long get_total_count (gimple, const char *);
extern void sp_annotate_bb (basic_block);
extern void sp_smooth_cfg (void);
#endif
