/**
 * \file
 * \brief DynamicRawMessageQueue class implementation
 *
 * \author Copyright (C) 2015 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \date 2015-10-22
 */

#include "distortos/DynamicRawMessageQueue.hpp"

#include "distortos/memory/dummyDeleter.hpp"

namespace distortos
{

/*---------------------------------------------------------------------------------------------------------------------+
| public functions
+---------------------------------------------------------------------------------------------------------------------*/

DynamicRawMessageQueue::DynamicRawMessageQueue(const size_t elementSize, const size_t queueSize) :
		entryStorageUniquePointer_{new typename EntryStorageUniquePointer::element_type[queueSize]},
		valueStorageUniquePointer_{new uint8_t[elementSize * queueSize]},
		rawMessageQueue_{{entryStorageUniquePointer_.get(), memory::dummyDeleter},
				{valueStorageUniquePointer_.get(), memory::dummyDeleter}, elementSize, queueSize}
{

}

/**
 * \brief DynamicRawMessageQueue's destructor
 */

DynamicRawMessageQueue::~DynamicRawMessageQueue()
{

}

}	// namespace distortos
