//
// Copyright(c) 2017-present Iuri Dotta (dotta dot iuri at gmail dot com)
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
// Official repository: https://github.com/idotta/edfio
//

#pragma once

#include "../../Utils.hpp"
#include "../../header/HeaderGeneral.hpp"
#include "../../header/HeaderSignal.hpp"

#include <vector>
#include <stdexcept>
#include <fstream>

namespace edfio
{

	inline std::vector<HeaderSignalFields> ReaderHeaderSignal::operator ()(Stream &stream)
	{
		std::vector<HeaderSignalFields> signals(m_totalSignals);
		if (!stream || !stream.is_open())
			throw std::invalid_argument(detail::GetError(FileErrc::FileNotOpened));

		stream.clear();
		stream.seekg(256, std::ios::beg);

		try
		{
			for (auto &s : signals)
				stream >> s.m_label;
			for (auto &s : signals)
				stream >> s.m_transducer;
			for (auto &s : signals)
				stream >> s.m_physDimension;
			for (auto &s : signals)
				stream >> s.m_physicalMin;
			for (auto &s : signals)
				stream >> s.m_physicalMax;
			for (auto &s : signals)
				stream >> s.m_digitalMin;
			for (auto &s : signals)
				stream >> s.m_digitalMax;
			for (auto &s : signals)
				stream >> s.m_prefilter;
			for (auto &s : signals)
				stream >> s.m_samplesInDataRecord;
			for (auto &s : signals)
				stream >> s.m_reserved;
		}
		catch (std::exception e)
		{
			throw std::invalid_argument(detail::GetError(FileErrc::FileReadError));
		}
		return std::move(signals);
	}

}
