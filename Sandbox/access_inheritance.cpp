class A
{

// public members are visible globally
public:
  int x;

// protected members are visisble in the defining class and derived classes
protected:
  int y;

// private members are only accessible in defining class
private:
  int z;

};

// public and protected members are inherited without change, private members
// are not inherited
class B: public A
{
  // x is public
  // y is protected
  // z is not accessible from B
};

// public members downgrade to protected, protected members are inherited as is,
// private members are not inherited
class C: protected A
{
  // x is protected
  // y is protected
  // z is not accessible from C
};

// public and protected members downgrade to private, private members are not
// inherited
class D: private A
{
  // x is private
  // y is private
  // z is not accessible from D
};
