

class A
{
};

__declspec (thread) static   A a;

void threadlocalstorage()
{
  __declspec(thread) static int n;
}