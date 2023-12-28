#pragma once
#include "Set.h"

template <typename T>
class SetByCriteria:public Set {
public:
    SetByCriteria(const Predicate<T>& predicate) : predicate(predicate) {}

    virtual bool contains(const T& element) const override;
    virtual void addElement(int element) override;
    virtual void removeElement(int element) override;
 

private:
    const Predicate<T>& predicate;
};

template<typename T>
bool SetByCriteria::contains(const T& element) const {
    return predicate(element);
}

template<typename T>
void SetByCriteria::addElement(int element) override {

}
virtual void SetByCriteria::removeElement(int element) override;
