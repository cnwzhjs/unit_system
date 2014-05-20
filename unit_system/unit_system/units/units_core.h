#pragma once

#include <string>

namespace units {

	typedef double rep_t;

	template<typename TUnit>
	class unit {
	public:
		unit(rep_t rep) : value_(rep) {}
		unit(const unit& that) : value_(that.value_) {}
		~unit() {}

		rep_t value() const { return value_; }

		static std::string name();

	private:
		rep_t value_;
	};

	template<typename T1, typename T2>
	class mul_unit : public unit<mul_unit<T1, T2>> {
	public:
		typedef T1 unit1;
		typedef T2 unit2;

		mul_unit(rep_t rep) : unit<mul_unit<T1, T2>>(rep) {}
		mul_unit(const mul_unit& that) : unit<mul_unit<T1, T2>>(that) {}

		static std::string name() { return T1::name() + "*" + T2::name(); }
	};

	template<typename T1, typename T2>
	class div_unit : public unit<div_unit<T1, T2>> {
	public:
		typedef T1 unit1;
		typedef T2 unit2;

		div_unit(rep_t rep) : unit<div_unit<T1, T2>>(rep) {}
		div_unit(const div_unit& that) : unit<div_unit<T1, T2>>(that) {}

		static std::string name() { return T1::name() + "/" + T2::name(); }
	};

	template<typename TUnit>
	class rec_unit : public unit<rec_unit<TUnit>> {
	public:
		typedef TUnit base;

		rec_unit(rep_t rep) : unit<rec_unit<TUnit>>(rep) {}
		rec_unit(const rec_unit& that) : unit<rec_unit<TUnit>>(that) {}

		static std::string name() { return TUnit::name() + "^-1"; }
	};

}

#define DEFINE_UNIT(KLASS, NAME) class KLASS : public unit<KLASS> {\
public:\
	KLASS(rep_t rep) : unit<KLASS>(rep) {} \
	KLASS(const KLASS& that) : unit<KLASS>(that) {} \
	static std::string name() { return #NAME; } \
};
