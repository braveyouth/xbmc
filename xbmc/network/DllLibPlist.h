#pragma once

/*
 *      Copyright (C) 2011 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "DynamicDll.h"

#include <plist/plist.h>

class DllLibPlistInterface
{
public:
  virtual ~DllLibPlistInterface() {}

  virtual void        plist_from_bin        (const char *plist_bin,   uint32_t length, plist_t * plist  )=0;
  virtual plist_t     plist_new_dict        (void                                                       )=0;
  virtual uint32_t    plist_dict_get_size   (plist_t node                                               )=0;
  virtual void        plist_get_string_val  (plist_t node,            char **val                        )=0;
  virtual void        plist_get_real_val    (plist_t node,            double *val                       )=0;
  virtual plist_t     plist_dict_get_item   (plist_t node,            const char* key                   )=0;
  virtual void        plist_free            (plist_t plist                                              )=0;  

};

class DllLibPlist : public DllDynamic, DllLibPlistInterface
{
  DECLARE_DLL_WRAPPER(DllLibPlist, DLL_PATH_LIBPLIST)
  DEFINE_METHOD0(plist_t,       plist_new_dict)
  DEFINE_METHOD1(uint32_t,      plist_dict_get_size,  (plist_t p1))
  DEFINE_METHOD1(void,          plist_free,           (plist_t p1))
  DEFINE_METHOD2(void,          plist_get_string_val, (plist_t p1,      char **p2))
  DEFINE_METHOD2(void,          plist_get_real_val,   (plist_t p1,      double *p2))
  DEFINE_METHOD2(plist_t,       plist_dict_get_item,  (plist_t p1,      const char* p2))
  DEFINE_METHOD3(void,          plist_from_bin,       (const char *p1,  uint32_t p2, plist_t *p3))


  BEGIN_METHOD_RESOLVE()
    RESOLVE_METHOD_RENAME(plist_new_dict,         plist_new_dict)    
    RESOLVE_METHOD_RENAME(plist_free,             plist_free)
    RESOLVE_METHOD_RENAME(plist_dict_get_size,    plist_dict_get_size)
    RESOLVE_METHOD_RENAME(plist_from_bin,         plist_from_bin)
    RESOLVE_METHOD_RENAME(plist_get_real_val,     plist_get_real_val)
    RESOLVE_METHOD_RENAME(plist_get_string_val,   plist_get_string_val)
    RESOLVE_METHOD_RENAME(plist_dict_get_item,    plist_dict_get_item)

  END_METHOD_RESOLVE()
};

