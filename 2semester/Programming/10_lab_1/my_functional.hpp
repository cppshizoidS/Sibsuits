#ifndef MY_FUNCTIONAL_HPP
#define MY_FUNCTIONAL_HPP

#include <memory>
#include "my_move.hpp"
#include "unique_ptr.hpp"

namespace my_functional {

class FunctionWrapper {
public:
    virtual ~FunctionWrapper() {}
    virtual void operator()() const = 0;
    virtual my_unique_ptr::unique_ptr<FunctionWrapper> clone() const = 0;
};

template<typename FunctionType>
class Function : public FunctionWrapper {
private:
    FunctionType func;
public:
    explicit Function(FunctionType f) : func(my_move(f)) {}

    void operator()() const override {
        func();
    }

    my_unique_ptr::unique_ptr<FunctionWrapper> clone() const override {
        return std::make_unique<Function>(func);
    }
};



template <typename LambdaType>
class LambdaFunction : public FunctionWrapper {
private:
    LambdaType lambda;

public:
    explicit LambdaFunction(LambdaType l) : lambda(my_move(l)) {}

    void operator()() const override {
        lambda();
    }

    my_unique_ptr::unique_ptr<FunctionWrapper> clone() const override {
        return std::make_unique<LambdaFunction>(lambda);
    }
};

class MyFunction {
private:
    my_unique_ptr::unique_ptr<FunctionWrapper> funcWrapper;

public:
    MyFunction() : funcWrapper(nullptr) {}

    friend bool operator==(const MyFunction& lhs, const MyFunction& rhs);
     // Inequality operator
    friend bool operator!=(const MyFunction& lhs, const MyFunction& rhs) {
        return !(lhs == rhs);
    };


    

    template <typename FunctionType>
    MyFunction(FunctionType f) : funcWrapper(std::make_unique<Function<FunctionType>>(my_move(f))) {}

    // copy constructor
    MyFunction(const MyFunction& other) : funcWrapper(nullptr) {
        if (other.funcWrapper) {
            funcWrapper = other.funcWrapper->clone();
        }
    }

    // move constructor
    MyFunction(MyFunction&& other) noexcept : funcWrapper(my_move(other.funcWrapper)) {
        other.funcWrapper = nullptr;
    }

    // copy assignment operator
    MyFunction& operator=(const MyFunction& other) {
        if (this != &other) {
            funcWrapper = nullptr;
            if (other.funcWrapper) {
                funcWrapper = other.funcWrapper->clone();
            }
        }
        return *this;
    }

    // move assignment operator
    MyFunction& operator=(MyFunction&& other) noexcept {
        if (this != &other) {
            funcWrapper = my_move(other.funcWrapper);
            other.funcWrapper = nullptr;
        }
        return *this;
    }

    void operator()() const {
        if (funcWrapper) {
            (*funcWrapper)();
        }
    }
    friend bool operator==(const MyFunction& lhs, const MyFunction& rhs) {
        if (lhs.funcWrapper && rhs.funcWrapper) {
            return typeid(*lhs.funcWrapper) == typeid(*rhs.funcWrapper);
        }
        return lhs.funcWrapper == rhs.funcWrapper;
    }

};


}
#endif // MY_FUNCTIONAL_HPP
