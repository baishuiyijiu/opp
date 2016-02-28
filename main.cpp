#include <iostream>
#include <string.h>
using namespace std;


class mystring
{
//private:
  public:
    char* s;

public:
    mystring()
    {

        s  = new char[1024];
        cout <<"mystring"<<endl;

    }
    mystring(const mystring &it) //深拷贝
    {
        cout<<"copy mystring"<<endl;
        s = new char[1024];
        memset(s,0,1024);
        strcpy(s,it.s);

    }
    ~mystring()
    {
        cout<<"delete mystring"<<endl;

    }
    mystring operator = (const mystring &it)
    {
        cout<<"operate mystring"<<endl;
        memset(s,0,1024);
        strcpy(s,it.s);
        return *this;
    }
    mystring operator = (const char *str)
    {

        memset(s,0,1024);
        strcpy(s,str);
        return *this;
    }

    mystring operator = (int i)
    {
        memset(s,0,1024);
        sprintf(s,"%d",i);
        return *this;
    }

    mystring operator + (const mystring &it)
    {
        strcat(s,it.s);

        return *this;
    }
    mystring operator + (const char *str)
    {
        strcat(s,str);

        return *this;
    }
    void operator +=(const char* str)
    {
        strcat(this->s,str);

    }

    mystring operator + (int i)
    {
        char temp[100] = {0};

        sprintf(temp,"%d",i);

        strcat(s,temp);

        return *this;
    }
    friend mystring operator +(const char*str,const mystring &it);
};

mystring operator +(const char*str,const mystring &it)
{
    mystring str1;
    char buf[1024] = {0};
    sprintf(buf,"%s%s",str,it.s);
    strcpy(str1.s,buf);
    return str1;
}

mystring operator +(int i,const mystring &it)
{
    mystring str1;
    char buf[1024] = {0};
    sprintf(buf,"%d%s",i,it.s);
    strcpy(str1.s,buf);
    return str1;
}



int main01()
{
    mystring str1;
    mystring str3;
    strcpy(str1.s,"helloworld");
    mystring str2 = str1;
    //str2.operator =( str1); // 不是拷贝构造的过程，
    str3 = str2 = 100;

    cout << str2.s << endl;
    return 0;
}
int main()
{
    mystring str1;
    str1="hello";
    mystring str2;
    str2=" world";
    mystring str3;
   // str3 = str1 +str2;
    str3 = 100+str1;
    str3 += "BBBBB";
    cout << str3.s << endl;
    return 0;
}

