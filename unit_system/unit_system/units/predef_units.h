#pragma once

#include "units_core.h"
#include "units_conv.h"

namespace units {

	DEFINE_UNIT(metre, m)
	DEFINE_UNIT(kilogram, kg)
	DEFINE_UNIT(second, s)
	DEFINE_UNIT(ampere, A)
	DEFINE_UNIT(kelvin, K)
	DEFINE_UNIT(mole, mol)
	DEFINE_UNIT(candela, cd)

	DEFINE_UNIT(kilometer, km)
	DEFINE_UNIT(centimeter, cm)
	DEFINE_UNIT(gram, g)

	DEFINE_CONVERSION(metre, kilometer, from.value() / 1000)
	DEFINE_CONVERSION(kilometer, metre, from.value() * 1000)
	DEFINE_CONVERSION(metre, centimeter, from.value() * 100)
	DEFINE_CONVERSION(centimeter, metre, from.value() / 100)
	DEFINE_CONVERSION(gram, kilogram, from.value() / 1000)
	DEFINE_CONVERSION(kilogram, gram, from.value() * 1000)

}
