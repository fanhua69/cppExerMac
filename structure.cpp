
#include <iostream>
#include <vector>
#include <list>

#pragma pack(show)

#pragma pack(4)

#pragma pack(show)


using namespace std;

struct Test
{
  Test(int &m1):n(0),m(m1)
  {
  }

  void fun()
  {
  }

  const int n;
  const int &m;
};

struct CLS
{
  int m_i;
  CLS(int i) : m_i(i)
  {
  }
  
  CLS(int m,double n):CLS()
  {
  }

  CLS()
  {
    CLS(0);
  }
};

class ExampleClass
{
  char c[9];
  double d;
}aa;

union ExampleUnion
{
  char c[9];
  double d;
};

struct  a
{
  int a1;
  char a2;
  union Example
  {
    char c[9];
    double d;
  }aa;
}A;

void structure(void)
{
  int d = sizeof(ExampleUnion);
  d = 9;
  //4294967296;
  //int a = 0XFFFF; // 4294967295;
  //if ( a > 65536 )
  //{
  //  cout << "32 bit" << endl;
  //}
  //else
  //{
  //  cout << "16 bit" << endl;
  //}

  char str1[] = "abc";
  char str2[] = "abc";
  const char str3[] = "abc";
  const char str4[] = "abc";
  const char *str5 = "abc";
  const char *str6 = "abc";
  char *str7 = "abc";
  char *str8 = "abc";
  cout << (str1 == str2) << endl;//0  �ֱ�ָ����Ե�ջ�ڴ�
  cout << (str3 == str4) << endl;//0  �ֱ�ָ����Ե�ջ�ڴ�
  cout << (str5 == str6) << endl;//1ָ�����ֳ�������ַ��ͬ
  cout << (str7 == str8) << endl;//1ָ�����ֳ�������ַ��ͬ


  //char a[] = "hello";
  //a[0] = 'X';
  //char *p = "world"; // ע��p ָ�����ַ���
  //p[0] = 'X'; // ���������ܷ��ָô�������ʱ����
  
  
  typedef std::list <int> IntArray;
  IntArray array;
  array.push_back(1);
  array.push_back(2);
  array.push_back(2);
  array.push_back(3);

  // ɾ��array���������е�2
  for ( IntArray::iterator itor = array.begin(); itor != array.end();)
  {
    if ( 2 == *itor )
    {
      itor = array.erase(itor);
    }
    else
    {
      itor++;
    }
  }

 // vector <int> array;
 // array.push_back(1);
 // array.push_back(2);
 // array.push_back(3);

 // vector<int>::size_type i;
 // decltype((i)) k = i;
 // cout << typeid(i).name() << endl;

  //for ( int i = array.size() - 1; i >= 0; i-- ) // �������array����
  //{
  //  cout << typeid(i).name() << endl;
  //  cout << array[i] << endl;
  //}
 // 
 //// unsigned int i;
 // for ( i = array.size() - 1; i >= 0; --i ) // �������array����
 // {
 //   cout << array[i] << endl;
 // }

 // int j; 
 // for ( j = 0; j < array.size(); j++) 
 // {
 //   cout << array[j] << endl;
 // }



  //int  b = 1;
  //int i = static_cast<int>(b);
  //int& j = reinterpret_cast<int&>(b);
  //cout << i << endl;
  //cout << j << endl;

  //float a = 1.0f;
  //cout << (int)a << endl;
  //cout << (int&)a << endl;
  //cout << boolalpha << ((int)a == (int&)a) << endl; // ���ʲô��
  //float b = 0.0f;
  //cout << (int)b << endl;
  //cout << (int&)b << endl;
  //cout << boolalpha << ((int)b == (int&)b) << endl; // ���ʲô��


  //Test a(1);
  //a.fun();

  //Test b;  // Test b(); is wrong
  //b.fun();

  //cout << (true ? 1 : '1') << endl;

  //unsigned int const size1 = 2;
  //char str1[size1];
  //unsigned int temp = 0;
  //cin >> temp;
  //unsigned int const size2 = temp;
  //const int nn =10;
  //char str2[nn];
}
