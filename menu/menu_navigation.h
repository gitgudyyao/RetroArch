/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2015 - Daniel De Matteis
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MENU_NAVIGATION_H
#define _MENU_NAVIGATION_H

#include <stddef.h>
#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct menu_navigation
{
   struct
   {
      /* Quick jumping indices with L/R.
       * Rebuilt when parsing directory. */
      struct
      {
         size_t list[2 * (26 + 2) + 1];
         unsigned size;
      } indices;
      unsigned acceleration;
   } scroll;
   size_t selection_ptr;
} menu_navigation_t;

enum menu_navigation_ctl_state
{
   MENU_NAVIGATION_CTL_CLEAR = 0,
   MENU_NAVIGATION_CTL_INCREMENT,
   MENU_NAVIGATION_CTL_DECREMENT,
   MENU_NAVIGATION_CTL_SET,
   MENU_NAVIGATION_CTL_SET_LAST,
   MENU_NAVIGATION_CTL_DESCEND_ALPHABET,
   MENU_NAVIGATION_CTL_ASCEND_ALPHABET,
   MENU_NAVIGATION_CTL_SET_SELECTION,
   MENU_NAVIGATION_CTL_GET_SELECTION,
   MENU_NAVIGATION_CTL_SET_SCROLL_INDICES
};

bool menu_navigation_ctl(enum menu_navigation_ctl_state state, void *data);

#ifdef __cplusplus
}
#endif

#endif
