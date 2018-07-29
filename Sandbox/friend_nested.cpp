template <typename T>
class A
{
public:
  class B;
  B makeDummy() { return B(10); }

  template <typename U>
  void useDummy(typename A<U>::B b);
};

/*
* B has a one to one relationship with A, since each instantiation of A is
* related to one instantiation of B
*
* A<T>::B has a one to many friendship with A<T>, since A<T>::B is a friend with
* each template instantiation of A<T> (due to template <typename>)
*/
template <typename T>
class A<T>::B
{
public:
  B(int x): x(x) { }

private:
  int x;
  template<typename> friend class A;
};

template <typename T>
template <typename U>
void A<T>::useDummy(typename A<U>::B b)
{
  b.x;
}

int main()
{
  A<int> a;
  A<int>::B b = a.makeDummy();

  A<double> c;
  A<double>::B d = c.makeDummy();

  a.useDummy<double>(d);
}
