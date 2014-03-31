
#pragma once

#include <array>
#include <type_traits>


namespace reflectionzeug
{

namespace helpers
{

template <bool Condition, bool... MoreConditions>
struct all;

template <bool... MoreConditions>
struct all<true, MoreConditions...> : public all<MoreConditions...>
{
};

template <bool... MoreConditions>
struct all<false, MoreConditions...>
{
    enum { value = false };
};

template <>
struct all<true>
{
    enum { value = true };
};

template <>
struct all<false>
{
    enum { value = false };
};

template <bool Condition>
struct neg
{
    enum { value = true };
};

template <>
struct neg<true>
{
    enum { value = false };
};

template <typename Type>
struct is_array
{
    enum { value = false };
};

template <typename Type, size_t Size>
struct is_array<std::array<Type, Size>>
{
    enum { value = true };
};

}
    
template <typename Condition>
struct NegHelper : public helpers::neg<Condition::value> {};
    
template <typename Condition>
using Neg = NegHelper<Condition>;

template <typename... Conditions>
struct AllHelper : public helpers::all<Conditions::value...> {};
    
template <typename... Conditions>
using All = AllHelper<Conditions...>;

template <typename... Conditions>
struct EnableIfHelper : std::enable_if<All<Conditions...>::value> {};
    
template <typename... Conditions>
using EnableIf = typename EnableIfHelper<Conditions...>::type;

template <typename... Conditions>
struct DisableIfHelper : public std::enable_if<!All<Conditions...>::value> {};

template <typename... Conditions>
using DisableIf = typename DisableIfHelper<Conditions...>::type;

template <typename Type>
using isArray = helpers::is_array<Type>;

template <typename Type>
using isBoolArray = All<isArray<Type>, std::is_same<typename Type::value_type, bool>>;

template <typename Type>
using isIntArray = All<isArray<Type>, std::is_same<typename Type::value_type, int>>;

template <typename Type>
using isDoubleArray = All<isArray<Type>, std::is_same<typename Type::value_type, double>>;

} // namespace reflectionzeug
