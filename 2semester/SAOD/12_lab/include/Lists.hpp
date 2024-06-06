#pragma once

#include <cstddef>
#include <iostream>
#include <random>

template <typename T> struct NodeList {
    NodeList<T> *next_, *prev_;
    T value_;

    explicit NodeList<T>(const T &value) :
        next_(nullptr), prev_(nullptr), value_(value) {}
};

template <typename T> class IList {
protected:
    NodeList<T> *first_, *last_;
    std::size_t size_;

    void __push_back__(const T &value) {
        NodeList<T> *p = new NodeList<T>(value);
        if (size_ == 0)
            first_ = last_ = p;
        else {
            p->prev_ = last_;
            last_->next_ = p;
            last_ = p;
        }
        size_++;
    }

    void __push_front__(const T &value) {
        NodeList<T> *p = new NodeList<T>(value);
        if (size_ == 0)
            first_ = last_ = p;
        else {
            p->next_ = first_;
            first_->prev_ = p;
            first_ = p;
        }
        size_++;
    }

    T __pop_back__() {
        if (size_ == 0)
            throw std::logic_error("This list is empty!");

        T res = 0;

        if (size_ == 1) {
            res = first_->value_;
            delete first_;
            first_ = last_ = nullptr;
        } else {
            res = last_->value_;
            NodeList<T> *p = last_;
            last_ = last_->prev_;
            last_->next_ = nullptr;
            delete p;
        }
        size_--;

        return res;
    }

    T __pop_front__() {
        if (size_ == 0)
            throw std::logic_error("This list is empty!");

        T res = 0;

        if (size_ == 1) {
            res = first_->value_;
            delete first_;
            first_ = last_ = nullptr;
        } else {
            res = first_->value_;
            NodeList<T> *p = first_;
            first_ = first_->next_;
            first_->prev_ = nullptr;
            delete p;
        }
        size_--;

        return res;
    }

public:
    IList() :
        first_(nullptr), last_(nullptr), size_(0) {}

    IList(const IList<T> &other) :
        IList() {
        if (other.first_ != nullptr) {
            NodeList<T> *pr = other.first_;
            for (std::size_t i = 0; i < other.size_; i++) {
                __push_back__(pr->value_);
                pr = pr->next_;
            }
        }
    }

    IList(IList<T> &&other) {
        size_ = other.size_;
        first_ = other.first_;
        last_ = other.last_;

        other.size_ = 0;
        other.first_ = nullptr;
        other.last_ = nullptr;
    }

    ~IList() {
        clear();
    }

    void clear() {
        while (size_ > 0)
            __pop_back__();
    }

    std::size_t get_size() const {
        return size_;
    }

    bool is_empty() const {
        if (first_ == nullptr)
            return true;
        return false;
    }

    void copy(const IList<T> &other) {
        clear();
        NodeList<T> *pr = other.first_;
        for (std::size_t i = 0; i < other.size_; i++) {
            __push_back__(pr->value_);
            pr = pr->next_;
        }
    }

    void print() const {
        NodeList<T> *p = first_;
        for (std::size_t i = 0; i < size_; i++) {
            std::cout << p->value_ << " ";
            p = p->next_;
        }
        std::cout << std::endl;
    }

    void fill_inc(std::size_t size) {
        T a = 0;
        for (std::size_t i = 0; i < size; i++)
            __push_back__(++a);
    }

    void fill_dec(std::size_t size) {
        T a = 0;
        for (std::size_t i = 0; i < size; i++)
            __push_back__(size - (++a));
    }

    void fill_rand(std::size_t size, const T &min_value, const T &max_value) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min_value, max_value);
        for (std::size_t i = 0; i < size; i++)
            __push_back__(dist(gen));
    }

    IList<T> operator=(const IList<T> &right) {
        copy(right);
        return *this;
    }

    IList<T> operator+(const IList<T> &right) {
        IList<T> res(*this);

        if (res.first_ == nullptr)
            res = right;
        else if (right.first_ != nullptr) {
            NodeList<T> *pr = right.first_;
            for (std::size_t i = 0; i < right.size_; i++) {
                __push_back__(pr->value_);
                pr = pr->next_;
            }
        }

        return res;
    }

    void operator+=(const IList<T> &right) {
        if (right.first_ != nullptr) {
            NodeList<T> *pr = right.first_;
            for (std::size_t i = 0; i < right.size_; i++) {
                __push_back__(pr->value_);
                pr = pr->next_;
            }
        }
    }
};

template <typename T> class list : public IList<T> {
public:
    void push_back(const T &value) {
        this->__push_back__(value);
    }

    void push_front(const T &value) {
        this->__push_front__(value);
    }

    T pop_back() {
        return this->__pop_back__();
    }

    T pop_front() {
        return this->__pop_front__();
    }

    void fill(const T &value) {
        NodeList<T> *p = this->first_;
        for (std::size_t i = 0; i < this->size_; i++) {
            p->value_ = value;
            p = p->next_;
        }
    }

    T operator()(std::size_t index) const {
        if (this->size_ == 0)
            throw std::logic_error("This list is empty!");
        else if (index >= this->size_)
            throw std::logic_error("The index is larger than size of the list!");

        NodeList<T> *res = nullptr;

        if (index == 0)
            res = this->first_;
        else if (index == this->size_ - 1)
            res = this->last_;
        else if (index < this->size_) {
            res = this->first_;
            for (std::size_t i = 0; i < index; i++)
                res = res->next_;
        }

        return res->value_;
    }
};

template <typename T> class stack : public IList<T> {
public:
    void push(const T &value) {
        this->__push_back__(value);
    }

    T pop() {
        return this->__pop_back__();
    }

    T check() {
        return this->last_->value_;
    }
};

template <typename T> class queue : public IList<T> {
public:
    void push(const T &value) {
        this->__push_front__(value);
    }

    T pop() {
        return this->__pop_front__();
    }

    T check() {
        return this->last_->value_;
    }
};