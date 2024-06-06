#pragma once

#include "Lists.hpp"

#include <cstddef>
#include <stdexcept>

template <typename T> struct HashNode {
    HashNode<T> *next, *prev;
    unsigned key;

    list<T> *data;

    HashNode(unsigned key_, const T &value) :
        next(nullptr), prev(nullptr), key(key_) {
        data = new list<T>;
        data->push_back(value);
    }

    ~HashNode() {
        if (prev != nullptr)
            prev->next = next;
        if (next != nullptr)
            next->prev = prev;
        data->clear();
        delete data;
    }
};

template <typename TKey, typename TValue> class HashTable {
private:
    HashNode<TValue> *firts;
    HashNode<TValue> *last;
    std::size_t size;

    unsigned getHash(const TKey &key, std::size_t size_table) {
        return key % size_table;
    }

    bool is_exist(unsigned hash) {
        bool res = false;
        HashNode<TValue> *p = firts;
        while (p != nullptr) {
            if (p->key == hash) {
                res = true;
                break;
            }
            p = p->next;
        }
        return res;
    }

    void addNew(unsigned hash, const TValue &value) {
        HashNode<TValue> *p = new HashNode<TValue>(hash, value);
        if (size == 0)
            last = firts = p;
        else {
            p->prev = last;
            last->next = p;
            last = p;
        }
        size++;
    }

public:
    HashTable() :
        firts(nullptr), last(nullptr), size(0) {}

    ~HashTable() {
        clear();
    }

    void clear() {
        HashNode<TValue> *p = firts;
        HashNode<TValue> *temp = firts;
        while (size > 0) {
            temp = p;
            p = p->next;
            delete temp;
            size--;
        }
    }

    void addDirectLinking(const TKey &key, const TValue &value, std::size_t size_table) {
        unsigned hash = getHash(key, size_table);
        bool is_exist = false;
        HashNode<TValue> *p = firts;
        while (p != nullptr) {
            if (p->key == hash) {
                is_exist = true;
                break;
            }
            p = p->next;
        }
        if (is_exist)
            p->data->push_back(value);
        else
            addNew(hash, value);
    }

    void addOpenAddressingQuadraticSample(const TKey &key, const TValue &value, std::size_t size_table) {
        unsigned hash = getHash(key, size_table);
        HashNode<TValue> *p = firts;

        if (is_exist(hash)) {
            int h = 1;
            while (is_exist(hash)) {
                hash += h * h;
                if (hash >= size_table)
                    hash -= size_table;
                if (hash >= size_table) {
                    hash = hash + size_table - h * h;
                    break;
                }
                h++;
            }
            if (is_exist(hash)) {
                while (p->key != hash)
                    p = p->next;
                p->data->push_back(value);
            } else
                addNew(hash, value);
        } else
            addNew(hash, value);
    }

    void addOpenAddressingLinearSample(const TKey &key, const TValue &value, std::size_t size_table) {
        unsigned hash = getHash(key, size_table);
        HashNode<TValue> *p = firts;

        if (is_exist(hash)) {
            while (is_exist(hash)) {
                hash++;
                if (hash >= size_table) {
                    hash--;
                    break;
                }
            }
            if (is_exist(hash)) {
                while (p->key != hash)
                    p = p->next;
                p->data->push_back(value);
            } else
                addNew(hash, value);
        } else
            addNew(hash, value);
    }

    void remove(const TKey &key) {
        unsigned hash = getHash(key);
        HashNode<TValue> *p = firts;
        while (p != nullptr && p->key != hash)
            p = p->next;
        if (p == nullptr)
            return;
        delete p;
        size--;
    }

    TValue get(const TKey &key) {
        unsigned hash = getHash(key);
        HashNode<TValue> *p = firts;
        while (p != nullptr && p->key != hash)
            p = p->next;
        if (p == nullptr)
            throw std::logic_error("Key is not normal!");
        return (*p->data)(0);
    }

    std::size_t get_collisions() {
        HashNode<TValue> *p = firts;
        std::size_t collision = 0;

        while (p != nullptr) {
            collision += p->data->get_size() - 1;
            p = p->next;
        }

        return collision;
    }
};

std::size_t directLinking(const std::string &str, std::size_t size_table);
std::size_t openAddressingLinearSample(const std::string &str, std::size_t size_table);
std::size_t openAddressingQuadraticSample(const std::string &str, std::size_t size_table);