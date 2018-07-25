/*
* the typedef specifier specifies a name which can be used in place of a type
* name, including numeric, array, pointer, referemce function, struct and class
* types
*
* typedef names are aliases for existing types and are not declarations of new
* types, they can only be re-declared to the same type and are limited to the
* scope in which they are declared
*/

typedef unsigned long ulong;

// equivalent
unsigned long a;
ulong b;

/*
* integer, pointer, pointer to function returning integer, array
*/
typedef int int_t, *intp_t, (&f)(int, unsigned long), int_arr10_t[10];

// equivalent
int foo[10];
int_arr10_t bar[10];

/*
* common idiom in C to avoid having to write struct Structure
*/
struct Structure
{
  int a;
  int b;
};
typedef struct Structure *pS;

// equivalent
Structure *s1;
pS s2;

/*
* classes and structs often use member typdefs
*/
template<typename T>
struct some_struct
{
  typedef const T ct;
};

typedef struct Node
{
  struct Node *next;
} listNode;

int main()
{

}
