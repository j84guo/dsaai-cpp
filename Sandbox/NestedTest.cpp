template <typename T>
class A
{

public:
  class B;

};

template <typename T>
class A<T>::B
{

};

int main()
{
  A<int> a;
  A<int>::B b;
}
