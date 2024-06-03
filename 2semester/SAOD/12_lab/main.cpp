#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>

struct tLE32 {
  tLE32 *next;
  union {
    int data;
    unsigned char Digit[sizeof(data)];
  };
};

struct Queue32 {
  tLE32 *head;
  tLE32 *tail;
};

void QueueFillRand(int n, tLE32 *(&head), tLE32 *(&tail)) {
  srand(time(NULL));
  int i = 1;
  tLE32 *p;
  head = tail = new tLE32;
  head->next = tail->next = 0;
  tail->data = rand();
  i++;
  do {
    p = new tLE32;
    p->data = rand();
    tail->next = p;
    tail = p;
    i++;

  } while (i <= n);
  tail->next = 0;
}

int CheckSum(tLE32 *head) {
  tLE32 *p;
  double sum = 0;
  for (p = head; p; p = p->next) {
    sum += p->data;
  }
  return sum;
}

void PrintList(tLE32 *head, tLE32 *tail) {
  tLE32 *p;
  for (p = head; p; p = p->next) {
    std::cout.setf(std::ios::left);
    int temp = p->data;
  }
}

void DeleteList(tLE32 *(&head), tLE32 *(&tail)) {
  tLE32 *p, *t;
  for (p = head; p; p = t) {
    t = p->next;
    delete p;
  }
  head = tail = NULL;
}

/*
 Hash-Insert (T, K)
 i := 0
 DO
    j := H (K,i)
    IF ( T[j] = NULL )
        T[j] = K
        return j
    FI
    i:= i+1
 OD ( i = m )
 */

void HashInsert(tLE32 *(&head), tLE32 *(&tail), int key) { int i = 0; }

int main() {}
