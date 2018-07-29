class A;

// incomplete type 'A' named in nested name specifier
// class A::B
// {
//
// };

class A
{

public:
  class B;

};

// we can refer to a member of A now that A is defined
class A::B
{

};

int main()
{

}
