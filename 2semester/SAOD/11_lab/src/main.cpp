#include <math.h>

#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

struct tLE16 {
  tLE16 *next;
  union {
    unsigned short int data;
    unsigned char Digit[sizeof(data)];
  };
};

struct tLE32 {
  tLE32 *next;
  union {
    int data;
    unsigned char Digit[sizeof(data)];
  };
};

struct Queue16 {
  tLE16 *head;
  tLE16 *tail;
};

struct Queue32 {
  tLE32 *head;
  tLE32 *tail;
};

void QueueFillInc(int n, tLE32 *(&head), tLE32 *(&tail)) {
  int i = 1;
  tLE32 *p;
  head = tail = new tLE32;
  head->next = tail->next = 0;
  tail->data = i;
  i++;
  do {
    p = new tLE32;
    p->data = i;
    tail->next = p;
    tail = p;
    i++;

  } while (i <= n);
  tail->next = 0;
}

void QueueFillInc(int n, tLE16 *(&head), tLE16 *(&tail)) {
  int i = 1;
  tLE16 *p;
  head = tail = new tLE16;
  head->next = tail->next = 0;
  tail->data = i;
  i++;
  do {
    p = new tLE16;
    p->data = i;
    tail->next = p;
    tail = p;
    i++;

  } while (i <= n);
  tail->next = 0;
}

void QueueFillRand(int n, tLE16 *(&head), tLE16 *(&tail)) {
  srand(time(NULL));
  int i = 1;
  tLE16 *p;
  head = tail = new tLE16;
  head->next = tail->next = 0;
  tail->data = rand() % 65535;
  i++;
  do {
    p = new tLE16;
    p->data = rand() % 65535;
    tail->next = p;
    tail = p;
    i++;
  } while (i <= n);
  tail->next = 0;
}

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

void QueueFillDec(int n, tLE16 *(&head), tLE16 *(&tail)) {
  int i = 1;
  tLE16 *p;
  head = tail = new tLE16;
  head->next = tail->next = 0;
  tail->data = n;
  i++;
  do {
    p = new tLE16;
    p->data = n - i + 1;
    tail->next = p;
    tail = p;
    i++;

  } while (i <= n);
  tail->next = 0;
}

void QueueFillDec(int n, tLE32 *(&head), tLE32 *(&tail)) {
  int i = 1;
  tLE32 *p;
  head = tail = new tLE32;
  head->next = tail->next = 0;
  tail->data = n;
  i++;
  do {
    p = new tLE32;
    p->data = n - i + 1;
    tail->next = p;
    tail = p;
    i++;

  } while (i <= n);
  tail->next = 0;
}

int CheckSum(tLE16 *head) {
  tLE16 *p;
  double sum = 0;
  for (p = head; p; p = p->next) {
    sum += p->data;
  }
  return sum;
}

int RunNumber(tLE16 *head) {
  int sequence = 1;
  tLE16 *p;
  for (p = head; p->next; p = p->next) {
    if (p->data > p->next->data) {
      sequence++;
    }
  }
  return sequence;
}

int CheckSum(tLE32 *head) {
  tLE32 *p;
  double sum = 0;
  for (p = head; p; p = p->next) {
    sum += p->data;
  }
  return sum;
}

int RunNumber(tLE32 *head) {
  int sequence = 1;
  tLE32 *p;
  for (p = head; p->next; p = p->next) {
    if (p->data > p->next->data) {
      sequence++;
    }
  }
  return sequence;
}

std::string decimalToBinary(int decimal) {
  std::string binary = "";

  if (decimal == 0) {
    binary = "0";
  } else {
    while (decimal > 0) {
      binary = std::to_string(decimal % 2) + binary;
      decimal /= 2;
    }
  }

  return binary;
}

void PrintList(tLE16 *head, tLE16 *tail) {
  tLE16 *p;
  for (p = head; p; p = p->next) {
    cout.setf(ios::left);
    int temp = p->data;
    cout << p->data << " (" << decimalToBinary(temp) << ") ";
  }
  cout << endl << "Summa: " << CheckSum(head) << endl;
  cout << "Series: " << RunNumber(head);
  cout << endl;
}

void PrintList(tLE32 *head, tLE32 *tail) {
  tLE32 *p;
  for (p = head; p; p = p->next) {
    cout.setf(ios::left);
    int temp = p->data;
    cout << p->data << " (" << decimalToBinary(temp) << ") ";
  }
  cout << endl << "Summa: " << CheckSum(head) << endl;
  cout << "Series: " << RunNumber(head);
  cout << endl;
}

void DeleteList(tLE32 *(&head), tLE32 *(&tail)) {
  tLE32 *p, *t;
  for (p = head; p; p = t) {
    t = p->next;
    delete p;
  }
  head = tail = NULL;
}

