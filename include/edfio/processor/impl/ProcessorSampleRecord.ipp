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

	template<>
	inline ProcessorSampleRecord<SampleType::Digital>::Out ProcessorSampleRecord<SampleType::Digital>::Calc(DigiType sample)
	{
		return sample;
	}

	template<>
	ProcessorSampleRecord<SampleType::Digital>::Out ProcessorSampleRecord<SampleType::Digital>::Calc(PhysType sample)
	{
		return static_cast<Out>((sample - m_offset) / m_scaling);
	}

	template<>
	inline ProcessorSampleRecord<SampleType::Physical>::Out ProcessorSampleRecord<SampleType::Physical>::Calc(DigiType sample)
	{
		return m_scaling * static_cast<double>(sample) + m_offset;
	}

	template<>
	ProcessorSampleRecord<SampleType::Physical>::Out ProcessorSampleRecord<SampleType::Physical>::Calc(PhysType sample)
	{
		return (sample - m_offset) / m_scaling;
	}

	template<SampleType SampleT>
	typename ProcessorSampleRecord<SampleT>::Out ProcessorSampleRecord<SampleT>::operator()(In in)
	{
		auto record = std::move(in);
		int sample = 0;
		size_t idx = 0;
		for (unsigned char r : record())
		{
			if (r < 0 && idx++)
				sample = -1;
			sample <<= 8;
			sample |= r;
			idx++;
		}
		return Calc(sample);
	}

}
