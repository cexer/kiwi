/*-----------------------------------------------------------------------------
| Copyright (c) 2013-2019, Nucleic Development Team.
|
| Distributed under the terms of the Modified BSD License.
|
| The full license is in the file COPYING.txt, distributed with this software.
|----------------------------------------------------------------------------*/
#pragma once
#include <functional>
#include <map>
#include <memory>
#include <utility>
#include "AssocVector.h"


namespace kiwi
{

namespace impl
{


#if defined(_KIWI_HAS_CPP11)
template<
	typename K,
	typename V,
	typename C = std::less<K>,
	typename A = std::allocator< std::pair<K, V> > >
using _KIWI_MAP_TYPE = Loki::AssocVector<K, V, C, A>;

#else

#define _KIWI_MAP_TYPE Loki::AssocVector

#endif


// template<
// 	typename K,
// 	typename V,
// 	typename C = std::less<K>,
// 	typename A = std::allocator< std::pair<const K, V> > >
// using MapType = std::map<K, V, C, A>;

} // namespace impl

} // namespace kiwi
