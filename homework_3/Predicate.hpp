#pragma once

template <typename T>
class Predicate {
public:
    virtual bool operator()(const T& element) const = 0;
};
