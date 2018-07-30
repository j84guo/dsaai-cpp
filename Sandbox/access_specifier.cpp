class A
{
public:
  int x;

  void useOther(A a)
  {
    a.z;
  }

protected:
  int y;

private:
  int z;
};

int main()
{
  int i;
  A a;

  a.x;
  // a.y;
  // a.z;

  /*
  * note that objects can access private members of other objects of same class
  */
  A b;
  b.useOther(a);
}
