#pragma once
#include <utility>
#include "ops.hpp"

template <typename ScalarT>
class Value {
public:
    Value() = delete;
    Value(const ScalarT& data, double grad = 0.0, Operation op = Operation::None)
        : data_(data), grad_(grad), op_(op) {
    }
    Value(ScalarT&& data, double grad = 0.0, Operation op = Operation::None)
        : data_(data), grad_(grad), op_(op) {
    }
    Value operator=(Value val) {
        std::swap(this->data_, val.data_);
        std::swap(this->grad_, val.grad_);
    }

    template <typename RhsScalarT,
              typename ReturnT = decltype(std::declval<ScalarT>() + std::declval<RhsScalarT>())
    > auto operator+(const Value<RhsScalarT>& val) const -> Value<ReturnT> {

        return Value<ReturnT>(static_cast<ReturnT>(this->data_ + val.data()));
    }
    Value operator-(const Value& val) const {
        return Value(this->data_ - val.data_);
    }
    Value operator*(const Value& val) const {
        return Value(this->data_ * val.data_);
    }
    Value operator/(const Value& val) const {
        return Value(this->data_ / val.data_);
    }
    Value operator+=(const Value& val) {
        this->data_ += val.data_;
    }
    Value operator-=(const Value& val) {
        this->data_ -= val.data_;
    }
    Value operator*=(const Value& val) {
        this->data_ *= val.data_;
    }
    Value operator/=(const Value& val) {
        this->data_ /= val.data_;
    }
    ScalarT& data() {
        return this->data_;
    }

    double& grad() {
        return this->grad_;
    }
    const ScalarT& data() const {
        return this->data_;
    }
    const ScalarT& grad() const {
        return this->grad_;
    }

private:
    ScalarT data_;
    double grad_;
    Operation op_;
};