void DigitalSort(tLE16 *(&S), tLE16 *(&tail), int &M, int dec = 0) {
  M = 0;                // счетчик
  int KDI[2] = {1, 0};  // индексы битов для определения цифры
  int L = 2;       // колво битов
  tLE16 *temp;     // вреиненный указатель
  Queue16 q[256];  // очередь для каждой цифры
  tLE16 *p;  // указатель для перебора входного списка
  unsigned char d;  // текущая цифра
  int k;            // индекс бита
  // перебор битов
  for (int j = L - 1; j >= 0; j--) {
    // инициализация очередей
    for (int i = 0; i < 256; i++) {
      q[i].tail = (tLE16 *)&(q[i].head);  // определяем значение цифры на бите
    }
    p = S;
    k = KDI[j];
    // распределение элементов по очередям в зависимости от значения цифры
    while (p != NULL) {
      M++;
      d = p->Digit[k];
      q[d].tail->next = p;
      q[d].tail = p;
      p = p->next;
    }
    temp = p = (tLE16 *)&S;

    int i = 0;
    int sign = 1;
    if (dec == 1) {
      i = 255;
      sign = -1;
    }
    // сбор элементов из очередей в отсортированном порядке
    while ((i > -1) && (i < 256)) {
      M++;
      if (q[i].tail != (tLE16 *)&(q[i].head)) {
        p->next = q[i].head;
        p = q[i].tail;
      }
      i += sign;
    }
    p->next = NULL;
    S = temp->next;
  }
  return;
}

void DigitalSort(tLE32 *(&S), tLE32 *(&tail), int &M, int dec = 0) {
  M = 0;
  int KDI[4] = {3, 2, 1, 0};
  int L = 4;
  tLE32 *temp;
  Queue32 q[256];
  tLE32 *p;
  unsigned char d;
  int k;

  for (int j = L - 1; j >= 0; j--) {
    for (int i = 0; i < 256; i++) {
      q[i].tail = (tLE32 *)&(q[i].head);
    }
    p = S;
    k = KDI[j];
    while (p != NULL) {
      M++;
      d = p->Digit[k];
      q[d].tail->next = p;
      q[d].tail = p;
      p = p->next;
    }
    temp = p = (tLE32 *)&S;

    int i = 0;
    int sign = 1;
    if (dec == 1) {
      i = 255;
      sign = -1;
    }

    while ((i > -1) && (i < 256)) {
      M++;
      if (q[i].tail != (tLE32 *)&(q[i].head)) {
        p->next = q[i].head;
        p = q[i].tail;
      }
      i += sign;
    }

    p->next = NULL;
    S = temp->next;
  }
  return;
}

int main() {
  int n = 10, M_real_inc, M_real_dec, M_real_rand, temp = 0;
  tLE16 *head16 = NULL, *tail16 = NULL;
  tLE32 *head32 = NULL, *tail32 = NULL;
  int C = 0, M = 0;

  n = 20;
  temp = 0;
  cout << "2 bit" << endl;
  QueueFillRand(n, head16, tail16);
  cout << "First list: ";
  PrintList(head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  cout << endl;
  PrintList(head16, tail16);
  cout << endl << "4 bit" << endl;
  QueueFillRand(n, head32, tail32);
  cout << "First list: ";
  PrintList(head32, tail32);
  DigitalSort(head32, tail32, temp, 0);
  cout << endl;
  PrintList(head32, tail32);

  cout << endl << endl;
  cout << endl << "The complexity of digital sorting DigitalSort" << endl;
  cout << setw(35) << "2 bit" << endl;
  cout << setw(5) << " n" << setw(7) << "teor" << setw(10) << "inc" << setw(10)
       << "dec" << setw(10) << "rand" << endl;

  // 100
  n = 100;
  temp = 0;
  QueueFillDec(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_dec = temp;
  temp = 0;
  QueueFillInc(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_inc = temp;
  temp = 0;
  QueueFillRand(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_rand = temp;
  cout << setw(5) << n << setw(7) << 2 * (256 + n) << setw(9) << M_real_inc
       << setw(10) << M_real_dec << setw(10) << M_real_rand << endl;

  // 200
  n = 200;
  temp = 0;
  QueueFillDec(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_dec = temp;
  temp = 0;
  QueueFillInc(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_inc = temp;
  temp = 0;
  QueueFillRand(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_rand = temp;
  cout << setw(5) << n << setw(7) << 2 * (256 + n) << setw(9) << M_real_inc
       << setw(10) << M_real_dec << setw(10) << M_real_rand << endl;

  // 300
  n = 300;
  temp = 0;
  QueueFillDec(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_dec = temp;
  temp = 0;
  QueueFillInc(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_inc = temp;
  temp = 0;
  QueueFillRand(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_rand = temp;
  cout << setw(5) << n << setw(7) << 2 * (256 + n) << setw(9) << M_real_inc
       << setw(10) << M_real_dec << setw(10) << M_real_rand << endl;

  // 400
  n = 400;
  temp = 0;
  QueueFillDec(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_dec = temp;
  temp = 0;
  QueueFillInc(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_inc = temp;
  temp = 0;
  QueueFillRand(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_rand = temp;
  cout << setw(5) << n << setw(7) << 2 * (256 + n) << setw(9) << M_real_inc
       << setw(10) << M_real_dec << setw(10) << M_real_rand << endl;

  // 500
  n = 500;
  temp = 0;
  QueueFillDec(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_dec = temp;
  temp = 0;
  QueueFillInc(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_inc = temp;
  temp = 0;
  QueueFillRand(n, head16, tail16);
  DigitalSort(head16, tail16, temp, 0);
  M_real_rand = temp;
  cout << setw(5) << n << setw(7) << 2 * (256 + n) << setw(9) << M_real_inc
       << setw(10) << M_real_dec << setw(10) << M_real_rand << endl;

  cout << endl
       << endl
       << "The complexity of digital sorting DigitalSort" << endl;
  cout << setw(10) << "4 bit" << endl;
  cout << setw(5) << " n" << setw(7) << "teor" << setw(10) << "inc" << setw(10)
       << "dec" << setw(10) << "rand" << endl;
}
