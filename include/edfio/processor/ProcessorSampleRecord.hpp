//
// Copyright(c) 2017-present Iuri Dotta (dotta dot iuri at gmail dot com)
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
// Official repository: https://github.com/idotta/edfio
//

#pragma once

#include "../core/SampleType.hpp"
#include "../core/Record.hpp"

namespace edfio
{

	template <SampleType SampleT>
	struct ProcessorSampleRecord
	{
		using ProcType = typename impl::Sample<SampleT>::type;
		using DigiType = impl::Sample<SampleType::Digital>::type;
		using PhysType = impl::Sample<SampleType::Physical>::type;

		ProcessorSampleRecord(double offset, double scaling)
			: m_offset(offset)
			, m_scaling(scaling)
		{
		}

		ProcType operator ()(Record<char> record);

	private:
		const double m_offset;
		const double m_scaling;
	};

}

#include "impl/ProcessorSampleRecord.ipp"
