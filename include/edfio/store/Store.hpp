//
// Copyright(c) 2017-present Iuri Dotta (dotta dot iuri at gmail dot com)
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
// Official repository: https://github.com/idotta/edfio
//

#pragma once

namespace edfio
{

	template <class Type, class Stream, typename IterCategory>
	class Store
	{
	public:
		typedef Stream stream_type;
		typedef Store<Type, Stream, IterCategory> store_type;

		typedef Type value_type;
		typedef Type const* pointer;
		typedef Type const& reference;
		typedef long long difference_type;
		typedef unsigned long size_type;

		class iterator
		{
		public:
			typedef typename Store::difference_type difference_type;
			typedef typename Store::value_type value_type;
			typedef typename Store::reference reference;
			typedef typename Store::pointer pointer;
			typedef IterCategory iterator_category;
			typedef typename Store::stream_type stream_type;
		};

		typedef iterator const const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator; //optional
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator; //optional

		Store() = delete;

		Store(stream_type &stream)
			: m_stream(stream)
		{
		}

		virtual size_type size() const = 0;

	protected:
		virtual reference getR(size_type off) = 0;
		virtual pointer getP(size_type off) = 0;

		Stream &m_stream;
	};

}