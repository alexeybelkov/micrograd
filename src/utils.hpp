#pragma once

#include <utility>

template <typename T, typename U>
consteval auto TypeDeducerAdd() {
    return std::declval<T>() + std::declval<U>();
}
