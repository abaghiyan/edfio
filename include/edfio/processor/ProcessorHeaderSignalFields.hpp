//
// Copyright(c) 2017-present Iuri Dotta (dotta dot iuri at gmail dot com)
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
// Official repository: https://github.com/idotta/edfio
//

#pragma once

#include "../core/DataFormat.hpp"
#include "../header/HeaderSignal.hpp"

namespace edfio
{

	struct ProcessorHeaderSignalFields
	{
		ProcessorHeaderSignalFields(DataFormat version, double datarecordDuration)
			: m_version(version)
			, m_datarecordDuration(datarecordDuration)
		{}
		std::vector<HeaderSignal> operator ()(std::vector<HeaderSignalFields> in);
	private:
		DataFormat m_version;
		double m_datarecordDuration;
	};

}

#include "impl/ProcessorHeaderSignalFields.ipp"
