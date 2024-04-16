#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <cassert>
#include <iostream>
#include <utility>

template <typename Item>
class single_linked_list
{
 public:
  using      value_type = Item;
  using       size_type = size_t;
  using difference_type = ptrdiff_t;
  using         pointer = value_type *;
  using   const_pointer = const value_type *;
  using       reference = value_type &;
  using const_reference = const value_type &;

 private:
  struct node
  {
    node *next = nullptr;
    Item data;

    explicit node(value_type item) noexcept
        : data { std::move(item) }
          {
          };
  };

 public:
  class single_linked_list_const_iterator
  {
   private:
    friend class single_linked_list;

    explicit single_linked_list_const_iterator(const node *ptr) noexcept
        : m_current { ptr }
    {
    }

   public:
    using   difference_type = single_linked_list::difference_type;
    using        value_type = single_linked_list::value_type;
    using           pointer = single_linked_list::const_pointer;
    using         reference = single_linked_list::const_reference;
    using iterator_category = std::forward_iterator_tag;

    reference operator*() const noexcept
    {
      assert(m_current != nullptr);
      return m_current->data;
    }

    virtual single_linked_list_const_iterator& operator++() noexcept
    {
      assert(m_current != nullptr);
      m_current = m_current->next;
      return *this;
    }

    virtual single_linked_list_const_iterator cbegin() const noexcept
    {
      return const_iterator { m_head };
    }

    virtual single_linked_list_const_iterator cend() const noexcept
    {
      return const_iterator { nullptr };
    }
/*
    virtual single_linked_list_iterator operator++(int) noexcept
    {
      assert(m_current != nullptr);
      auto copy = *this;

      m_current = m_current->next;
      return copy;
    }
*/
    bool operator==(single_linked_list_const_iterator other) const noexcept
    {
      return m_current == other.m_current;
    }

    bool operator!=(single_linked_list_const_iterator other) const noexcept
    {
      return *this != other;
    }

   protected:
    const node *Get() const noexcept
    {
      return m_current;
    }

   protected:
    const node *m_current;
  };

  // Reverse iterator
  class single_linked_list_reverse_iterator : public single_linked_list_const_iterator
  {
   private:
    friend class single_linked_list;

    explicit single_linked_list_reverse_iterator(node *ptr) noexcept
        : single_linked_list_const_iterator { ptr }
    {
    }

   public:
    using   difference_type = single_linked_list::difference_type;
    using        value_type = single_linked_list::value_type;
    using           pointer = single_linked_list::pointer;
    using         reference = single_linked_list::reference;
    using iterator_category = std::forward_iterator_tag;

    reference operator *() noexcept
    {
      auto &&res = single_linked_list_const_iterator::operator*();
      return const_cast<reference>(res);
    }

    single_linked_list_reverse_iterator& operator++() noexcept
    {
      single_linked_list_const_iterator::operator++();
      return *this;
    }

    single_linked_list_reverse_iterator operator++(int) noexcept
    {
      auto res = single_linked_list_const_iterator::operator++(0);
      return single_linked_list_reverse_iterator { const_cast<node *>(res.Get()) };
    }
  };

  class single_linked_list_iterator : public single_linked_list_const_iterator
  {
   private:
    friend class single_linked_list;

    explicit single_linked_list_iterator(node *ptr) noexcept
        : single_linked_list_const_iterator { ptr }
    {
    }

   public:
    using   difference_type = single_linked_list::difference_type;
    using        value_type = single_linked_list::value_type;
    using           pointer = single_linked_list::pointer;
    using         reference = single_linked_list::reference;
    using iterator_category = std::forward_iterator_tag;

    reference operator *() noexcept
    {
      auto &&res = single_linked_list_const_iterator::operator*();
      return const_cast<reference>(res);
    }

    single_linked_list_iterator& operator++() noexcept
    {
      single_linked_list_const_iterator::operator++();
      return *this;
    }

