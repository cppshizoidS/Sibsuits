#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

struct phoneInfo
{
    std::string firstname,lastname,patronymic,phoneNumber;
};

bool comprasion(phoneInfo x, phoneInfo y,int &fKey,int &sKey,bool &reverse)
{
    std::string fKeyPole1 ,fKeyPole2, sKeyPole1,sKeyPole2 ;
    switch(fKey)
    {
        case 1: {fKeyPole1 = x.firstname;fKeyPole2 = y.firstname; break;}
        case 2: {fKeyPole1 = x.lastname;fKeyPole2 = y.lastname; break;}
        case 3: {fKeyPole1 = x.patronymic;fKeyPole2 = y.patronymic; break;}
        case 4: {fKeyPole1 = x.phoneNumber;fKeyPole2 = y.phoneNumber; break;}
    }
    switch(sKey)
    { 
        case 1: {sKeyPole1 = x.firstname; sKeyPole2 = y.firstname; break;}
        case 2: {sKeyPole1 = x.lastname; sKeyPole2 = y.lastname; break;}
        case 3: {sKeyPole1 = x.patronymic; sKeyPole2 = y.patronymic; break;}
        case 4: {sKeyPole1 = x.phoneNumber; sKeyPole2 = y.phoneNumber; break;}
    }
    if (reverse)
    {
        if (fKeyPole1 > fKeyPole2) 
            return true;
        else if (fKeyPole1 < fKeyPole2)
            return false;
        else 
            return sKeyPole1 > sKeyPole2;
    }
    else
    {
        if (fKeyPole1 < fKeyPole2) 
            return true;
        else if (fKeyPole1 > fKeyPole2)
            return false;
        else 
            return sKeyPole1 < sKeyPole2;
    }
}

void SelectSort(std::vector <phoneInfo> &phoneBook,int &fKey,int &sKey,bool &reverse)
{
    int k;
    int n=phoneBook.size();
    for (int i=0; i<n-1; i++)
    {
        k = i;
        for (int j=i+1; j<n; j++)
        {
            if (comprasion(phoneBook[j],phoneBook[k],fKey,sKey,reverse)) k = j;
        }
        
        
        std::swap(phoneBook[i],phoneBook[k]);
    }
}
void printTable(std::vector<phoneInfo> &phoneBook)
{
    std::cout << std::left << std::setw(15) << "First name" 
         << std::setw(15) << "Last name" 
         << std::setw(15) << "patronymic" 
         << std::setw(15) << "Phone number" << "\n\n";

    for (auto phoneInfo : phoneBook) 
    {
        std::cout << std::left << std::setw(15) << phoneInfo.firstname 
             << std::setw(15) << phoneInfo.lastname 
             << std::setw(15) << phoneInfo.patronymic 
             << std::setw(15) << phoneInfo.phoneNumber << "\n";
    }
    std::cout << "\n";
}
int main() 
{
    std::vector<phoneInfo> phoneBook
    {
        {"Alex","Krivoschecov","Alexandrovich","88005553535"},
        {"Konstantin","Prozorenko","Vladislavovich","89513929080"},
        {"Nikita","Zhinov","Andreevich","12345678900"},
        {"Mihail","Romanov","Alexandrovich","98765432100"}
    }; 
    printTable(phoneBook);
    std::cout << "Default sort key: last name and phone number\n\n";
    std::cout << "Do you want to change a key(1 or 0)?";
    int ans,fKey=2,sKey=4;
    
    std::cin >> ans;
    if (ans==1)
    {
        ans=0;
        std::cout << "Choose first key:\n" << "1. First name\n2. Last name\n3. patronymic\n4. Phone number\n";
        std::cin >> ans;
        switch(ans)
        {
            case 1: {fKey=1; break;}
            case 2: {fKey=2; break;}
            case 3: {fKey=3; break;}
            case 4: {fKey=4; break;}
        }
        std::cout << "Choose second key:\n" << "1. First name\n2. Last name\n3. patronymic\n4. Phone number\n";
        std::cin >> ans;
        switch(ans)
        {
            case 1: {sKey=1; break;}
            case 2: {sKey=2; break;}
            case 3: {sKey=3; break;}
            case 4: {sKey=4; break;}
        }
    }
    bool reverse = false;
    SelectSort(phoneBook,fKey,sKey,reverse);
    printTable(phoneBook);
    return 0;
}