/* GemRB - Infinity Engine Emulator
 * Copyright (C) 2003 The GemRB Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *
 */

#ifndef INDEXEDARCHIVE_H
#define INDEXEDARCHIVE_H

#include "globals.h"

#include "Plugin.h"

namespace GemRB {

class GEM_EXPORT IndexedArchive : public Plugin {
public:
	virtual int OpenArchive(const char* filename) = 0;
	virtual DataStream* GetStream(unsigned long Resource, unsigned long Type) = 0;
};

}

#endif
