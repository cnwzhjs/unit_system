#pragma once

#include "units_core.h"

namespace units {

	template<typename TFrom, typename TTo>
	class unit_converter {
	public:
		static TTo convert(const TFrom&);
	};

	template<typename TTo, typename TFrom>
	static inline TTo convert(const TFrom& from) {
		return unit_converter<TFrom, TTo>::convert(from);
	}

}

#define DEFINE_CONVERSION(FROM, TO, CALC) \
	template<> struct unit_converter<FROM, TO> {  \
		static TO convert(const FROM& from) { \
			return TO(CALC); \
		} \
	};
