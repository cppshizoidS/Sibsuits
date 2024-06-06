#include <iostream>
#include <ctime>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;

int SIZE_OF_HASH_TABLE = 11;
int NUM_OF_VALUES = 50;

int No_Collision = 0;

struct list{
    list* next;
    int data;
};

struct hash_table{
    hash_table* next;
    int hash;
    
    list* data;
};

int hash_func(int value){
    return value % SIZE_OF_HASH_TABLE;
}

void printList(hash_table* head) {
    cout << "~~~~~~~~~~~~ Метод прямого связывания ~~~~~~~~~~~~" << endl;
    while (head != nullptr) {
        cout << head->hash << "   ";
        list* temp = head->data;
        while (temp != nullptr) {
            cout << " -> " << temp->data;
            temp = temp->next;
        }
        head = head->next;
        cout << endl;
    }
}

void addToTheTable(hash_table* head, int value) {
    int hash = hash_func(value);
    hash_table* find = head;

    while (find != nullptr){
        if (find->hash == hash){
            break;
        }
        find = find->next;
    }

    if (find == nullptr){
        hash_table* p = new hash_table;
        p->hash = hash;
        p->data = new list;
        p->data->next = nullptr;
        p->data->data = value;
        find->next = p;
        p->next = nullptr;
    }else{
        list* ps = new list;
        ps->data = value;
        ps->next = find->data;
        find->data = ps;
    }
    return;
}

int genValue() {
    return rand() % 1000;
}

int hashSearch(hash_table* head, int value) {
    int input = hash_func(value);
    int i = 1;
    list* answer = nullptr;
    while (head != nullptr) {
        if (head->hash == input) {
            answer = head->data;
            while (answer != nullptr) {
                if (answer->data == value) {
                    return i;
                }
                i++;
                answer = answer->next;
            }
            return 0;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    srand(time(NULL));

    hash_table* head = nullptr;
    int value;

    // Инициализация таблицы
    hash_table* p, * temp;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }

    // Запись в хеш-таблицу
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    printList(head);
    cout << "Коллизии = " << NUM_OF_VALUES - No_Collision << endl;
    
    hash_table* ptr = new hash_table;
    delete ptr;
    

    //задание 2 таблица
    NUM_OF_VALUES = 1000;
    cout << endl << endl;
    cout << setw(20) << "Размер хеш-" << setw(27) << "Количество" << setw(30) << "Количество" << endl;
    cout << setw(15) << "таблицы" << setw(39) << "исходных символов" << setw(24) << "коллизий" << endl;
    
    
    //размер таблицы = 19
    SIZE_OF_HASH_TABLE = 19;
    No_Collision = 0;
    head = nullptr;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    cout << setw(5) << SIZE_OF_HASH_TABLE << setw(20) << NUM_OF_VALUES << setw(20) << NUM_OF_VALUES - No_Collision << endl;
    new hash_table;
    
    
    //размер таблицы = 29
    SIZE_OF_HASH_TABLE = 29;
    No_Collision = 0;
    head = nullptr;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    cout << setw(5) << SIZE_OF_HASH_TABLE << setw(20) << NUM_OF_VALUES << setw(20) << NUM_OF_VALUES - No_Collision << endl;
    new hash_table;
    
    
    
    //размер таблицы = 37
    SIZE_OF_HASH_TABLE = 37;
    No_Collision = 0;
    head = nullptr;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    cout << setw(5) << SIZE_OF_HASH_TABLE << setw(20) << NUM_OF_VALUES << setw(20) << NUM_OF_VALUES - No_Collision << endl;
    new hash_table;
    
    
    //размер таблицы = 47
    SIZE_OF_HASH_TABLE = 47;
    No_Collision = 0;
    head = nullptr;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    cout << setw(5) << SIZE_OF_HASH_TABLE << setw(20) << NUM_OF_VALUES << setw(20) << NUM_OF_VALUES - No_Collision << endl;
    new hash_table;
    
    
    //размер таблицы = 53
    SIZE_OF_HASH_TABLE = 53;
    No_Collision = 0;
    head = nullptr;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    cout << setw(5) << SIZE_OF_HASH_TABLE << setw(20) << NUM_OF_VALUES << setw(20) << NUM_OF_VALUES - No_Collision << endl;
    new hash_table;
    
    
    //размер таблицы = 59
    SIZE_OF_HASH_TABLE = 59;
    No_Collision = 0;
    head = nullptr;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    cout << setw(5) << SIZE_OF_HASH_TABLE << setw(20) << NUM_OF_VALUES << setw(20) << NUM_OF_VALUES - No_Collision << endl;
    new hash_table;
    
    
    //размер таблицы = 67
    SIZE_OF_HASH_TABLE = 67;
    No_Collision = 0;
    head = nullptr;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    cout << setw(5) << SIZE_OF_HASH_TABLE << setw(20) << NUM_OF_VALUES << setw(20) << NUM_OF_VALUES - No_Collision << endl;
    new hash_table;
    
    
    //размер таблицы = 79
    SIZE_OF_HASH_TABLE = 79;
    No_Collision = 0;
    head = nullptr;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    cout << setw(5) << SIZE_OF_HASH_TABLE << setw(20) << NUM_OF_VALUES << setw(20) << NUM_OF_VALUES - No_Collision << endl;
    new hash_table;
    
    
    //размер таблицы = 89
    SIZE_OF_HASH_TABLE = 89;
    No_Collision = 0;
    head = nullptr;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    cout << setw(5) << SIZE_OF_HASH_TABLE << setw(20) << NUM_OF_VALUES << setw(20) << NUM_OF_VALUES - No_Collision << endl;
    new hash_table;
    
    
    //размер таблицы = 97
    SIZE_OF_HASH_TABLE = 97;
    No_Collision = 0;
    head = nullptr;
    temp = reinterpret_cast<hash_table*>(&head);
    for (int i = 0; i < SIZE_OF_HASH_TABLE; i++) {
        p = new hash_table;
        temp->next = p;
        No_Collision++;
        temp = p;
        p->hash = i;
        p->data = nullptr;
        p->next = nullptr;
    }
    for (int i = 0; i < NUM_OF_VALUES; i++) {
        value = genValue();
        addToTheTable(head, value);
    }
    cout << setw(5) << SIZE_OF_HASH_TABLE << setw(20) << NUM_OF_VALUES << setw(20) << NUM_OF_VALUES - No_Collision << endl;
    new hash_table;
    
    return 0;
}

