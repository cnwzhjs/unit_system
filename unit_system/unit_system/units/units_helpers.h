#pragma once

#include <iostream>
#include "units_core.h"

namespace units {

	template<typename TUnit>
	std::ostream& operator<<(std::ostream& os, const unit<TUnit>& v) {
		os << v.value() << TUnit::name();
		return os;
	}

}
