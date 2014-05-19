#pragma once

#include "units_core.h"
#include "units_conv.h"
#include "units_reduce.h"

namespace units {

	template<typename T1, typename T2>
	typename reduce_unit<mul_unit<T1, T2>>::type operator*(const unit<T1>& a, const unit<T2>& b) {
		return reduce_unit<mul_unit<T1, T2>>::type(a.value() * b.value());
	}

	template<typename T1, typename T2>
	typename reduce_unit<div_unit<T1, T2>>::type operator/(const unit<T1>& a, const unit<T2>& b) {
		return reduce_unit<div_unit<T1, T2>>::type(a.value() / b.value());
	}

	template<typename TUnit>
	typename TUnit operator+(const unit<TUnit>& a, const unit<TUnit>& b) {
		return TUnit(a.value() + b.value());
	}

	template<typename TUnit>
	typename TUnit operator-(const unit<TUnit>& a, const unit<TUnit>& b) {
		return TUnit(a.value() - b.value());
	}

	template<typename T1, typename T2>
	T1 operator+(const unit<T1>& a, const unit<T2>& b) {
		return a + convert<T1>(static_cast<const T2&>(b));
	}

	template<typename T1, typename T2>
	T1 operator-(const unit<T1>& a, const unit<T2>& b) {
		return a - convert<T1>(static_cast<const T2&>(b));
	}

}
