#pragma once

#include "units_core.h"

namespace units {

	template<typename T>
	struct reduce_unit {
		typedef T type;
	};

	template<typename T1, typename T2>
	struct reduce_unit<mul_unit<div_unit<T1, T2>, T2>> {
		typedef typename reduce_unit<T1>::type type;
	};

	template<typename T1, typename T2, typename T3>
	struct reduce_unit<mul_unit<T1, mul_unit<T2, T3>>> {
		typedef typename reduce_unit<mul_unit<mul_unit<T1, T2>, T3>>::type type;
	};

	template<typename T1, typename T2, typename T3>
	struct reduce_unit<mul_unit<T1, div_unit<T2, T3>>> {
		typedef typename reduce_unit<div_unit<mul_unit<T1, T2>, T3>>::type type;
	};

	template<typename T1, typename T2, typename T3, typename T4>
	struct reduce_unit<mul_unit<div_unit<T1, T2>, div_unit<T3, T4>>> {
		typedef typename reduce_unit<div_unit<mul_unit<T1, T3>, mul_unit<T2, T4>>>::type type;
	};

	template<typename T1, typename T2>
	struct reduce_unit<div_unit<T1, rec_unit<T2>>> {
		typedef typename reduce_unit<mul_unit<T1, T2>>::type type;
	};

	template<typename T1, typename T2, typename T3>
	struct reduce_unit<div_unit<T1, div_unit<T2, T3>>> {
		typedef typename reduce_unit<div_unit<mul_unit<T1, T3>, T2>>::type type;
	};

	template<typename T1, typename T2>
	struct reduce_unit<div_unit<mul_unit<T1, T2>, T1>> {
		typedef typename reduce_unit<T2>::type type;
	};

	template<typename T1, typename T2>
	struct reduce_unit<div_unit<mul_unit<T1, T2>, T2>> {
		typedef typename reduce_unit<T1>::type type;
	};

}
