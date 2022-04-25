#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include "Book.h"

class file
{
    public:
        file() {}
        void writeBooks(Book *book, int num)
        {
            fstream b;
            b.open("Books.txt", ios::out);
            b << num << endl;
            for (int i = 0; i<num; i++)
            {
                b << book[i].getName() << '\t';
                b << book[i].getPublisher()<< '\t';
                b << book[i].getCategory() << '\t';
                b << book[i].getPrice()<< '\t';
                b << book[i].getAvailable_copies()<< endl;
            }
        }
        void readBooks(Book *book ,int &num)
        {
            fstream b;
            string s;
            int n;
            float f;
            b.open("Books.txt", ios::in);
            b >> num;
            //cout<<"num" <<num<<endl;
            for (int i = 0; i< num; i++)
            {
                b >> s;
                book[i].setName(s);
                b >> s;
                book[i].setPublisher(s);
                b >> s;
                book[i].setCategory(s);
                b >> f;
                book[i].setPrice(f);
                b >> n;
                book[i].setAvailable_copies(n);
            }
        }

      /*  void readAdmin(Admin a)
        {
            fstream b;
            string s;
            b.open("Admin.txt", ios::in);
            b >> num;
            //cout<<"num" <<num<<endl;
            for (int i = 0; i< num; i++)
            {
                b >> s;
                a[i].setName(s);
                b >> s;
                a[i].setPassword(s);
                b >> s;
                a[i].setPhone(s);
            }
        }*/
        virtual ~file() {}

    protected:

    private:
};

#endif // FILE_H
