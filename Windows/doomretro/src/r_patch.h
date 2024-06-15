/*
========================================================================

                               DOOM Retro
         The classic, refined DOOM source port. For Windows PC.

========================================================================

  Copyright © 1993-2022 by id Software LLC, a ZeniMax Media company.
  Copyright © 2013-2022 by Brad Harding <mailto:brad@doomretro.com>.

  DOOM Retro is a fork of Chocolate DOOM. For a list of acknowledgments,
  see <https://github.com/bradharding/doomretro/wiki/ACKNOWLEDGMENTS>.

  This file is a part of DOOM Retro.

  DOOM Retro is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation, either version 3 of the license, or (at your
  option) any later version.

  DOOM Retro is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with DOOM Retro. If not, see <https://www.gnu.org/licenses/>.

  DOOM is a registered trademark of id Software LLC, a ZeniMax Media
  company, in the US and/or other countries, and is used without
  permission. All other trademarks are the property of their respective
  holders. DOOM Retro is in no way affiliated with nor endorsed by
  id Software.

========================================================================
*/

#pragma once

typedef struct
{
    int             topdelta;
    int             length;
} rpost_t;

typedef struct
{
    int             numposts;
    rpost_t         *posts;
    unsigned char   *pixels;
} rcolumn_t;

typedef struct
{
    int             width;
    int             height;
    unsigned int    widthmask;

    int             leftoffset;
    int             topoffset;

    // this is the single malloc'ed/free'd array
    // for this patch
    unsigned char   *data;

    // these are pointers into the data array
    unsigned char   *pixels;
    rcolumn_t       *columns;
    rpost_t         *posts;
} rpatch_t;

const rpatch_t *R_CachePatchNum(int id);

const rpatch_t *R_CacheTextureCompositePatchNum(int id);

const rcolumn_t *R_GetPatchColumnWrapped(const rpatch_t *patch, int columnIndex);
const rcolumn_t *R_GetPatchColumnClamped(const rpatch_t *patch, int columnIndex);

void R_InitPatches(void);