    single_linked_list_iterator operator++(auto) noexcept
    {
      auto res = single_linked_list_const_iterator::operator++(0);
      return single_linked_list_iterator { const_cast<node *>(res.Get()) };
    }
  };
  // Reverse iterator class
  class reverse_iterator : public single_linked_list_const_iterator
  {
   public:
    explicit reverse_iterator(node *ptr) noexcept
        : single_linked_list_const_iterator { ptr }
    {
    }

    reverse_iterator& operator++() noexcept
    {
      assert(this->m_current != nullptr);
      auto *prev = this->m_current;
      this->m_current = this->m_current->next;

      // Traverse until the end of the list
      while (this->m_current && this->m_current->next)
      {
        auto *nextNode = this->m_current->next;
        this->m_current->next = prev;
        prev = this->m_current;
        this->m_current = nextNode;
      }

      // Handle the last node
      if (this->m_current)
      {
        this->m_current->next = prev;
      }

      return *this;
    }

    reverse_iterator operator++(int) noexcept
    {
      auto copy = *this;
      ++(*this);
      return copy;
    }
  };

  using iterator       = single_linked_list_iterator;
  using rev_iterator   = single_linked_list_reverse_iterator;
  using const_iterator = single_linked_list_const_iterator;

  single_linked_list() = default;

  single_linked_list(std::initializer_list<Item> items)
  {
    for (auto &item : items)
    {
      push_back(item);
    }
  }

  ~single_linked_list()
  {
    clear();
  }

  void clear() noexcept
  {
    while (m_head)
    {
      delete std::exchange(m_head, m_head->next);
    }

    m_tail = nullptr;
  }

  void push_front(value_type item)
  {
    auto newnode = new node { std::move(item) };
    if (m_head)
    {
      newnode->next = m_head;
      m_head = newnode;
    }
    else
    {
      m_head = m_tail = newnode;
    }
  }

  void push_back(value_type item)
  {
    auto newnode = new node { std::move(item) };
    if (m_tail)
    {
      m_tail->next = newnode;
      m_tail = newnode;
    }
    else
    {
      m_head = m_tail = newnode;
    }
  }

  void insert_after(const_iterator place, value_type item)
  {
    auto ptr = const_cast<node *>(place.Get());
    if (!ptr)
    {
      push_front(std::move(item));
      return;
    }

    auto newnode = new node { std::move(item) };
    newnode->next = ptr->next;
    ptr->next = newnode;
  }

  const_iterator find(const_reference item) const noexcept
  {
    for (auto it = begin(); it != end(); ++it)
    {
      if (*it == item)
      {
        return it;
      }
    }
    return const_iterator { nullptr };
  }

  iterator find(const_reference item) noexcept
  {
    auto it = static_cast<const single_linked_list &>(*this).find(item);
    return iterator { const_cast<node *>(it.Get()) };
  }

  void erase_after(const_iterator place) noexcept
  {
    auto ptr = const_cast<node *>(place.Get());
    if (ptr)
    {
      auto nodeToDelete = ptr->next;
      if (ptr->next)
      {
        ptr->next = ptr->next->next;
      }
      delete nodeToDelete;
    }
    else
    {
      assert(m_head != nullptr);
      delete std::exchange (m_head, m_head->next);
    }
  }

  void pop_front() noexcept
  {
    erase_after(iterator { nullptr });
  }

  const_iterator begin() const noexcept
  {
    return const_iterator { m_head };
  }

  iterator end() const noexcept
  {
    return iterator { nullptr };
  }

  const_iterator cbegin() const noexcept
  {
    return const_iterator { m_head };
  }

  const_iterator cend() const noexcept
  {
    return const_iterator { nullptr };
  }

  iterator begin() noexcept
  {
    return iterator { m_head };
  }

  iterator end() noexcept
  {
    return iterator { nullptr };
  }

  [[nodiscard]] bool empty() const noexcept { return !m_head; }

 private:
  static node *m_head = nullptr;
  node *m_tail = nullptr;
};
#endif